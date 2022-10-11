# Calculate sphere volume
# Create variables
PI = 3.14159265358979
radius = -1

# Get input
while radius < 0:
  radius = float(input("Enter the radius of the sphere: "))

# Calculate and print result
volume = 4 / 3 * PI * (radius**3)
print(f"The volume of the sphere is: {volume}")
