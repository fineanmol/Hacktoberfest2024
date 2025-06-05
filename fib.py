x = []
a = int(input("enter an integer_ "))
b = 0
c = 1
for i in range(a):
    d = b + c
    b, c = c, d
    x.append(b)
print(x)