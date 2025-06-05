import datetime

birth_year = int(input("Please enter your birth year :\n"))

dt = datetime.datetime.now()

current_year = int(dt.strftime("%Y"))

print("Your age is ", current_year - birth_year)

