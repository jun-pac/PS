import os
import gc
import time
import uuid
import argparse
import datetime
import numpy as np
import dgl
from tqdm import tqdm
from torch_sparse import SparseTensor

import torch
import torch.nn.functional as F
from ogb.nodeproppred import DglNodePropPredDataset
import matplotlib.pylab as plt


def edge_homophily(g, label):
    src, dst, eid = g._graph.edges(0)
    num_e=src.shape[0]
    print(f"num_e : {num_e} | dst.shape[0] : {dst.shape[0]}")
    same_arr=np.squeeze(np.where(label[src]==label[dst]))
    return same_arr.shape[0]/num_e,same_arr.shape[0],num_e



name='Connectivity'
f_log=open('./txtlog/'+name+'.txt','a')

t0=time.time()
f_log.write(f"\nCalculation begin : {time.time():.6f}\n")
f_log.flush()
dataset = DglNodePropPredDataset(name='ogbn-mag', root='../data/')
splitted_idx = dataset.get_idx_split()

g, init_labels = dataset[0]
paper_year=g.nodes['paper'].data['year']
splitted_idx = dataset.get_idx_split()
train_nid = splitted_idx['train']['paper']
val_nid = splitted_idx['valid']['paper']
test_nid = splitted_idx['test']['paper']

init_labels = init_labels['paper'].squeeze()


print(f"type(init_labels) : {type(init_labels)} | init_labels.shape : {init_labels.shape}")
f_log.write(f"type(init_labels) : {type(init_labels)} | init_labels.shape : {init_labels.shape}\n")
f_log.flush()
print(f"Some init labels : {init_labels[0:10]}")

num_p=init_labels.shape[0]
adjs = []
for i, etype in enumerate(g.etypes):
    src, dst, eid = g._graph.edges(i)
    adj = SparseTensor(row=dst, col=src)
    adjs.append(adj)

# PP_sym = adjs[2].to_symmetric()
# dst, src, _ = PP_sym.coo()
# src = src.numpy()
# dst = dst.numpy()
    
node_ty=np.zeros((10,349),dtype=np.longlong)
edge_ttyy=np.zeros((10,10,349,349), dtype=np.longlong)
edge_connectivity=np.zeros((10,10,349,349), dtype=np.float64)

dst, src, _ = adjs[2].coo()

cnt=0
for i in range(len(init_labels)):
    node_ty[paper_year[i]-2010][init_labels[i]]+=1 # Is it correct?
    if paper_year[i]==2019 and cnt<50:
        print(i,paper_year[i],init_labels[i])
        cnt+=1

for i in tqdm(range(len(dst))):
    t1=paper_year[src[i]]-2010
    t2=paper_year[dst[i]]-2010
    edge_ttyy[t1][t2][init_labels[src[i]]][init_labels[dst[i]]]+=1
    edge_ttyy[t2][t1][init_labels[dst[i]]][init_labels[src[i]]]+=1

print("This will take some time...")
for t1 in tqdm(range(10)):
    for t2 in range(10):
        for y1 in range(349):
            for y2 in range(349):
                if (node_ty[t1][y1]<=1 or node_ty[t2][y2]<=1):
                    edge_connectivity[t1][t2][y1][y2]=0
                else:
                    if(t1==t2 and y1==y2):
                        cnt=node_ty[t1][y1]*(node_ty[t1][y1]-1)
                    else:
                        cnt=node_ty[t1][y1]*node_ty[t2][y2]
                    edge_connectivity[t1][t2][y1][y2]=edge_ttyy[t1][t2][y2][y2]/cnt

np.save("./connectivity",edge_connectivity)

print(f"...End! : {time.time()-t0}")
f_log.write(f"...End! : {time.time()-t0}\n")
f_log.flush()



# for i in range(10):
#     for j in range(10):
#         if(map_num[i][j]==0):
#             map_homo[i][j]=0
#         else:
#             map_homo[i][j]=map_same[i][j]/map_num[i][j]
#         f_log.write(f"{map_homo[i][j]:.4f} ")
#     f_log.write('\n')
# f_log.flush()
# np.save("./homophiliy",map_homo)

# y, x = np.meshgrid(np.linspace(0, 9, 10), np.linspace(0,9,10))
# fig, ax = plt.subplots()


# c = ax.pcolormesh(x, y, map_homo, cmap='RdBu', vmin=0, vmax=1)
# ax.set_title('heatmap of homophily')
# ax.axis([x.min(), x.max(), y.min(), y.max()])
# fig.colorbar(c, ax=ax)
# plt.savefig('./fig_homo.png', dpi=300)

