def hanged(chances):
    if chances==6:
        print("      \n"
             " +---+\n"
             " |   |\n"
             "     |\n"
             "     |\n"
             "     |\n"
             "     |\n"
             "=======\n")
    elif chances==5:
        print("      \n"
              " +---+\n"
              " |   |\n"
              " O   |\n"
              "     |\n"
              "     |\n"
              "     |\n"
              "=======\n")
    elif chances==4:
        print("      \n"
              " +---+\n"
              " |   |\n"
              " O   |\n"
              " |   |\n"
              " |   |\n"
              "     |\n"
              "=======\n")
    elif chances==3:
        print("      \n"
              " +---+\n"
              " |   |\n"
              " O   |\n"
              "\|   |\n"
              " |   |\n"
              "     |\n"
              "=======\n")
    elif chances==2:
        print("      \n"
              " +---+\n"
              " |   |\n"
              " O   |\n"
              "\|/  |\n"
              " |   |\n"
              "     |\n"
              "=======\n")
    elif chances==1:
        print("      \n"
              " +---+\n"
              " |   |\n"
              " O   |\n"
              "\|/  |\n"
              " |   |\n"
              "/    |\n"
              "=======\n")
    elif chances==0:
        print("      \n"
              " +---+\n"
              " |   |\n"
              " O   |\n"
              "\|/  |\n"
              " |   |\n"
              "/ \  |\n"
              "=======\n")

def play_loop():
    global play_game
    response=["y", "n","Y","N"]
    play_game = input("Do You want to play again? y = yes, n = no \n")
    while play_game not in response:
        play_game = input("Do You want to play again? y = yes, n = no \n")
    if play_game == "y":
        Hangman()
    elif play_game == "n":
        print("Thanks For Playing! We expect you back again!")
        exit()
        # Initializing all the conditions required for the game:

        
import random
# number of chances given to users 

#list from which word will be selected for guessing
listOfWords = ['APPLE', 'BILBO', 'CHORUSED', 'DISIMAGINE',
               'ENSURING', 'FORMALISING', 'GLITCHES', 'HARMINE', 'INDENTATION',
               'JACKED', 'KALPACS', 'LAUNDRY', 'MASKED', 'NETTED', 'OXFORD',
               'PARODY', 'QUOTIENTS', 'RACERS', 'SADNESS',
               'THYREOID', 'UNDUE', 'VENT', 'WEDGED', 'XERIC',
               'YOUTHHOOD', 'ZIFFS']

#generating random words from list for guessing
def randomword(list):
    word=random.choice(list)
    word=word.lower()
    return word

def Hangman():

    # random word from list for guessing
    word= randomword(listOfWords)

    print ("\nLets start guessing a letter\n")
    guesses=''
    chances = 6
    #giving chances to user until all chances availed
    while chances > 0:
        # calling hanged function for printing hanged person pattern
        hanged(chances)

        availed = 0

        # for every character in word    
        for x in word:
            #if the guessed letter is in the required word
            if x in guesses:         
        
            # print then out the character
                print (x,end = ''),    

            else:
        
            # if not found, print a dash
                print ("_ ",end = ''),     
           
            # and increase the failed counter with one
                availed += 1    

        # if availed is equal to zero

        # print You Won
        if availed == 0:
            print ("")
            print ("You won")
            play_loop()

        # exit the script
            break              

        print


        # ask the user go guess a letter from word
        guess = input("\n\nTry to guess a letter:")
        # set the players guess to guesses
        guesses += guess
        # if the guess is not found in the secret word
        if guess not in word:
            print ("\nWrong")
         # turns counter decreases with 1 (now 9)
            chances -= 1 
     
        # how many turns are left
            print ("\nYou have", + chances, 'more guesses') 
     
        # if availed all the chances
            if chances == 0:
                hanged(chances)
        
            # print "You Lose"
                print ("\nYou Lose. The correct word is ",word)
                play_loop()


#Asking user for name
username = input("What is your name? ")
print ("\nHello, " , username, "Lets play the game!")               

Hangman()
    
