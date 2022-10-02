'''
@Coded by TSG
Problem:
FizzBuzz is a well known programming assignment, asked during interviews.
The given code solves the FizzBuzz problem and uses the words "Solo" and "Learn" instead of "Fizz" and "Buzz".
It takes an input n and outputs the numbers from 1 to n.
For each multiple of 3, print "Solo" instead of the number.
For each multiple of 5, prints "Learn" instead of the number.
For numbers which are multiples of both 3 and 5, output "SoloLearn".
You need to change the code to skip the even numbers, so that the logic only applies to odd numbers in the range.
'''

# Code goes here
for x in range(1, int(input())):
    if x % 2 == 0: continue 
    if x % 3 == 0 and x % 5 == 0: print("SoloLearn")
    elif x % 3 == 0: print("Solo")
    elif x % 5 == 0: print("Learn")  
    else: print(x)
