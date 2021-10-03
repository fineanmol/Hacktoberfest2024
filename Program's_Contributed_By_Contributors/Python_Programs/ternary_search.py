def ternary_search(arr, l, r, x):
    if (r >= l):
        mid1 = l + (r - l)//3
        mid2 = mid1 + (r - l)//3

        if arr[mid1] == x:
            return mid1

        if arr[mid2] == x:
            return mid2

        if arr[mid1] > x:
            return ternary_search(arr, l, mid1-1, x)

        if arr[mid2] < x:
            return ternary_search(arr, mid2+1, r, x)

        return ternary_search(arr, mid1+1, mid2-1, x)

    return -1


## Testing
arr = [2, 4, 6, 8, 3, 6, 9]
result = ternary_search(arr, 0, len(arr)-1, 3)
if result == -1:
    print("Element is not present in array")
else:
    print (f"Element is present at index: {result}")
