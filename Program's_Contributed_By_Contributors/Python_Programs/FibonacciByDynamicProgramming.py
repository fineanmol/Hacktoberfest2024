
def FibonacciByDynamicProgramming(n):

    # Initializing the array with the first two Fibonacci numbers
    fib_array = [0, 1]

    # Handling the base case efficiently
    if n <= 2:
        return fib_array[n - 1]

    # Generating the next Fibonacci numbers up to the nth number
    for i in range(n - 2):
        fib_array += [fib_array[-1] + fib_array[-2]]

    return fib_array[-1]

# Enter the range limit for the series
num = int(input("Enter the range limit for the Fibonacci series: "))

print("The Fibonacci Series: ")
for i in range(1, num + 1):
    print("%d" % FibonacciByDynamicProgramming(i))
