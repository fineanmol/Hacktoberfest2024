#fibonacci series

n = int(input("Enter how many series you want:"))
a = 0
b = 1
for i in range(0,n):
    c = a + b
    print(c,end=" ") 
    a = b
    b = c