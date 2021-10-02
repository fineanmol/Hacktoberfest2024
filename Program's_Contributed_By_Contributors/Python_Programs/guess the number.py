import random
randNo = random.randint(1,100)
userGuess = None
guesses = 0

while (userGuess != randNo):
    userGuess = int(input("Enter your guess: "))
    guesses = guesses + 1
    if(userGuess == randNo):
        print("You guessed it right!")
    else:
        if(userGuess>randNo):
            print("You guessed it wrong!\nEnter a smaller number")
        else:
            print("You guessed it wrong!\nEnter a larger number")
    
print(f"You guessed the number in {guesses} guesses")
