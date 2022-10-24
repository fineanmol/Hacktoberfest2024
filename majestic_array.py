# You are given given task is to print whether array is ‘majestic’ or not.A ‘majsetic’ array is an array whose sum of first three number is equal to last three number.

# Input Description: You are given a number ‘n’,Next line contains ‘n’ space separated

# Output Description: Print 1 if array is majestic and 0 if it is not

# Sample Input :7
# 1 2 3 4 6 0 0

# Sample Output : 1

from array import *

arr=array('i',[])                 # declared and empty int type array
n=int(input("Enter the size of the array "))           #Enter the list 1

for i in range(n):               
  x=int(input())
  arr.append(x)

print(arr)  

sum1=arr[0]+arr[1]+arr[2]          #summing first 3 terms
sum2=arr[n-1]+arr[n-2]+arr[n-3]    #summing last 3 terms

if sum1==sum2:                     #condition
  print('1')
else:
  print('0')
