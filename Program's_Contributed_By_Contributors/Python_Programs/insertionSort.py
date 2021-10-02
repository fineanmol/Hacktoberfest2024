def insertionSort(arr): 
  
    # traversing through the length of whole array
    for i in range(1, len(arr)): 
        key = arr[i] 
        j = i-1
        while j >=0 and key < arr[j] :
                #comparing current element with its previous one, and if previous one is greater
                #move it one place ahead of current
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key 
  
  
# Driver test case
arr = [12, 11, 13, 5, 6] 
insertionSort(arr) 
print ("Sorted array is:") 
for i in range(len(arr)): 
    print ("%d" %arr[i]) 
