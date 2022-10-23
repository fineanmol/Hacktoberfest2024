name = input("What is your name?")
name_vowels = [l for l in name if l in ['a', 'e', 'i', 'o', 'u']]
name_ratio = (len(name_vowels) / len(name)) * 100

print(f"Your name is {int(name_ratio)}% vowels")
