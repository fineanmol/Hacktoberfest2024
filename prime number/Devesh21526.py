def prime( a):
    flag=True
    for i in range(2,a):
        if a%i==0:
            return False
        else:
            continue
    if flag==True:
        return True

a=int(input("Enter the number u want to check"))
print(prime(a))
