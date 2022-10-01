#The main approach is to reverse the integer and check if the reversed integer is equal to the original integer.

def pali(x): #n is the input integer
    t = int(x) #make a copy of the original integer to reverse because we want the original integer to compare with the reversed integer
    p = 0
    r = 0
    while x > 0:
        m = x % 10  #thsi will give u the last digit of the intger. For example-123%10=3 
        r = r*10+m  #now we have the variable in which we are going to store the reversed integer. r=0*/10+3=3. when the loop runs for second time, it will be: r=3*10+2=32 and so on.
        x = x//10   #this will remove the digit at ones place(the last digit from right) from the integer.eg: 123//10=12
    if t == r:
        return True
    else:
        return False

l=pali(12321) 
print(l)
k=pali(12343)
print(k)