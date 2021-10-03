def k_smallest(arr, k):
    arr.sort()
    return arr[k-1]


## Testing
arr = [2, 4, 6, 8, 3, 6, 9]
result = k_smallest(arr, 3)
print (f"k smallest item is: {result}")
