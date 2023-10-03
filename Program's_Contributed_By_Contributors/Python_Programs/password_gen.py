# random password generator
import string
import random


def generate_password(length=12, include_nums=True, include_symbols=True):
    source = string.ascii_letters
    if include_nums:
        source += string.digits
    if include_symbols:
        source += string.punctuation

    password = ''.join(random.choice(source) for _ in range(length))
    return password


if __name__ == '__main__':
    length = int(input("Enter length for password: "))
    nums = input("Include numbers (y/n): ").lower() == 'y'
    syms = input("Include symbols (y/n): ").lower() == 'y'
    print(f"\nGenerated Password: {generate_password(length,nums,syms)}")
