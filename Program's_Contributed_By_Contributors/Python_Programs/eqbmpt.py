#Equilibrium Point

#This problem is part of GFG SDE Sheet. Click here to view more.
#Given an array A of n positive numbers. The task is to find the first Equilibrium Point in an array. Equilibrium Point in an array is a #position such that the sum of elements before it is equal to the sum of elements after it.

#Note: Retun the index of Equilibrium point. (1-based index)

#Example 1:

#Input: n = 5 A[] = {1,3,5,2,2} Output: 3 Explanation:
#equilibrium point is at position 3 as elements before it (1+3) = elements after it (2+2).

# Python program to find the equilibrium
# index of an array

# Function to find the equilibrium index


def equilibrium(arr):

	# finding the sum of whole array
	total_sum = sum(arr)
	leftsum = 0
	for i, num in enumerate(arr):

		# total_sum is now right sum
		# for index i
		total_sum -= num

		if leftsum == total_sum:
			return i
		leftsum += num

	# If no equilibrium index found,
	# then return -1
	return -1


# Driver code
if __name__ == "__main__":
	arr = [-7, 1, 5, 2, -4, 3, 0]

	# Function call
	print('First equilibrium index is ',
		equilibrium(arr))
#First equilibrium index is  3
