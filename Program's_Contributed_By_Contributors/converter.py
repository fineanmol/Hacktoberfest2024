
# The code convert input decimal into hexa binary and octet

# Function to convert decimal to other number systems
def convert_decimal(number):
    binary = bin(number)   # Convert to binary
    octal = oct(number)    # Convert to octal
    hexadecimal = hex(number)  # Convert to hexadecimal

    # Display results
    print(f"Decimal: {number}")
    print(f"Binary: {binary[2:]}")  # Remove '0b' prefix
    print(f"Octal: {octal[2:]}")    # Remove '0o' prefix
    print(f"Hexadecimal: {hexadecimal[2:].upper()}")  # Remove '0x' prefix and convert to uppercase

# Main program
if __name__ == "__main__":
    try:
        decimal_number = int(input("Enter a decimal number: "))
        convert_decimal(decimal_number)
    except ValueError:
        print("Please enter a valid integer.")
