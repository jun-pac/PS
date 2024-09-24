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


class JJ_Norm(torch.nn.Module):
    def __init__(self, labels, times, num_time, num_label, split):
        super().__init__()
        self.labels = labels
        self.times = times
        self.num_time = num_time
        self.num_label = num_label
        self.split = split
        self.train_time_idx=[[] for _ in range(self.split)]
        self.train_idx=[[[] for _ in range(self.num_labels)] for _ in range(self.split)]
        self.test_idx=[]
        self.train_time_cnt=torch.zeros(self.num_time, requires_grad=False)
        self.train_cnt=torch.zeros(1, requires_grad=False)
        self.test_cnt=torch.zeros(self.num_time, self.num_label, requires_grad=False)
        
        for i in range(len(labels)):
            if(self.times[i]>=self.split):
                self.test_idx.append(i)
                self.test_cnt[0]+=1
            else:
                self.train_time_idx[self.times[i]].append(i)
                self.train_idx[self.times[i]][self.labels[i]].append(i)
                self.train_time_cnt[self.times[i]]+=1
                self.train_cnt[self.times[i]][self.labels[i]]+=1
        
        

    def forward(self, x):
        clone_x=torch.clone(x)
        train_mean = torch.zeros((self.num_time, self.num_label, clone_x.shape[1]), requires_grad=False)
        train_time_mean = torch.zeros((self.num_time, clone_x.shape[1]), requires_grad=False)
        test_mean = torch.zeros((clone_x.shape[1]), requires_grad=False)

        test_mean=torch.mean(x[self.test_idx],-1)
        for t in range(self.split):
            train_time_mean[t] = torch.mean(x[self.train_time_idx[t]],-1)
            for y in range(self.num_labels):
                train_mean[t][y] = torch.mean(x[self.train_idx[t][y]],-1)

        test_var = torch.norm(torch.mean(x[self.test_idx]-test_mean,-1))**2
        rsq = torch.zeros(self.num_time,requires_grad=False)
        msq = torch.zeros(self.num_time,requires_grad=False)
        for t in range(self.split):
            for y in range(self.num_labels):
                rsq[t]+=torch.norm(torch.mean(train_mean[t][y]-train_time_mean,-1))**2
                msq[t]+=torch.norm(torch.mean(x[self.train_idx[t][y]]-train_mean[t][y],-1))**2
        # # Add norm values
        # test_var = torch.zeros(1,requires_grad=False)
        # rsq = torch.zeros(self.num_time,requires_grad=False)
        # msq = torch.zeros(self.num_time,requires_grad=False)
        # for u in range(clone_x.shape[0]):
        #     if(self.times[u]>=self.split):
        #         test_var[0] += torch.norm(clone_x[u] - test_mean) ** 2
        #     else:
        #         t = self.times[u]
        #         msq[t] += torch.norm(train_mean[t][self.labels[u]] - train_time_mean[t]) ** 2
        #         rsq[t] += torch.norm(clone_x[u] - train_mean[t][self.labels[u]]) ** 2


        # # Calculate Statistics
        # test_var[0]/=max(1,test_cnt[0]-1)
        # for t in range(self.split):
        #     msq[t]/=max(1,train_time_cnt[t]-1)
        #     rsq[t]/=max(1,train_time_cnt[t]-1)
        # alpha=torch.ones(self.split,requires_grad=False)
        # alpha_sq=torch.zeros(self.split,requires_grad=False)
        # for t in range(self.split):
        #     alpha_sq[t]=(test_var[0]-msq[t])/max(0.000001,rsq[t])
        #     if(alpha_sq[t]>0):
        #         alpha[t]=torch.sqrt(alpha_sq[t])
        #     else:
        #         alpha[t]=0       


        # # Update modified vals
        # for u in range(clone_x.shape[0]):
        #     if(self.times[u]<self.split):
        #         clone_x[u] = alpha[t] * x[u] + (1 - alpha[t]) * train_mean[t][self.labels[u]]
        return clone_x

