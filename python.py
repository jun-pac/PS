import numpy as np

a=np.array([1,3,4,5,6])
b=np.where(a%2==0)
print(b) #(array([2, 4]),)

print(b[0].shape) # (2,)
b=np.squeeze(b) 
print(b) # [2 4]
print(type(b)) # <class 'numpy.ndarray'>

a=np.array([[1,3,4,5,6],[2,2,2,2,2]])
b=np.where(a%2==0)
print(b) # (array([0, 0, 1, 1, 1, 1, 1]), array([2, 4, 0, 1, 2, 3, 4]))


b=np.where(a%2==0,True,False)
print(b)
'''
[[False False  True False  True]
 [ True  True  True  True  True]]
'''