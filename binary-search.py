# Python 3 program for recursive binary search.
#It's designed to find a number in a list named arr
# Modifications needed for the older Python 2 are found in comments.

# Returns index of x in arr if present, else -1
#Define 'arr' (list of numbers), 'low' (lowest number for search range), 'high' (highest number for search range), 'x' (number to be searched for)
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
arr = [ 2, 3, 4, 10, 40 ]
x = 10

# Function call
result = binary_search(arr, 0, len(arr)-1, x)
# Print the message if the result have been found or not been found
if result != -1:
	print("Element is present at index", str(result))
else:
	print("Element is not present in array")
