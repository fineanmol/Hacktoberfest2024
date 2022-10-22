# Program to check if a number is prime or not

num = 29

flag = False
if num > 1:
    
    for i in range(2, num):
        if (num % i) == 0:
            
            flag = True
           
            break


if flag:
    print(num, "is not a prime number")
else:
    print(num, "is a prime number")
