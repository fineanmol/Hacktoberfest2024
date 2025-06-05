#program for faulty calculator
#values  :-  45*3=555 , 56+9=77 ,56/6=4;
a=int(input("Enter first number:-"))
print("select operation you want to perform:-\n1.+\n2.-\n3.*\n4./\n")
b=input()
c=int(input("Enter secont number:-"))
if a==45 and b=='*' and c==3:
    print(a,'*',c,'=555')
elif a==56 and b=='+' and c==9:
    print(a,'+',c,'=77')
elif a==56 and b=='/' and c==6:
    print(a,'/',c,'=4')
else:
    if b=='+':
        print(a+c)
    elif b=='-':
        print(a-c)
    elif b=='*':
        print(a*c)
    elif b=='/':
        print(a/c)

