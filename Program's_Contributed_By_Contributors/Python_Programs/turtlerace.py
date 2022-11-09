from turtle import Turtle, Screen
import random

is_race_on = False
screen = Screen()
screen.setup(width=500, height=400)
screen.title("Turtle Racing Game")
screen.bgcolor("black")
user_bet = screen.textinput(title="Make your bet", prompt="Which turtle will win the race? Enter a color: ")
color = ["orange", "purple", "blue", "green", "yellow", "red"]
y_positions = [-70, -40, -10, 20, 50, 80]
all_turtles = []
for turtle_index in range(0, 6):
    t = Turtle(shape="turtle")
    t.color(color[turtle_index])
    t.penup()
    t.goto(x=-230, y=y_positions[turtle_index])
    all_turtles.append(t)

if user_bet:
    is_race_on = True
while is_race_on:
    
    for turtle in all_turtles:
        if turtle.xcor() > 230:
            is_race_on = False
            winning_color = turtle.pencolor()
            if winning_color == user_bet:
                print(f"You've won! The {winning_color} turtle is the winner! ")
            else:
                print(f"You've lost! The {winning_color} turtle is the winner! ")
        random_distance = random.randint(0, 10)
        turtle.fd(random_distance)

screen.exitonclick()
