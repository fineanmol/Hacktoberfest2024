import random
randnum = random.randint(1,100)
userGuess = None
guesses = 0
while (userGuess != randnum):
    userGuess = int(input("Enter Your Guess: "))
    guesses += 1
    
    if (userGuess == randnum):
        print("You Guessed it right!")
    else :
        if (userGuess>randnum):
            print("You guessed it wrong ! Enter a smaller number")
        else :
            print("You guessed it wrong ! Enter a larger number")

print(f"You guessed number in {guesses} guesses.")
with open("hiscore.txt","r") as f:
    hiscore = int(f.read())

if (guesses<hiscore):
    print("You have just broken highscore!!!")    
with open("hiscore.txt","w") as f:
    f.write(str(guesses)) 

