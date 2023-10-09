# Initialize boolean variables to track game state
game_opened_once = False
car_started = False

# Start an infinite loop for the game
while True:
    # Check if the game has been opened for the first time
    if not game_opened_once:
        command = input("Enter command (type help to get help): ").lower()
        game_opened_once = True
    else:
        command = input("Enter command: ").lower()

    # Process user commands
    if command == "start":
        # Check if the car is already started
        if car_started:
            print("Car has already started")
        else:
            # Start the car and update the state
            print("Car has started")
            car_started = True

    elif command == "stop":
        # Check if the car is already stopped
        if not car_started:
            print("Car has already stopped")
        else:
            # Stop the car and update the state
            print("Car has stopped")
            car_started = False

    elif command == "quit":
        print("Quitting...")
        break  # Exit the loop and end the game

    elif command == "help":
        # Display a help menu with available commands
        print("""
start - starts the car
stop - stops the car
quit - quits out of the game
help - brings up this help menu
        """)
    else:
        # Handle invalid commands
        print("Invalid command. Type 'help' for available commands.")
