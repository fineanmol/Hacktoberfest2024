def sort012(arr):
  low=0
  high=len(arr)-1
  mid=0
  while mid<=high:
    if arr[mid]==0:
      arr[low],arr[mid]=arr[mid],arr[low]
      low=low+1
      mid=mid+1
    elif arr[mid]==1:
      mid=mid+1
    else:
      arr[mid],arr[high]=arr[high],arr[mid]
      high=high-1
  return arr

arr=[0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
ans = sort012(arr)
print(ans)