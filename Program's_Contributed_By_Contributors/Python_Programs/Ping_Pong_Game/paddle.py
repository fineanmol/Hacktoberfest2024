from turtle import Turtle


class Paddle(Turtle):
    def __init__(self,pos):
        super().__init__()
        self.shape("square")
        self.shapesize(stretch_wid=5, stretch_len=1)
        self.penup()
        self.goto(pos)
        self.color("white")

    def go_up(self):
        if self.ycor() < 260:
            new_yaxis = self.ycor() + 20
            self.sety(new_yaxis)

    def go_down(self):
        if self.ycor() > -260:
            new_yaxis = self.ycor() - 20
            self.sety(new_yaxis)
