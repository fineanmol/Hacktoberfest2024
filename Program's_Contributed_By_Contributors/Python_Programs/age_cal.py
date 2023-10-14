def ageCalculator(y, m, d):
    import datetime
    today = datetime.datetime.now().date()
    dob = datetime.date(y, m, d)
    age = int((today-dob).days / 365.25)
    print(age)
yr = int(input("Enter BirthYear : "))
mt = int(input("Enter BirthMonth: "))
dt = int(input("Enter BirthDay: "))
ageCalculator(yr,mt,dt)
