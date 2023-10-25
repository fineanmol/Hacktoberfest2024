import math
from tkinter import *
# ---------------------------- CONSTANTS ------------------------------- #
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
FONT_NAME = "Courier"
WORK_MIN = 25
SHORT_BREAK_MIN = 5
LONG_BREAK_MIN = 20
REPS = 0
TIMER = str()

# ---------------------------- TIMER RESET ------------------------------- #


def reset_timer():
    global REPS, LONG_BREAK_MIN, SHORT_BREAK_MIN, WORK_MIN
    REPS, LONG_BREAK_MIN, SHORT_BREAK_MIN, WORK_MIN = 0, 20, 5, 25
    window.after_cancel(TIMER)
    canvas.itemconfig(time_text, text="00:00")
    label_checkmark.config(text="")
    work_break_label.config(text="Work")


# ---------------------------- TIMER MECHANISM ------------------------------- #

def start_timer():
    global REPS
    REPS += 1
    work_sec = WORK_MIN * 60
    short_sec = SHORT_BREAK_MIN * 60
    long_sec = LONG_BREAK_MIN * 60
    if REPS == 8:
        Label.config(work_break_label, text="20 min Break")
        count_down(long_sec)
    elif REPS > 8:
        reset_timer()
        return
    elif REPS % 2 == 0:
        Label.config(work_break_label, text="5 min Break")
        count_down(short_sec)
    else:
        Label.config(work_break_label, text="Work")
        count_down(work_sec)


# ---------------------------- COUNTDOWN MECHANISM ------------------------------- #
def count_down(count):
    count_min = count // 60
    count_sec = count % 60
    if count_sec < 10:
        count_sec = "0" + str(count_sec)
    if count_min < 10:
        count_min = "0" + str(count_min)
    canvas.itemconfig(time_text, text=f"{count_min}:{count_sec}")
    if count > 0:
        global TIMER
        TIMER = window.after(1000, count_down, count-1)
    else:
        start_timer()
        marks = ""
        work_session = math.floor(int(REPS/2))

        for i in range(work_session):
            marks += "✨"
        label_checkmark.config(text=marks, font=(FONT_NAME, 25, "bold"))


# ---------------------------- UI SETUP ------------------------------- #

window = Tk()
window.title("Pomodoro Technique")
window.config(padx=100, pady=100, bg=YELLOW, width=600, height=500)


label_timer = Label(text="Timer", fg=GREEN, bg=YELLOW, highlightthickness=0, font=(FONT_NAME, 50, "bold"))
label_timer.grid(column=1, row=0)


canvas = Canvas(width=200, height=224, highlightthickness=0, bg=YELLOW)
tomato_img = PhotoImage(file="tomato.png")
canvas.create_image(100, 112, image=tomato_img)
time_text = canvas.create_text(100, 135, text="00:00", font=(FONT_NAME, 40, "bold"), fill="white")
canvas.grid(column=1, row=1)


start_button = Button(text="Start", bg=PINK, fg="white", highlightthickness=0, font=(FONT_NAME, 30, "normal"),
                      command=start_timer)
start_button.config(pady=25)
start_button.grid(column=0, row=2)

reset_button = Button(text="Reset", bg=PINK, fg="white", highlightthickness=0, font=(FONT_NAME, 30, "normal"),
                      command=reset_timer)
reset_button.config(pady=25)
reset_button.grid(column=2, row=2)

work_break_label = Label(text="Work", bg=YELLOW, fg=RED, font=(FONT_NAME, 45, "bold"))
work_break_label.grid(column=3, row=1)

label_checkmark = Label(text="", fg=GREEN, bg=YELLOW, highlightthickness=0)
label_checkmark.grid(column=1, row=2)
label_checkmark.config(pady=10, padx=10)


window.mainloop()