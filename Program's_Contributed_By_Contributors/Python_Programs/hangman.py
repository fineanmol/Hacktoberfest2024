import random
def hangman():
    word=random.choice(["guitar","piano","bike","sound","music","song","film","party","bunny","board","card","slim","phone","iphone","python","java","dream"])
    valid=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
    turns=10
    guessmade=""

    while len(word)>0:
        mainword= str("")
        missed=0
        for i in word:
            if i in guessmade:
                mainword= mainword + i
            else:
                mainword=mainword + "_" + " "

        if mainword==word:
            print("You guessed the word  {}".format(mainword))
            print("Congrats, you win")
            break
        print("                                                   ")
        print ("Guess the word  {}".format(mainword))
        guess=input()            
        while True:
            if guess in valid:
                guessmade=guessmade + guess
                break
            else:
                print("Enter a valid alphabet")
                guess=input()
        
        if guess not in word:
            turns=turns-1
            if turns==9:
                print("9 turns left")
                print("  --------  ")
            if turns==8:
                print("8 turns left")
                print("  --------  ")
                print("     O      ")
            if turns==7:
                print("7 turns left")
                print("  --------  ")
                print("     O      ")
                print("     |      ")
            if turns==6:
                print("6 turns left")
                print("  --------  ")
                print("     O      ")
                print("     |      ")
                print("    /       ")
            if turns==5:
                print("5 turns left")
                print("  --------  ")
                print("     O      ")
                print("     |      ")
                print("    / \     ")
            if turns==4:
                print("4 turns left")
                print("  --------  ")
                print("   \ O      ")
                print("     |      ")
                print("    / \     ")
            if turns==3:
                print("3 turns left")
                print("  --------  ")
                print("   \ O /    ")
                print("     |      ")
                print("    / \     ")
            if turns==2:
                print("2 turns left")
                print("  --------  ")
                print("   \ O /|   ")
                print("     |      ")
                print("    / \     ")
            if turns==1:
                print("1 turn left ")
                print("One more wrong word and this man dies!!")
                print("  --------  ")
                print("   \ O_|    ")
                print("     |\     ")
                print("    / \     ")                        
            if turns==0:
                print("you lost")
                print("Khatam tata bye bye gaya!")
                print("  --------  ")
                print("     O_|    ")
                print("    /|\     ")
                print("    / \     ") 
                print("The word was {}".format(word.title()))
                break

name=input("Enter your name: ")
print("Welcome %s" %name.title())
print("--------------------------")
print("Try to guess the word in less than 10 attempts")
hangman()
