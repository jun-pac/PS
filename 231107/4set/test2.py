import sys
sys.setrecursionlimit(1000010)

memo={}

def expectation(r,b):
    if (r,b) in memo:
        return memo[(r,b)]
    if(r==0):
        memo[(r,b)]=0
        return 0
    elif(b==0):
        memo[(r,b)]=r
        return r
    else:
        temp=r/(r+b)*(1+expectation(r-1,b))+b/(r+b)*(-1+expectation(r,b-1))
        memo[(r,b)]=max(0,temp)
        return max(0,temp)

print(expectation(4000,4000))
