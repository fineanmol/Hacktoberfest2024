# A python program for fun enjoyment where you need to guess a no using hints.

import random
randNumber = random.randint(1,100)
userGuess = None
guesses = 0
while(userGuess!=randNumber):
    userGuess = int(input("Enter your guess between(1 to 100):"))
    if userGuess>100 or userGuess<1:
        print("Enter Valid Number")
    guesses+=1
    if(userGuess == randNumber):
        print("You Guessed it right!!")
    else:
        if(userGuess>randNumber):
            print("You Guessed it worng!! Enter a smaller number")
        else:
            print("You Guessed it wrong!! Enter a larger number")
            
print(f"You Guessed the number in {guesses} Guesses")
