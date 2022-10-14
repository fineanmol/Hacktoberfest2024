# input three numbers from the user to find the greatest of the three  

num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))
num3 = int(input("Enter third number: "))

#to find greatest of three use conditions


if (num1 >= num2) and (num1 >= num3):
    greatest = num1
elif (num2 >= num3) and (num2 >= num1):
    greatest = num2
else:
    greatest = num3

print("The greatest number of the three numbers is: ", greatest)

#contributed by shivaniBadola
