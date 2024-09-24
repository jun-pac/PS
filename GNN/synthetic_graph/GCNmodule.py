"""Torch Module for Simplifying Graph Convolution layer"""
# pylint: disable= no-member, arguments-differ, invalid-name
import torch as th
import torch
from torch.nn import init

from torch import nn
import dgl
from dgl import function as fn
from dgl import DGLError
from dgl.utils import expand_as_pair
from dgl.nn.pytorch.conv.graphconv import EdgeWeightNorm
import torch.nn.functional as F
import dgl.nn as dglnn


def normalize(h):
    return (h - h.mean(0)) / h.std(0)

class JJ_Norm(torch.nn.Module):
    def __init__(self, labels, times, num_time, num_label, split):
        super().__init__()
        self.labels = labels
        self.times = times
        self.num_time = num_time
        self.num_label = num_label
        self.split = split
        self.train_idx = (self.times<self.split).nonzero().squeeze()
        self.test_idx = (self.times>=self.split).nonzero().squeeze()
        #print(self.train_idx.shape)
        #print(self.test_idx.shape)

    def forward(self, x):
        clone_x=torch.clone(x)
        train_mean = torch.zeros((self.num_time, self.num_label, x.shape[1]), requires_grad=False)
        train_cnt = torch.zeros((self.num_time, self.num_label), requires_grad=False)
        train_time_mean = torch.zeros((self.num_time, x.shape[1]), requires_grad=False)
        train_time_cnt = torch.zeros(self.num_time, requires_grad=False)
        test_cnt = torch.zeros(1, requires_grad=False)
        test_mean = torch.zeros((x.shape[1]), requires_grad=False)
        for u in self.test_idx:
            test_cnt[0] += 1
            test_mean+=x[u]
        for u in self.train_idx:
            t=self.times[u]
            train_time_cnt[t] += 1
            train_cnt[t][self.labels[u]] += 1
            train_mean[t][self.labels[u]] += x[u]                 
        for t in range(self.num_time):
            for l in range(self.num_label):
                train_time_mean[t]+=train_mean[t][l]
                train_mean[t][l]=train_mean[t][l]/max(1,train_cnt[t][l])
            train_time_mean[t]/=max(1,train_time_cnt[t])
        test_mean/=max(1,test_cnt[0])


        # Add norm values
        test_var = torch.zeros(1,requires_grad=False)
        rsq = torch.zeros(self.num_time,requires_grad=False)
        msq = torch.zeros(self.num_time,requires_grad=False)
        for u in self.test_idx:
            test_var[0] += torch.norm(x[u] - test_mean) ** 2
        for u in self.train_idx:
            t = self.times[u]
            msq[t] += torch.norm(train_mean[t][self.labels[u]] - train_time_mean[t]) ** 2
            rsq[t] += torch.norm(x[u] - train_mean[t][self.labels[u]]) ** 2


        # Calculate Statistics
        test_var[0]/=max(1,test_cnt[0]-1)
        for t in range(self.split):
            msq[t]/=max(1,train_time_cnt[t]-1)
            rsq[t]/=max(1,train_time_cnt[t]-1)
        alpha=torch.ones(self.split,requires_grad=False)
        alpha_sq=torch.zeros(self.split,requires_grad=False)
        for t in range(self.split):
            alpha_sq[t]=(test_var[0]-msq[t])/max(0.000001,rsq[t])
            if(alpha_sq[t]>0):
                alpha[t]=torch.sqrt(alpha_sq[t])
            else:
                alpha[t]=0       


        # Update modified vals
        for u in self.train_idx:
            t = self.times[u]
            clone_x[u] = alpha[t] * x[u] + (1 - alpha[t]) * train_mean[t][self.labels[u]]
        return clone_x


class PNY(torch.nn.Module):
    def __init__(self, labels, times, num_time, num_label, split, relative_connectivity):
        super().__init__()
        self.labels = labels
        self.times = times
        self.num_time = num_time
        self.num_label = num_label
        self.split = split
        self.P=relative_connectivity
        self.train_idx = (self.times<self.split).nonzero().squeeze()
        self.test_idx = (self.times>=self.split).nonzero().squeeze()

    def forward(self, prev_x, x):
        clone_x=torch.clone(x)
        previous_cov_matrix=[torch.cov(prev_x[torch.squeeze((self.labels==y).nonzero())].T) for y in range(self.num_label)]

        # Calculate covariances
        current_cov_matrix=torch.zeros((self.num_label, self.num_time, x.shape[1], x.shape[1]))
        for y1 in range(self.num_label):
            for t1 in range(self.num_time):
                denom=0
                for y2 in range(self.num_label):
                    for t2 in range(self.num_time):
                        denom+=self.P[y1][t1][y2][t2]*(2 if abs(t2-t1)>min(self.num_time-1-t1,t1) else 1)
                denom=denom*denom
                for y2 in range(self.num_label):
                    temp=0
                    for t2 in range(self.num_time):
                        temp+=self.P[y1][t1][y2][t2]*(4 if abs(t2-t1)>min(self.num_time-1-t1,t1) else 1)
                    temp=temp/denom
                    current_cov_matrix[y1][t1]+=temp*previous_cov_matrix[y2]
        #print(f"cur cov matrix : {current_cov_matrix[0][0]}")
        #print(f"some Ps {self.P[0][0][0][0]} {self.P[0][4][1][3]} {self.P[1][4][3][2]}")

        # Calculate feature transform matrix
        cov_transform_matrix=torch.zeros((self.num_label, self.num_time, x.shape[1], x.shape[1]))
        for y1 in range(self.num_label):
            L_max, Q_max=torch.linalg.eigh(current_cov_matrix[y1][self.num_time - 1])

            L_max=L_max.real
            Q_max=Q_max.real
            L_max_sq=torch.sqrt(L_max)
            L_max_sq=torch.diag(L_max_sq)
            for t1 in range(self.split):
                L, Q=torch.linalg.eigh(current_cov_matrix[y1][t1])
                L=L.real
                Q=Q.real
                L_sq=torch.sqrt(L)
                Inv_L_sq=1/L_sq
                Inv_L_sq=torch.diag(Inv_L_sq)
                cov_transform_matrix[y1][t1]=Q_max@L_max_sq@Inv_L_sq@Q.T

        # Calculate feature means
        train_mean = torch.zeros((self.num_time, self.num_label, x.shape[1]), requires_grad=False)
        train_cnt = torch.zeros((self.num_time, self.num_label), requires_grad=False)
        for u in range(x.shape[0]):
            t=self.times[u]
            train_cnt[t][self.labels[u]] += 1
            train_mean[t][self.labels[u]] += x[u]                 
        for t in range(self.num_time):
            for l in range(self.num_label):
                train_mean[t][l]=train_mean[t][l]/max(1,train_cnt[t][l])

        # Update modified vals
        for u in self.train_idx:
            t = self.times[u]
            y = self.labels[u]
            clone_x[u] = cov_transform_matrix[y][t]@(x[u]-train_mean[t][y])+train_mean[t][y]
        return clone_x



class GraphConv_PNY(nn.Module):
    def __init__(
        self,
        labels, 
        times, 
        num_time, 
        num_label, 
        split, 
        relative_connectivity,
        in_feats,
        out_feats,
        norm="right",
        weight=True,
        bias=True,
        activation=None,
        allow_zero_in_degree=False,
    ):
        super().__init__()
        if norm not in ("none", "both", "right", "left"):
            raise DGLError(
                'Invalid norm value. Must be either "none", "both", "right" or "left".'
                ' But got "{}".'.format(norm)
            )
        self._in_feats = in_feats
        self._out_feats = out_feats
        self._norm = norm
        self._allow_zero_in_degree = allow_zero_in_degree
        self.PNY_Norm=PNY(labels, times, num_time, num_label, split, relative_connectivity)

        if weight:
            self.weight = nn.Parameter(th.Tensor(in_feats, out_feats))
        else:
            self.register_parameter("weight", None)

        if bias:
            self.bias = nn.Parameter(th.Tensor(out_feats))
        else:
            self.register_parameter("bias", None)

        self.reset_parameters()

        self._activation = activation

    def reset_parameters(self):
        if self.weight is not None:
            init.xavier_uniform_(self.weight)
        if self.bias is not None:
            init.zeros_(self.bias)


    def set_allow_zero_in_degree(self, set_value):
        self._allow_zero_in_degree = set_value

    def forward(self, graph, feat, weight=None, edge_weight=None):
        with graph.local_scope():
            if not self._allow_zero_in_degree:
                if (graph.in_degrees() == 0).any():
                    raise DGLError(
                        "There are 0-in-degree nodes in the graph, "
                        "output for those nodes will be invalid. "
                        "This is harmful for some applications, "
                        "causing silent performance regression. "
                        "Adding self-loop on the input graph by "
                        "calling `g = dgl.add_self_loop(g)` will resolve "
                        "the issue. Setting ``allow_zero_in_degree`` "
                        "to be `True` when constructing this module will "
                        "suppress the check and let the code run."
                    )
            aggregate_fn = fn.copy_u("h", "m")
            if edge_weight is not None:
                assert edge_weight.shape[0] == graph.num_edges()
                graph.edata["_edge_weight"] = edge_weight
                aggregate_fn = fn.u_mul_e("h", "_edge_weight", "m")

            # (BarclayII) For RGCN on heterogeneous graphs we need to support GCN on bipartite.
            feat_src, feat_dst = expand_as_pair(feat, graph)
            if self._norm in ["left", "both"]:
                degs = graph.out_degrees().to(feat_src).clamp(min=1)
                if self._norm == "both":
                    norm = th.pow(degs, -0.5)
                else:
                    norm = 1.0 / degs
                shp = norm.shape + (1,) * (feat_src.dim() - 1)
                norm = th.reshape(norm, shp)
                feat_src = feat_src * norm

            if weight is not None:
                if self.weight is not None:
                    raise DGLError(
                        "External weight is provided while at the same time the"
                        " module has defined its own weight parameter. Please"
                        " create the module with flag weight=False."
                    )
            else:
                weight = self.weight

            prev_x=torch.clone(feat_src)
            graph.srcdata["h"] = feat_src
            graph.update_all(aggregate_fn, fn.sum(msg="m", out="h"))
            rst = graph.dstdata["h"]

            if self._norm in ["right", "both"]:
                degs = graph.in_degrees().to(feat_dst).clamp(min=1)
                if self._norm == "both":
                    norm = th.pow(degs, -0.5)
                else:
                    norm = 1.0 / degs
                shp = norm.shape + (1,) * (feat_dst.dim() - 1)
                norm = th.reshape(norm, shp)
                rst = rst * norm
            rst = self.PNY_Norm(prev_x,rst)

            if weight is not None:
                rst = th.matmul(rst, weight)
            
            if self.bias is not None:
                rst = rst + self.bias

            if self._activation is not None:
                rst = self._activation(rst)

            return rst


    def extra_repr(self):
        """Set the extra representation of the module,
        which will come into effect when printing the model.
        """
        summary = "in={_in_feats}, out={_out_feats}"
        summary += ", normalization={_norm}"
        if "_activation" in self.__dict__:
            summary += ", activation={_activation}"
        return summary.format(**self.__dict__)



class GCN(nn.Module):
    def __init__(self, in_size, hid_size, out_size):
        super().__init__()
        self.layers = nn.ModuleList()
        # two-layer GCN
        self.layers.append(
            dglnn.GraphConv(in_size, hid_size, activation=F.relu, norm="right")
        )
        self.layers.append(dglnn.GraphConv(hid_size, out_size, norm="right")) # Self connection?
        self.dropout = nn.Dropout(0.5)

    def forward(self, g, features):
        h = features
        for i, layer in enumerate(self.layers):
            if i != 0:
                h = self.dropout(h)
            h = layer(g, h)
        return h



class GCN_JJ(nn.Module):
    def __init__(self, labels, times, num_time, num_label, split, in_size, hid_size, out_size):
        super().__init__()
        self.layers = nn.ModuleList()
        self.layers.append(
            dglnn.GraphConv(in_size, hid_size, activation=F.relu, norm="right")
        )
        self.layers.append(dglnn.GraphConv(hid_size, out_size, norm="right")) # Self connection?
        self.dropout = nn.Dropout(0.5)
        self.JJ_Norm=JJ_Norm(labels, times, num_time, num_label, split)


    def forward(self, g, features):
        h = features
        for i, layer in enumerate(self.layers):
            if i != 0:
                h = self.dropout(h)
            h = layer(g, h)
            h = self.JJ_Norm(h)
        return h


class GCN_PNY(nn.Module):
    def __init__(self, labels, times, num_time, num_label, split, relative_connectivity, in_size, hid_size, out_size):
        super().__init__()
        self.layers = nn.ModuleList()
        self.layers.append(
            GraphConv_PNY(labels, times, num_time, num_label, split, relative_connectivity, in_size, hid_size, activation=F.relu, norm="left")
        )
        self.layers.append(GraphConv_PNY(labels, times, num_time, num_label, split, relative_connectivity, hid_size, out_size, norm="left")) # Self connection?
        self.dropout = nn.Dropout(0.5)

    def forward(self, g, features):
        h = features
        for i, layer in enumerate(self.layers):
            if i != 0:
                h = self.dropout(h)
            h = layer(g, h)
        return h

