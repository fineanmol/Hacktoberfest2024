from tkinter import *
from tkinter import ttk
import tkinter.messagebox
field = []
PLAYER1 = []
PLAYER2 = []
i = 0
j = 0
VICTORY = {(1, 2, 3), (4, 5, 6), (7, 8, 9), (1, 5, 9), (3, 5, 7), (1, 4, 7), (3, 6, 9), (2, 5, 8)}


class App:

    def __init__(self, master):

        self.frame1 = Frame(master)
        self.frame1.grid(row=0, columnspan=3)
        self.L1 = Label(master, text="PLAYER1")
        self.L1.grid(row=0, column=0)
        self.L2 = Label(master, text="Draw")
        self.L2.grid(row=0, column=1)
        self.L3 = Label(master, text="PLAYER2")
        self.L3.grid(row=0, column=2)
        self.frame2 = Frame(master)
        self.frame2.grid(row=1, columnspan=3)
        self.L4 = Label(master, text="#") 
        self.L4.grid(row=1, column=0)
        self.L5 = Label(master, text="#")  
        self.L5.grid(row=1, column=1)
        self.L6 = Label(master, text="#")  
        self.L6.grid(row=1, column=2)

        self.frame3 = Frame(master)
        self.frame3.grid(row=2, column=0)
        self.c1 = Canvas(self.frame3, width=70, height=70)
        self.c1.bind("<Button-1>", lambda event, args=self.c1: self.printX(event, args))
        self.c1.grid(sticky=NW)
        self.c1.create_line(70, 0, 70, 70)
        self.frame4 = Frame(master)
        self.frame4.grid(row=2, column=1)
        self.c2 = Canvas(self.frame4, width=70, height=70)
        self.c2.grid(sticky=NW)
        self.c2.create_line(70, 0, 70, 70)
        self.frame5 = Frame(master)
        self.frame5.grid(row=2, column=2)
        self.c3 = Canvas(self.frame5, width=70, height=70)
        self.c3.grid(sticky=NW)

        self.frame6 = Frame(master)
        self.frame6.grid(row=3, column=0)
        self.c4 = Canvas(self.frame6, width=70, height=70)
        self.c4.grid(sticky=NW)
        self.c4.create_line(1, 1, 69, 1)
        self.c4.create_line(70, 0, 70, 70)
        self.frame7 = Frame(master)
        self.frame7.grid(row=3, column=1)
        self.c5 = Canvas(self.frame7, width=70, height=70)
        self.c5.grid(sticky=NW)
        self.c5.create_line(1, 1, 69, 1)
        self.c5.create_line(70, 0, 70, 70)
        self.frame8 = Frame(master)
        self.frame8.grid(row=3, column=2)
        self.c6 = Canvas(self.frame8, width=70, height=70)
        self.c6.grid(sticky=NW)
        self.c6.create_line(1, 1, 69, 1)

        self.frame9 = Frame(master)
        self.frame9.grid(row=4, column=0)
        self.c7 = Canvas(self.frame9, width=70, height=70)
        self.c7.grid(sticky=NW)
        self.c7.create_line(1, 1, 69, 1)
        self.c7.create_line(70, 0, 70, 70)
        self.frame10 = Frame(master)
        self.frame10.grid(row=4, column=1)
        self.c8 = Canvas(self.frame10, width=70, height=70)
        self.c8.grid(sticky=NW)
        self.c8.create_line(1, 1, 69, 1)
        self.c8.create_line(70, 0, 70, 70)
        self.frame11 = Frame(master)
        self.frame11.grid(row=4, column=2)
        self.c9 = Canvas(self.frame11, width=70, height=70)
        self.c9.grid(sticky=NW)
        self.c9.create_line(1, 1, 69, 1)

    def printX(self, event, x):
        if x == self.c1:
            if 1 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(1)
                PLAYER1.append(1)
                self.play("PLAYER2")

            else:
                pass
        elif x == self.c2:
            if 2 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(2)
                PLAYER1.append(2)
                self.play("PLAYER2")
            else:
                pass
        elif x == self.c3:
            if 3 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(3)
                PLAYER1.append(3)
                self.play("PLAYER2")
            else:
                pass
        elif x == self.c4:
            if 4 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(4)
                PLAYER1.append(4)
                self.play("PLAYER2")
            else:
                pass
        elif x == self.c5:
            if 5 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(5)
                PLAYER1.append(5)
                self.play("PLAYER2")
            else:
                pass
        elif x == self.c6:
            if 6 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(6)
                PLAYER1.append(6)
                self.play("PLAYER2")
            else:
                pass
        elif x == self.c7:
            if 7 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(7)
                PLAYER1.append(7)
                self.play("PLAYER2")
            else:
                pass
        elif x == self.c8:
            if 8 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(8)
                PLAYER1.append(8)
                self.play("PLAYER2")
            else:
                pass
        elif x == self.c9:
            if 9 not in field:
                x.create_line(10, 10, 60, 60)
                x.create_line(10, 60, 60, 10)
                field.append(9)
                PLAYER1.append(9)
                self.play("PLAYER2")
            else:
                pass


    def printO(self, event, x):
        if x == self.c1:
            if 1 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(1)
                PLAYER2.append(1)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c2:
            if 2 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(2)
                PLAYER2.append(2)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c3:
            if 3 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(3)
                PLAYER2.append(3)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c4:
            if 4 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(4)
                PLAYER2.append(4)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c5:
            if 5 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(5)
                PLAYER2.append(5)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c6:
            if 6 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(6)
                PLAYER2.append(6)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c7:
            if 7 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(7)
                PLAYER2.append(7)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c8:
            if 8 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(8)
                PLAYER2.append(8)
                self.play("PLAYER1")
            else:
                pass
        elif x == self.c9:
            if 9 not in field:
                x.create_oval(25, 25, 50, 50)
                field.append(9)
                PLAYER2.append(9)
                self.play("PLAYER1")
            else:
                pass


    def play(self, turn):
        Game = True
        i = 0
        j = 0
        while Game:
            for k in VICTORY:
                x = set(k)
                if x.issubset(set(PLAYER1)):
                    tkinter.messagebox.showinfo("NOTICE", "PLAYER 1 WON")


                elif x.issubset(set(PLAYER2)):
                    tkinter.messagebox.showinfo("NOTICE", "PLAYER 2 WON")

                elif(len(field)==9):
                    tkinter.messagebox.showinfo("NOTICE", "MATCH ENDED IN A DRAW")
                    field.append(10)
                    Game = False
                    break
                else:
                    pass
            if(turn == "PLAYER1"):
                self.c1.bind("<Button-1>", lambda event, args=self.c1: self.printX(event, args)) 
                self.c2.bind("<Button-1>", lambda event, args=self.c2: self.printX(event, args))
                self.c3.bind("<Button-1>", lambda event, args=self.c3: self.printX(event, args))
                self.c4.bind("<Button-1>", lambda event, args=self.c4: self.printX(event, args))
                self.c5.bind("<Button-1>", lambda event, args=self.c5: self.printX(event, args))
                self.c6.bind("<Button-1>", lambda event, args=self.c6: self.printX(event, args))
                self.c7.bind("<Button-1>", lambda event, args=self.c7: self.printX(event, args))
                self.c8.bind("<Button-1>", lambda event, args=self.c8: self.printX(event, args))
                self.c9.bind("<Button-1>", lambda event, args=self.c9: self.printX(event, args))

                turn = "PLAYER2"
                i = i+1
                print(i)
                print("i")
                break
            else:
                self.c1.bind("<Button-1>", lambda event, args=self.c1: self.printO(event, args))
                self.c2.bind("<Button-1>", lambda event, args=self.c2: self.printO(event, args))
                self.c3.bind("<Button-1>", lambda event, args=self.c3: self.printO(event, args))
                self.c4.bind("<Button-1>", lambda event, args=self.c4: self.printO(event, args))
                self.c5.bind("<Button-1>", lambda event, args=self.c5: self.printO(event, args))
                self.c6.bind("<Button-1>", lambda event, args=self.c6: self.printO(event, args))
                self.c7.bind("<Button-1>", lambda event, args=self.c7: self.printO(event, args))
                self.c8.bind("<Button-1>", lambda event, args=self.c8: self.printO(event, args))
                self.c9.bind("<Button-1>", lambda event, args=self.c9: self.printO(event, args))

                j = j+1
                print(j)
                print("j")

                turn = "PLAYER1"
                break
        if len(field) < 10:
            pass
        else:
            if(len(field)==9):
                tkinter.messagebox.showinfo("NOTICE", "MATCH ENDED IN A DRAW")
                Game = False


root = Tk()
a = App(root)
a.play("PLAYER1")
root.mainloop()
