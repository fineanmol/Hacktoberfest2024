import random

def hangman():
    word_list = ["python", "java", "ruby", "javascript", "html"]
    word_to_guess = random.choice(word_list)
    guessed_letters = []
    attempts = 6

    while attempts > 0:
        display_word = ""
        for letter in word_to_guess:
            if letter in guessed_letters:
                display_word += letter
            else:
                display_word += "_"

        print(display_word)
        guess = input("Guess a letter: ").lower()

        if guess in guessed_letters:
            print("You already guessed that letter. Try again.")
        elif guess in word_to_guess:
            guessed_letters.append(guess)
            print("Good guess!")
        else:
            attempts -= 1
            print(f"Wrong guess. {attempts} attempts left.")

        if set(word_to_guess) <= set(guessed_letters):
            print(f"Congratulations! You guessed the word: {word_to_guess}")
            break

        if attempts == 0:
            print(f"Sorry, you ran out of attempts. The word was: {word_to_guess}")

# Uncomment the line below to play the game
# hangman()
