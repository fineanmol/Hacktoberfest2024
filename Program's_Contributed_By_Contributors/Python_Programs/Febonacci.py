
# Author : Adarsh Gupta

# Python3 : Concept : To find the febonacci series of nth term using recursion

# GITHUB : https://github.com/adarshaddee



def feboRecur(n):
    if n == 0 or n == 1:
        return n
        
    elif n<0:
        return "Not possible"

    else:
        return feboRecur(n-1) + feboRecur(n-2)
        
num = int(input("Enter your febonacci series number: "))

print("\nYour febonacci series answer is",feboRecur(num))










# This may give an Error because of recursion
