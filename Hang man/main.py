import random
from hangman_art import stages, logo
from hangman_name import word_list
from replit import clear

print(logo)
game_is_finished = False
lives = len(stages) - 1

chosen_word = random.choice(word_list)
word_length = len(chosen_word)

display = []
for _ in range(word_length):
    display += "_"

while not game_is_finished:
    guess = input("Guess a letter: ").lower()

    clear()

    if guess in display:
        print(f"You've already guessed {guess}")

    for position in range(word_length):
        letter = chosen_word[position]
        if letter == guess:
            display[position] = letter
    print(f"{' '.join(display)}")

    if guess not in chosen_word:
        print(f"You guessed {guess}, that's not in the word. You lose a life.")
        lives -= 1
        if lives == 0:
            game_is_finished = True
            print("You lose.")
    
    if not "_" in display:
        game_is_finished = True
        print("You win.")

    print(stages[lives])