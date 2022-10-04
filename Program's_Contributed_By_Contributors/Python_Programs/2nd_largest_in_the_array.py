lst = []
 
n = int(input("Enter number of elements : "))
 
for i in range(0, n):
    ele = int(input("Enter number: "))
 
    lst.append(ele)

def print2largest(arr, arr_size):
  if (arr_size < 2):  
    print(" Invalid Input ")
    return
  
  arr.sort
  
  for i in range(arr_size-2, -1, -1):
  
    if (arr[i] != arr[arr_size - 1]):
     
      print("The second largest element is",
            arr[i])
      return
  
  print("There is no second largest element")

n = len(lst)
print2largest(lst, n)