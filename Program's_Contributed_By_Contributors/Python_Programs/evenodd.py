# Function to check if a number is odd or even
def check_odd_even(number):
    if number % 2 == 0:
        return f"{number} is Even"
    else:
        return f"{number} is Odd"

# Input from user
number = int(input("Enter a number: "))

# Output the result
print(check_odd_even(number))
