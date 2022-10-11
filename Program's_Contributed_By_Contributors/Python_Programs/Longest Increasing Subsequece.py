# Dynamic programming Python implementation of LIS problem

 

# lis returns length of the longest increasing subsequence

# in arr of size n

def lis(arr):

    n = len(arr)

 

    # Declare the list (array) for LIS and initialize LIS

    # values for all indexes

    lis = [1]*n

    for i in range (1, n):

        for j in range(0, i):

            if arr[i] > arr[j] and lis[i]< lis[j] + 1 :

                lis[i] = lis[j]+1



    maximum = 0


    for i in range(n):

        maximum = max(maximum, lis[i])

 

    return maximum


arr = [10, 22, 9, 33, 21, 50, 41, 60]

print "Length of lis is", lis(arr)
