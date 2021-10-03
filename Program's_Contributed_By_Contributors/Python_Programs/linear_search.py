def linear_search(arr, n, x):
    for i in range(0, n):
        if (arr[i] == x):
            return i
    return -1


## Testing
arr = [2, 4, 6, 8, 3, 6, 9]
result = linear_search(arr, len(arr), 3)
if(result == -1):
    print("Element is not present in array")
else:
    print(f"Element is present at index: {result}")
