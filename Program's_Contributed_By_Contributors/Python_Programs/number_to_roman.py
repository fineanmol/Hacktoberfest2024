def intToRoman(num: int) -> str:
    """
    Convert an integer to a roman numeral.
    constraint: 1 <= num <= 3999

    :type num: int
    :rtype: str   
    """

    # Creating Dictionary for Lookup
    num_map = {
        1: "I",
        5: "V",    4: "IV",
        10: "X",   9: "IX",
        50: "L",   40: "XL",
        100: "C",  90: "XC",
        500: "D",  400: "CD",
        1000: "M", 900: "CM",
    }
    
    # Result Variable
    r = ''
    
    
    for n in [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]:
        # If n in list then add the roman value to result variable
        while n <= num:
            r += num_map[n]
            num-=n
    return r

# Driver Code
if __name__ == "__main__":
    print(intToRoman(1994))
    