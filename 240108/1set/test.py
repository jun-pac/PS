
n = int(input())
a=[]
acnt=[]

adict={}
for _ in range(n):
    x=int(input())
    a.append(x)
    if x not in adict:
        adict[x]=0
    adict[x]+=1

for key in adict:
    acnt.append([adict[key],key])
acnt.sort()
acnt.reverse()

m = int(input())
b=[]
bdict={}
for _ in range(m):
    x=int(input())
    b.append(x)

k = int(input())
    


dist_num=len(adict)
print(a)
print(b)
print(acnt)

bb=0
aa=0
for i in range(k):
    while aa<len(acnt) and acnt[aa][0]==1:
        aa+=1
    if aa>=len(acnt):
        break
    while(bb<m and (b[bb] in adict)):
        bb+=1
    if(bb==m):
        break

    dist_num+=1
    adict[b[bb]]=1

print(dist_num)

