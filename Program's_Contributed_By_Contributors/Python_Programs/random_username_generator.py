import random

print("This is simple username creator program")

names = input("Your full-name: ").split(" ")
random_number = int(input("Put your lucky number (1-9): "))

if not(len(names) > 1):
    print("Please, input the right names")
    exit()


first_letter = names[0][:random_number]
surnmae_letter = names[-1][:random_number]

number = f"{random.randrange(1,999)}"
combine = [first_letter, surnmae_letter, number]
random.shuffle(combine)
print(combine)
username = "".join(combine)
print(username)