import random

def generate_random_number(length):
    """Generate a random multi-digit number."""
    return ''.join(random.choices('0123456789', k=length))

def check_guess(secret_number, guess):
    """
    Compare the secret number with the guess and return the number of correct digits.
    """
    return sum(1 for x, y in zip(secret_number, guess) if x == y)

def play_mastermind():
    print("Welcome to Mastermind!")

    while True:
        player1_number = input("Player 1, enter your secret number: ")
        if not player1_number.isdigit():
            print("Please enter a valid multi-digit number.")
            continue
        break

    player2_attempts = 0
    while True:
        player2_guess = input("Player 2, make your guess: ")
        if not player2_guess.isdigit() or len(player2_guess) != len(player1_number):
            print("Please enter a valid multi-digit guess.")
            continue

        player2_attempts += 1
        correct_digits = check_guess(player1_number, player2_guess)

        if correct_digits == len(player1_number):
            print(f"Congratulations, Player 2! You guessed the number in {player2_attempts} attempts.")
            break
        else:
            print(f"Correct digits: {correct_digits}/{len(player1_number)}")

    player2_number = generate_random_number(len(player1_number))
    player1_attempts = 0

    while True:
        player1_guess = input("Player 1, make your guess: ")
        if not player1_guess.isdigit() or len(player1_guess) != len(player2_number):
            print("Please enter a valid multi-digit guess.")
            continue

        player1_attempts += 1
        correct_digits = check_guess(player2_number, player1_guess)

        if correct_digits == len(player2_number):
            print(f"Congratulations, Player 1! You guessed the number in {player1_attempts} attempts.")
            break
        else:
            print(f"Correct digits: {correct_digits}/{len(player2_number)}")

        if player1_attempts >= player2_attempts:
            print("Player 2 wins the game.")
            break

    play_again = input("Do you want to play again? (yes/no): ")
    if play_again.lower() != 'yes':
        print("Thanks for playing Mastermind!")

if __name__ == "__main__":
    play_mastermind()
