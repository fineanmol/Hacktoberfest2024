#return factorical for whole numbers as int
#return ValueError for negative numbers
def factorial(n):
    if n >= 0:
        if n == 1 or n == 0:
            return 1
        else:
            return n*factorial(n-1)
    else:
        raise ValueError
