# Python 3 code to find sum
# of elements in given array


def _sum(arr):

	# initialize a variable
	# to store the sum
	# while iterating through
	# the array later
	sum = 0

	# iterate through the array
	# and add each element to the sum variable
	# one at a time
	for i in arr:
		sum = sum + i

	return(sum)


# main function
if __name__ == "__main__":
	# input values to list
	arr = [12, 3, 4, 15]

	# calculating length of array
	n = len(arr)
	# calling function ans store the sum in ans
	ans = _sum(arr)
	# display sum
	print('Sum of the array is ', ans)
