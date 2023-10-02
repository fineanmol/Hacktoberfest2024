def get_height():
    a = int(input("Height in 1.inches or 2. feet and inches or 3.centimeters? choose and type 1 or 2 or 3 ->"))
    if a == 1:
        height = float(input("Enter your height in inches: "))
        return height * 2.54 / 100
    elif a == 2:
        height = str(input("Enter in this format: 5'4 or foot'inches ->"))
        return (float(height[0]) * 12 * 2.54 + float(height[2]) * 2.54) / 100
    elif a == 3:
        height = float(input("Enter your height in centimeters: "))
        return height / 100

def get_weight():
    b = int(input("Weight in 1.kg or 2.pounds? choose and type 1 or 2 ->"))
    weight = float(input("Enter your weight: "))
    if b == 1:
        return weight
    elif b == 2:
        return weight * 0.453592

def calculate_bmi(height, weight):
    return weight / (height * height)

def print_bmi_category(bmi):
    if bmi <= 16:
        print("You are severely underweight")
    elif bmi <= 17:
        print("You are moderately underweight")
    elif bmi <= 18.5:
        print("You are mildly underweight")
    elif bmi <= 25:
        print("You are healthy")
    elif bmi <= 30:
        print("You are overweight")
    elif bmi <= 35:
        print("You belong to obesity class I")
    elif bmi <= 40:
        print("You belong to obesity class II")
    else:
        print("You belong to obesity class III")

def main():
    height = get_height()
    weight = get_weight()
    bmi = calculate_bmi(height, weight)
    print(f"Your Body Mass Index is: {bmi}")
    print_bmi_category(bmi)

if __name__ == "__main__":
    main()