#return lcm of 2 numbers as int
def lcm(a, b):
    def gcd(a, b):
        if a == 0:
            return b
        elif b == 0:
            return a
        elif a == b:
            return a
        elif a > b:
            return gcd(a-b, b)
        else:
            return gcd(a, b-a)

    lcm = (a*b)//gcd(a, b)
    return lcm
