n=int(input("enter a number :> "))
def checkPalindrome(num):
    # copy=num
    # rem=0
    # sum=0
    # while(copy>0):
    #     rem=copy%10
    #     sum=sum*10+rem
    #     copy=copy//10  
    copy = str(num)

    if(copy==copy[::-1]):
        print("Number is palindrome")
    else:
        print("Number is Not palindrome")

        
checkPalindrome(n)
