# Function to convert decimal to other number systems
def decimal_to_other(number):
    print(f"Decimal to Binary: {bin(number)}")
    print(f"Decimal to Octal: {oct(number)}")
    print(f"Decimal to Hexadecimal: {hex(number)}")

# Function to convert binary to decimal
def binary_to_decimal(binary):
    decimal = int(binary, 2)
    print(f"Binary to Decimal: {decimal}")
    decimal_to_other(decimal)

# Function to convert octal to decimal
def octal_to_decimal(octal):
    decimal = int(octal, 8)
    print(f"Octal to Decimal: {decimal}")
    decimal_to_other(decimal)

# Function to convert hexadecimal to decimal
def hex_to_decimal(hexadecimal):
    decimal = int(hexadecimal, 16)
    print(f"Hexadecimal to Decimal: {decimal}")
    decimal_to_other(decimal)

# Main program to demonstrate conversions
if __name__ == "__main__":
    number = 50
    print(f"Number: {number}")
    decimal_to_other(number)

    binary_number = '110010'
    print(f"\nBinary Number: {binary_number}")
    binary_to_decimal(binary_number)

    octal_number = '62'
    print(f"\nOctal Number: {octal_number}")
    octal_to_decimal(octal_number)

    hex_number = '32'
    print(f"\nHexadecimal Number: {hex_number}")
    hex_to_decimal(hex_number)
