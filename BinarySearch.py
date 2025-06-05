def binary_search(array, target):

  low = 0
  high = len(array) - 1

  while low <= high:
    mid = (low + high) // 2

    if array[mid] == target:
      return mid

    elif array[mid] < target:
      low = mid + 1

    else:
      high = mid - 1

  return -1


# Example case:

array = [1, 3, 5, 7, 9]
target = 5

index = binary_search(array, target)

if index != -1:
  print(f"The target element is found at index {index}.")
else:
  print("The target element is not found in the array.")
