import string
import random

alphabets = list(string.ascii_letters)
numbers = list(string.digits)
symbols = list(string.punctuation)

print("-------------------------------- $ WELCOME TO THE PASSWORD GENERATOR $ --------------------------------")
req_alphs = int(input("Enter the number of alphabets required: "))
req_nums = int(input("Enter the number of numbers required: "))
req_syms = int(input("Enter the number of symbols required: "))

chars = []
for char in range(1, req_alphs + 1):
    chars.append(random.choice(alphabets))

for char in range(1, req_nums + 1):
    chars.append(random.choice(numbers))

for char in range(1, req_syms + 1):
    chars.append(random.choice(symbols))

random.shuffle(chars)

password = ""
for i in chars:
    password += i

print("The password you can use is :", password)
