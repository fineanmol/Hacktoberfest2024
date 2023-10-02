# number guessing game
# username -> dev-32 
import random as r

EASY = 10
HARD = 5


def check_ans(guess, ans):
    if guess > ans:
        print("Too high.")
    elif guess < ans:
        print("Too low.")
    else:
        print("Boom !! your answer is correct.")


def difficulty():
    diff = input("Choose a difficulty.Type 'easy' or 'hard': ")
    if diff == "easy":
        return EASY
    else:
        return HARD


print("WELCOME TO THE GUESSING GAME!!")
print("Think of a number between 1 and 100.")
ans = r.randint(1, 100)

# print(f"The correct answer is :{ans}")
turns = difficulty()
status = 0
while turns:
    print(f"You have {turns} attempts remaining to guess the number!!")
    guess = int(input("Make a guess: "))

    if (guess == ans):
        print("Congrats!! you won.")
        status = 1
        break
    else:
        check_ans(guess, ans)
        turns -= 1

if status == 0:
    print("Sorry!! you lost the game.")
