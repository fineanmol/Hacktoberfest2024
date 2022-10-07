r,h = [int(a) for a in input("Enter the radius and height of the cone in centimeters(xx xx): ").split()]

pi = 3.141592653589793

vol = pi*(r**2)*(h/3)

print(f"The volume of the cone is {round(vol, 3)} cm³")
