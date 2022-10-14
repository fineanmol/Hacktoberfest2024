import random

name = (input('Please, enter your name!\n'))
if not name.isalpha():
    print("Please enter only alphabetical characters for your name.\n")
else:
    print("\nHi," + name,"!" '''
Rules:
    
If you get any of the below numbers, you win the respective prizes.
Here are the lucky numbers alongwith the respective prizes: 

56 : A Brand new car toy.
95 : Bicycle Peddles.
69 : Barbie Doll.

To continue, please press 1.
''')
    confirm= int(input())
    if confirm== 1:
        beg=10
        end=100
        random_integer = random.randint(beg, end)
        print("\nYour Number is :", random_integer,"\n")
        if random_integer == 56:
            print("\nYou Won : A Brand new car toy.")
        elif random_integer == 95:
            print("\nYou Won : Bicycle Peddles.")
        elif random_integer == 69:
            print("\nYou Won : Barbie Doll")
        else:
            print("Ah! You Lose : Better luck next time.")
    else:
        print("You chose not to play : See you again!")    