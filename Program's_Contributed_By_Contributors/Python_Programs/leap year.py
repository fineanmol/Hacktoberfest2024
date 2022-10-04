# Check leap year

def leap_year_check(yr):
    leap = False
    if yr % 4 == 0:
        leap = True
        if yr % 100 ==0 and yr % 400 != 0:
            leap = False
        else: 
            leap = True
    if leap: 
        print("{0} is a leap year".format(yr))
    else: 
        print("{0} is not a leap year".format(yr))

leap_year_check(1700)