
import matplotlib.pyplot as plt

MX=10
MN=-10

def conv(x,h):
    assert len(x) == len(h)
    l=len(x)
    res=[0]*l
    for i in range(MN,MX+1):
        print("CONV ",i)
        for k in range(MN,MX+1):
            print(k, i-k, "WIET :",k-MN, i-k-MN)
            if(x[k-MN]*(0 if (i-k-MN<0 or i-k-MN>MX) else h[i-k-MN])!=0):
                print("PO : ",x[k-MN]*(0 if (i-k-MN<0 or i-k-MN>MX) else h[i-k-MN]))
            res[i-MN]=res[i-MN]+x[k-MN]*(0 if (i-k-MN<0 or i-k-MN>MX) else h[i-k-MN])
    return res

idx=list(range(MN,MX+1))
X=[1 if 3<=i and i<=8 else 0 for i in range(MN,MX+1)]
H=[1 if 4<=i and i<=15 else 0 for i in range(MN,MX+1)]
print("LEN : ",len(H))
#print(H)
#print([H[-i] for i in range(len(H))])
Y=conv(X,H)
#Y[10]=100
print(Y)
plt.plot(idx,Y)
plt.show()