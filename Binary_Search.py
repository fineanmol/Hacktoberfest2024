def binary_search(arr,start,end,target):
    mid = (start+end)//2
    if start > end:
        return -1
    if arr[mid] < target:
        return binary_search(arr, mid+1, end, target)
    elif arr[mid] > target:
        return binary_search(arr, start, mid-1, target)
    elif arr[mid] == target:
        return mid
    

arr = [20,30,40,60,80,90]
ans = binary_search(arr,0,len(arr)-1 ,20)
if ans  == -1:
    print("Target Not Found")
else:
    print("Target found at index",ans)
