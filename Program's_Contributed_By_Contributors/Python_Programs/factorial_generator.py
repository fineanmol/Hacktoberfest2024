# function to generate the factorial of a number (using recursion)
def factorial(n):
    if n == 0: return 1
    return n*factorial(n-1)