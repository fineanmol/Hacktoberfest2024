#WAP to check whether a number is even or odd without using modulus(%) operator.

num = int(input("Enter a number "))
bnum = bin(num)
print(bnum)
rem = num & 1    #only int or str type can be used with bit wise "and(&)" opretor
if (rem == 0):
    print("EVEN NUMBER")
else:
    print("ODD NUMBER")
