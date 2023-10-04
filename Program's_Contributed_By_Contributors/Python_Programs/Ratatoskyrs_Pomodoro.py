from tkinter import *
from PIL import ImageTk, Image
import math

# ---------------------------- CONSTANTS ------------------------------- #
# Define color and time constants
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
FONT_NAME = "Courier"
WORK_MIN = 25
SHORT_BREAK_MIN = 10
LONG_BREAK_MIN = 20

# Initialize global variables
REPS = 0
CHECKS = 0
TIMER = None


# ---------------------------- TIMER RESET ------------------------------- #
# noinspection PyTypeChecker
def timer_reset():
    """
    Reset the timer, label, and global variables.
    """
    global CHECKS, REPS, TIMER
    window.after_cancel(TIMER)
    canvas.itemconfig(timer_text, text="00:00")
    timer_label.config(text="Timer")
    check_label.config(text="")
    CHECKS = 0
    REPS = 0


# ---------------------------- TIMER MECHANISM ------------------------------- #
def timer_start():
    """
    Start the timer based on the current rep count.
    """
    global REPS, CHECKS
    REPS += 1
    work_sec = WORK_MIN * 60
    short_break_sec = SHORT_BREAK_MIN * 60
    long_break_sec = LONG_BREAK_MIN * 60

    if REPS % 8 == 0:
        countdown(long_break_sec)
        timer_label.config(text="Break", fg=RED)
    elif REPS % 2 == 0:
        countdown(short_break_sec)
        timer_label.config(text="Break", fg=PINK)
    else:
        countdown(work_sec)
        timer_label.config(text="Work", fg=GREEN)


# ---------------------------- COUNTDOWN MECHANISM ------------------------------- #
def countdown(count):
    """
    Countdown timer function.

    Parameters:
        count (int): The countdown time in seconds.
    """
    global TIMER, REPS, CHECKS
    count_min = math.floor(count / 60)
    count_sec = count % 60

    if count_sec < 10:
        count_sec = f"0{count_sec}"

    canvas.itemconfig(timer_text, text=f"{count_min}:{count_sec}")

    if count > 0:
        TIMER = window.after(1000, countdown, count - 1)
    else:
        timer_start()
        if REPS == 9:
            timer_reset()
            timer_start()
        if REPS % 2 == 0:
            CHECKS += 1
            check_label.config(text=check_icon * CHECKS)


# ---------------------------- UI SETUP ------------------------------- #
window = Tk()
window.title("Ratatoskyrs Pomodoro Timer")
window.config(padx=100, pady=50, bg=YELLOW)

# Create canvas and add tomato image
canvas = Canvas(width=200, height=224, bg=YELLOW, highlightthickness=0)
canvas.create_image(100, 112)
timer_text = canvas.create_text(100, 135, text="00:00", fill="black", font=(FONT_NAME, 35, "bold"))

# Create buttons and labels
start_button = Button(text="Start", command=timer_start, highlightthickness=0)
reset_button = Button(text="Reset", command=timer_reset, highlightthickness=0)
timer_label = Label(text="Timer", font=(FONT_NAME, 44,), fg=GREEN, bg=YELLOW)
check_icon = "✓ "
check_label = Label(font=(FONT_NAME, 34, "bold"), fg=GREEN, bg=YELLOW)

# Layout widgets on the window
canvas.grid(column=1, row=1)
timer_label.grid(column=1, row=0)
start_button.grid(column=0, row=2)
reset_button.grid(column=2, row=2)
check_label.grid(column=1, row=2)

# Start the Tkinter event loop
window.mainloop()
