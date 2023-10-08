def armstrongChecker(num:int) -> bool:
    """
    An Armstrong number is a number that 
    is equal to the sum of its digits 
    each raised to the power of the number of digits.

    Usage examples:

    >>> armstrongChecker(153)
    True
    >>> armstrongChecker(370)
    True
    >>> armstrongChecker(1634)
    True
    >>> armstrongChecker(25)
    False
    >>> armstrongChecker(1456)
    False

    """
    temp = str(num)
    result = 0
    for i in temp:
        result += int(i) ** len(temp)
    return num == result

#number = int(input("Enter a number: "))
number = 370
print(f"\n\tGiven number is {number} \n\t{armstrongChecker(number) = }\n")
