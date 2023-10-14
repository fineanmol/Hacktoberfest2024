# A python program for fun enjoyment where you need to guess a no using hints.

import random
random_number = random.randint(1,100)
userGuess = None
guesses = 0
while(userGuess!=random_number):
    userGuess = int(input("Enter your guess between(1 to 100):"))
    if userGuess>100 or userGuess<1:
        print("Enter Valid Number")
    guesses+=1
    if(userGuess == random_number):
        print("You Guessed it right!!")
    else:
        if(userGuess>random_number):
            print("You Guessed it worng!! Enter a smaller number")
        else:
            print("You Guessed it wrong!! Enter a larger number")
            
print(f"You Guessed the number in {guesses} Guesses")
