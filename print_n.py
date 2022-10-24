def print1ToN(n):
    if n <= 1:
        return print(1, end = ' ')
    print1ToN(n - 1)
    print(n, end = ' ')

def printNto1(n):
    if n <= 1:
        return print(1)
    print(n, end = ' ')
    return printNto1(n - 1)

if __name__ == '__main__':
    n = int(input('Enter Input : '))
    print1ToN(n)
    printNto1(n)