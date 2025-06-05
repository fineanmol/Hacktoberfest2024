import heapq

def heapify(array, n, i):
  """Converts a subtree into a max heap.
  Args:
    array: The array to heapify.
    n: The size of the heap.
    i: The index of the root node of the subtree.
  """
  largest = i
  left = 2 * i + 1
  right = 2 * i + 2

  if left < n and array[left] > array[largest]:
    largest = left
  if right < n and array[right] > array[largest]:
    largest = right

  if largest != i:
    array[i], array[largest] = array[largest], array[i]
    heapify(array, n, largest)

def heapsort(array):
  """Sorts the array using heap sort.
  Args:
    array: The array to sort.
  """
  n = len(array)

  # Build a max heap.
  for i in range(n // 2 - 1, -1, -1):
    heapify(array, n, i)

  # Extract the elements from the heap one by one.
  for i in range(n - 1, 0, -1):
    array[0], array[i] = array[i], array[0]
    heapify(array, i, 0)

array = [5, 3, 2, 1, 4]
heapsort(array)
print("Sorted array:", array)
