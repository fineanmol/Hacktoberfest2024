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
	elif arr[mid] < x:
		return binary_search(arr, mid + 1, high, x)

	else:
	# Element is not present in the array
		return -1


if __name__ == "__main__":

	preference = input("Do you want to provide a cutom array? [Y] or [N] :")
	if preference.lower() == "y" or preference.lower() =="n":
		if preference.lower() == "y":		
			# Test custom input array
			arr=[]
			n = int(input("Enter the number of elements in an array: "))
			print("Please provide the elements in sorted order")
			for i in range(1, n+1):
				arr.append(int(input(f"Enter the term {i}: ")))
			item = int(input("Enter the element you want to search: "))
		elif preference.lower() == "n":
			# Test array Default
			arr = [2, 3, 4, 10, 40]
			item = 10
		
		# Function call
		result = binary_search(sorted(arr), 0, len(arr)-1, item)
		print(f"The array is: {arr}")
		print(f"The searched term is: {item}")
		if result != -1:
			print("Element is present at index", str(result+2))
			print("If the answer is not correct, please provide an array in ascending order")
		else:
			print("Element is not present in array")
	else:
		print("Please select a correct preference")