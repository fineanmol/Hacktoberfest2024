#Return True if number is kaprekar number else return False
def kaprekar(n):
    square = n*n

    def count_digits(n):
        if n < 10 and n >= 0:
            return 1
        else:
            return 1+count_digits(n//10)
    dig_in_sq = count_digits(square)

    if dig_in_sq % 2 != 0:
        square = "0"+str(square)
        dig_in_sq += 1
    else:
        square = str(square)

    first_half = int(square[:dig_in_sq//2])
    second_half = int(square[dig_in_sq//2:])

    if first_half+second_half == n:
        return True
    else:
        return False

