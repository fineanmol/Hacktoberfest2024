from turtle import Turtle


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.color("white")
        self.hideturtle()
        self.l_score = 0
        self.r_score = 0
        self.penup()
        self.update_score()

    def update_score(self):
        self.clear()
        self.goto(-100, 200)
        self.write(self.l_score, font=("courier", 80, "normal"), align="center")
        self.goto(100, 200)
        self.write(self.r_score, font=("courier", 80, "normal"), align="center")

    def update_l_score(self):
        self.l_score += 1
        self.update_score()

    def update_r_score(self):
        self.r_score += 1
        self.update_score()

    def game_over(self,player):
        self.goto(0,0)
        self.write(f"The {player} side player is the winner",font=("courier", 20, "normal"),align="center")