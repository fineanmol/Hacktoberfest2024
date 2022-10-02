n=int(input("enter a number"))
def checkPalindrome(num):
    copy=num
    rem=0
    sum=0
    while(copy>0):
        rem=copy%10
        sum=sum*10+rem
        copy=copy//10     

    if(n==sum):
        print("Number is Palindromw")
    else:
        print("No. is Not Palindrome")

        
checkPalindrome(n)
