def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

# Input: Ask the user for a number
try:
    num = int(input("Enter a non-negative integer: "))

    if num < 0:
        print("Factorial is not defined for negative numbers.")
    else:
        result = factorial(num)
        print(f"The factorial of {num} is {result}")
except ValueError:
    print("Invalid input. Please enter a non-negative integer.")
