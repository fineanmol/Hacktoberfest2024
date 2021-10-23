li=[]
count=0
x=int(input("Enter a Num : "))
while(x):
    if(x%2==0):
        x/=2
        print(x)
        li.append(x)
        count+=1
    elif(x==1):
        print(li)
        print("Number of Iterations ",count)
        break
    else:
        x=x*3+1
        print(x)
        li.append(x)
        count+=1
print(li)
