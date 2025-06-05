import time
from turtle import Screen,Turtle
from random import randint,choice

FONT = ("Courier", 24, "normal")

class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.score = 0
        self.color("black")
        self.penup()
        self.hideturtle()
        self.refresh()

    def refresh(self):
        self.goto(-280,260)
        self.write(arg=f"score:{self.score} ",font=FONT)
    
    def game_over(self):
        self.goto(0,0)
        self.write(arg=f"Game Over",align="center",font=FONT)

    def addScore(self):    
        self.score += 1
        self.clear()
        self.refresh()
    
STARTING_POSITION = (0, -280)
MOVE_DISTANCE = 10
FINISH_LINE_Y = 280

class Player(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("turtle")
        self.penup()
        self.right(-90)
        self.restart()

    def move(self):
        self.forward(MOVE_DISTANCE)
    
    def restart(self):
        self.goto(STARTING_POSITION)

COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 10

class CarManager:
    def __init__(self):
        super().__init__()
        self.cars = []
        self.distance = STARTING_MOVE_DISTANCE
        self.create()
    
    def create(self):
        c = Turtle("square")
        c.shapesize(1,2)
        c.penup()
        c.color(choice(COLORS))
        c.setheading(180)
        c.goto(300,randint(-250,250))
        self.cars.append(c)

    
    def move(self):
        for c in self.cars:
            c.forward(self.distance)
    
    def nextLevel(self):
        self.distance += MOVE_INCREMENT

screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)

p = Player()
c = CarManager()
sc = Scoreboard()

screen.listen()
screen.onkey(p.move,"Up")

game_is_on = True
time_counter = 0
while game_is_on:
    if time_counter % 6 == 5:
        c.create()
    time.sleep(0.1)
    screen.update()
    c.move()
    time_counter += 1

    for car in c.cars:
        if car.distance(p) < 20:
            game_is_on = False
            sc.game_over()
    
    if p.ycor() >= FINISH_LINE_Y:
        c.nextLevel()
        p.restart()
        sc.addScore()

screen.exitonclick()
