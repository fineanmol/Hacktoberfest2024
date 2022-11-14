from tkinter import *
import time
import random

root = Tk()
root.title("Bounce Ball Game")
root.geometry("500x570")
root.resizable(0, 0)
root.wm_attributes("-topmost", 1)
canvas = Canvas(root, width=500, height=500, bd=0, highlightthickness=0, highlightbackground="Red", bg="Black")
canvas.pack(padx=10, pady=10)
score = Label(height=50, width=80, text="Score: 00", font="Calibri 14 italic")
score.pack(side="left")
root.update()


class Ball:
    def __init__(self, cvs, clr, pole, stones, scre):
        self.stones = stones
        self.cvs = cvs
        self.pole = pole
        self.scre = scre
        self.bottom_hit = False
        self.hit = 0
        self.id = canvas.create_oval(10, 10, 25, 25, fill=clr, width=1)
        self.cvs.move(self.id, 230, 461)
        start = [4, 3.8, 3.6, 3.4, 3.2, 3, 2.8, 2.6]
        random.shuffle(start)

        self.a = start[0]
        self.b = -start[0]
        self.cvs.move(self.id, self.a, self.b)
        self.cvs_height = canvas.winfo_height()
        self.cvs_width = canvas.winfo_width()

    def stone_strike(self, push):
        for stone_line in self.stones:
            for stone in stone_line:
                stone_push = self.cvs.coords(stone.id)

                try:
                    if push[2] >= stone_push[0] and push[0] <= stone_push[2]:
                        if push[3] >= stone_push[1] and push[1] <= stone_push[3]:
                            canvas.bell()
                            self.hit += 1
                            self.scre.configure(text="Score: " + str(self.hit))
                            self.cvs.delete(stone.id)
                            return True
                except:
                    continue
        return False

    def pole_strike(self, push):
        pole_push = self.cvs.coords(self.pole.id)
        if push[2] >= pole_push[0] and push[0] <= pole_push[2]:
            if push[3] >= pole_push[1] and push[1] <= pole_push[3]:

                return True
            return False

    def draw(self):
        self.cvs.move(self.id, self.a, self.b)
        push = self.cvs.coords(self.id)
        # print(pos)
        start = [4, 3.8, 3.6, 3.4, 3.2, 3, 2.8, 2.6]
        random.shuffle(start)
        if self.stone_strike(push):
            self.b = start[0]
        if push[1] <= 0:
            self.b = start[0]
        if push[3] >= self.cvs_height:
            self.bottom_hit = True
        if push[0] <= 0:
            self.a = start[0]
        if push[2] >= self.cvs_width:
            self.a = -start[0]
        if self.pole_strike(push):
            self.b = -start[0]


class Pole:
    def __init__(self, cvs, clr):
        self.cvs = cvs
        self.id = canvas.create_rectangle(0, 0, 100, 10, fill=clr)
        self.cvs.move(self.id, 200, 485)
        self.a = 0
        self.pauseSeconds = 0
        self.cvs_width = canvas.winfo_width()
        self.cvs.bind_all("<Left>", self.turn_left)
        self.cvs.bind_all("<Right>", self.turn_right)
        self.cvs.bind_all("<space>", self.pauseSeconds)

    def draw(self):
        push = self.cvs.coords(self.id)
        # print(pos)
        if push[0] + self.a <= 0:
            self.a = 0
        if push[2] + self.a >= self.cvs_width:
            self.a = 0
        self.cvs.move(self.id, self.a, 0)

    def turn_left(self, event):
        self.a = -3.5

    def turn_right(self, event):
        self.a = 3.5

    def pause(self, event):
        self.pauseSeconds += 1
        if self.pauseSeconds == 2:
            self.pauseSeconds = 0


class Stone:
    def __init__(self, cvs, clr):
        self.cvs = cvs
        self.id = canvas.create_oval(5, 5, 25, 25, fill=clr, width=2)


playing = False


def start_game(event):
    global playing
    if playing is False:
        playing = True
        score.configure(text="Score: 00")
        canvas.delete("all")
        BALL_COLOR = ["blue", "green", "violet"]
        STONE_COLOR = ["green", "dark blue", "red", "pink", "violet", "yellow",
                       "orange", "gray", "brown", "white", "blue", "yellow green",
                       "navajo white", "dark gray", "violet red", "powder blue", "blue violet"]
        random.shuffle(BALL_COLOR)
        pole = Pole(canvas, "yellow")
        stones = []
        for i in range(0, 5):
            b = []
            for j in range(0, 19):
                random.shuffle(STONE_COLOR)
                tmp = Stone(canvas, STONE_COLOR[0])
                b.append(tmp)
            stones.append(b)

        for i in range(0, 5):
            for j in range(0, 19):
                canvas.move(stones[i][j].id, 25 * j, 25 * i)

        ball = Ball(canvas, BALL_COLOR[0], pole, stones, score)
        root.update_idletasks()
        root.update()

        time.sleep(1)
        while 1:
            if pole.pauseSeconds != 1:
                try:
                    canvas.delete(m)
                    del m
                except:
                    pass
                if not ball.bottom_hit:
                    ball.draw()
                    pole.draw()
                    root.update_idletasks()
                    root.update()
                    time.sleep(0.01)
                    if ball.hit == 95:
                        canvas.create_text(250, 250, text="YOU WON !!", fill="yellow", font="Calibri 24 ")
                        root.update_idletasks()
                        root.update()
                        playing = False
                        break
                else:
                    canvas.create_text(250, 250, text="GAME OVER!!", fill="red", font="Calibri 24 ")
                    root.update_idletasks()
                    root.update()
                    playing = False
                    break
            else:
                try:
                    if m == None: pass
                except:
                    m = canvas.create_text(250, 250, text="PAUSE!!", fill="green", font="Calibri 24 ")
                root.update_idletasks()
                root.update()


root.bind_all("<Return>", start_game)
canvas.create_text(250, 250, text="Press Enter to start Game!!", fill="yellow", font="Calibri 18")
j = canvas.find_all()
root.mainloop()
