from tkinter import *
from tkinter.ttk import *

from time import strftime

root = Tk()
root.title("Clock")

def time_clock():
    string= strftime('%H:%M:%S %p')
    label.config(text=string)
    label.after(1000,time_clock)

label= Label(root, font=("ds-digital",100),background= "Black", foreground = "Cyan")
label.pack(anchor='center')
time_clock()

mainloop()
