# Program to check if a number is neon number or not

num = int(input("Enter a number \n"))
sqr = num*num #square of num
sumOfDigit = 0

#calculating sum of digits of sqr
while sqr>0:
    sumOfDigit =sumOfDigit + sqr%10
    sqr = sqr//10

if (num == sumOfDigit):
    print("Neon Number \n")
else:
    print("Not a Neon Number \n")
