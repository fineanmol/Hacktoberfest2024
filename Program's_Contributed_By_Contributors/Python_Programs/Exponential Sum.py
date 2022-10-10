s=0
a=int(input('Enter the base Number: '))
e=int(input('Enter the Exponent: '))
for i in range(1,e+1):
    t=a**i
    print(a,'raised to index',i,' = ',t)
    s+=t
print('Sum of this Progression is: ',s)
