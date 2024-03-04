import os
import gc
import time
import uuid
import argparse
import datetime
import numpy as np
import dgl
from torch_sparse import SparseTensor

import torch
import torch.nn.functional as F
from ogb.nodeproppred import DglNodePropPredDataset
import matplotlib.pylab as plt


def edge_homophily(g, label):
    src, dst, eid = g._graph.edges(0)
    num_e=src.shape[0] # 이게 지금 {u,v} 꼴로 들어있는건가? # {v_idx, v}가 아니라?
    print(f"num_e : {num_e} | dst.shape[0] : {dst.shape[0]}")
    '''
    for i in range(num_e):
        if label[src[i]]==label[dst[i]]:
            same_cls+=1
    '''
    same_arr=np.squeeze(np.where(label[src]==label[dst])) # if(src[idx]==dst[idx]) res.append(idx)
    return same_arr.shape[0]/num_e,same_arr.shape[0],num_e



name='homophily_by_year'
f_log=open('./txtlog/'+name+'.txt','a')

t0=time.time()
f_log.write(f"\nCalculation begin : {time.time():.6f}\n")
f_log.flush()
dataset = DglNodePropPredDataset(name='ogbn-mag', root='../data/')
splitted_idx = dataset.get_idx_split()

g, init_labels = dataset[0]
paper_year=g.nodes['paper'].data['year'] # 이게 지금 다 dict임.
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

# only PP
dst, src, _ = adjs[2].coo() # rowptr,col,_=adj_t.csr()이 ptr을 적는 것. coo는 {u,v}를 적는 것
print(f"Type of src : {type(src)}")
src = src.numpy()
dst = dst.numpy()
new_g=dgl.graph((src,dst),num_nodes=num_p)
#homo=dgl.node_homophily(new_g, init_labels)
t0=time.time()
homo,_,_=edge_homophily(new_g, init_labels)
print(f"Edge homophily for PP : {homo:.4f} | time : {time.time()-t0:.4f}")
f_log.write(f"Edge homophily for PP : {homo:.4f} | time : {time.time()-t0:.4f}\n")
f_log.flush()

# only sym
PP_sym = adjs[2].to_symmetric()
dst, src, _ = PP_sym.coo()
src = src.numpy()
dst = dst.numpy()
new_g=dgl.graph((src,dst),num_nodes=num_p)
homo,_,_=edge_homophily(new_g, init_labels)
print(f"Edge homophily for PP_sym : {homo:.4f} | time : {time.time()-t0:.4f}")
f_log.write(f"Edge homophily for PP_sym : {homo:.4f} | time : {time.time()-t0:.4f}\n")
f_log.flush()

f_log.write(f"===========================\n")
f_log.flush()
# for Past year subgraph
for yy in range(2010,2020):
    newsrc=np.load('../data/subgraph/PP'+str(yy)+'src.npy')
    newdst=np.load('../data/subgraph/PP'+str(yy)+'dst.npy')
    edges=(np.concatenate((newsrc, newdst)), np.concatenate((newdst, newsrc)))
    new_g=dgl.graph(edges,num_nodes=num_p)
    homo,_,_=edge_homophily(new_g, init_labels)
    print(f"Edge homophily for PP{yy} : {homo:.4f} | time : {time.time()-t0:.4f}")
    f_log.write(f"Edge homophily for PP{yy} : {homo:.4f} | time : {time.time()-t0:.4f}\n")
    f_log.flush()


print(f"===========================")
print(f"This step will take some time...")
f_log.write(f"===========================\n")
f_log.write(f"This step will take some time...\n")
f_log.flush()
# for specific year-to-year

dist_num=[0]*10 # cnt_dist[i] : Number of edges connecting nodes with i year deviation
dist_same=[0]*10 # cnt_same[i] : Number of edges connecting nodes with i year deviation, and same label
map_num=[[0]*10 for i in range(10)]
map_same=[[0]*10 for i in range(10)]
map_homo=[[0]*10 for i in range(10)]
dst, src, _ = adjs[2].coo()
for i in range(len(dst)):
    year_diff=abs(paper_year[dst[i]]-paper_year[src[i]])
    y1=paper_year[src[i]]-2010
    y2=paper_year[dst[i]]-2010
    dist_num[year_diff]+=1
    map_num[y1][y2]+=1
    map_num[y2][y1]+=1
    if(init_labels[src[i]]==init_labels[dst[i]]):
        dist_same[year_diff]+=1
        map_same[y1][y2]+=1
        map_same[y2][y1]+=1

print(f"...End! : {time.time()-t0}")
f_log.write(f"...End! : {time.time()-t0}\n")
f_log.flush()

print(f"Edge homophily by year difference")
f_log.write(f"Edge homophily by year difference\n")
f_log.flush()
for i in range(10):
    print(f"Edge homophily | {i} year diff : {dist_same[i]/dist_num[i]:.4f}")
    f_log.write(f"Edge homophily | {i} year diff : {dist_same[i]/dist_num[i]:.4f}\n")
    f_log.flush()

f_log.write(f"Raw datas : \n")
for i in range(10):
    f_log.write(f"{dist_num[i]} {dist_same[i]} {dist_same[i]/dist_num[i]:.8f}\n")
for i in range(10):
    for j in range(10):
        if(map_num[i][j]==0):
            map_homo[i][j]=0
        else:
            map_homo[i][j]=map_same[i][j]/map_num[i][j]
        f_log.write(f"{map_same[i][j]/map_num[i][j]:.4f} ")
    f_log.write('\n')
f_log.flush()

y, x = np.meshgrid(np.linspace(0, 9, 10), np.linspace(0,9,10))
fig, ax = plt.subplots()


c = ax.pcolormesh(x, y, map_homo, cmap='RdBu', vmin=0, vmax=1)
ax.set_title('heatmap of homophily')
# set the limits of the plot to the limits of the data
ax.axis([x.min(), x.max(), y.min(), y.max()])
fig.colorbar(c, ax=ax)
plt.savefig('./fig1.png', dpi=300)



'''
g, init_labels, num_nodes, n_classes, train_nid, val_nid, test_nid, evaluator, paper_year = load_dataset(args,f_log,args.time_bit)

# =======
# rearange node idx (for feats & labels)
# =======

train_node_nums = len(train_nid)
valid_node_nums = len(val_nid)
test_node_nums = len(test_nid)
trainval_point = train_node_nums
valtest_point = trainval_point + valid_node_nums
total_num_nodes = len(train_nid) + len(val_nid) + len(test_nid)

if total_num_nodes < num_nodes:
    flag = torch.ones(num_nodes, dtype=bool)
    flag[train_nid] = 0
    flag[val_nid] = 0
    flag[test_nid] = 0
    extra_nid = torch.where(flag)[0]
    print(f'Find {len(extra_nid)} extra nid for dataset {args.dataset}')
    f_log.write(f'Find {len(extra_nid)} extra nid for dataset {args.dataset}\n')
    f_log.flush()
else:
    extra_nid = torch.tensor([], dtype=torch.long)

init2sort = torch.cat([train_nid, val_nid, test_nid, extra_nid])
sort2init = torch.argsort(init2sort)
assert torch.all(init_labels[init2sort][sort2init] == init_labels)
labels = init_labels[init2sort]

#print(f"max(paper_year[train_nid]) : {max(paper_year[train_nid])} | min(paper_year[train_nid]) : {min(paper_year[train_nid])}")
#print(f"max(paper_year[val_nid]) : {max(paper_year[val_nid])} | min(paper_year[val_nid]) : {min(paper_year[val_nid])}")
#print(f"max(paper_year[test_nid]) : {max(paper_year[test_nid])} | min(paper_year[test_nid]) : {min(paper_year[test_nid])}")
#f_log.write(f"max(paper_year[train_nid]) : {max(paper_year[train_nid])} | min(paper_year[train_nid]) : {min(paper_year[train_nid])}\n")
#f_log.write(f"max(paper_year[val_nid]) : {max(paper_year[val_nid])} | min(paper_year[val_nid]) : {min(paper_year[val_nid])}\n")
#f_log.write(f"max(paper_year[test_nid]) : {max(paper_year[test_nid])} | min(paper_year[test_nid]) : {min(paper_year[test_nid])}\n")
#f_log.flush()
# train : 2010~2017 | valid : 2018 | test : 2019

# =======
# features propagate alongside the metapath
# =======
'''