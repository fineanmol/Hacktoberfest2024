def calculate_median(numbers):
    sorted_numbers = sorted(numbers)
    n = len(sorted_numbers)
    
    if n % 2 == 0:
        # If the list has an even number of elements, average the two middle values.
        middle1 = sorted_numbers[n // 2]
        middle2 = sorted_numbers[n // 2 - 1]
        median = (middle1 + middle2) / 2
    else:
        # If the list has an odd number of elements, the median is the middle value.
        median = sorted_numbers[n // 2]
    
    return median

# Example usage:
numbers = [5, 2, 9, 1, 5, 6]
result = calculate_median(numbers)
print("Median:", result)
