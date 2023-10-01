from tkinter import *
import random

move = ["rock", "paper", "scissor"]

def fun():
    computer = move[random.randint(0,2)]
    player = var.get()
    choose.config(text="Player choose " + player + " and computer choose " + computer)
    if player==computer:
        result.config(text="Its a Tie")

    elif player=="rock":
        if computer=="paper":
            result.config(text="Computer Win")

        elif computer=="scissor":
            result.config(text="Player Win")

    elif player=="paper":
        if computer=="scissor":
            result.config(text="Computer Win")

        elif computer=="rock":
            result.config(text="Player Win")

    elif player=="scissor":
        if computer=="rock":
            result.config(text="Computer Win")

        elif computer=="paper":
            result.config(text="Player Win")

root = Tk()
#root.geometry('250x300')

global result, var, choose

var=StringVar()

Rock = Radiobutton(root, text="Rock", variable=var, value="rock")
Rock.grid(row=0, column=0, padx=10, pady=10)
Rock.select()

Paper = Radiobutton(root, text="Paper", variable=var, value="paper")
Paper.grid(row=0, column=1, padx=10, pady=10)

Scissor = Radiobutton(root, text="Scissor", variable=var, value="scissor")
Scissor.grid(row=0, column=2, padx=10, pady=10)

submit = Button(root, text="submit", command=fun)
submit.grid(row=1, column=0, padx=10, pady=10, columnspan=3)

choose = Label(root, text="")
choose.grid(row=2, column=0, padx=10, pady=10, columnspan=3)

result = Label(root, text="")
result.grid(row=3, column=0, padx=10, pady=10, columnspan=3) 

root.mainloop()
