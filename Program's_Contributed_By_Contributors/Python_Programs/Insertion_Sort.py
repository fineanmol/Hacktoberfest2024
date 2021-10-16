# Insertion sort
def insertion_Sort(arr):
  for i in range(1, len(arr)):
    key = arr[i]
    j = i - 1
     # Compare key with each element on the left of it until an element smaller than it is found.
    while j >= 0 and key < arr[j]:
      arr[j + 1] = arr[j]
      j = j - 1
    #Place Key element just after the smaller than it.
    arr[j + 1] = key

a=[]
n=int(input("Enter number of elements: "))
for i in range(0,n):
    b=int(input("Enter element: "))
    a.append(b)
insertion_Sort(a)
print('Sorted Array:')
print(a)