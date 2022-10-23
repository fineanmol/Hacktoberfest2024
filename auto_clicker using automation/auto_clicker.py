import pyautogui
from pynput.keyboard import Key, Listener

#  ======== Controls ========
start_or_pause_key = Key.f1
exit_key = Key.esc
delay = 1   # seconds

# ==== global variables ====
pause = True
running = True


def display_controls():

    print("F1 = Start / Pause")
    print("ESC = Exit\n")


def choose_delay():

    try:
        return float(input("Enter wanted delay (seconds): "))
    except ValueError:
        print(f"You did not give a valid input, default delay : {delay}sec")
        return delay


def key_press(key):
    global running, pause

    if key == start_or_pause_key:
        pause = not pause
        print("< Pause >") if pause else print("< Start >")
    elif key == exit_key:
        running = False
        print("< Exit >")


def main():

    delay = choose_delay()
    print(f"delay = {str(delay)}sec\n")
    display_controls()

    listener = Listener(on_press=key_press)
    listener.start()

    while running:
        if not pause:
            pyautogui.click(pyautogui.position())
            pyautogui.PAUSE = delay
    listener.stop()


if __name__ == "__main__":
    main()