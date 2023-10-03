import datetime
year = int(input("Enter the year you are born : "))

now = datetime.date.today()
age = now.year - year
print(age)