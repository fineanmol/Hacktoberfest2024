#Define a function for sorting using sort() mathod. 
def basic_sort(arr):
  #implementiing thr mathod for sorting.
    arr.sort()
    return arr

#Taking input from user as a List
arr = list(map(int,input().split(" ")))

# printing or calling the function
print(basic_sort(arr))
           
