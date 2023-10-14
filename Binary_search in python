def binary_search(arr, target):
    start = 0
    end = len(arr) - 1

    while start <= end:
        mid = (start + end) // 2
        current = arr[mid]

        if current == target:
            return mid
        if current > target:
            end = mid - 1
        else:
            start = mid + 1

    return -1 

arr = [20,30,40,60,80,90]
ans = binary_search(arr,80)
if ans  == -1:
    print("Target Not Found")
else:
    print("Target found at index",ans)
