Height = float(input("Enter your height in centimeters: "))/100
Weight = float(input("Enter your Weoght in Kg: "))
BMI = Weight/(Height*Height)
print(f"Your Body Mass Index is: {BMI}")

if(BMI>0):
    if(BMI<=16):
        print("You are severaly underweigth")
    elif(BMI<=18.5):
        print("You are underweight")
    elif (BMI <= 25):
        print("You are Healthy")
    elif (BMI <= 30):
        print("You are overwight")
    else:17
        print("You are severaly overweight")
else:
    print("Enter valid details")
