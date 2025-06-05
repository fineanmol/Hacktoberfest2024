n=input("Enter a number : ")
l=len(n)
sum=0
for i in range(l):
    x=int(n[i])
    c=x**3
    print(c)
    sum=sum+c
    print(sum)

if sum==int(n):
    print(n," is an armstrong number")   
else:
    print(n," is not an armstrong number") 