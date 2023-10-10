def is_vowel(c):
    vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
    if c in vowels:
        return True
    else:
        return False

str = input("Enter a string: ")
# Remove the newline character from the input
str = str.rstrip('\n')
len = len(str)
# Check if the last character is a vowel
while len > 0 and is_vowel(str[len - 1]):
    # If it's a vowel, remove it by setting it to null terminator
    # str = str[:len - 1]
    len -= 1
str = str[:len]
print("Modified string:", str)
