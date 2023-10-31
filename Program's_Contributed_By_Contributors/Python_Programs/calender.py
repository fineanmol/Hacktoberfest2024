import calendar

try:
    # To take month and year input from the user
    yy = int(input("Enter year: "))
    mm = int(input("Enter month: "))

    # Check if the year and month inputs are valid
    if yy < 0 or mm < 1 or mm > 12:
        print("Invalid year or month input.")
    else:
        # display the calendar
        print(calendar.month(yy, mm))
except ValueError:
    print("Invalid input. Please enter a valid year and month.")