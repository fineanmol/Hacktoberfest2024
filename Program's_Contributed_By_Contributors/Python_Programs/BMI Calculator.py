Height = float(input("Enter your height in centimeters: "))/100
Weight = float(input("Enter your Weoght in Kg: "))
print(f"Your Body Mass Index is: {}").format(Weight/(Height**2))
if(BMI>0):
    if(BMI<=16):
        print("ypu are severaly underweigth")
    elif(BMI<=18.5):
        print("you are underweight")
    elif (BMI <= 25):
        print("ypu are Healthy")
    elif (BMI <= 30):
        print("you are overwight")
    else:17
        print("You are severaly overweight")
else:
    print("enter valid details")
