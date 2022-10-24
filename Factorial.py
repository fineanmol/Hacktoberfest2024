def itertative_factorial(n):
    fact=1
    for i in range(2,n+1):
        fact *=i

    return fact


print(itertative_factorial(5))


def recrussion_factorial(n):

    if n==1:
        return n

    else:
        temp=recrussion_factorial(n-1)
        temp*=n
    return temp

print(recrussion_factorial(5))


def recrussion_factorial_sort(n):

    if n==1: return n
    else: return n*recrussion_factorial_sort(n-1)

print(recrussion_factorial_sort(5))