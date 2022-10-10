# Python implementation
def add(a, b):
	# for loop will start from 1 and move till the value of second number ,
	# first number(a) is incremented in for loop
	for i in range(1, b + 1):
		a = a + 1
	return a


# driver code
# first number is 10 and second number is 32 , for loop
# will start from 1 and move till 32 and the value of a
# is incremented 32 times which will give us the total
# sum of two numbers
a = add(10, 32)
print(a)


