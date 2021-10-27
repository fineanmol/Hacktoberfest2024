N = int(input())
n = []
b = []
n1,n2 = 0,1
while n2<N:
        if n1 != n2:
            n.append(n2)
        n1, n2 = n2, n1+n2

print(n)