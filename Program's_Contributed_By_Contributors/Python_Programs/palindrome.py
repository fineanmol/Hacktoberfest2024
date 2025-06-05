# initialize the variables
num=int(input("Enter number:"))
org=num
rev=0

# creating a list to count the occurence 
l1=list()
l2=list()

# main logic to check integer palindrome
while(num>0):
    rem=num%10
    rev=rev*10+rem
    num=num//10

    l2.append(rem)
    if rem not in l1:
        l1.append(rem)
   

# check the integer is a palindrome ?
if(org==rev):
    print("The number is a palindrome!")
else:
    print("The number is not a palindrome!")
    
# print the number of occurence
for i in l1:
    print(f"Digit {i}: {l2.count(i)} occurrences")
    