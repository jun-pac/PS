MX=20
x=[0,0,0,1,2,3,2,2,1,0,0,0,0,0,0]+[0]*(MX-15)
y=[0]*MX

for i in range(2,MX):
    y[i]=-2*y[i-1]+x[i]+2*x[i-2]
for i in range(MX):
    print("X :",i-5,"Y :",y[i])


