import matplotlib.pyplot as plt
MN=-30
MX=30

def CONV(x,h):
    res=[0]*(MX-MN+1)
    for i in range(MN,MX+1):
        for k in range(MN,MX+1):
            res[i+MN]=res[i+MN]+x(k)*h(i-k)
    return res

def X1(idx):
    if 0<=idx and idx<=9:
        return 1
    else:
        return 0

def H1(idx):
    if 0<=idx and idx<=4:
        return 1
    else:
        return 0

Y=CONV(X1,H1)
print("y[4] :",Y[4+MN]," y[14] :",Y[14+MN])
plt.plot(list(range(MN,MX+1)), Y)
plt.show()

