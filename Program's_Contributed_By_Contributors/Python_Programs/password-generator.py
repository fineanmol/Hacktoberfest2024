import string
import random


## characters to generate password from
characters = list(string.ascii_letters + string.digits + "!@#$%^&*()")

def generate_random_password():
	## Password length from terminal Input
	length = int(input("Password length: "))

	## randomize Character
	random.shuffle(characters)

	## picking random characters from the list
	password = []
	for i in range(length):
		password.append(random.choice(characters))

	## shuffling the resultant password
	random.shuffle(password)

	## converting the list to string and print it to terminal

	print("".join(password))


## call the function
generate_random_password()