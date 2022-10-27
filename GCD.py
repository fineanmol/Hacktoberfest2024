#Function uses Euclid's formula to calculate GCD of two numbers.
def gcd(a,b):
    while(b!=0):
        if(a>b):
            a%=b
        else:
            temp=a
            a=b
            b=temp
    return a


num=input("Enter 2 numbers: ").split()
print("GCD of",num[0],"and",num[1],"is",gcd(int(num[0]),int(num[1])))