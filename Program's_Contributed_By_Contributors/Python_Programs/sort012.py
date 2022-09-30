def sort012(array):
  low=0
  high=len(array)-1
  middle=0
  while middle<=high:
    if array[middle]==0:
      array[low],array[middle]=array[middle],array[low]
      low=low+1
      middle=middle+1
    elif array[middle]==1:
      middle=middle+1
    else:
      array[middle],array[high]=array[high],array[middle]
      high=high-1
  return array

arr=[0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
ans = sort012(arr)
print(ans)