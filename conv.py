def convert_number(decimal_number):
    # Convert to binary, octal, and hexadecimal
    binary_rep = bin(decimal_number)
    octal_rep = oct(decimal_number)
    hex_rep = hex(decimal_number)

    # Display the results
    print(f"Decimal: {decimal_number}")
    print(f"Binary: {binary_rep}")
    print(f"Octal: {octal_rep}")
    print(f"Hexadecimal: {hex_rep}")

# Input from the user
try:
    decimal_input = int(input("Enter a decimal number: "))
    convert_number(decimal_input)
except ValueError:
    print("Please enter a valid decimal number.")
