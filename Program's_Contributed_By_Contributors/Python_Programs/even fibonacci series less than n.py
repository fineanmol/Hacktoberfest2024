N = int(input())
n = []
b = []
n1,n2 = 0,1
while n2<N:
        if n1 != n2:
            n.append(n2)
        n1, n2 = n2, n1+n2
for i in range(len(n)):
        a = n[i]
        if a % 2 == 0:
            b.append(a)
print(b)