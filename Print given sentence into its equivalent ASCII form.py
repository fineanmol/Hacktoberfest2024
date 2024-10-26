# Python3 implementation for
# converting a string into it's
# ASCII equivalent sentence

# Function to compute the ASCII
# value of each character one by one
def ASCIISentence( str ):
	
	for i in str:
		print(ord(i), end = '')
	print('\n', end = '')
	
# Driver code
str = "GeeksforGeeks"
print("ASCII Sentence:")
ASCIISentence(str)

# This code is contributed by "Sharad_Bhardwaj".
