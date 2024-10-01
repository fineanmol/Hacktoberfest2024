num=int(input("Enter a number : "))
org=num
sum=0
for i in str(num):
    a=num%10
    sum=sum+a*a*a
    num=num//10
if (sum==org):
    print(org,"is an armstrong no.")
else:
    print(org,"is not an armstrong no.")
