import argparse

import dgl
import dgl.nn as dglnn
from dgl.data.utils import load_graphs

import torch
import torch.nn as nn
import torch.nn.functional as F
from dgl import AddSelfLoop
import os
import numpy as np
import random
import os
import time
import torch.nn.functional as F
from tqdm import tqdm 
from multiprocessing import Pool
import multiprocessing
from itertools import repeat

chunk_size=100
sym_chunk_size=1000
core_num=multiprocessing.cpu_count()
len_newsrc=0
t0=time.time()



def task(idx):
    src=[]
    dst=[]
    for i in range(idx,min(idx+chunk_size,args.num_node)):
        for j in range(args.num_node):
            delta=abs(times[i]-times[j])
            yi=label[i]
            yj=label[j]
            if (i!=j and random.uniform(0, 1)<(gamma if yi==yj else alpha+beta*delta/args.num_time)):
                src.append(i)
                dst.append(j)
    return np.array([src, dst])


def sym_task(idx):
    addsrc=[]
    adddst=[]
    for i in range(idx,min(idx+sym_chunk_size,len_newsrc)):
        if abs(times[newsrc[i]]-times[newdst[i]])>min(args.num_time-1-times[newdst[i]],times[newdst[i]]-0):
            addsrc.append(newsrc[i])
            adddst.append(newdst[i])
    return np.array([addsrc, adddst])


class GCN(nn.Module):
    def __init__(self, in_size, hid_size, out_size):
        super().__init__()
        self.layers = nn.ModuleList()
        # two-layer GCN
        self.layers.append(
            dglnn.GraphConv(in_size, hid_size, activation=F.relu)
        )
        self.layers.append(dglnn.GraphConv(hid_size, out_size)) # Self connection?
        self.dropout = nn.Dropout(0.5)

    def forward(self, g, features):
        h = features
        for i, layer in enumerate(self.layers):
            if i != 0:
                h = self.dropout(h)
            h = layer(g, h)
        return h


class JJ_Norm(torch.nn.Module):
    def __init__(self, labels, times, num_time, num_label, split):
        super().__init__()
        self.labels = labels
        self.times = times
        self.num_time = num_time
        self.num_label = num_label
        self.split = split

    def forward(self, x):
        clone_x=torch.clone(x)
        train_mean = torch.zeros((self.num_time, self.num_label, clone_x.shape[1]), requires_grad=False)
        train_cnt = torch.zeros((self.num_time, self.num_label), requires_grad=False)
        train_time_mean = torch.zeros((self.num_time, clone_x.shape[1]), requires_grad=False)
        train_time_cnt = torch.zeros(self.num_time, requires_grad=False)
        test_cnt = torch.zeros(1, requires_grad=False)
        test_mean = torch.zeros((clone_x.shape[1]), requires_grad=False)
        for u in range(clone_x.shape[0]):
            t=self.times[u]
            if(t>=self.split):
                test_cnt[0] += 1
                test_mean+=clone_x[u]
            else:
                train_time_cnt[t] += 1
                train_cnt[t][self.labels[u]] += 1
                train_mean[t][self.labels[u]] += clone_x[u]                 
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
        for u in range(clone_x.shape[0]):
            if(self.times[u]>=self.split):
                test_var[0] += torch.norm(clone_x[u] - test_mean) ** 2
            else:
                t = self.times[u]
                msq[t] += torch.norm(train_mean[t][self.labels[u]] - train_time_mean[t]) ** 2
                rsq[t] += torch.norm(clone_x[u] - train_mean[t][self.labels[u]]) ** 2


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
        for u in range(clone_x.shape[0]):
            if(self.times[u]<self.split):
                clone_x[u] = alpha[t] * x[u] + (1 - alpha[t]) * train_mean[t][self.labels[u]]
        return clone_x


class GCN2(nn.Module):
    def __init__(self, in_size, hid_size, out_size, labels, times):
        super().__init__()
        self.layers = nn.ModuleList()
        self.layers.append(
            dglnn.GraphConv(in_size, hid_size, activation=F.relu)
        )
        self.layers.append(dglnn.GraphConv(hid_size, out_size)) # Self connection?
        self.dropout = nn.Dropout(0.5)
        self.JJ_Norm=JJ_Norm(labels, times, args.num_time, args.num_label, args.split)


    def forward(self, g, features):
        h = features
        for i, layer in enumerate(self.layers):
            if i != 0:
                h = self.dropout(h)
            h = layer(g, h)
            h = self.JJ_Norm(h)
        return h


def evaluate(g, features, labels, mask, model):
    model.eval()
    with torch.no_grad():
        logits = model(g, features)
        logits = logits[mask]
        labels = labels[mask]
        _, indices = torch.max(logits, dim=1)
        correct = torch.sum(indices == labels)
        return correct.item() * 1.0 / len(labels)


def train(g, features, labels, masks, model):
    # define train/val samples, loss function and optimizer
    train_mask = masks[0]
    loss_fcn = nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=1e-2, weight_decay=5e-4)
    for epoch in range(args.epoch):
        model.train()
        logits = model(g, features)
        loss = loss_fcn(logits[train_mask], labels[train_mask])
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        
def train2(g, features, labels, masks, model):
    # define train/val samples, loss function and optimizer
    train_mask = masks[0]
    loss_fcn = nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=1e-2, weight_decay=5e-4)
    for epoch in tqdm(range(args.epoch)):
        model.train()
        logits = model(g, features)
        loss = loss_fcn(logits[train_mask], labels[train_mask])
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        

def train_0(g, f_log, alpha, beta):
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    g = g.to(device)
    features = g.ndata["feat"]
    labels = g.ndata["label"]
    masks = g.ndata["train_mask"].type(torch.bool), g.ndata["val_mask"].type(torch.bool), g.ndata["test_mask"].type(torch.bool)
    model = GCN(features.shape[1], 16, 10).to(device)
    if args.dt == "bfloat16":
        g = dgl.to_bfloat16(g)
        features = features.to(dtype=torch.bfloat16)
        model = model.to(dtype=torch.bfloat16)
    train(g, features, labels, masks, model)
    acc = evaluate(g, features, labels, masks[2], model)
    print(f"Model0 with a:{alpha:.4f}, b:{beta:.4f} | Test accuracy {acc:.4f}")
    # f_log.write("{:.4f}, ".format(acc))
    # f_log.flush()


def train_1(g, f_log, alpha, beta):
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    g = g.to(device)
    features = g.ndata["feat"]
    labels = g.ndata["label"]
    masks = g.ndata["train_mask"].type(torch.bool), g.ndata["val_mask"].type(torch.bool), g.ndata["test_mask"].type(torch.bool)
    model = GCN(features.shape[1], 16, 10).to(device) # Same model, but use symmetric data
    if args.dt == "bfloat16":
        g = dgl.to_bfloat16(g)
        features = features.to(dtype=torch.bfloat16)
        model = model.to(dtype=torch.bfloat16)
    train(g, features, labels, masks, model)
    acc = evaluate(g, features, labels, masks[2], model)
    print(f"Model1 with a:{alpha:.4f}, b:{beta:.4f} | Test accuracy {acc:.4f}")
    # f_log.write("{:.4f}, ".format(acc))
    # f_log.flush()


def train_2(g, f_log, alpha, beta, times):
    print(f"torch.cuda.is_available() : {torch.cuda.is_available()}")
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    g = g.to(device)
    features = g.ndata["feat"]
    labels = g.ndata["label"]
    masks = g.ndata["train_mask"].type(torch.bool), g.ndata["val_mask"].type(torch.bool), g.ndata["test_mask"].type(torch.bool)
    model = GCN2(features.shape[1], 16, 10, labels, times).to(device)
    if args.dt == "bfloat16":
        g = dgl.to_bfloat16(g)
        features = features.to(dtype=torch.bfloat16)
        model = model.to(dtype=torch.bfloat16)
    train2(g, features, labels, masks, model)
    acc = evaluate(g, features, labels, masks[2], model)
    print(f"Model2 with a:{alpha:.4f}, b:{beta:.4f} | Test accuracy {acc:.4f}")
    # f_log.write("{:.4f}, ".format(acc))
    # f_log.flush()



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--root",type=str, default='./data/')
    parser.add_argument("--feat_dim", type=int, default=5)
    parser.add_argument("--num_label", type=int, default=10)
    parser.add_argument("--num_node", type=int, default=1000)
    parser.add_argument("--num_time", type=int, default=10)
    parser.add_argument("--dt", type=str, default="float",help="data type(float, bfloat16)")
    parser.add_argument("--epoch", type=int, default=200)
    parser.add_argument("--gamma", type=float, default=0.4)
    parser.add_argument("--max_beta", type=float, default=0.2)
    parser.add_argument("--feat_std", type=float, default=4)
    parser.add_argument("--repeat", type=int, default=50)
    parser.add_argument("--split", type=int, default=8) # if t>=split, than node belongs to test set.

    torch.autograd.set_detect_anomaly(True)
    
    args = parser.parse_args()
    f_log0=open('./txtlog/'+'b'+str(args.max_beta)+'_'+'g'+str(args.gamma)+'_'+'s'+str(args.feat_std)+'_Invar0.txt','a') # Normal method
    f_log1=open('./txtlog/'+'b'+str(args.max_beta)+'_'+'g'+str(args.gamma)+'_'+'s'+str(args.feat_std)+'_Invar1.txt','a') # 1st order stats alignment
    f_log2=open('./txtlog/'+'b'+str(args.max_beta)+'_'+'g'+str(args.gamma)+'_'+'s'+str(args.feat_std)+'_Invar2.txt','a') # 2nd order stats alignment
    

    for i in range(args.repeat):
        for num in range(9):
            label_rands=torch.randperm(args.num_node)
            time_rands=torch.randperm(args.num_node)

            label=[0]*args.num_node
            times=[0]*args.num_node
            train_mask=[0]*args.num_node
            valid_mask=[0]*args.num_node
            test_mask=[0]*args.num_node

            for i in range(args.num_node):
                label[i]=label_rands[i]%args.num_label
                times[i]=time_rands[i]%args.num_time

            for i in range(args.num_node):
                train_mask[i]=(times[i]<args.split)
                valid_mask[i]=(times[i]>=args.split and times[i]<args.split)
                test_mask[i]=(times[i]>=args.split)
                
            label=torch.Tensor(label).type(torch.long)
            times=torch.Tensor(times).type(torch.long)
            train_mask=torch.Tensor(train_mask).type(torch.bool)
            valid_mask=torch.Tensor(valid_mask).type(torch.bool)
            test_mask=torch.Tensor(test_mask).type(torch.bool)

            alpha=args.max_beta*2/3*(8-num)/8
            beta=args.max_beta*num/8
            gamma=args.gamma
            with Pool(core_num) as p:
                result = p.map(task, range(0,args.num_node,chunk_size))
            src_dst = np.concatenate(result, axis=1)
            src, dst = src_dst
            
            newsrc=np.concatenate((src,dst))
            newdst=np.concatenate((dst,src))

            with Pool(core_num) as p:
                result = p.map(sym_task, range(0,len(newsrc),sym_chunk_size))
            src_dst = np.concatenate(result, axis=1)
            addsrc, adddst = src_dst
            symsrc=np.concatenate((newsrc,addsrc))
            symdst=np.concatenate((newdst,adddst))

            new_edges={}
            sym_edges={}
            num_nodes={}
            new_edges[('node','-','node')]=(newsrc,newdst)
            sym_edges[('node','-','node')]=(symsrc,symdst)
            num_nodes['node']=args.num_node
            new_g = dgl.heterograph(new_edges,num_nodes_dict=num_nodes)
            sym_g = dgl.heterograph(sym_edges,num_nodes_dict=num_nodes)

            feat_center=torch.zeros([args.num_label,args.feat_dim])
            for i in range(args.num_label):
                feat_center[i]=torch.randn(args.feat_dim)

            feature=torch.zeros([args.num_node,args.feat_dim])
            for i in range(args.num_node):
                cur_label = label[i]
                feature[i] = torch.randn(args.feat_dim)*args.feat_std+feat_center[cur_label]
                
            new_g.nodes['node'].data["label"]=label
            new_g.nodes['node'].data["feat"]=feature
            new_g.nodes['node'].data["train_mask"]=train_mask
            new_g.nodes['node'].data["val_mask"]=valid_mask
            new_g.nodes['node'].data["test_mask"]=test_mask
            sym_g.nodes['node'].data["label"]=label
            sym_g.nodes['node'].data["feat"]=feature
            sym_g.nodes['node'].data["train_mask"]=train_mask
            sym_g.nodes['node'].data["val_mask"]=valid_mask
            sym_g.nodes['node'].data["test_mask"]=test_mask

            train_2(sym_g, f_log2, alpha, beta, times)
            train_0(new_g, f_log0, alpha, beta)
            train_1(sym_g, f_log1, alpha, beta)

        # f_log0.write("\n")
        # f_log0.flush()
        # f_log1.write("\n")
        # f_log1.flush()
        # f_log2.write("\n")
        # f_log2.flush()


    

'''
python TSBM_PMP.py --gamma 0.05 --max_beta 0.02 
python TSBM_PMP.py --gamma 0.12 --max_beta 0.06 
python TSBM_PMP.py --gamma 0.12 --max_beta 0.08
python TSBM_PMP.py --gamma 0.16 --max_beta 0.06 
python TSBM_PMP.py --gamma 0.16 --max_beta 0.10
python TSBM_PMP.py --gamma 0.32 --max_beta 0.12
python TSBM_PMP.py --gamma 0.32 --max_beta 0.16
python TSBM_PMP.py --gamma 0.4 --max_beta 0.2 
'''
