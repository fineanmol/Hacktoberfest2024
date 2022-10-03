# Program to create a calculator using Python that performs basic mathematical operations like addition, subtraction,
# multiplication, division


print("Operation you want to perform :\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division")
option = int(input("Input a number 1, 2, 3, 4 "))

print("Enter the two numbers")
a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))

if option==1:
  print("{} + {} = {}".format(a, b, a+b))

elif option==2:
  print("{} - {} = {}".format(a, b, a-b))

elif option==3:
  print("{} * {} = {}".format(a, b, a*b))

else:
  print("{} / {} = {}".format(a, b, a/b))
