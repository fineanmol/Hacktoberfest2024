Program to check if a number is prime or not

num = 29

# To take input from the user
#num = int(input("Enter a number: "))

# define a flag variable
flag = False

# prime numbers are greater than 1
if num > 1:
    # check for factors
    for i in range(2, num):
        if (num % i) == 0:
            # if factor is found, set flag to True
            flag = True
            # break out of loop
            break

# check if flag is True
if flag:
    print(num, "is not a prime number")
else:
    print(num, "is a prime number")
Run Code
In this program, we have checked if num is prime or not. Numbers less than or equal to 1 are not prime numbers. Hence, we only proceed if the num is greater than 1.

We check if num is exactly divisible by any number from 2 to num - 1. If we find a factor in that range, the number is not prime, so we set flag to True and break out of the loop.

Outside the loop, we check if flag is True or False.

If it is True, num is not a prime number.
If it is False, num is a prime number.
Note: We can improve our program by decreasing the range of numbers where we look for factors.

In the above program, our search range is from 2 to num - 1.

We could have used the range, range(2,num//2) or range(2,math.floor(math.sqrt(num)+1)). The latter range is based on the fact that a composite number must have a factor less than or equal to the square root of that number. Otherwise, the number is prime.

You can change the value of variable num in the above source code to check whether a number is prime or not for other integers.

In Python, we can also use the for...else statement to do this task without using an additional flag variable.

Example 2: Using a for...else statement
# Program to check if a number is prime or not

num = 407

# To take input from the user
#num = int(input("Enter a number: "))

# prime numbers are greater than 1
if num > 1:
   # check for factors
   for i in range(2,num):
       if (num % i) == 0:
           print(num,"is not a prime number")
           print(i,"times",num//i,"is",num)
           break
   else:
       print(num,"is a prime number")
       
# if input number is less than
# or equal to 1, it is not prime
else:
   print(num,"is not a prime number")
Run Code
Output

407 is not a prime number
11 times 37 is 407
Here, we have used a for..else statement to check if num is prime.

It works on the logic that the else clause of the for loop runs if and only if we don't break out the for loop. That condition is met only when no factors are found, which means that the given number is prime.

So, in the else clause, we print that the number is prime.

Share on:
Did you find this article helpful?
Related Examples
Python Example

Print all Prime Numbers in an Interval

Python Example

Find the Factors of a Number

Python Example

Find the Factorial of a Number

Python Example

Check Armstrong Number


Join our newsletter for the latest updates.
Enter Email Address*
Join


Tutorials
Python 3 Tutorial
JavaScript Tutorial
SQL Tutorial
C Tutorial
Java Tutorial
Kotlin Tutorial
C++ Tutorial
Swift Tutorial
C# Tutorial
Go Tutorial
DSA Tutorial
Examples
Python Examples
JavaScript Examples
C Examples
Java Examples
Kotlin Examples
C++ Examples
Company
About
Advertising
Privacy Policy
Terms & Conditions
Contact
Blog
Youtube
Apps
Learn Python
Learn C Programming
Learn Java
© Parewa Labs Pvt. Ltd. All rights reserved.

   
