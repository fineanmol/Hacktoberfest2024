Height=float(input("What is your height in centimeters: "))
Weight=float(input("What is your Weight in Kg: "))

Height = Height/100

BMI=Weight/(Height*Height)

print("your Body Mass Index is: ",BMI)

if(BMI>0):
	if(BMI<=16):
		print("severely underweight")
	elif(BMI<=18.5):
		print("underweight")
	elif(BMI<=25):
		print("Healthy")
	elif(BMI<=30):
		print("overweight")
	else: print("severely overweight/ Obese")
else:("enter valid details")