import random
def guess(x):
    random_number=random.randint(1,10)
    guess=0
    while guess!=random_number:
        guess=input(f'guess a number between 1 and {x}')
        if int(guess)<random_number:
            print("Sorry,guess again, too low")
        elif int(guess)>random_number:
            print("Sorry, guess again, too high")
        elif int(guess)==random_number:  
            print(f'Congrats, right number {random_number}')
guess(10)
