#return True if the number is prime else return False
def prime(n):
    if n == 1:
        return False
    elif n == 2:
        return True
    elif n > 2:
        for i in range(2, n):
            if n % i == 0:
                return False
                break
            else:
                return True
    else:
        return False
