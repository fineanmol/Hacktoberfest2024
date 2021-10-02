import string
import random

allLetters = string.ascii_letters
allNumbers = string.digits
allSymbols = string.punctuation

allCharacters = allLetters + allNumbers + allSymbols
passwordLength = 20


temp = random.sample(allCharacters, passwordLength)
password = "".join(temp)


print(f"Generated Password: {password}")
