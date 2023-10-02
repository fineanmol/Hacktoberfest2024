"""
-----------------
Boolean Variables
-----------------
"""
game_opened_once = False
car_started = False

while True:

    # Checks whether the game has already been opened

    if not game_opened_once:
        command = input("Enter command (type help to get help): ").lower()
        game_opened_once = True
    else:
        command = input("Enter command: ").lower()

    # Start command block
    if command == "start":
        if car_started:
            print("Car has already started")
        else:
            print("Car has started")
            car_started = True

    # Stop command block
    elif command == "stop":
        if not car_started:
            print("Car has already stopped")
        else:
            print("Car has stopped")

    # Quit command block
    elif command == "quit":
        print("Quitting...")
        break

    # Help command block
    elif command == "help":
        print("""
start - starts the car
stop - stops the car
quit - quits out of the game 

help - brings up this help menu
        """)
