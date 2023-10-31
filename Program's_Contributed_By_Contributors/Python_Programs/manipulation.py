a = []
num = int(input("Enter the number of elements in The list : "))
for i in range(num):
    b=int(input())
    a.append(b)
print("List read successfully :")

a.sort()

print("List sorted is :")
for i in a:
    print(i)

print(a[1:5])

data = input("Enter the data to be manipulated : ")

print(data.upper())

print(data.lower())


