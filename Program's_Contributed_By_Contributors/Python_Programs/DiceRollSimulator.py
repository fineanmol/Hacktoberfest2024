import tkinter
import random

dice = ['\u2680', '\u2681','\u2682','\u2683','\u2684','\u2685',]




root = tkinter.Tk()
canvas = tkinter.Canvas()
root.title('Dice Roll Simulator')
root.geometry('400x400')

frame = tkinter.Frame()
frame.pack(pady=20)


dice_label = tkinter.Label(frame, text='', font=("Helvetica", 100), fg="black")
dice_label.grid(row=0, column=0, padx=5)
sub_dice_label = tkinter.Label(frame,text="",font=("Helvetica", 20))
sub_dice_label.grid(row=1,column=0)



def roll():
    def get_number(x):
        if x == '\u2680':
            return(1)
        elif x == '\u2681':
            return(2)
        elif x == '\u2682':
            return(3)
        elif x == '\u2683':
            return(4)
        elif x == '\u2684':
            return(5)
        elif x == '\u2685':
            return(6)
    d = random.choice(dice)
    sub_d = get_number(d)
    dice_label.config(text=d)
    sub_dice_label.config(text=sub_d)

btn = tkinter.Button(root,text="Roll",command=roll,font=("Helvetica",25))
btn.pack(pady=20)
root.mainloop()