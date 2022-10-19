n = int(input())
a = 0
b = 1
c = 0
for e in range(n):
    if e == n - 1:
        print(c, end='\n')
    else:
        print(c, end=' ')
        a = b
        b = c
        c = a + b