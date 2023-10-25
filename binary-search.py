

# Python 3 program for recursive binary search.
# Modifications needed for the older Python 2 are found in comments.

# Returns index of x in arr if present, else -1
def binary_search(arr, low, high, x):

	# Check base case
	if high >= low:

		mid = (high + low) // 2

		# If element is present at the middle itself
		if arr[mid] == x:
			return mid

		# If element is smaller than mid, then it can only
		# be present in left subarray
		elif arr[mid] > x:
			return binary_search(arr, low, mid - 1, x)

		# Else the element can only be present in right subarray
		else:
			return binary_search(arr, mid + 1, high, x)

	else:
		# Element is not present in the array
		return -1

# Test array
# arr = [ 2, 3, 4, 10, 40 ]
# x = 10

#Enter the array to perform biinary search
try :
    a=[]
    n=int(input("Enter Number of elements in array in sorted order:"))
    for i in range(0,n):
       l=int(input())
       a.append(l)
    print(a)
    
    x=int(input("Enter a Number to search in array:"))
    print(x)
    
    # Function call
    result = binary_search(a, 0, len(a)-1, x)
    
    if result != -1:
    	print("Element is present at index", str(result))
    else:
    	print("Element is not present in array")
except:
    print("Data is incomplete !!! please enter array and number to search completely  ")
    


