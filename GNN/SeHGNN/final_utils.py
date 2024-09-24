import os
import sys
import gc
import random

import dgl
import dgl.function as fn

import torch
import torch.nn as nn
import torch.nn.functional as F
from torch_sparse import SparseTensor
from torch_sparse import remove_diag, set_diag
import copy 

import numpy as np
import scipy.sparse as sp
from sklearn.metrics import f1_score
from tqdm import tqdm
from ogb.nodeproppred import DglNodePropPredDataset, Evaluator

import functools
from contextlib import closing
import multiprocessing as mp
from multiprocessing import Pool
from tqdm import tqdm
import argparse
import sys
#sys.path.insert(0,'/users/PAS1289/oiocha/Adaptive_Sampling/SeHGNN/sparse_tools')
print(sys.path)
import sparse_tools
import time

def set_random_seed(seed=0):
    random.seed(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    if torch.cuda.is_available():
        torch.cuda.manual_seed(seed)


def get_n_params(model):
    pp = 0
    for p in list(model.parameters()):
        nn = 1
        for s in list(p.size()):
            nn = nn*s
        pp += nn
    return pp


def reduce_year(year_name):
    # reduce P2018AP2018P2018 -> PAPP
    res=''
    for s in year_name:
        if('0'<=s and s<='9'): continue
        res=res+s
    return res

def hg_sym_propagate(new_g, tgt_type, num_hops, max_hops, extra_metapath, mode, f_log, debug=False, echo=True):
    for hop in range(1, max_hops):
        reserve_heads = [ele[:hop] for ele in extra_metapath if len(ele) > hop] # 
        # f_log.write(f"DEBUG_hg1 | hop : {hop} | reserve_heads : {reserve_heads}\n")
        # f_log.flush()
        for etype in new_g.etypes:
            # f_log.write(f"DEBUG_hg2 | etype : {etype}\n")
            # f_log.flush()
            stype, direction, dtype = new_g.to_canonical_etype(etype)
            if len(stype)==1 or len(dtype)==1: continue # 
            # f_log.write(f"DEBUG_hg2.2 | stype : {stype} | dtype : {dtype} | type(new_g.nodes[stype]) : {type(new_g.nodes[stype])}\n")

            for k in list(new_g.nodes[stype].data.keys()): 
                if len(reduce_year(k)) == hop: #
                    current_dst_name = f'{dtype}{k}' # {dtype}{stype}
                    # f_log.write(f"DEBUG_hg3.2 | k : {k} | current_dst_name : {current_dst_name}\n")
                    # f_log.flush()
                    if (hop == num_hops and dtype[0] != tgt_type and k not in reserve_heads) \
                      or (hop > num_hops and k not in reserve_heads):
                        continue
                    if echo: print(k, etype, current_dst_name)
                    # f_log.write(f"type(new_g) : {type(new_g)}\n")
                    # f_log.write(f"DEBUG_hg4 | actual update k : {k} | etype : {etype} | current_dst_name : {current_dst_name} | type(new_g[etype]) : {type(new_g[etype])}\n")
                    # f_log.flush()
                    
                    new_g[etype].update_all(
                        fn.copy_u(k, 'm'),
                        fn.mean('m', current_dst_name), etype=etype)
                    
                    # Updated feature : (maybe) new_g.nodes[stype].data[current_dst_name]
                    # So build new graph with deleted edge, and manually update it!

        # remove no-use items
        for ntype in new_g.ntypes:
            if ntype[0] == tgt_type: continue 
            removes = []
            for k in new_g.nodes[ntype].data.keys():
                # f_log.write(f"DEBUG_hg5 | reduce_year(k) : {reduce_year(k)} | remove_append : {len(reduce_year(k)) <= hop}\n")
                if len(reduce_year(k)) <= hop:
                    removes.append(k)
            for k in removes:
                new_g.nodes[ntype].data.pop(k)
            if echo and len(removes): print('remove', removes)
        # f_log.write("\n")
        gc.collect()
    
        if echo: print(f'-- hop={hop} ---')
        for ntype in new_g.ntypes:
            for k, v in new_g.nodes[ntype].data.items():
                if echo: print(f'{ntype} {k} {v.shape}')
        if echo: print(f'------\n')

            
    # print(f"Synthesize year feature")
    # f_log.write(f"Synthesize year feature\n")
    # f_log.flush()
    # P2010 ~ P2019 is node itself, not data keys. 
    # there is a node named 'P', it sholud only contains a key 'Y'. 
    # Data keys are something like P2018AP2018P2018 # Something propagated!!

    paper_year=new_g.nodes['P'].data['Y'] #
    # for k in new_g.nodes['P'].data.keys():
    #     print(f"Feature for key 'P' : {k}")
    #     f_log.write(f"Feature for key 'P' : {k}\n")
    #     f_log.flush()

    pfeats={} #
    for k,v in new_g.nodes['P2019'].data.items():
        # print(f"type(v) : {type(v)}")
        # f_log.write(f"type(v) : {type(v)}\n")
        pfeats[reduce_year(k)]=torch.clone(v) #

    for ntype in new_g.ntypes:
        if ntype[0]!='P' or len(ntype)==1: continue
        # ntype is something like P2018
        yy=int(ntype[1:]) # Something like 2018
        # print(f"Papers with year : P{yy}")
        # f_log.write(f"Papers with year : P{yy}\n")
        # f_log.flush()

        for k in new_g.nodes[ntype].data.keys():
            # k in something like 
            reduce_key=reduce_year(k)
            # print(f"Papers' key and reduced key : {k}, {reduce_key}")
            # f_log.write(f"Papers' key and reduced key : {k}, {reduce_key}\n")
            # f_log.flush()
        
            year_idx=np.squeeze(np.argwhere(paper_year==yy)) # 
            pfeats[reduce_key][year_idx]=new_g.nodes[ntype].data[k][year_idx]
            '''
            for i in range(len(paper_year)):
                assert (paper_year[i]>=2010 and paper_year[i]<2020)
                if yy==paper_year[i]:
                    pfeats[reduce_key][i]=new_g.nodes[ntype].data[k][i]
            '''
            
    for ntype in new_g.ntypes:
        if ntype[0]!='P': continue 
        removes=[]
        for k in new_g.nodes[ntype].data.keys():
            # print(f"Delete | ntype : {ntype} | key : {k}")
            # f_log.write(f"Delete | ntype : {ntype} | key : {k}\n")
            # f_log.flush()
            removes.append(k)
        for k in removes:
            new_g.nodes[ntype].data.pop(k)
    
    for k,v in pfeats.items():
        new_g.nodes['P'].data[k]=v
    gc.collect()

    return new_g


def hg_propagate(new_g, tgt_type, num_hops, max_hops, extra_metapath, mode, f_log, echo=True):
    f_log.write(f"DEBUG_hg0 | new_g : {new_g}\n")
    f_log.write(f"DEBUG_hg0 | tgt_type : {tgt_type}\n")
    f_log.write(f"DEBUG_hg0 | num_hops : {num_hops}\n")
    f_log.write(f"DEBUG_hg0 | max_hops : {max_hops}\n")
    f_log.write(f"DEBUG_hg0 | extra_metapath : {extra_metapath}\n")
    f_log.flush()

    for hop in range(1, max_hops):
        reserve_heads = [ele[:hop] for ele in extra_metapath if len(ele) > hop]
        #print(f"DEBUG_hg1 | hop : {hop} | reserve_heads : {reserve_heads}")
        # f_log.write(f"DEBUG_hg1 | hop : {hop} | reserve_heads : {reserve_heads}\n")
        # f_log.flush()
        for etype in new_g.etypes:
            #print(f"DEBUG_hg2 | etype : {etype}")
            # f_log.write(f"DEBUG_hg2 | etype : {etype}\n")
            # # A-I A-P F-P I-A P-A P-F P-P # P>P
            # f_log.flush()
            stype, direction, dtype = new_g.to_canonical_etype(etype)
            if len(stype)>1 or len(stype)>1: continue

            # A-I -> A I
            #print(f"DEBUG_hg2.2 | stype : {stype} | dtype : {dtype} | type(new_g.nodes[stype]) : {type(new_g.nodes[stype])}")
            # f_log.write(f"DEBUG_hg2.2 | stype : {stype} | dtype : {dtype} | type(new_g.nodes[stype]) : {type(new_g.nodes[stype])}\n")

            for k in list(new_g.nodes[stype].data.keys()):
                if len(k) == hop:
                    current_dst_name = f'{dtype}{k}'
                    #print(f"DEBUG_hg3.2 | k : {k} | current_dst_name : {current_dst_name}")
                    # f_log.write(f"DEBUG_hg3.2 | k : {k} | current_dst_name : {current_dst_name}\n")
                    # f_log.flush()
                    if (hop == num_hops and dtype != tgt_type and k not in reserve_heads) \
                      or (hop > num_hops and k not in reserve_heads):
                        continue
                    if echo: print(k, etype, current_dst_name)
                    # f_log.write(f"type(new_g) : {type(new_g)}\n")
                    # f_log.write(f"DEBUG_hg4 | actual update k : {k} | etype : {etype} | current_dst_name : {current_dst_name} | type(new_g[etype]) : {type(new_g[etype])}\n")
                    
                    # f_log.write(f"toggle debug | etype : {etype} | hop : {hop} | num_hops : {num_hops} | dtype : {dtype} | direction : {direction} | stype : {stype}\n")
                    # f_log.flush()

                    if(((mode=='toggle' and hop == num_hops) or mode=='mono') and dtype==tgt_type and stype==tgt_type and direction[1]=='-'):
                        continue

                    if(mode=='toggle' and hop!=num_hops and dtype==tgt_type and stype==tgt_type and direction[1]=='>'):
                        continue
                    
                    if(mode=='full' and direction[1]=='>'):
                        continue
                    
                    new_g[etype].update_all(
                        fn.copy_u(k, 'm'),
                        fn.mean('m', current_dst_name), etype=etype)
                    
                    # Updated feature : (maybe) new_g.nodes[stype].data[current_dst_name]
                    # So build new graph with deleted edge, and manually update it!

        # remove no-use items
        for ntype in new_g.ntypes:
            if ntype == tgt_type: continue
            removes = []
            for k in new_g.nodes[ntype].data.keys():
                # f_log.write(f"DEBUG_hg5 | k : {k} | remove_append : {len(k) <= hop}\n")
                # f_log.flush()
                if len(k) <= hop:
                    removes.append(k)
            for k in removes:
                new_g.nodes[ntype].data.pop(k)
            if echo and len(removes): print('remove', removes)
        gc.collect()
        
        if echo: print(f'-- hop={hop} ---')
        for ntype in new_g.ntypes:
            for k, v in new_g.nodes[ntype].data.items():
                if echo: print(f'{ntype} {k} {v.shape}')
        if echo: print(f'------\n')

    return new_g


def clear_hg(new_g, echo=False):
    if echo: print('Remove keys left after propagation')
    for ntype in new_g.ntypes:
        keys = list(new_g.nodes[ntype].data.keys())
        if len(keys):
            if echo: print("clear_hg", ntype, keys)
            for k in keys:
                new_g.nodes[ntype].data.pop(k)
    return new_g


def check_acc(preds_dict, condition, init_labels, train_nid, val_nid, test_nid):
    mask_train, mask_val, mask_test = [], [], []
    remove_label_keys = []
    na, nb, nc = len(train_nid), len(val_nid), len(test_nid)

    for k, v in preds_dict.items():
        pred = v.argmax(1)

        a, b, c = pred[train_nid] == init_labels[train_nid], \
                  pred[val_nid] == init_labels[val_nid], \
                  pred[test_nid] == init_labels[test_nid]
        ra, rb, rc = a.sum() / len(train_nid), b.sum() / len(val_nid), c.sum() / len(test_nid)

        vv = torch.log((v / (v.sum(1, keepdim=True) + 1e-6)).clamp(1e-6, 1-1e-6))
        la, lb, lc = F.nll_loss(vv[train_nid], init_labels[train_nid]), \
                     F.nll_loss(vv[val_nid], init_labels[val_nid]), \
                     F.nll_loss(vv[test_nid], init_labels[test_nid])

        if condition(ra, rb, rc, k):
            mask_train.append(a)
            mask_val.append(b)
            mask_test.append(c)
        else:
            remove_label_keys.append(k)
        print(k, ra, rb, rc, la, lb, lc, (ra/rb-1)*100, (ra/rc-1)*100, (1-la/lb)*100, (1-la/lc)*100)

    print(set(list(preds_dict.keys())) - set(remove_label_keys))
    print((torch.stack(mask_train, dim=0).sum(0) > 0).sum() / len(train_nid))
    print((torch.stack(mask_val, dim=0).sum(0) > 0).sum() / len(val_nid))
    print((torch.stack(mask_test, dim=0).sum(0) > 0).sum() / len(test_nid))
    return remove_label_keys


def train(model, train_loader, loss_fcn, optimizer, evaluator, device,
          feats, label_feats, labels_cuda, label_emb, paper_year=None, mask=None, scalar=None):
    model.train()
    total_loss = 0
    iter_num = 0
    y_true, y_pred = [], []

    for batch in train_loader:
        batch_feats = {k: x[batch].to(device) for k, x in feats.items()}
        batch_labels_feats = {k: x[batch].to(device) for k, x in label_feats.items()}
        # if mask is not None:
        #     batch_mask = {k: x[batch].to(device) for k, x in mask.items()}
        # else:
        #     batch_mask = None
        batch_label_emb = label_emb[batch].to(device)
        batch_y = labels_cuda[batch]

        optimizer.zero_grad()
        if scalar is not None:
            with torch.cuda.amp.autocast():
                output_att = model(batch_feats, batch_labels_feats, batch_label_emb)
                if isinstance(loss_fcn, nn.BCELoss):
                    output_att = torch.sigmoid(output_att)
                loss_train = loss_fcn(output_att, batch_y)
            scalar.scale(loss_train).backward()
            scalar.step(optimizer)
            scalar.update()
        else:
            output_att = model(batch_feats, batch_labels_feats, batch_label_emb)
            if isinstance(loss_fcn, nn.BCELoss):
                output_att = torch.sigmoid(output_att)
            L1 = loss_fcn(output_att, batch_y)
            loss_train = L1
            loss_train.backward()
            optimizer.step()

        y_true.append(batch_y.cpu().to(torch.long))
        if isinstance(loss_fcn, nn.BCELoss):
            y_pred.append((output_att.data.cpu() > 0).int())
        else:
            y_pred.append(output_att.argmax(dim=-1, keepdim=True).cpu())
        total_loss += loss_train.item()
        iter_num += 1
    loss = total_loss / iter_num
    acc = evaluator(torch.cat(y_true, dim=0), torch.cat(y_pred, dim=0))
    return loss, acc


def train_multi_stage(model, train_loader, enhance_loader, loss_fcn, optimizer, evaluator, device,
                      feats, label_feats, labels, label_emb, predict_prob, gama, paper_year=None, scalar=None):
    model.train()
    loss_fcn = nn.CrossEntropyLoss()
    y_true, y_pred = [], []
    total_loss = 0
    loss_l1, loss_l2 = 0., 0.
    iter_num = 0
    for idx_1, idx_2 in zip(train_loader, enhance_loader):
        idx = torch.cat((idx_1, idx_2), dim=0)
        L1_ratio = len(idx_1) * 1.0 / (len(idx_1) + len(idx_2))
        L2_ratio = len(idx_2) * 1.0 / (len(idx_1) + len(idx_2))

        batch_feats = {k: x[idx].to(device) for k, x in feats.items()}
        batch_labels_feats = {k: x[idx].to(device) for k, x in label_feats.items()}
        batch_label_emb = label_emb[idx].to(device)
        y = labels[idx_1].to(torch.long).to(device)
        extra_weight, extra_y = predict_prob[idx_2].max(dim=1)
        extra_weight = extra_weight.to(device)
        extra_y = extra_y.to(device)

        optimizer.zero_grad()
        if scalar is not None:
            with torch.cuda.amp.autocast():
                output_att = model(batch_feats, batch_labels_feats, batch_label_emb)
                L1 = loss_fcn(output_att[:len(idx_1)],  y)
                L2 = F.cross_entropy(output_att[len(idx_1):], extra_y, reduction='none')
                L2 = (L2 * extra_weight).sum() / len(idx_2)
                loss_train = L1_ratio * L1 + gama * L2_ratio * L2
            scalar.scale(loss_train).backward()
            scalar.step(optimizer)
            scalar.update()
        else:
            output_att = model(batch_feats, label_emb[idx].to(device))
            L1 = loss_fcn(output_att[:len(idx_1)],  y)
            L2 = F.cross_entropy(output_att[len(idx_1):], extra_y, reduction='none')
            L2 = (L2 * extra_weight).sum() / len(idx_2)
            # teacher_soft = predict_prob[idx_2].to(device)
            # teacher_prob = torch.max(teacher_soft, dim=1, keepdim=True)[0]
            # L3 = (teacher_prob*(teacher_soft*(torch.log(teacher_soft+1e-8)-torch.log_softmax(output_att[len(idx_1):], dim=1)))).sum(1).mean()*(len(idx_2)*1.0/(len(idx_1)+len(idx_2)))
            # loss = L1 + L3*gama
            loss_train = L1_ratio * L1 + gama * L2_ratio * L2
            loss_train.backward()
            optimizer.step()

        y_true.append(labels[idx_1].to(torch.long))
        y_pred.append(output_att[:len(idx_1)].argmax(dim=-1, keepdim=True).cpu())
        total_loss += loss_train.item()
        loss_l1 += L1.item()
        loss_l2 += L2.item()
        iter_num += 1

    print(loss_l1 / iter_num, loss_l2 / iter_num)
    loss = total_loss / iter_num
    approx_acc = evaluator(torch.cat(y_true, dim=0),torch.cat(y_pred, dim=0))
    return loss, approx_acc


@torch.no_grad()
def gen_output_torch(model, feats, label_feats, label_emb, test_loader, device):
    model.eval()
    preds = []
    for batch in tqdm(test_loader):
        batch_feats = {k: x[batch].to(device) for k, x in feats.items()}
        batch_labels_feats = {k: x[batch].to(device) for k, x in label_feats.items()}
        batch_label_emb = label_emb[batch].to(device)
        preds.append(model(batch_feats, batch_labels_feats, batch_label_emb).cpu())
    preds = torch.cat(preds, dim=0)
    return preds


def get_ogb_evaluator(dataset):
    evaluator = Evaluator(name=dataset)
    return lambda preds, labels: evaluator.eval({
            "y_true": labels.view(-1, 1),
            "y_pred": preds.view(-1, 1),
        })["acc"]


def load_dataset(args,f_log=None,time_bit=0):
    if args.dataset == 'ogbn-products':
        # num_nodes=2449029, num_edges=123718280, num_feats=100, num_classes=47
        # train/val/test 196615/39323/2213091
        return load_homo(args)
    elif args.dataset == 'ogbn-proteins':
        # num_nodes=132534, num_edges=79122504, num_feats=8, 112 binary classification tasks, num_classes=2
        # train/val/test 86619/21236/24679
        return load_homo(args)
    elif args.dataset == 'ogbn-arxiv':
        # num_nodes=169343, num_edges=1166243, num_feats=128, num_classes=40
        # train/val/test 90941/29799/48603
        return load_homo(args)
    elif args.dataset == 'ogbn-papers100M':
        # num_nodes=111059956, num_edges=1615685872, num_feats=128, num_classes=172
        # train/val/test/extra 1207179/125265/214338/98.61%
        return load_homo(args)
    elif args.dataset == 'ogbn-mag':
        # train/val/test 629571/64879/41939
        return load_mag(args,f_log,time_bit)
    else:
        assert 0, 'Only allowed [ogbn-products, ogbn-proteins, ogbn-arxiv, ogbn-papers100M, ogbn-mag]'


def load_homo(args):
    dataset = DglNodePropPredDataset(name=args.dataset, root=args.root)
    splitted_idx = dataset.get_idx_split()

    g, init_labels = dataset[0]
    splitted_idx = dataset.get_idx_split()
    train_nid = splitted_idx['train']
    val_nid = splitted_idx['valid']
    test_nid = splitted_idx['test']

    # features = g.ndata['feat'].float()
    init_labels = init_labels.squeeze()
    n_classes = dataset.num_classes
    evaluator = get_ogb_evaluator(args.dataset)

    diag_name = f'{args.root}subgraph/{args.dataset}_diag.pt'
    if not os.path.exists(diag_name):
        src, dst, eid = g._graph.edges(0)
        m = SparseTensor(row=dst, col=src, sparse_sizes=(g.num_nodes(), g.num_nodes()))

        if args.dataset in ['ogbn-proteins', 'ogbn-products']:
            if args.dataset == 'ogbn-products':
                m = remove_diag(m)
            assert torch.all(m.get_diag() == 0)
            mm_diag = sparse_tools.spspmm_diag_sym_AAA(m, num_threads=16)
            tic = datetime.datetime.now()
            mmm_diag = sparse_tools.spspmm_diag_sym_AAAA(m, num_threads=28)
            toc = datetime.datetime.now()
            torch.save([mm_diag, mmm_diag], diag_name)
        else:
            assert torch.all(m.get_diag() == 0)
            t = m.t()
            mm_diag = sparse_tools.spspmm_diag_ABA(m, m, num_threads=16)
            mt_diag = sparse_tools.spspmm_diag_ABA(m, t, num_threads=16)
            tm_diag = sparse_tools.spspmm_diag_ABA(t, m, num_threads=28)
            tt_diag = sparse_tools.spspmm_diag_ABA(t, t, num_threads=28)
            torch.save([mm_diag, mt_diag, tm_diag, tt_diag], diag_name)

    if args.dataset in ['ogbn-arxiv', 'ogbn-papers100M']:
        src, dst, eid = g._graph.edges(0)

        new_edges = {}
        new_edges[('P', 'cite', 'P')] = (src, dst)
        new_edges[('P', 'cited_by', 'P')] = (dst, src)

        new_g = dgl.heterograph(new_edges, {'P': g.num_nodes()})
        new_g.nodes['P'].data['P'] = g.ndata.pop('feat')
        g = new_g

    return g, init_labels, g.num_nodes(), n_classes, train_nid, val_nid, test_nid, evaluator


def load_mag(args, f_log, time_bit):
    t0=time.time()
    dataset = DglNodePropPredDataset(name=args.dataset, root=args.root)
    splitted_idx = dataset.get_idx_split()

    g, init_labels = dataset[0]
    splitted_idx = dataset.get_idx_split()
    train_nid = splitted_idx['train']['paper']
    val_nid = splitted_idx['valid']['paper']
    test_nid = splitted_idx['test']['paper']

    features = g.nodes['paper'].data['feat']
    if len(args.extra_embedding):
        print(f'Use extra embeddings generated with the {args.extra_embedding} method')
        path = os.path.join(args.emb_path, f'{args.extra_embedding}_nars')
        author_emb = torch.load(os.path.join(path, 'author.pt'), map_location=torch.device('cpu')).float()
        topic_emb = torch.load(os.path.join(path, 'field_of_study.pt'), map_location=torch.device('cpu')).float()
        institution_emb = torch.load(os.path.join(path, 'institution.pt'), map_location=torch.device('cpu')).float()
    else:
        author_emb = torch.Tensor(g.num_nodes('author'), args.embed_size).uniform_(-0.5, 0.5)
        topic_emb = torch.Tensor(g.num_nodes('field_of_study'), args.embed_size).uniform_(-0.5, 0.5)
        institution_emb = torch.Tensor(g.num_nodes('institution'), args.embed_size).uniform_(-0.5, 0.5)

    g.nodes['paper'].data['feat'] = features
    g.nodes['author'].data['feat'] = author_emb
    g.nodes['institution'].data['feat'] = institution_emb
    g.nodes['field_of_study'].data['feat'] = topic_emb
    paper_year=g.nodes['paper'].data['year']

    init_labels = init_labels['paper'].squeeze()
    n_classes = int(init_labels.max()) + 1 
    evaluator = get_ogb_evaluator(args.dataset)

    # for k in g.ntypes:
    #     print(k, g.ndata['feat'][k].shape)
    #for k in g.ntypes:
    #    print(k, g.nodes[k].data['feat'].shape)
        #f_log.write(f"DEBUG_load1 | {k} {g.nodes[k].data['feat'].shape}\n")
        #f_log.flush()

    adjs = []
    for i, etype in enumerate(g.etypes):
        src, dst, eid = g._graph.edges(i)
        adj = SparseTensor(row=dst, col=src)
        adjs.append(adj)
        #print(g.to_canonical_etype(etype), adj)
        #f_log.write(f"DEBUG_load2 | {g.to_canonical_etype(etype)} {adj}\n")
        #f_log.flush()

    # F --- *P --- A --- I
    # paper : [736389, 128]
    # author: [1134649, 256]
    # institution [8740, 256]
    # field_of_study [59965, 256]
    
    nums={'P':736389, 'A':1134649, 'I':8740, 'F':59965}

    new_edges = {}
    ntypes = set()

    etypes = [ # src->tgtx
        ('A', 'A-I', 'I'),
        ('A', 'A-P', 'P'),
        ('P', 'P-P', 'P'),
        ('P', 'P-F', 'F'),
    ]
    

    paper_feat=g.nodes['paper'].data['feat']
    f_log.write(f"init paper_feat.shape : {paper_feat.shape} | paper_feat.dtype : {paper_feat.dtype}\n")
    if time_bit!=0:
        # Build time positional encoding
        positional_encoding=[]
        for i in range(time_bit):
            wave=np.arange(time_bit)
            wave=np.cos((wave-i)*np.pi/time_bit)
            pos_row=torch.from_numpy(wave)
            positional_encoding.append(pos_row)
        positional_encoding=torch.stack(positional_encoding).to(torch.float32)
        #print(f"positional_encoding.shape : {positional_encoding.shape} | positional_encoding.dtype : {positional_encoding.dtype}")
        #f_log.write(f"positional_encoding.shape : {positional_encoding.shape} | positional_encoding.dtype : {positional_encoding.dtype}\n")

        print(f"init paper_feat.shape : {paper_feat.shape} | paper_feat.dtype : {paper_feat.dtype}")
        f_log.write(f"init paper_feat.shape : {paper_feat.shape} | paper_feat.dtype : {paper_feat.dtype}\n")
        year_to_idx=[0]*2020
        for i in range(time_bit):
            year_to_idx[2019-i]=time_bit-1-i
        year_to_idx=np.array(year_to_idx)

        paper_time_encoding=torch.squeeze(positional_encoding[year_to_idx[g.nodes['paper'].data['year']]])
        #print(f"paper_time_encoding.shape : {paper_time_encoding.shape} | paper_time_encoding.dtype : {paper_time_encoding.dtype}")
        #f_log.write(f"paper_time_encoding.shape : {paper_time_encoding.shape} | paper_time_encoding.dtype : {paper_time_encoding.dtype}\n")

        paper_feat=torch.cat((paper_feat, paper_time_encoding),dim=1)
        print(f"final paper_feat.shape : {paper_feat.shape} | paper_feat.dtype : {paper_feat.dtype}")
        f_log.write(f"final paper_feat.shape : {paper_feat.shape} | paper_feat.dtype : {paper_feat.dtype}\n")

        f_log.flush()


    PP_sym = adjs[2].to_symmetric() #  ('paper', 'cites', 'paper')
    #adjs[2] = adjs[2].to_symmetric()
    #assert torch.all(adjs[2].get_diag() == 0)
    
    num_nodes={}
    for etype, adj in zip(etypes, adjs):
        stype, rtype, dtype = etype
        dst, src, _ = adj.coo()
        src = src.numpy()
        dst = dst.numpy()

        if stype == 'P' and dtype == 'P':
            # paper to paper
            dstc, srcc, _ = PP_sym.coo()
            srcc = srcc.numpy()
            dstc = dstc.numpy()
            src_append = []
            dst_append = []
            # src is newer. i.e. year[src]>=year[dst] but year[src]+1==year[dst] is also possible
            print(f"Final Edges num | srcc size : {len(srcc)} | dstc size : {len(dstc)} | src size : {len(src)} | dst size : {len(dst)}")
            # args.synthesis_mode == tos : it used symmetric edges
            if(len(args.synthesis_mode)==3 and args.synthesis_mode[2]=='s'):
                for yy in range(2010,2020):
                    if not (os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'src_'+args.synthesis_mode+'.npy') and os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'dst_'+args.synthesis_mode+'.npy')):
                        newsrc=[]
                        newdst=[]
                        for i in range(len(srcc)):
                            newsrc.append(srcc[i])
                            newdst.append(dstc[i]) 
                            if(args.synthesis_mode[1]=='o'):
                                if abs(paper_year[srcc[i]]-paper_year[dstc[i]])>min(2019-paper_year[dstc[i]],paper_year[dstc[i]]-2010):
                                    newsrc.append(srcc[i])
                                    newdst.append(dstc[i])   
                            else:
                                if abs(paper_year[srcc[i]]-paper_year[dstc[i]])>min(2019-paper_year[srcc[i]],paper_year[srcc[i]]-2010):
                                    newsrc.append(srcc[i])
                                    newdst.append(dstc[i])

                        if(args.synthesis_mode[0]=='o'):
                            newsrc, newdst = np.array(newsrc), np.array(newdst) 
                        else:
                            newsrc, newdst = np.array(newdst), np.array(newsrc) 
                        np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'src_'+args.synthesis_mode,newsrc)
                        np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'dst_'+args.synthesis_mode,newdst)
                    else:
                        newsrc=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'src_'+args.synthesis_mode+'.npy')
                        newdst=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'dst_'+args.synthesis_mode+'.npy')

            else:
                for yy in range(2010,2020):
                    if not (os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'src_'+args.synthesis_mode+'.npy') and os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'dst_'+args.synthesis_mode+'.npy')):
                        newsrc=[]
                        newdst=[]
                        for i in range(len(src)):
                            newsrc.append(src[i])
                            newdst.append(dst[i]) 
                            if(args.synthesis_mode[1]=='o'):
                                if abs(paper_year[src[i]]-paper_year[dst[i]])>min(2019-paper_year[dst[i]],paper_year[dst[i]]-2010):
                                    newsrc.append(src[i])
                                    newdst.append(dst[i])   
                            else:
                                if abs(paper_year[src[i]]-paper_year[dst[i]])>min(2019-paper_year[src[i]],paper_year[src[i]]-2010):
                                    newsrc.append(src[i])
                                    newdst.append(dst[i])

                        if(args.synthesis_mode[0]=='o'):
                            newsrc, newdst = np.array(newsrc), np.array(newdst) 
                        else:
                            newsrc, newdst = np.array(newdst), np.array(newsrc) 
                        np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'src_'+args.synthesis_mode,newsrc)
                        np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'dst_'+args.synthesis_mode,newdst)
                    else:
                        newsrc=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'src_'+args.synthesis_mode+'.npy')
                        newdst=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'dst_'+args.synthesis_mode+'.npy')
    
                # print(f"NEW EDGE PP - year : {yy} | before symm size : {len(newsrc)} | {'P'+str(yy)}, {'P'+str(yy)+'-'+'P'+str(yy)}, {'P'+str(yy)}")
                # f_log.write(f"NEW EDGE PP - year : {yy} | before symm size : {len(newsrc)} | {'P'+str(yy)}, {'P'+str(yy)+'-'+'P'+str(yy)}, {'P'+str(yy)}\n")
                # f_log.flush()
                new_edges[('P'+str(yy), 'P'+str(yy)+'-'+'P'+str(yy), 'P'+str(yy))] =(newsrc, newdst) 
                num_nodes['P'+str(yy)]=nums['P']
            num_nodes['P']=nums['P']

            for i in range(len(src)):
                if paper_year[src[i]]==paper_year[dst[i]]:
                    src_append.append(dst[i].item())
                    dst_append.append(src[i].item())
            src_append, dst_append = np.array(src_append), np.array(dst_append)
            dst=np.concatenate((dst,dst_append))
            src=np.concatenate((src,src_append))
            #new_edges[(stype, rtype, dtype)] = (np.concatenate((srcc, dstc)), np.concatenate((dstc, srcc))) # Isnt this symmetric already?
            new_edges[(stype, rtype, dtype)] = (srcc, dstc) # Always change this at no cost (24.02.25)
            new_edges[(stype, stype+'>'+dtype, dtype)] = (dst, src) 

    
            dst, src= torch.from_numpy(dst).to(dtype=torch.long), torch.from_numpy(src).to(dtype=torch.long)
            adj = SparseTensor(row=dst, col=src)
            adjs[2]=adj

            # rev if new_edges[(stype, stype+'>'+dtype, dtype)] = (dst, src) 
            # normal if new_edges[(stype, stype+'>'+dtype, dtype)] = (src, dst)
            
        elif(stype=='P'):
            for yy in range(2010,2020):
                print(f"yy : {yy} | src : {stype} | dst : {dtype}")
                if not (os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'src.npy') and os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'dst.npy')):
                    # f_log.write(f"yy : {yy} | src : {stype} | dst : {dtype}\n")
                    # f_log.flush()
                    newsrc=[]
                    newdst=[]
                    for i in range(len(src)):
                        if paper_year[src[i]]<=yy: 
                            newsrc.append(src[i])
                            newdst.append(dst[i])
                    newsrc, newdst = np.array(newsrc), np.array(newdst)
                    np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'src',newsrc)
                    np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'dst',newdst)
                else:
                    newsrc=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'src.npy')
                    newdst=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'dst.npy')
                
                new_edges[(stype+str(yy), stype+str(yy)+'-'+dtype+str(yy), dtype+str(yy))] = (newsrc, newdst)
                new_edges[(dtype+str(yy), dtype+str(yy)+'-'+stype+str(yy), stype+str(yy))] = (newdst, newsrc)
                num_nodes[stype+str(yy)]=nums[stype]
                num_nodes[dtype+str(yy)]=nums[dtype]
            new_edges[(stype, stype+'-'+dtype, dtype)] = (src, dst) # 
            new_edges[(dtype, dtype+'-'+stype, stype)] = (dst, src)
            num_nodes[stype]=nums[stype]
            num_nodes[dtype]=nums[dtype]

        elif(dtype=='P'):
            for yy in range(2010,2020):
                print(f"yy : {yy} | src : {stype} | dst : {dtype}")
                if not (os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'src.npy') and os.path.exists(args.root+'symgraph/'+stype+dtype+str(yy)+'dst.npy')):
                    # f_log.write(f"yy : {yy} | src : {stype} | dst : {dtype}\n")
                    # f_log.flush()
                    newsrc=[]
                    newdst=[]
                    for i in range(len(src)):
                        if paper_year[dst[i]]<=yy:
                            newsrc.append(src[i])
                            newdst.append(dst[i])
                    newsrc, newdst = np.array(newsrc), np.array(newdst)
                    np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'src',newsrc)
                    np.save(args.root+'symgraph/'+stype+dtype+str(yy)+'dst',newdst)
                else:
                    newsrc=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'src.npy')
                    newdst=np.load(args.root+'symgraph/'+stype+dtype+str(yy)+'dst.npy')
                
                new_edges[(stype+str(yy), stype+str(yy)+'-'+dtype+str(yy), dtype+str(yy))] = (newsrc, newdst)
                new_edges[(dtype+str(yy), dtype+str(yy)+'-'+stype+str(yy), stype+str(yy))] = (newdst, newsrc)
                num_nodes[stype+str(yy)]=nums[stype]
                num_nodes[dtype+str(yy)]=nums[dtype]
            new_edges[(stype, stype+'-'+dtype, dtype)] = (src, dst)
            new_edges[(dtype, dtype+'-'+stype, stype)] = (dst, src)
            num_nodes[stype]=nums[stype]
            num_nodes[dtype]=nums[dtype]

        else:
            for yy in range(2010,2020): # 
                new_edges[(stype+str(yy), stype+str(yy)+'-'+dtype+str(yy), dtype+str(yy))] = (src, dst)
                new_edges[(dtype+str(yy), dtype+str(yy)+'-'+stype+str(yy), stype+str(yy))] = (dst, src)
                num_nodes[stype+str(yy)]=nums[stype]
                num_nodes[dtype+str(yy)]=nums[dtype]
            new_edges[(stype, stype+'-'+dtype, dtype)] = (src, dst)
            new_edges[(dtype, dtype+'-'+stype, stype)] = (dst, src)
            num_nodes[stype]=nums[stype]
            num_nodes[dtype]=nums[dtype]

            #ntypes.add(stype)
            #ntypes.add(dtype)

    new_g = dgl.heterograph(new_edges,num_nodes_dict=num_nodes)
    print(f"g.nodes['paper'].data.keys() : {g.nodes['paper'].data.keys()}")
    # g.nodes['paper'].data.keys() : dict_keys(['year', 'feat'])
    # feat, year


    #new_g.nodes['P'].data['P'] = g.nodes['paper'].data['feat']
    #new_g.nodes['P'].data['P'] = paper_feat
    #new_g.nodes['A'].data['A'] = g.nodes['author'].data['feat']
    
    for i in range(2010,2020):
        new_g.nodes['P'+str(i)].data['P'+str(i)] = paper_feat
        new_g.nodes['A'+str(i)].data['A'+str(i)] = g.nodes['author'].data['feat']
        new_g.nodes['I'+str(i)].data['I'+str(i)] = g.nodes['institution'].data['feat']
        new_g.nodes['F'+str(i)].data['F'+str(i)] = g.nodes['field_of_study'].data['feat']
        print(f"paper year : {'P'+str(i)}")
        # f_log.write(f"paper year : {'P'+str(i)}, 4types : {type(paper_feat)}, {type(g.nodes['author'].data['feat'])}, {g.nodes['institution'].data['feat']}, {g.nodes['field_of_study'].data['feat']}\n")
        # f_log.flush()
    new_g.nodes['P'].data['Y'] = paper_year

    IA, PA, PP, FP = adjs

    diag_name = f'{args.root}symgraph/{args.dataset}_PFP_diag.pt'
    if not os.path.exists(diag_name):
        PF = FP.t()
        PFP_diag = sparse_tools.spspmm_diag_sym_ABA(PF)
        torch.save(PFP_diag, diag_name)

    diag_name = f'{args.root}symgraph/{args.dataset}_PPP_diag.pt'
    if not os.path.exists(diag_name):
        # PP = PP.to_symmetric()
        # assert torch.all(PP.get_diag() == 0)
        PPP_diag = sparse_tools.spspmm_diag_sym_AAA(PP_sym)
        torch.save(PPP_diag, diag_name)


    PP=PP.t()

    diag_name = f'{args.root}symgraph/{args.dataset}_P<P<P_diag.pt'
    PPP_diag = sparse_tools.spspmm_diag_ABA(PP,PP)
    torch.save(PPP_diag, diag_name)

    diag_name = f'{args.root}symgraph/{args.dataset}_P<PP_diag.pt'
    PPP_diag = sparse_tools.spspmm_diag_ABA(PP,PP_sym)
    torch.save(PPP_diag, diag_name)


    diag_name = f'{args.root}symgraph/{args.dataset}_PAP_diag.pt'
    if not os.path.exists(diag_name):
        PAP_diag = sparse_tools.spspmm_diag_sym_ABA(PA)
        torch.save(PAP_diag, diag_name) 

    print(f"Load mag Done! ... {time.time()-t0:.5f}s")
    f_log.write(f"Load mag Done! ... {time.time()-t0:.5f}s\n")
    f_log.flush()
    return new_g, init_labels, new_g.num_nodes('P'), n_classes, train_nid, val_nid, test_nid, evaluator, paper_year

