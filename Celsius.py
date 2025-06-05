print("Celsius to Fahrenheit = 1 \nFahrenheit to Celsius = 2")
number = input("Enter your choice number_ ")
value = input("Enter the value to be converted_ ")

if number == "1":
    val = (float(value) * 9/5)+ 32
    print("Celsius to Fahrenheit = " ,val)
elif number == "2":
    val = (float(value) -32)*5/9
    print("Fahrenheit to Celsius = " ,val)
else:
    print("wrong choice \nenter again")
