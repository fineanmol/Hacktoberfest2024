# NUMPY ARRAYS
import numpy as np
a = np.array([1,2,3,4])
np.empty(2)
np.arange(4)
np.linspace(0,10 , num =5)
np.sort([1,4,2,3,6,5])
a.reshape(2,2)
# Creating 2D array
b = np.array([[1,2,3,4],[5,6,7,8]])
b
# Creating 3D array
c = np.array([[[1,2,3,4],[5,6,7,8]],[[1,2,3,4],[5,6,7,8]]])
c
Initial PlaceHolder in Numpy Array
np.zeros(5,dtype="int64")
np.ones((5,4),dtype="int32")
np.zeros((5,2),dtype=int)
np.full((5,2),5)
# Creating Identity matrix
np.eye(5,dtype=int)
# Create a Numpy array with random values
np.random.random((5,3))
# Create a Numpy array with random values in a range
np.random.randint(0,10,(3,3))
# Array with evenly spaced numbers
np.linspace(0,10,5)

# array of evenly spaced numbers over a specified space
np.arange(0,10,2)
# convert list to numpy array
list = [1,2,3,4]
np.array(list)
# convert tuple to numpy array
tuple = (1,2,3,4)
np.array(tuple)

Analysing a Numpy array
c = np.random.randint(0,10,(5,5))
c
# Shape of array
c.shape
# Dimension of array
c.ndim
# Size of array
c.size

# Data type of array
c.dtype
Mathematical operations on a np array
a = np.random.randint(0,10,(5,5))
b = np.random.randint(10,20,(5,5))
print(a)
print(b)
# Addition of two arrays
print(a+b)
# Addition of two arrays
print(np.add(a,b))
# Subtraction of two arrays
print(a-b)

# Subtraction of two arrays
print(np.subtract(a,b))
# Multiplication of two arrays
print(a*b)

# Multiplication of two arrays
print(np.multiply(a,b))
# Division of two arrays
print(a/b)

# Division of two arrays
print(np.divide(a,b))

Array Manipulation
array = np.random.randint(0,10,(5,5))
array

# transpose of array
array.T
# transpose of array
array.transpose()
# reshape of array
array.reshape(25,1)
