import random

def guess_number():
    number_to_guess = random.randint(1, 100)  # Chooses a Random number between 1 and 100
    attempts = 0    #Keeps a track of the number of times the user has tried to guess the number
    guessed = False #Sets default guess to False

    print("Welcome to the Number Guessing Game!")
    print("I have chosen a number between 1 and 100. Can you guess it?")

    while not guessed:      #It will run untill the user guesses the number correctly

        user_guess = int(input("Enter your guess: "))   #Asks the user for their guess
        attempts += 1   #Increase the number of attempts by 1 if the user has made a guess

        if user_guess < number_to_guess:    #If the user's guess is less than the number to guess
            if number_to_guess - user_guess < 5:  #If the user's guess is within 5 of the number to guess
                print("You're getting close! Try again.")
            else:
                print("Too low! Try again.")
        elif user_guess > number_to_guess:  #If the user's guess is greater than the number to guess
            if user_guess - number_to_guess < 5:  #If the user's guess is within 5 of the number to guess
                print("You're getting close! Try again.")
            else:
                print("Too high! Try again.")
        else:
            print(f"Congratulations! You guessed the number in {attempts} attempts.")
            guessed = True   #Sets the guess to True so the loop will end

# Start the game
guess_number()
