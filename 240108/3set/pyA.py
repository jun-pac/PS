# problem A

def getTotalExecutionTime(n, logs):
    m=len(logs)
    res=[0]*n
    duration=[0]*n
    stack=[-1]*n
    scnt=0
    for i in range(m):
        temp=logs[i].split(':')
        idx=int(temp[0])
        t=int(temp[2])
        if temp[1][0]=='s':
            duration[idx]-=t
            stack[scnt]=idx
            scnt+=1
        else:
            duration[idx]+=t+1
            scnt-=1
            if scnt!=0:
                res[stack[scnt-1]]-=duration[idx]
    for i in range(n):
        res[i]+=duration[i]
    return res
    

n = int(input())
m=int(input())
data=[]
for i in range(m):
    s=input()
    data.append(s)
print(getTotalExecutionTime(n,data))





# # problem A

# def foo(n, logs):
#     m=len(logs)
#     res=[0]*n
#     stack=[-1]*n
#     scnt=0
#     for i in range(m):
#         temp=logs[i].split(':')
#         idx=int(temp[0])
#         t=int(temp[2])
#         if temp[1][0]=='s':
#             res[idx]-=t
#             stack[scnt]=idx
#             scnt+=1
#         else:
#             res[idx]+=t+1
#             scnt-=1
#             if scnt!=0:
#                 res[stack[scnt-1]]-=res[idx]
#     return res
    

# n = int(input())
# m=int(input())
# data=[]
# for i in range(m):
#     s=input()
#     data.append(s)
# print(foo(n,data))