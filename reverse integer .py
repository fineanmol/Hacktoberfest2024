def reverse_integer(x):
    if x >= 0:
        result = int(str(x)[::-1])
    else:
        result = -int(str(-x)[::-1])
    return result

# Example usage
x = 123
print(reverse_integer(x))  # Output: 321
