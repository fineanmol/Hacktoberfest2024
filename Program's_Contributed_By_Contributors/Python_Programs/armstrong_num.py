# 123 = 1** (no.of digits) + 2** (no.of digits) + 3** (no:of digits)

num=int(input("enter the number"));
length=len(str(num))
temp=num;

def check (num):
    sum=0;
    while num:
        sum=sum+(num%10)**length;
        num=num//10;
    return sum    



def armstrong (num):
    if(num):
        returned_val=check(num)
        if returned_val==temp:
            print(f"{temp} is a armstrong number");
        else:
           print(f"{temp} is not an armstrong number");
    else:
        print("you haven't entered the number")
    

armstrong(num)
