# Simple Game of Rock, Paper, Scissors...

from random import randint
player_wins = 0 
AI_wins = 0

print("Hello Player!")
win_score = int(input("Enter the winning score (e.g. 3): "))

while player_wins < win_score and AI_wins < win_score:
    print(f"Your Score: {player_wins} AI Score: {AI_wins}")

    player = input("\n(Choose Rock, Paper or Scissors...or Enter q to exit...): ").lower()
    if player == "quit" or player == "q":
        break
    random_num = randint(0, 2)
    if (random_num == 0):
        computer = "rock"
    elif (random_num == 1):
        computer = "paper"
    else:
        computer = "scissors"

    print(f"The AI plays: {computer}")

    if player == computer:
        print("It's a tie!")
    elif player == "rock":
        if computer == "paper":
            print("AI wins!")
            AI_wins += 1
        else:
            print("YOU win!")
            player_wins += 1
    elif player == "paper":
        if computer == "rock":
            print("YOU win!")
            player_wins += 1
        else:
            print("AI wins!")
            AI_wins += 1
    elif (player == "scissors"):
        if (computer == "rock"):
            print("AI wins!")
            AI_wins += 1
        else:
            print("You win!")
            player_wins += 1
    else:
        print("Invalid Entry!")

if player_wins > AI_wins:
    print("CONGRATS, YOU BEAT THE AI!")
elif player_wins == AI_wins:
    print("YOU'VE MADE FRIENDS WITH THE AI!")
else: 
    print("YOU LOST AGAINST THE AI! Prepare for World Domination :(")
