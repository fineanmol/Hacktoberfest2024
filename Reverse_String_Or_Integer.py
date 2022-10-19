
# Given an integer, return the integer  with reversed digits.
#The integer could be either positive or negative.
def reverse(x):
    string = str(x)
    if string[0] == '-':
        return int('-'+string[:0:-1])
    else:
        return int(string[::-1])
#main
print(reverse(-321))
print(reverse(987))