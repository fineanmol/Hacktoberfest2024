def fibonacci_search(arr, target):
    # Initialize Fibonacci numbers
    fib_m2 = 0  # (m-2)th Fibonacci number
    fib_m1 = 1  # (m-1)th Fibonacci number
    fib_m = fib_m2 + fib_m1  # mth Fibonacci number

    # Find the smallest Fibonacci number greater than or equal to the length of the array
    while fib_m < len(arr):
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1

    # Marks the eliminated range from front
    offset = -1

    # While there are elements to be inspected
    while fib_m > 1:
        # Check if fib_m2 is a valid location
        i = min(offset + fib_m2, len(arr) - 1)

        # If target is greater than the value at index fib_m2, cut the subarray from offset to i
        if arr[i] < target:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i

        # If target is less than the value at index fib_m2, cut the subarray after i+1
        elif arr[i] > target:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1

        # Element found
        else:
            return i

    # Comparing the last element with target
    if fib_m1 and arr[offset + 1] == target:
        return offset + 1

    # Target not found
    return -1

# Test the function
arr = [1, 3, 7, 15, 18, 21, 27, 30]
target = int(input("Enter a number to search: "))
result = fibonacci_search(arr, target)

if result != -1:
    print(f"Element found at index {result}.")
else:
    print("Element not found in the array.")
