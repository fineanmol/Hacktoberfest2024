#---------------------CREATE VARIABLES------------------------
Operator = ""
Num1 = 0
Num2 = 0
while True:
#--------------------GET VALUES FROM THE USER--------------------
    print("Enter the operator from the above list : \n","\t Addition = + \n","\t Substraction = - \n","\t Multiplication = * \n", "\t Division = / \n","\t Power = ** \n")
    Num1 = int(input("Enter the number 1 : "))
    Num2 = int(input("Enter the number 2 : "))
    Operator = str(input("Enter the Operator  : " ))
#----------------------SIMPLE FUNCTIONS---------------------------
    def Addition (Num1,Num2):
        "This for the addition of two numbers"
        Ans = Num1+Num2
        return Ans
    def Substraction (Num1,Num2):
        "This for the substraaction of two numbers"
        Ans = Num1-Num2
        return Ans

    def Multiplication(Num1,Num2):
        "This for the multiplication of two numbers"
        Ans = Num1*Num2
        return Ans

    def Division (Num1,Num2):
        "This for the division of two numbers"
        Ans = Num1/Num2
        return Ans

    def Power (Num1,Num2):
        "This for the power of two numbers"
        Ans = Num1**Num2
        return Ans

#----------------------PROCESS AND DISPLAY------------------------
    if Operator == '+':
        print ("The addition of the two numbers are :", Addition(Num1,Num2))
    elif Operator == '-':
        print ("The substraction of the two numbers are :", Substraction(Num1,Num2))
    elif Operator == '*':
        print ("The multiplication of the two numbers are :", Multiplication(Num1,Num2))
    elif Operator == '/':
        print ("The division of the two numbers are :", Division(Num1,Num2))
    elif Operator == '**':
        print ("The power of the two numbers are :", Power(Num1,Num2))
    else:
        print("Please enter the correct operator and opperands")

    


