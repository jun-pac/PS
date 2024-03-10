import argparse

import dgl
import torch
import numpy as np
import random
from dgl.data.utils import save_graphs
from dgl.data.utils import load_graphs
import os
import time
import torch.nn.functional as F
from tqdm import tqdm 
from multiprocessing import Pool
from itertools import repeat
chunk_size=100
sym_chunk_size=1000
core_num=8
len_newsrc=0

t0=time.time()
num_node=3000
num_label=10
num_time=100

label_rands=torch.randperm(num_node)
time_rands=torch.randperm(num_node)

label=[0]*num_node
times=[0]*num_node
train_mask=[0]*num_node
valid_mask=[0]*num_node
test_mask=[0]*num_node

for i in range(num_node):
    label[i]=label_rands[i]%num_label
    times[i]=time_rands[i]%num_time

for i in range(num_node):
    train_mask[i]=(times[i]<55)
    valid_mask[i]=(times[i]>=55 and times[i]<60)
    test_mask[i]=(times[i]>=60)
    
label=torch.Tensor(label).type(torch.long)
times=torch.Tensor(times).type(torch.long)
train_mask=torch.Tensor(train_mask).type(torch.bool)
valid_mask=torch.Tensor(valid_mask).type(torch.bool)
test_mask=torch.Tensor(test_mask).type(torch.bool)


# Define Sample Functions 
sample_func={}
'''
sample_func['3']=lambda cur_label:torch.randn(args.feat_dim)*0.2+feat_center[cur_label]
sample_func['2']=lambda cur_label:torch.randn(args.feat_dim)*0.2+feat_center[cur_label]
sample_func['1']=lambda cur_label:torch.randn(args.feat_dim)*0.2+feat_center[cur_label]
sample_func['0']=lambda cur_label:torch.randn(args.feat_dim)*0.2+feat_center[cur_label]
sample_func['33']=lambda cur_label:torch.randn(args.feat_dim)*0.2+feat_center[cur_label]
'''
sample_func['MUL1']=lambda cur_label:torch.randn(args.feat_dim)*32+feat_center[cur_label]
sample_func['MUL2']=lambda cur_label:torch.randn(args.feat_dim)*32+feat_center[cur_label]
sample_func['MUL3']=lambda cur_label:torch.randn(args.feat_dim)*8+feat_center[cur_label]


# Define SBM probability matrices
matrix_func={}
'''
matrix_func['3']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.2*(num_time-delta_t)/num_time)
matrix_func['3_tinvar']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.1)
matrix_func['2']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.8*(num_time-delta_t)/num_time)
matrix_func['2_tinvar']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.4)
matrix_func['1']=lambda delta_t,label_i,label_j:(0.2 if label_i==label_j else 0.06*(num_time-delta_t)/num_time)
matrix_func['1_tinvar']=lambda delta_t,label_i,label_j:(0.2 if label_i==label_j else 0.03)
matrix_func['0']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.4*(num_time-delta_t)*(num_time-delta_t)/num_time/num_time)
matrix_func['0_tinvar']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.2)
matrix_func['33']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.2*(num_time-delta_t)/num_time)
matrix_func['33_tinvar']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.1)
matrix_func['MUL1_tinvar']=lambda delta_t,label_i,label_j:(0.5 if label_i==label_j else 0.2)
matrix_func['MUL2_tinvar']=lambda delta_t,label_i,label_j:(0.5 if label_i==label_j else 0.2)
matrix_func['MUL3_tinvar']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.3)
'''
matrix_func['MUL1']=lambda delta_t,label_i,label_j:(0.5 if label_i==label_j else 0.4*(num_time-delta_t)/num_time)
matrix_func['MUL2']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.4*(num_time-delta_t)/num_time)
matrix_func['MUL3']=lambda delta_t,label_i,label_j:(0.8 if label_i==label_j else 0.6*(num_time-delta_t)/num_time)
t0=time.time()


def task(idx):
    src=[]
    dst=[]
    for i in range(idx,min(idx+chunk_size,num_node)):
        for j in range(num_node):
            delta=abs(times[i]-times[j])
            yi=label[i]
            yj=label[j]
            if (i!=j and random.uniform(0, 1)<matrix(delta,yi,yj)):
                src.append(i)
                dst.append(j)
    return np.array([src, dst])


def sym_task(idx):
    addsrc=[]
    adddst=[]
    for i in range(idx,min(idx+sym_chunk_size,len_newsrc)):
        if abs(times[newsrc[i]]-times[newdst[i]])>min(num_time-1-times[newdst[i]],times[newdst[i]]-0):
            addsrc.append(newsrc[i])
            adddst.append(newdst[i])
    return np.array([addsrc, adddst])
    


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--graphnum", type=str, default='3')
    parser.add_argument("--time_invar", action='store_true', default=False)
    parser.add_argument("--root",type=str, default='./data/')
    parser.add_argument("--sym", action='store_true', default=False)
    parser.add_argument("--feat_dim", type=int, default=5)
    args = parser.parse_args()

    graph_name=args.graphnum+("_tinvar" if args.time_invar else "")    
    name=graph_name+("_sym" if args.sym else "")
    name=name+"_feat"+str(args.feat_dim)

    
    matrix=matrix_func[graph_name]
    with Pool(core_num) as p:
        result = p.map(task, range(0,num_node,chunk_size))
    src_dst = np.concatenate(result, axis=1)
    src, dst = src_dst
    newsrc=np.concatenate((src,dst))
    newdst=np.concatenate((dst,src))

    print(f"Directed edge generated : {time.time()-t0}")

    if(args.sym):
        len_newsrc=len(newsrc)
        with Pool(core_num) as p:
            result = p.map(sym_task, range(0,len(newsrc),sym_chunk_size))
        src_dst = np.concatenate(result, axis=1)
        addsrc, adddst = src_dst
        newsrc=np.concatenate((newsrc,addsrc))
        newdst=np.concatenate((newdst,adddst))
        print(f"Symmetric edge generated : {time.time()-t0}")


    new_edges={}
    num_nodes={}
    new_edges[('node','-','node')]=(newsrc,newdst) # undirected
    num_nodes['node']=num_node
    new_g = dgl.heterograph(new_edges,num_nodes_dict=num_nodes)

    

    feat_center=torch.zeros([num_label,args.feat_dim])
    for i in range(num_label):
        feat_center[i]=torch.randn(args.feat_dim)

    feature=torch.zeros([num_node,args.feat_dim])
    for i in range(num_node):
        cur_label = label[i]
        feature[i] = sample_func[args.graphnum](cur_label)

    new_g.nodes['node'].data["label"]=label
    new_g.nodes['node'].data["feat"]=feature
    new_g.nodes['node'].data["train_mask"]=train_mask
    new_g.nodes['node'].data["val_mask"]=valid_mask
    new_g.nodes['node'].data["test_mask"]=test_mask

    print(f"graph created : {time.time()-t0}")
    t0=time.time()

    name=args.root+name
    glabel={'label':label}
    if not os.path.exists(name):
        save_graphs(name,[new_g],glabel)
    print(f"graph saved : {time.time()-t0}")

'''
Node number : 3000 (55 : 5 : 40)
python3 SBM_graph.py --graphnum MUL2 --feat_dim 5
python3 SBM_graph.py --graphnum MUL2 --sym --feat_dim 5

'''
