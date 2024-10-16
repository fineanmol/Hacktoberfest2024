# Function to convert decimal to other number systems
def convert_number(decimal_num):
    binary = bin(decimal_num)  # Convert to binary
    octal = oct(decimal_num)   # Convert to octal
    hexadecimal = hex(decimal_num)  # Convert to hexadecimal

    # Display the results
    print(f"Decimal: {decimal_num}")
    print(f"Binary: {binary}")
    print(f"Octal: {octal}")
    print(f"Hexadecimal: {hexadecimal}")

# Input from the user
try:
    decimal_num = int(input("Enter a decimal number: "))
    convert_number(decimal_num)
except ValueError:
    print("Please enter a valid integer.")
