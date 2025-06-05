def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    return a / b


print("Select operation.")
print("01. Add")
print("02. Subtract")
print("03. Multiply")
print("04. Divide")

while True:
    
    choice = input("Enter operation (01 / 02 / 03 / 04): ")

    if choice in ('1', '2', '3', '4'):
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))

        if choice == '1':
            print(num1, "+", num2, "=", add(num1, num2))

        elif choice == '2':
            print(num1, "-", num2, "=", subtract(num1, num2))

        elif choice == '3':
            print(num1, "*", num2, "=", multiply(num1, num2))

        elif choice == '4':
            print(num1, "/", num2, "=", divide(num1, num2))
        
       
        next_calculation = input(" next calculation? (yes/no): ")
        if next_calculation == "no":
          break
    
    else:
        print("Thank You")
