import random

def choose_word():
    words = ["apple", "banana", "cherry", "dog", "elephant", "falcon", "giraffe"]
    return random.choice(words)

def display_word(word, guessed_letters):
    displayed = ""
    for letter in word:
        if letter in guessed_letters:
            displayed += letter
        else:
            displayed += "_"
    return displayed

def hangman():
    word_to_guess = choose_word()
    guessed_letters = []
    attempts = 6

    print("Welcome to Hangman!")
    
    while attempts > 0:
        print("\nAttempts left:", attempts)
        print(display_word(word_to_guess, guessed_letters))
        
        guess = input("Guess a letter: ").lower()
        
        if guess in guessed_letters:
            print("You already guessed that letter.")
            continue
        
        guessed_letters.append(guess)
        
        if guess in word_to_guess:
            print("Good guess!")
        else:
            print("Wrong guess.")
            attempts -= 1
        
        if display_word(word_to_guess, guessed_letters) == word_to_guess:
            print("\nCongratulations! You guessed the word:", word_to_guess)
            break

    if attempts == 0:
        print("\nYou ran out of attempts. The word was:", word_to_guess)

    play_again = input("Play again? (yes/no): ").lower()
    if play_again == "yes":
        hangman()

hangman()
