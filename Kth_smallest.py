# python program for the above approach
LLONG_MAX = 9223372036854775807
LLONG_MIN = -9223372036854775807

# Function to check if count of elements
# greater than req in product array are
# more than K or not
def check(req, posA, posB, negA, negB, K):

	# Stores the count of numbers less
	# than or equal to req
	cnt = 0

	# Case with both elements of A[] and
	# B[] are negative
	first = 0
	second = len(negB) - 1

	# Count number of pairs formed from
	# array A[] and B[] with both elements
	# negative and there product <= req
	while (first < len(negA)):
		while (second >= 0 and negA[first] * negB[second] <= req):
			second -= 1

		# Update cnt
		cnt += len(negB) - second - 1
		first += 1

	# Case with both elements of A[] and
	# B[] are positive
	first = 0
	second = len(posB) - 1

	# Count number of pairs formed from
	# array A[] and B[] with both elements
	# positive and there product <= req
	while (first < len(posA)):
		while (second >= 0 and posA[first] * posB[second] > req):
			second -= 1

		# Update cnt
		cnt += second + 1
		first += 1

	# Case with elements of A[] and B[]
	# as positive and negative respectively
	first = len(posA) - 1
	second = len(negB) - 1

	# Count number of pairs formed from
	# +ve integers of A[] and -ve integer
	# of array B[] product <= req
	while (second >= 0):
		while (first >= 0 and posA[first] * negB[second] <= req):
			first -= 1

		# Update cnt
		cnt += len(posA) - first - 1
		second -= 1

	# Case with elements of A[] and B[]
	# as negative and positive respectively
	first = len(negA) - 1
	second = len(posB) - 1

	# Count number of pairs formed from
	# -ve and +ve integers from A[] and
	# B[] with product <= req
	for first in range(first, -1, -1):
		while (second >= 0 and negA[first] * posB[second] <= req):
			second -= 1

		# Update cnt
		cnt += len(posB) - second - 1

	# Return Answer
	return (cnt >= K)


# Function to find the Kth smallest
# number in array formed by product of
# any two elements from A[] and B[]
def kthSmallestProduct(A, B, K):

	posA = []
	negA = []
	posB = []
	negB = []

	# Loop to iterate array A[]
	for it in A:
		if (it >= 0):
			posA.append(it)
		else:
			negA.append(it)

		# Loop to iterate array B[]
	for it in B:
		if (it >= 0):
			posB.append(it)
		else:
			negB.append(it)

		# Stores the lower and upper bounds
		# of the binary search
	l = LLONG_MIN
	r = LLONG_MAX

	# Stores the final answer
	ans = 0

	# Find the kth smallest integer
	# using binary search
	while (l <= r):

		# Stores the mid
		mid = (l + r) // 2

		# If the number of elements
		# greater than mid in product
		# array are more than K
		if (check(mid, posA, posB, negA, negB, K)):
			ans = mid
			r = mid - 1
		else:
			l = mid + 1

		# Return answer
	return ans


# Driver Code
if __name__ == "__main__":

	A = [-4, -2, 0, 3]
	B = [1, 10]
	K = 7

	print(kthSmallestProduct(A, B, K))

	# This code is contributed by rakeshsahni
