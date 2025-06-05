# Program to display the Fibonacci sequence up to n-th term

n = int(input("How many terms? "))

n1, n2 = 0, 1
count = 0

if n <= 0:
   print("Please enter a positive integer")
elif n == 1:
   print("Fibonacci sequence upto",n,":")
   print(n1)
else:
   print("Fibonacci sequence:")
   while count < n:
       print(n1)
       temp = n1 + n2
       n1 = n2
       n2 = temp
       count += 1
