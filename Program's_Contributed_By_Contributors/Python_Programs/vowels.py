# Python program to accept the strings
# which contains all the vowels

# Function for check if string
# is accepted or not
def check(string) :

	string = string.lower()

	# set() function convert "aeiou"
	# string into set of characters
	# i.e.vowels = {'a', 'e', 'i', 'o', 'u'}
	vowels = set("aeiou")

	# set() function convert empty
	# dictionary into empty set
	s = set({})

	# looping through each
	# character of the string
	for char in string :

		# Check for the character is present inside
		# the vowels set or not. If present, then
		# add into the set s by using add method
		if char in vowels :
			s.add(char)
		else:
			pass
			
	# check the length of set s equal to length
	# of vowels set or not. If equal, string is
	# accepted otherwise not
	if len(s) == len(vowels) :
		print("Accepted")
	else :
		print("Not Accepted")


# Driver code
if __name__ == "__main__" :
	
	string = "SEEquoiaL"

	# calling function
	check(string)
