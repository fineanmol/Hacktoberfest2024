def count_ones(arr, low, high):
    if high>=low:
        mid = low + (high-low)//2
        if ((mid == high or arr[mid+1]==0) and (arr[mid]==1)):
            return mid+1

        if arr[mid]==1:
            return count_ones(arr, (mid+1), high)

        return count_ones(arr, low, mid-1)
    return 0


## Testing
arr = [1, 1, 0, 1, 0, 0, 0, 1, 0]
print(f"There are `{count_ones(arr, 0, len(arr)-1)}` 1's in the given array")
