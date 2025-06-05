import math

a = float(input("Enter first coefficient."))
b = float(input("Enter the second coefficient."))
c = float(input("Enter the third coefficient."))

discrim = b**2-(4*a*c)

if(discrim>0):
    print("Solutions of this equstion are:")
    print((-b + math.sqrt(discrim)) / (2 * a))
    print((-b - math.sqrt(discrim)) / (2 * a))

elif(discrim==0):
    print("Solution of this equation is:")
    print(-b / (2 * a))

else:
    print("No solutions for this equation.")
