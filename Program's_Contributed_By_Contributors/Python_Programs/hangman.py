import random

word_list = [
    'rainbow',
    'computer',
    'science',
    'programming',
    'python',
    'mathematics',
    'player',
    'condition',
    'reverse',
    'water',
    'board',
    'geeks'
]

def get_word():
    word = random.choice(word_list)
    return word.lower()

hangman_figures = [
    '''
        _____ \n
       |     | \n
       |     |\n
       |     O\n
       |    \|/\n
       |     |\n
       |    / \ \n
       |      \n
     __|__\n
    ''',
    '''
        _____ \n
       |     | \n
       |     |\n
       |     O\n
       |    \|/\n
       |     |\n
       |      \ \n
       |      \n
     __|__\n
    ''',
    '''
        _____ \n
       |     | \n
       |     |\n
       |     O\n
       |    \|/\n
       |     |\n
       |      \n
       |      \n
     __|__\n
    ''',
    '''
        _____ \n
       |     | \n
       |     |\n
       |     O\n
       |     |/\n
       |     |\n
       |      \n
       |      \n
     __|__\n
    ''',
    '''
        _____ \n
       |     | \n
       |     |\n
       |     O\n
       |     |\n
       |     |\n
       |      \n
       |      \n
     __|__\n
    ''',
    '''
        _____ \n
       |     | \n
       |     |\n
       |     O\n
       |      \n
       |      \n
       |      \n
       |      \n
     __|__\n
    ''',
    '''
        _____ \n
       |     | \n
       |     |\n
       |      \n
       |      \n
       |      \n
       |      \n
       |      \n
     __|__\n
    '''
]

def guess_word(word):
    tries = 6;
    guessed_letters = []
    guessed_words = []
    word_completion = "_" * len(word)
    guessed = False
    print("Let's play hangman\n")
    print(hangman_figures[tries])
    print(word_completion)
    print("\n")
    print("The word has " + str(len(word)) + " letters")
    print("\n")
    while (not guessed and tries > 0):
        guess = input("Please guess a letter or word: ").lower()
        print("\n")
        if (len(guess) == 1 and guess.isalpha()):
            if guess in guessed_letters:
                print("You've already guessed " + guess)
            elif guess not in word:
                print(guess + " is not in the word")
                tries-=1
                guessed_letters.append(guess)
            else:
                print("Good job " + guess + " is in the word")
                guessed_letters.append(guess)
                word_as_list = list(word_completion)
                indices = [i for i, letter in enumerate(word) if letter == guess]
                for index in indices:
                    word_as_list[index] = guess
                word_completion = "".join(word_as_list)
                if "_" not in str(word_completion):
                    guessed = True
        elif (len(guess) == len(word) and guess.isalpha()):
            if guess in guessed_words:
                print("You've already guessed " + guess)
            elif (guess != word):
                print(guess + " is not the word")
                tries-=1
                guessed_words.append(guess)
            else:
                guessed = True
                word_completion = word
        else:
            print("Invalid Input")
        print(hangman_figures[tries])
        print(word_completion)
        print("\n")
    if guessed:
        print("Congratulations you have successfully guessed the word " + word)
    else:
        print("Sorry, you ran out of tries. The word was " + word + ". Maybe next time")

def play():
    word = get_word()
    guess_word(word)

play_again = 'y'
while (play_again == 'y'):
    play()
    play_again = input("Do you want to play again?(Y/N): ").lower()
else:
    print("Thank you for playing")
