import random
import numpy as np
import torch
train_nid=torch.Tensor([10,20,30,40])
val_nid=torch.Tensor([50,60,70])
test_nid=torch.Tensor([80,90,100])

train_node_nums = len(train_nid)
valid_node_nums = len(val_nid)
test_node_nums = len(test_nid)
total_num_nodes = len(train_nid) + len(val_nid) + len(test_nid)


print(f"train : {train_node_nums}, valid : {valid_node_nums}, test : {test_node_nums}")
total=torch.cat([train_nid, val_nid, test_nid])
shuffle=torch.randperm(total_num_nodes)
train_nid=total[shuffle[:train_node_nums]]
val_nid=total[shuffle[train_node_nums:train_node_nums+valid_node_nums]]
test_nid=total[shuffle[train_node_nums+valid_node_nums:total_num_nodes]]

print("New train : ",train_nid)
print("New valid : ",val_nid)
print("New test : ",test_nid)

temp=torch.randn(1)
print(f"temp : {temp}")



'''
cnt=0
print(np.exp(-2))
for _ in range(100):
    if(random.uniform(0, 1)<np.exp(-2)):
        cnt+=1
print(cnt/100)
print((1-np.exp(-2))**10)

print("alpha = ",0.9)
for i in range(2010,2018):
    print(i,np.exp(0.9*(i-2017)))

print("alpha = ",0.8)
for i in range(2010,2018):
    print(i,np.exp(0.8*(i-2017)))

print("alpha = ",0.7)
for i in range(2010,2018):
    print(i,np.exp(0.7*(i-2017)))

print("alpha = ",0.5)
for i in range(2010,2018):
    print(i,np.exp(0.5*(i-2017)))

print("alpha = ",0)
for i in range(2010,2018):
    print(i,np.exp(0*(i-2017)))

alpha=0.4
beta=0.9
print("alpha beta : ", alpha, beta)
sum=0
for i in range(2010,2018):
    print(i, alpha*beta**(2017-i))
    sum+=alpha*beta**(2017-i)
print("sum : ",sum)

alpha=0.4
beta=0.7
print("alpha beta : ", alpha, beta)
sum=0
for i in range(2010,2018):
    print(i, alpha*beta**(2017-i))
    sum+=alpha*beta**(2017-i)
print("sum : ",sum)

alpha=0.4
beta=0.6
print("alpha beta : ", alpha, beta)
sum=0
for i in range(2010,2018):
    print(i, alpha*beta**(2017-i))
    sum+=alpha*beta**(2017-i)
print("sum : ",sum)
'''