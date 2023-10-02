
#input height
a= int(input((" Height in 1.inches or 2. feet and inches or 3.centimeters? choose and type 1 or 2 or 3 ->")))

if a==1:
             Height = float(input(" Enter your height: "))
             Height*=2.54
elif ( a==2 ):
             Height_1 = str(input(" Enter in this format: 5'4 or foot'inches ->" ))
             Height =  float(Height_1[0]) *12 *2.54  + float(Height_1[2]) *2.54 
             

#input weight
b= int( input (" Weight in 1.kg or 2.pounds? choose and type 1 or 2 ->"))

Weight = float( input(" Enter your Weight-> "))
if b==2:
             Weight*=0.453592

#convert height into metres
Height = Height / 100

#calculate BMI
BMI = Weight / (Height*Height)

#printing BMI
print(f"Your Body Mass Index is: {BMI}")

#printing results
if( BMI > 0):
    if( BMI <= 16 ):
        print("You are severely underweight")
    elif( BMI <= 17 ):
        print("You are moderately underweight")
    elif( BMI <= 18.5 ):
        print("You are mildly underweight")
    elif ( BMI <= 25 ):
        print("You are healthy")
    elif ( BMI <= 30 ):
        print("You are overweight")
    elif ( BMI <= 35 ):
        print("You belong to obesity class I")
    elif ( BMI <= 40 ):
        print("You belong to obesity class II")
    else:
        print("You belong to obesity class III")
else:
    print("Enter valid details")
    
