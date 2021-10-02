# Program to display calendar from the given month and year

# importing calendar module
import calendar

# To take month and year input from the user
yy = int(input("Enter the year = "))
mm = int(input("Enter the month = "))

# Display the calendar
print(calendar.month(yy, mm))
