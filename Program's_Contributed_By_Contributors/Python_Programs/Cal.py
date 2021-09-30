class Calculator:
    def addition(self,x,y):
        return x+y
    def subtraction(self,x,y):
        return x-y
    def multiplication(self,x,y):
        return x*y
    def division(self,x,y):
        if y==0:
            return "not valid (Denominator is 0)"
        return x/y
c=Calculator()
flag="Y"
while flag=="Y" or flag=="y":
    print("1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n")
    choice=int(input("Enter the operator from above: "))
    a,b=input("Enter two operands seperated by space : ").split()
    a=int(a)
    b=int(b)
    if choice==1:
        print(f"Sum is {c.addition(a,b)}")
    elif choice==2:
        print(f"Difference is {c.subtraction(a,b)}")
    elif choice==3:
        print(f"Product is {c.multiplication(a,b)}")
    elif choice==4:
        print(f"Division is {c.division(a,b)}")
    else:
        print("Please enter correct input")
    flag=input("\nTo calculate again enter 'Y' or enter any key to exit : ")