# Input the two numbers
number1 = float(input("Enter the first number: "))
number2 = float(input("Enter the second number: "))

# Compare the two numbers
if number1 > number2:
    print(f"{number1} is bigger than {number2}")
elif number2 > number1:
    print(f"{number2} is bigger than {number1}")
else:
    print("Both numbers are equal")