# Exception Handling
a=input("Enter a number:")
b=input("Enter a number:")

try:
    print(int(a)+int(b))
except Exception as e:
    print(e)
print("done")