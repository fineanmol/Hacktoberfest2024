import random
user_choice = input("Enter a choice (rock, paper, scissors): ")
actions=["rock","paper","scissors"]
computer_choice=random.choice(actions)
print(f"\n Your chose {user_choice}, computer chose {computer_choice}.\n")

if user_choice == computer_choice:
    print(f"Both players selected {user_choice}. It's a tie")
elif user_choice == "rock":
    if computer_choice=="paper":
        print(f"Paper covers rock, you lose\n")
    else:
        print(f"Rock smashes scissors, You win\n")
elif user_choice == "paper":
    if computer_choice == "scissors":
        print(f"Scissors destroys paper, you lose\n")
    else:
        print(f"Paper covers rock, you win\n")
elif user_choice=="scissors":
    if computer_choice=="rock":
        print(f"Rock smashes scissors, you lose\n")
    else:
        print(f"Scissors destroys paper, you win\n")
