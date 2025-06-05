def start_game():
    print("Welcome to the Adventure Game!")
    print("You find yourself at a crossroad.")
    choice = input("Do you go left or right? ").strip().lower()

    if choice == "left":
        print("You encounter a dragon!")
    elif choice == "right":
        print("You find a hidden treasure!")
    else:
        print("Invalid choice. Game over.")

if __name__ == "__main__":
    start_game()
