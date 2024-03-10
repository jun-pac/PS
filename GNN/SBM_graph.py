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


t0=time.time()
num_node=1000
num_label=10
num_time=100
feat_dim=1

label_rands=torch.randperm(num_node)
time_rands=torch.randperm(num_node)

label=[0]*num_node
times=[0]*num_node
train_mask=[0]*num_node
valid_mask=[0]*num_node
test_mask=[0]*num_node

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
    train_mask[i]=(times[i]<60)
    valid_mask[i]=(times[i]>=60 and times[i]<80)
    test_mask[i]=(times[i]>=80)
    
label=torch.Tensor(label).type(torch.long)
times=torch.Tensor(times).type(torch.long)
train_mask=torch.Tensor(train_mask).type(torch.bool)
valid_mask=torch.Tensor(valid_mask).type(torch.bool)
test_mask=torch.Tensor(test_mask).type(torch.bool)

for i in range(num_node):
    label[i]=label_rands[i]%num_label
    times[i]=time_rands[i]%num_time

for i in range(num_node):
    train_mask[i]=(times[i]<60)
    valid_mask[i]=(times[i]>=60 and times[i]<80)
    test_mask[i]=(times[i]>=80)
    
label=torch.Tensor(label).type(torch.long)
times=torch.Tensor(times).type(torch.long)
train_mask=torch.Tensor(train_mask).type(torch.bool)
valid_mask=torch.Tensor(valid_mask).type(torch.bool)
test_mask=torch.Tensor(test_mask).type(torch.bool)


# Define Sample Functions 
sample_func={}
def sample_feat_distribution3(cur_label):
    # 0<=cur_label<num_label
    res=torch.randn(1)
    return res+0.2*cur_label
sample_func['3']=sample_feat_distribution3



# Define SBM probability matrices
matrix={}
temp=torch.zeros([num_time, num_label, num_label], dtype=torch.float32)
for t in range(num_time):
    for i in range(num_label):
        for j in range(num_label):
            temp[t][i][j]=(0.8 if i==j else 0.2*(num_time-t)/num_time)
matrix['3']=temp

for t in range(num_time):
    for i in range(num_label):
        for j in range(num_label):
            temp[t][i][j]=(0.8 if i==j else 0.1)
matrix['3_tinvar']=temp

print(f"matrix created : {time.time()-t0}")
t0=time.time()





if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--graphnum", type=str, default='3')
    parser.add_argument("--time_invar", action='store_true', default=False)
    parser.add_argument("--root",type=str, default='../GNN/data/')
    parser.add_argument("--sym_sampling", action='store_true', default=False)
    args = parser.parse_args()

    graph_name=args.graphnum+("_tinvar" if args.time_invar else "")    
    name=graph_name+("_sym" if args.sym_sampling else "")
    
    src=[]
    dst=[]
    for i in range(num_node):
        for j in range(num_node):
            delta=abs(times[i]-times[j])
            yi=label[i]
            yj=label[j]
            if (i!=j and random.uniform(0, 1)<matrix[graph_name][delta][yi][yj]):
                src.append(i)
                dst.append(j)
    src, dst = np.array(src), np.array(dst)
    newsrc=np.concatenate((src,dst))
    newdst=np.concatenate((dst,src))
    addsrc=[]
    adddst=[]

    if(args.sym_sampling):
        for i in range(len(newsrc)):
            if abs(times[newsrc[i]]-times[newdst[i]])>min(num_time-1-times[newdst[i]],times[newdst[i]]-0):
                addsrc.append(newsrc[i])
                adddst.append(newdst[i])
        addsrc, adddst = np.array(addsrc), np.array(adddst)    
        newsrc=np.concatenate((newsrc,addsrc))
        newdst=np.concatenate((newdst,adddst))
        

    new_edges={}
    num_nodes={}
    new_edges[('node','-','node')]=(src,dst) # undirected
    num_nodes['node']=num_node
    new_g = dgl.heterograph(new_edges,num_nodes_dict=num_nodes)


    feature=torch.zeros([num_node,feat_dim])
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
python3 SBM_graph.py --graphnum 3 # 28sec
python3 SBM_graph.py --graphnum 3 --sym_sampling # 44sec

python3 SBM_graph.py --graphnum 3 --time_invar # 30sec
python3 SBM_graph.py --graphnum 3 --time_invar --sym_sampling # 40sec

'''
