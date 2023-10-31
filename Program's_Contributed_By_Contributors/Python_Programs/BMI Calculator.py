# Input height
unit = int(input("Height in 1. inches or 2. feet and inches or 3. centimeters? Choose and type 1 or 2 or 3 ->"))

if unit == 1:
    height_cm = float(input("Enter your height in inches: "))
    height_cm *= 2.54
elif unit == 2:
    height_ft_inches = input("Enter in this format: 5'4 or foot'inches ->")
    feet, inches = map(int, height_ft_inches.split("'"))
    height_cm = feet * 30.48 + inches * 2.54
elif unit == 3:
    height_cm = float(input("Enter your height in centimeters: "))

# Input weight
unit = int(input("Weight in 1. kg or 2. pounds? Choose and type 1 or 2 ->"))

weight = float(input("Enter your weight: "))
if unit == 2:
    weight *= 0.453592

# Convert height into meters
height_m = height_cm / 100

# Calculate BMI
bmi = weight / (height_m * height_m)

# BMI categories dictionary
bmi_categories = {
    (0, 16): "You are severely underweight",
    (16, 17): "You are moderately underweight",
    (17, 18.5): "You are mildly underweight",
    (18.5, 25): "You are healthy",
    (25, 30): "You are overweight",
    (30, 35): "You belong to obesity class I",
    (35, 40): "You belong to obesity class II",
    (40, float('inf')): "You belong to obesity class III"
}

# Determine BMI category
bmi_category = None
for (min_value, max_value), category in bmi_categories.items():
    if min_value <= bmi < max_value:
        bmi_category = category
        break

# Printing BMI and category
print(f"Your Body Mass Index is: {bmi:.2f}")
if bmi_category:
    print(bmi_category)
else:
    print("Enter valid details")
