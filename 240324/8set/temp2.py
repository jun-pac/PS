


n = int(input())
plants=[int(x) for x in input().split(' ')]
m=int(input())
watered=[int(x) for x in input().split(' ')]

#print(plants)
#print(watered)

result = [0]*m
cnt=[1]*n
adds=[]
dels=[]
happy_cnt=n
for i in range(n):
    dels.append((plants[i],i))
        
for i in range(m):
    adds.append((i+1,watered[i]-1))
    dels.append((i+1+plants[watered[i]-1],watered[i]-1)) # inclusive
dels.sort()


adds_cur=0
dels_cur=0
for i in range(1,m+1):
    while (adds_cur<len(adds) and adds[adds_cur][0]<=i):
        if(cnt[adds[adds_cur][1]]>=0):
            cnt[adds[adds_cur][1]]+=1
        if(cnt[adds[adds_cur][1]]==1):
            happy_cnt+=1
        adds_cur+=1
    while (dels_cur<len(dels) and dels[dels_cur][0]<=i):
        cnt[dels[dels_cur][1]]-=1
        if(cnt[dels[dels_cur][1]]==0):
            happy_cnt-=1
            cnt[dels[dels_cur][1]]=-1
        dels_cur+=1
    result[i-1]=happy_cnt
    


print(result)

