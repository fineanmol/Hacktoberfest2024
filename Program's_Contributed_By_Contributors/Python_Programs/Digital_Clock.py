import time
from tkinter import *


def timing():
    current_timing = time.strftime('%H:%M:%S')
    clock.config(text=current_timing)
    clock.after(200, timing)


tk_window = Tk()
tk_window.geometry('350x120')
tk_window.title("Digital Clock")

clock = Label(tk_window, font=("Helvetica", 60, "italic"), fg="#00FF33", bg="#000000")
clock.grid(row=1, column=2, pady=10, padx=10)
timing()

tk_window.mainloop()
