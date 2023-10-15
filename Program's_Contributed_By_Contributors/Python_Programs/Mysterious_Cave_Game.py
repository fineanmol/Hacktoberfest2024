import time

def intro():
    print("Welcome to the Mysterious Cave Adventure!")
    time.sleep(2)
    print("You find yourself standing at the entrance of a dark cave.")
    time.sleep(2)
    print("You have a choice to make:")
    time.sleep(2)
    print("1. Enter the cave.")
    time.sleep(2)
    print("2. Run away.")

def explore_cave():
    print("You enter the cave and follow a narrow, winding path deeper into the darkness.")
    time.sleep(2)
    print("You can barely see anything, but you feel a strange presence.")
    time.sleep(2)
    print("You come to a fork in the path. You must choose:")
    time.sleep(2)
    print("1. Go left.")
    time.sleep(2)
    print("2. Go right.")
    choice = input("Enter your choice (1 or 2): ")
    
    if choice == "1":
        print("You go left and discover a hidden treasure chest filled with gold!")
        print("Congratulations, you're rich!")
    elif choice == "2":
        print("You go right and fall into a pit. You are trapped!")
        print("Game over!")

def main():
    intro()
    choice = input("Enter your choice (1 or 2): ")
    
    if choice == "1":
        explore_cave()
    elif choice == "2":
        print("You run away from the cave in fear. Adventure over!")

if __name__ == "__main__":
    main()
