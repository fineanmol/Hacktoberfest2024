from tkinter import *
from tkinter import font
import math
# ---------------------------- CONSTANTS ------------------------------- #
PINK = "#e2979c"
RED = "#e7305b"
GREEN = "#9bdeac"
YELLOW = "#f7f5dd"
FONT_NAME = "Courier"
WORK_MIN = 25
SHORT_BREAK_MIN = 5
LONG_BREAK_MIN = 20
CHECK_MARK = "✔"
reps = 0
timer = None
# ---------------------------- TIMER RESET ------------------------------- # 

def reser_timer():
    window.after_cancel(timer)
    canvas.itemconfig(timer_text, text="00:00")
    label.config(text="Timer")
    check_mark["text"] = ""

    


# ---------------------------- TIMER MECHANISM ------------------------------- # 

def start_timer():
    global reps
    reps +=1
    work_sec = WORK_MIN*60
    short_break_sec = SHORT_BREAK_MIN*60
    long_break_sec = LONG_BREAK_MIN*60
    if reps%8 == 0:
        count_down(long_break_sec)
        label.config(text="Break", fg=RED)
        
    elif reps%2==0:
        count_down(short_break_sec)
        label.config(text="Break" , fg=YELLOW)

    else:
        count_down(work_sec)
        label.config(text="Work")
        

    

# ---------------------------- COUNTDOWN MECHANISM ------------------------------- # 
def count_down(count):

    min = math.floor(count/60)
    sec = count%60
    if sec < 10 and min < 10:
        time= f"0{min}:0{sec}"
    elif min <10:
        time = f"0{min}:{sec}"
    elif sec < 10:
        time= f"{min}:0{sec}"
    else:
        time = f"{min}:{sec}"

    canvas.itemconfig(timer_text, text=time)
    if count>=0:
        global timer
        timer = window.after(1000, count_down, count - 1)

    else:
        start_timer()
        if reps%2 ==0:
            check_mark["text"] += CHECK_MARK


# ---------------------------- UI SETUP ------------------------------- #
window = Tk()
window.config(padx=100,pady=100, background=YELLOW)
window.title("Pomodoro Technique")

tomato_image = PhotoImage(file="./tomato.png")

canvas = Canvas(width=200,height=224, bg=YELLOW, highlightthickness=0)
canvas.create_image(100, 112, image=tomato_image)
timer_text = canvas.create_text(100,120, text="00:00", fill="white", font=(FONT_NAME, 24, "bold"))
canvas.grid(column=1, row=1)

label = Label(text="Timer", fg=GREEN, bg=YELLOW, font=(FONT_NAME, 30, "bold"))
label.grid(column=1, row=0)

start_btn = Button(text="Start",command=start_timer)
start_btn.config(pady=5,padx=10, bg="white",relief="flat",activebackground="white")
start_btn.grid(column=0,row=2)

reset_btn = Button(text="Reset", command=reser_timer)
reset_btn.config(pady=5,padx=10, bg="white",relief="flat",activebackground="white")
reset_btn.grid(column=2, row=2)

check_mark = Label(fg=GREEN, bg=YELLOW, font=(20))
check_mark.grid(column=1,row=3)






window.mainloop()
