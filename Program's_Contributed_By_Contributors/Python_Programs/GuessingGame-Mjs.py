print("""
|========================|
|     GUESSING GAME      |
|========================|
""")
                  
import random
print ("You have to guess  what number am I thinking about !👀")
print(" The number is bigger than zero and smaller than hundred")
answer = int(random.randrange(0 , 100))
i= 0
while True:
    guess   = int(input("Enter your guess :"))    

    if answer == guess:
        print ("Contragts!! you guessed the correct number😎")
        
        break
    elif answer > guess:
        print ("try a bigger number.\n")
        continue
    else:
        print (" try a smaller nmuber.\n")
        continue


for i in range(50):
    print( "You won.      🎇.        VICTORY.     🎆.          YAY !!        😎 ", end = " ")
print (" ")     
print(f"   {guess}.........You guessed the correct number 👍")
