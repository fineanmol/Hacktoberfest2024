a=int(input("Enter the first term of the GP: "))
r=int(input("Enter the common ratio: "))
n=int(input("Enter the number of terms: "))
sum=0
product=1
for i in range(n):
    term=a*pow(r,i)
    sum=sum+term
    product=product*term
print("Sum of",n,"terms=",sum)
print("Product of",n,"terms=",product)





