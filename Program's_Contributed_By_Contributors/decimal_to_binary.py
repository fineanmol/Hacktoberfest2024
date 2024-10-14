
# Convert a decimal number to binary using concept of "Recursion":
def decimal_to_binary(num):
    if num == 0:
        return ""
    else:
        return decimal_to_binary(num // 2) + str(num % 2)

# Example usage
decimal_number = 42
binary_number = decimal_to_binary(decimal_number)
if binary_number == "":
    binary_number = "0"  # Handle case for zero
print(f"The binary representation of {decimal_number} is {binary_number}.")
