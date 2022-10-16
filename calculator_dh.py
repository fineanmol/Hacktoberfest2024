# Program make a simple calculator

# This function adds two numbers
def add_num(x, y):
    return x + y

# This function subtracts two numbers
def subtract_num(x, y):
    return x - y

# This function multiplies two numbers
def multiply_num(x, y):
    return x * y

# This function divides two numbers
def divide_num(x, y):
    return x / y


print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")

while True:
    # take input from the user
    choice = input("Enter choice(1/2/3/4): ")

    # check if choice is one of the four options
    if choice in ('1', '2', '3', '4'):
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))

        if choice == '1':
            print(num1, "+", num2, "=", add_num(num1, num2))

        elif choice == '2':
            print(num1, "-", num2, "=", subtract_num(num1, num2))

        elif choice == '3':
            print(num1, "*", num2, "=", multiply_num(num1, num2))

        elif choice == '4':
            print(num1, "/", num2, "=", divide_num(num1, num2))
        
        # check if user wants another calculation
        # break the while loop if answer is no
        next_calculation = input("Let's do next calculation? (yes/no): ")
        if next_calculation == "no":
          break
    
    else:
        print("Invalid Input")