def ceilSearch(arr, low, high, x):
 
    # If x is smaller than or equal to first element,
    # then return the first element */
    if x <= arr[low]:
        return low
 
    # Otherwise, linearly search for ceil value */
    i = low
    for i in range(high):
        if arr[i] == x:
            return i
 
        # if x lies between arr[i] and arr[i+1] including
        # arr[i+1], then return arr[i+1] */
        if arr[i] < x and arr[i+1] >= x:
            return i+1
         
    # If we reach here then x is greater than the last element
    # of the array,  return -1 in this case */
    return -1
 
# Driver program to check above functions */
arr = [1, 2, 8, 10, 10, 12, 19]
n = len(arr)
x = 3
index = ceilSearch(arr, 0, n-1, x);
 
if index == -1:
    print ("Ceiling of %d doesn't exist in array "% x)
else:
    print ("ceiling of %d is %d"%(x, arr[index]))
