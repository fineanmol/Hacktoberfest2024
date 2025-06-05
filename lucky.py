# Python3 program to check for lucky number

# Returns 1 if n is a lucky number
# otherwise returns 0


def isLucky(n):

	# Function attribute will act
	# as static variable

	if isLucky.counter > n:
		return 1
	if n % isLucky.counter == 0:
		return 0

	# calculate next position of input no.
	# Variable "next_position" is just for
	# readability of the program we can
	# remove it and update in "n" only
	next_position = n - (n/isLucky.counter)

	isLucky.counter = isLucky.counter + 1

	return isLucky(next_position)


# Driver Code

isLucky.counter = 2 # Acts as static variable
x = 5

# Function call
if isLucky(x):
	print x, "is a Lucky number"
else:
	print x, "is not a Lucky number"

# Contributed by Harshit Agrawal
