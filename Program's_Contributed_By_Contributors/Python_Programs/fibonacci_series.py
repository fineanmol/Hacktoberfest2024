def generate_fibonacci(n):
    fibonacci_series = [0, 1]  # Initialize the series with the first two Fibonacci numbers

    while len(fibonacci_series) < n:
        next_number = fibonacci_series[-1] + fibonacci_series[-2]
        fibonacci_series.append(next_number)

    return fibonacci_series

# Example usage:
n = 10  # Can this to the number of Fibonacci numbers
fib_series = generate_fibonacci(n)
print(f"Fibonacci series of {n} numbers: {fib_series}")
