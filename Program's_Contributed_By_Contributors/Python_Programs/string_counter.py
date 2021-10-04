#Count all lower case, upper case, digits, and special symbols from a given string

input_string = "P@#yn26at^&itr5i!ve"

def findcounts(input_string):
    charsCount = 0
    digitsCount = 0
    symbolsCount = 0

    for char in input_string:
        if char.islower() or char.isupper():
            charsCount = charsCount + 1
        elif char.isnumeric():
            digitsCount = digitsCount+1
        else:
            symbolsCount = symbolsCount + 1

    print("chars", charsCount, "Digits: ", digitsCount, "symbols: ", symbolsCount)
