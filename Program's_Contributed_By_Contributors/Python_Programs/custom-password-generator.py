import sys, random, pyperclip

charused = sys.argv[1]
passlength = sys.argv[2]
while True:
    password = "".join(random.choices(population=str(charused),k=int(passlength)))
    pyperclip.copy(password)
    print("Your Password has been copied to clipboard!")
    isitok = input("\n\nPress enter to exit\npress 1 to regenerate password\n")
    if isitok == "":
        break
    elif isitok == "1":
        continue