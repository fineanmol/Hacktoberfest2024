import time

def countdown_timer(duration):
    try:
        # Parse the duration input and convert it to seconds
        duration = int(duration)
        if duration <= 0:
            print("Please enter a valid positive duration.")
            return

        # Start the countdown
        print(f"Countdown timer started for {duration} seconds.")
        for remaining in range(duration, 0, -1):
            print(f"Time remaining: {remaining} seconds", end='\r')
            time.sleep(1)

        # Timer expired
        print("Time's up!")

    except ValueError:
        print("Invalid input. Please enter a valid number.")

if __name__ == "__main__":
    while True:
        user_input = input("Enter the countdown duration in seconds (or 'q' to quit): ")
        
        if user_input.lower() == 'q':
            break
        else:
            countdown_timer(user_input)
