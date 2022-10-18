 # Exercise - 5
from emoji import emojize  # pip install emoji
import random
from time import sleep
import shutil
from simple_colors import *  # pip install simple_colors


def intro():
    """
    Function to print the basic introduction about te game
    """
    columns = shutil.get_terminal_size().columns

    print(magenta("SNAKE (🐍) WATER (💧) GUN (🔫)".center(columns)))  # Printing the name of the game

    sleep(1.5)  # Making program to sleep to print next statement after sometime

    print(cyan("GAME DEVELOPED BY - 👑 AKSHAT DODHIYA 👑".center(columns)))  # Printing the name of the developer

    sleep(2)  # Making program to sleep to execute next part of the program after sometime


intro()  # Calling the function intro() to introduce the game

computer_choice, user_choice = "", ""  # Declaring variables to store choices
computer_points, user_points, flag, chance = 0, 0, 0, 0  # Variables :
# store points, flag = to repeat loop once again for invalid input,
# chance = use in while loop for calculating the chances of the user
replay = ""  # Declaring empty string to store user's choice for replay


def choices():
    """
    This function takes input of user's choice and also takes random input from the computer from list 'options'
    """
    global computer_choice, user_choice  # Declaring variables as global to use in function
    options = ["Snake", "Water", "Gun"]  # List of options for computer to choose randomly
    computer_choice = random.choice(options)  # function to store random choice from list 'options'

    print("Choose:\t\tS for", emojize(":snake:"),
          "\t\tW for", emojize(":droplet:"),
          "\t\tG for", emojize(":pistol:"))  # Printing options for user to select
    user_choice = input().lower()  # storing input of the user in lower case


def results():
    """
    This function calculates points of both computer and user and
     it also prints whether the user won or lost in that chance and flag value is also handled in this function
    """
    global computer_points, user_points, flag  # Globalising variables for editing it's values
    flag = 0  # Initialising the value of flag to zero in each iteration
    if computer_choice == "Snake":
        if user_choice == "s" or user_choice == "snake":
            print(yellow("AWWW...!!"), emojize(":neutral_face:"), yellow("\nTWO SNAKES HAD BITTEN EACH OTHER :/"))

        elif user_choice == "w" or user_choice == "water":
            print(red("NOOO...!!"), emojize(":crying_face:"), red("\nTHE SNAKE DRANK YOUR WATER :("))
            computer_points += 1  # Incrementing computer_points by one

        elif user_choice == "g" or user_choice == "gun":
            print(green("YEAH...!!"), emojize(":victory_hand:"), green("\nYOU SHOT THE SNAKE BY GUN  :)"))
            user_points += 1  # Incrementing user_points by one

        else:
            print("!!कृपया सही विकल्प चुनें!!")  # Error message in 'HINDI' for invalid choice
            flag = 1  # Changing flag value to iterate the loop again in same chance

    elif computer_choice == "Water":
        if user_choice == "s" or user_choice == "snake":
            print(green("YEAH...!!"), emojize(":victory_hand:"), green("\nYOUR SNAKE DRANK THE WATER :)"))
            user_points += 1  # Incrementing user_points by one

        elif user_choice == "w" or user_choice == "water":
            print(yellow("AWWW...!!"), emojize(":neutral_face:"), yellow("\nWATER IS INCREASED :/"))

        elif user_choice == "g" or user_choice == "gun":
            print(red("NOOO...!!"), emojize(":crying_face:"), red("\nYOUR GUN SANK INTO THE WATER :("))
            computer_points += 1  # Incrementing computer_points by one

        else:
            print("!!कृपया सही विकल्प चुनें!!")  # Error message in 'HINDI' for invalid choice
            flag = 1  # Changing flag value to iterate the loop again in same chance

    elif computer_choice == "Gun":
        if user_choice == "s" or user_choice == "snake":
            print(red("NOOO...!!"), emojize(":crying_face:"), red("\nYOUR SNAKE WAS SHOT BY THE GUN :("))
            computer_points += 1  # Incrementing computer_points by one

        elif user_choice == "w" or user_choice == "water":
            print(green("YEAH...!!"), emojize(":victory_hand:"), green("\nYOUR WATER HAD SUNK THE GUN INTO IT :)"))
            user_points += 1  # Incrementing user_points by one

        elif user_choice == "g" or user_choice == "gun":
            print(yellow("AWWW...!!"), emojize(":neutral_face:"), yellow("\nTWO GUNS FIRED AT EACH OTHER :/"))

        else:
            print("!!कृपया सही विकल्प चुनें!!")  # Error message in 'HINDI' for invalid choice
            flag = 1  # Changing flag value to iterate the loop again in same chance


def replay_game():
    """
    Function to ask and store the choice of the user for replaying the game
    """
    while 1:  # infinite loop till the user enters a valid choice
        print("DO YOU WANT TO PLAY AGAIN ? \nENTER Y FOR YES AND N FOR NO")
        # Giving choice to the user for replaying the game
        global replay  # Globalising the variable to edit value of main variable
        replay = input().lower()  # Taking input in lower case string

        # if else condition to check whether the user has entered the valid input or not
        if replay == "y" or replay == "yes":
            break  # breaking infinite loop after getting valid input
        elif replay == "n" or replay == "no":
            break  # breaking infinite loop after getting valid input
        else:
            print(red("Please enter a valid input only"))
            continue  # executing the loop again due to invalid input given by the user


while 1:  # Infinite loop to play the game as many times as the user wants
    computer_points, user_points, flag, chance = 0, 0, 0, 0  # Initialising values to zero at the beginning of the game
    computer_choice, user_choice, replay = "", "", ""  # Emptying strings at the beginning of the game

    try:
        n = int(input("HOW MANY CHANCES DO YOU WANT TO PLAY ?\n"))
        if n < 1:
            print(red('Please enter only natural number', 'bold'))
            continue

    except Exception as e:
        print(red('Please enter only natural number', 'bold'))
        continue

    while chance < n:  # Iterating loop 'n' times for playing 'n' number of chances
        choices()  # Calling function to take choice of the user as input
        results()  # Calling function to calculate result of a particular chance
        if flag == 0:  # Incrementing flag's value only if the input given by the user will be valid
            chance += 1

    # Displaying points of both computer and user
    print("\n\t\t\tYOUR SCORE :", user_points)
    print("\n\t\t\tCOMPUTER'S SCORE :", computer_points)

    # Printing the final result of the game
    if computer_points > user_points:
        print(red("\n\t\t\tYOU LOST THE GAME !!"), emojize(":loudly_crying_face:"), red("YOU LOST THE GAME"))
    elif user_points > computer_points:
        print(green("\n\t\t\tHURRAH !!"), emojize(":smiling_face_with_sunglasses:"), green("YOU WON THE GAME"))
    else:
        print(yellow("\n\t\t\t!! TIE !!"), emojize(":disappointed_face:"), yellow("!! TRY AGAIN !!"))

    replay = ""

    replay_game()

    if replay == "n" or replay == "no":
        print(red("\n\t\t\tSAD TO SEE YOU GO !!", 'bold'), emojize(":disappointed_face:"))  # Printing exit statement
        exit()  # exiting the game
    if replay == "y" or replay == "yes":
        print(green("\n\t\t\tYO LET'S PLAY AGAIN", 'bold'), emojize(":smiling_face_with_smiling_eyes:"))
        # Printing a statement and replaying the game
