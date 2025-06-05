# Python3 implementation of the above approach

# Function to print the pattern
def printPattern(n):

	# Loop for rows
	for i in range(1, n + 1):

		# Loop for column
		for j in range(1, 2 * n):

			# For printing equal sides
			# of outer triangle
			if (j == (n - i + 1)
				or j == (n + i - 1)):
				print("* ",end="")

			# For printing equal sides
			# of inner triangle
			elif ((i >= 4 and i <= n - 4)
					and (j == n - i + 4
						or j == n + i - 4)):

				print("* ",end="")

			# For printing base
			# of both triangle
			elif (i == n
					or (i == n - 4
						and j >= n - (n - 2 * 4)
						and j <= n + n - 2 * 4)):

				print("* ", end="")

			# For spacing between the triangle
			else :
				print(" "+" ", end="")

		print()

# Driver Code
N = 9

printPattern(N)

# This code is contributed by mohit kumar 29
