def sort012(array):
  low=0
  high=len(array)-1
  mid=0
  while mid<=high:
    if array[mid]==0:
      array[low],array[mid]=array[mid],array[low]
      low=low+1
      mid=mid+1
    elif array[mid]==1:
      mid=mid+1
    else:
      array[mid],array[high]=array[high],array[mid]
      high=high-1
  return array

arr=[0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
ans = sort012(arr)
print(ans)