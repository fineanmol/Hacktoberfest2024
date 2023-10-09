num=int(input("Enter the number: "))  
sum_v=0  
for i in range(1,num):  
    if (num%i==0):  
        sum_v=sum_v+i  
if(sum_v==num):  
    print("The entered number is a perfect number")  
else:  
    print("The entered number is not a perfect number")  
