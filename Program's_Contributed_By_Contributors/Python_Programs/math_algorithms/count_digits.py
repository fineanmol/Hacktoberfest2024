#return digit count as int for positive numbers
#return digit count +1 (extra 1 for - sign) for negative numbers
def count_digits(n):
    if n < 0:
        n = n*-10  # for negative numbers. - sign will be counted as a digit
    if n < 10 and n >= 0:
        return 1
    else:
        return 1+count_digits(n//10)
