# Check leap year
#Leap year is the sequence of every 4 years so to check if  a given year is leap year or not we have to check its divisibility by 4,400, and 100.
def leap_year_check(yr):
    if (yr % 4 == 0 and yr % 100 != 0) or (yr % 400 == 0) == 0:
        print("Its a leap year")
    else:
        print("Its not a leap year")
leap_year_check(1700)
