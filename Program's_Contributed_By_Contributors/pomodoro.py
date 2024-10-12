import time

# Define Pomodoro session parameters
POMODORO_DURATION = 25 * 60  # 25 minutes
SHORT_BREAK_DURATION = 5 * 60  # 5 minutes
LONG_BREAK_DURATION = 15 * 60  # 15 minutes
POMODORO_SESSIONS = 4  # Number of Pomodoro sessions before a long break

def countdown(duration, label):
    while duration:
        mins, secs = divmod(duration, 60)
        time_format = f'{mins:02d}:{secs:02d}'
        print(f'{label} - Time Left: {time_format}', end='\r')
        time.sleep(1)
        duration -= 1
    print(f'{label} is over! Time for a break.')

def pomodoro_clock():
    for session in range(1, POMODORO_SESSIONS + 1):
        print(f"\nPomodoro Session {session}")
        countdown(POMODORO_DURATION, "Work")
        
        if session == POMODORO_SESSIONS:
            print("\nLong break time!")
            countdown(LONG_BREAK_DURATION, "Long Break")
        else:
            print("\nShort break time!")
            countdown(SHORT_BREAK_DURATION, "Short Break")
            
    print("All Pomodoro sessions completed! Well done!")

if __name__ == "__main__":
    pomodoro_clock()