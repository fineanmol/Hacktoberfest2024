number = int(input("Enter a number (positive integer): "))

def factorial(num):
    result = 1
    for i in range(1, num + 1):
        result *= i
    return result

if number >= 0:
    answer = factorial(number)
    print(f"{number}! = {answer}")
else:
    print(f"{number} is not a positive integer!")
