def solution(cap, k, score, m):
    if k >= score[m-1]:
        return 0
    
    vac_up=0
    vac_down=0
    reserve=[]
    mv=0
    ans=0
    for i in range(m-1):
        vac_up+=cap-score[i]
        reserve.append(cap-score[i])
    for i in range(m-1,len(score)):
        if(score[i]>k):
            mv+=score[i]-k
            ans+=1
        else:
            vac_down+=k-score[i]
            reserve.append(k-score[i])
    if(mv>vac_up+vac_down):
        return -1
    reserve.sort()
    reserve.reverse()
    cur=0
    for i in range(len(reserve)):
        cur+=reserve[i]
        if(cur>=mv):
            ans=i+1+ans
            break

    return ans


cap=int(input())
k=int(input())
sc=[int(x) for x in input().split(' ')]
m=int(input())
print(solution(cap,k,sc,m))
