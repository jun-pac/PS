A=[0,2,2,3,4,5,6,3,3,2]
B=[4,6,7,1,3,4,4,9]

A=sorted(A)
B=sorted(B)

onlyA=[] # Store indices of elements that are only presented in A
onlyB=[] # Store indices of elements that are only presented in A

# Two pointers
curA=0
curB=0

# Two pointer loop for 'unique-guaranteed lists'
while(curA<len(A) and curB<len(B)):
    if curA==len(A):
        onlyB.append(curB)
        curB+=1
    elif curB==len(B):
        onlyA.append(curA)
        curA+=1
    elif(A[curA]==B[curB]):
        curA+=1
        curB+=1
    else:
        if A[curA]<B[curB]:
            onlyA.append(curA)
            curA+=1
        else:
            onlyB.append(curB)
            curB+=1

'''
# Two pointer loop for general lists
while(curA<len(A) and curB<len(B)):
    if curA==len(A):
        onlyB.append(curB)
        last=B[curB]
        while(curB<len(B) and B[curB]==last):
            curB+=1
    elif curB==len(B):
        onlyA.append(curA)
        last=A[curA]
        while(curA<len(A) and A[curA]==last):
            curA+=1
    elif(A[curA]==B[curB]):
        last=A[curA]
        while(curA<len(A) and A[curA]==last):
            curA+=1
        last=B[curB]
        while(curB<len(B) and B[curB]==last):
            curB+=1
    else:
        if A[curA]<B[curB]:
            onlyA.append(curA)
            last=A[curA]
            while(curA<len(A) and A[curA]==last):
                curA+=1
        else:
            onlyB.append(curB)
            last=B[curB]
            while(curB<len(B) and B[curB]==last):
                curB+=1
'''

print("Elements that are only in A : ")
for i in onlyA:
    print(A[i], end=' ')
print()
print("Elements that are only in B : ")
for i in onlyB:
    print(B[i], end=' ')
print()