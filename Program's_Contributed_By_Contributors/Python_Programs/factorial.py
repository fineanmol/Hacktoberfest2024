def factorial(num):
    return 1 if (num < 2) else num * factorial(num - 1)


fact = factorial(5)
print(fact)
