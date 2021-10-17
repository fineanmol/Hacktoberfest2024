# Recursive Insertion sort 
def insertionSort(arr,n):
   # base case
   if n<=1:
      return
   # Recursive Call
   insertionSort(arr,n-1)
   key = arr[n-1]
   j = n-2
   # Compare key with each element on the left of it until an element smaller than it is found
   while (j>=0 and arr[j]>key):
      arr[j+1] = arr[j]
      j = j-1
   # Place key at after the element just smaller than it.
   arr[j+1]=key
a=[]
n=int(input("Enter number of elements: "))
for i in range(0,n):
    b=int(input("Enter element: "))
    a.append(b)
insertionSort(a,n)
print('Sorted Array:')
print(a)