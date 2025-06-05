#Program to find day by date. (Year>2000)
def leap(a):
    if (a % 4 == 0 and a % 400 == 0):
        return 1
    elif (a % 100 != 0 and a % 4 == 0):
        return 1
    else:
        return 0


def year(x):
    if (x > 2000):
        lp = int((x-2000-1)/4)
        oy = x-2000-1-(lp)
        todd = oy + lp*2
        return todd


def monthordi(y):
    modd = {2: 3, 3: 3, 4: 6, 5: 1, 6: 4, 7: 6,
            8: 2, 9: 5, 10: 0, 11: 3, 12: 5, 1: 1}
    return modd[y]


def monthleap(z):
    modd = {2: 3, 3: 4, 4: 0, 5: 2, 6: 5, 7: 0,
            8: 3, 9: 6, 10: 1, 11: 4, 12: 6, 1: 2}
    return modd[z]


def final(*p):
    a = year(p[2]) + monthordi(p[1]) + p[0]
    b = year(p[2]) + monthleap(p[1]) + p[0]
    c = a % 7
    d = b % 7
    week = {1: 'Monday', 2: 'Tuesday', 3: 'Wednesday',
            4: 'Thursday', 5: 'Friday', 6: 'Saturday', 0: 'Sunday'}
    if leap(p[2]) == 1:
        return week[d]
    else:
        return week[c]


a = int(input('Enter date'))
b = int(input('Enter month'))
c = int(input('Enter year'))
okk = final(a, b, c)
print(okk)
