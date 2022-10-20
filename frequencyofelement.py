# Python program to count the frequency of
# elements in a list using a dictionary

def CountFrequency(my_list):
	
	# Creating an empty dictionary
	freq = {}
	for items in my_list:
		freq[items] = my_list.count(items)
	
	for key, value in freq.items():
		print ("% d : % d"%(key, value))

# Driver function
if __name__ == "__main__":
	my_list =[1, 1, 1, 5, 5, 3, 1, 3, 3, 1, 4, 4, 4, 2, 2, 2, 2]
	CountFrequency(my_list)
