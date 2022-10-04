#Define a recursive function to find power of a number.
def power(n,a):
    if a==0:
        return 1
    else:
        return (n*power(n,a-1))

n = int(input("ENter the number : "))
a = int(input("Enter the power : "))
print("Power of the number is : ",power(n,a))
