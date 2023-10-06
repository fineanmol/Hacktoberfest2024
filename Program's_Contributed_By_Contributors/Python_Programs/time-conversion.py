import math
import random

# program to convert time to 24hour format string


def timeConversion(s):
    if 'PM' in s:
        hour = s[:2]
        if hour == '12':
            return s[:-2]
        else:
            return str(int(hour) + 12) + s[2:-2]
    else:
        hour = s[:2]
        if hour == '12':
            return '00' + s[2:-2]
        else:
            return s[:-2]


if __name__ == '__main__':
    s = input()
    result = timeConversion(s)
    print(result)
