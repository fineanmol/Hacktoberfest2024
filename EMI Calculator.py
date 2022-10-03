#emi
a=int(input('enter principal amount='))
b=int(input('enter rate of interest='))
c=int(input('enter number of years='))
d=((a*b/12)*(1+b/12)**c)/((1+b/12)**c)-1
print('EMI=',d)
