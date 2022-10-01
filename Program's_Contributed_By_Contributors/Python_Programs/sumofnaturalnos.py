def sumofnaturalno(num):
    if num < 0:
       print("Enter a positive number")
    else:
       sum = 0
       # use while loop to iterate until zero
       while(num > 0):
           sum += num
           num -= 1
       print("The sum is", sum)

n = int(input("Enter the number to find the sum of all number till there. "))
sumofnaturalno(n)
