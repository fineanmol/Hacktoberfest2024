#Return True if number is armstrong else return False
def armstrong(n):
    def count_digits(n):
        if n < 10 and n >= 0:
            return 1
        else:
            return 1+count_digits(n//10)

    sum_ = 0  # initialize sum to 0
    all_digits = []  # list to store individual extracted digits
    num_digits = count_digits(n)  # count number of digits using above function
    digit = num_digits  # make copy of these values to avoid repeated calculations
    initial_num = n

    while digit > 1:  # extract individual digits
        all_digits.append(n % 10)
        n = n // 10
        digit = digit-1
    all_digits.append(n)

    for i in all_digits:  # calculate sum by adding digit**no of digits
        sum_ = sum_+i**num_digits

    print(sum_)
    print(initial_num)

    if sum_ == initial_num:  # return True if armstrong
        return True
    else:
        return False


print(armstrong(1153))
