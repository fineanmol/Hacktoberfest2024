import numpy as np
import random

# creating a one dimensional array
arr_sin_dim = np.array([10, 20, 30, 40, 50])
print(f"One dimensional array: {arr_sin_dim}")

# creating a two dimensional array
arr_two_dim = np.array([[23, 56, 77, 89], [33, 78, 11, 33,], [33, 99, 49, 21]])
print(f"Two dimensional array:\n {arr_two_dim}")

# creating array using arange
arr_1 = np.arange(10) # creating a one dimensional array from 0-9
print(f"One dimensional array: {arr_1}")  

arr_2 = np.arange(1, 31).reshape(3, 10) # creating a two dimensional array with shape(3, 10)
print(f"Two dimensional array:\n {arr_2}")

# find the dimesion of the array with ndim 
print("Dimension of arr_2:")
print(arr_2.ndim)

# find the total element in the array 
print("Total elements in arr_2:")
print(arr_2.size)

# find the shape of the array
print("Shape of arr_2:")
print(arr_2.shape)

# reshape arr_2 array
print("Reshape arr_2 to (5, 6):")
arr_2_reshape = arr_2.reshape((5, 6))
print(arr_2_reshape)

# indexing and slicing
print(f"First element of arr_1 is {arr_1[0]}") # accessing the elements of an array

print(f"first element of arr_2 is {arr_2[0, 0]}") # accessinf the elements of two dimensional array

print(arr_1[3:]) # printing element from 3rd index
print(arr_2[0:2]) # printing rows of arr_2

# creating copy of existing array
arr_1_copy = arr_1.copy()
print(f"Copy of arr_1: {arr_1_copy}")

# Basic array operation:

# creating a ones array and and to existing array

one_array = np.ones(10)
print(arr_1 + one_array) # we can also do more opertion other than addition

# finding sum of an array
print(f"Total sum: {arr_1.sum()}")
print(f"Total sum: {arr_2.sum()}")

# finding sum throughout the axis
print(arr_2.sum(axis=1)) # axis=1 is the sum of rows amd axis=0 is the sum of columns

# multiplying a single element throughout an array
print(arr_2*2) # we can perform any other operation than multiplication

print(f"Maximum element in arr_2 is {arr_2.max()}") # finding maximum element
print(f"Minimum element in arr_2 is {arr_2.min()}") #finding minimum element

# creating ones array
print(np.ones([3,3]))

# creating zeroes array
print(np.zeros([3,3]))

# creating random array
print(np.random.randint(2, 10, (3,3)))

# reversing an exist array
print(np.flip(arr_2))

# converting multidimensional array to one dimesional
print(arr_2.flatten())