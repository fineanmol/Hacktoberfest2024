import random
user_action = input("Vyber si (kámen, papír, nůžky): ")
possible_actions = ["kámen", "papír", "nůžky"]
computer_action = random.choice(possible_actions)
print(f"\nVybral si {user_action}, počítač vybral {computer_action}.\n")

if user_action == computer_action:
    print(f"Oba dva hráči vybrali stejnou volbu: {user_action}. Je to remíza!")
elif user_action == "kámen":
    if computer_action == "nůžky":
        print("Kámen rozbil nůžky! Vyhral si!")
    else:
        print("Papír zabalil kámen! Prohrál si")
elif user_action == "papír":
    if computer_action == "kámen":
        print("Papír zabalil kámen! Vyhral si!")
    else:
        print("Nůžky střihli papír! Prohlal si.")
elif user_action == "nůžky":
    if computer_action == "papír":
        print("Nůžky střihli papír! Vyhral si!")
    else:
        print("Kámen rozbil nůžky! Prohlal si.")