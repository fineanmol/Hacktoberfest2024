def prime_number(n):
    c = 0
    for x in range(2, n):
        if n % x == 0:
            c = c + 1
    return c


n = int(input("Enter a number = "))
if prime_number(n) == 0:
    print("Prime number.")
else:
    print("Not prime number.")
