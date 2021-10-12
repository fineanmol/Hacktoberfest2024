#BMI CALCULATOR 


def BMI(height, weight): 
  bmi = weight/(height**2) 
  return bmi 

height = float(input("enter height in foot: "))

weight = float(input("enter weight in kg: "))               

bmi = BMI(height, weight) 
print("The BMI is", format(bmi))

print("Health status = ",end="")
if (bmi < 18.5): 
  print("Underweight") 

elif ( bmi >= 18.5 and bmi < 24.9): 
  print("Healthy") 

elif ( bmi >= 24.9 and bmi < 30): 
  print("Overweight") 

elif ( bmi >=30): 
  print("Suffering from Obesity")
