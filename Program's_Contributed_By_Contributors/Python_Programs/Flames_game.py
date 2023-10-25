# function for removing common characters with their respective occurrences


def remove_match_char(list1, list2):

	for i in range(len(list1)):
		for j in range(len(list2)):

			# if common character is found then remove that character and return list of concatenated list with True Flag
			if list1[i] == list2[j]:
				c = list1[i]

				# remove character from the list
				list1.remove(c)
				list2.remove(c)

				# concatenation of two list elements with *
				# * is act as border mark here
				list3 = list1 + ["*"] + list2

				# return the concatenated list with True flag
				return [list3, True]

	# no common characters is found
	# return the concatenated list with False flag
	list3 = list1 + ["*"] + list2
	return [list3, False]


# Driver code
if __name__ == "__main__":

	# take first name
	p1 = input("Player 1 name : ")

	# converted all letters into lower case
	p1 = p1.lower()

	# replace any space with empty string
	p1.replace(" ", "")

	# make a list of letters or characters
	p1_list = list(p1)

	# take 2nd name
	p2 = input("Player 2 name : ")
	p2 = p2.lower()
	p2.replace(" ", "")
	p2_list = list(p2)

	# taking a flag as True initially
	proceed = True

	# keep calling remove_match_char function
	# until common characters is found or
	# keep looping until proceed flag is True
	while proceed:

		# function calling and store return value
		ret_list = remove_match_char(p1_list, p2_list)

		# take out concatenated list from return list
		con_list = ret_list[0]

		# take out flag value from return list
		proceed = ret_list[1]

		# find the index of "*" / border mark
		star_index = con_list.index("*")

		# list slicing perform

		# all characters before * store in p1_list
		p1_list = con_list[: star_index]

		# all characters after * store in p2_list
		p2_list = con_list[star_index + 1:]

	# count total remaining characters
	count = len(p1_list) + len(p2_list)

	# list of FLAMES acronym
	result = ["Friends", "Love", "Affection", "Marriage", "Enemy", "Siblings"]

	# keep looping until only one item
	# is not remaining in the result list
	while len(result) > 1:

		# store that index value from
		# where we have to perform slicing.
		split_index = (count % len(result) - 1)

		# this steps is done for performing
		# anticlock-wise circular fashion counting.
		if split_index >= 0:

			# list slicing
			right = result[split_index + 1:]
			left = result[: split_index]

			# list concatenation
			result = right + left

		else:
			result = result[: len(result) - 1]

	# print final result
	print("Relationship status :", result[0])
