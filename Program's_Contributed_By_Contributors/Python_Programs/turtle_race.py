import turtle as t
import random

COLORS = ["purple", "indigo", "blue", "green", "yellow", "orange", "red"]
SCREEN_SIZE = (500, 400)
START_X = -230
START_Y = [150, 100, 50, 0, -50, -100, -150]
END_X = 230

screen = t.Screen()
screen.setup(width=SCREEN_SIZE[0], height=SCREEN_SIZE[1])
user_bet = screen.textinput(title="Make your bet", prompt=f"Pick the turtle color you want to bet on. Options are {COLORS}")
print(f"You chose {user_bet}.")

turtles = []
for index, color in enumerate(COLORS):
    new_turtle = t.Turtle(shape="turtle")
    new_turtle.color(color)
    new_turtle.penup()
    new_turtle.goto(START_X, START_Y[index])
    turtles.append(new_turtle)

game_is_on = True
winner = ""
if user_bet in COLORS:
    while game_is_on:
        for turtle in turtles:
            if game_is_on and turtle.xcor() > END_X:
                game_is_on = False
                winner = turtle.pencolor()
                if winner == user_bet:
                    print(f"Congrats! You won the bet. The {winner} color turtle is the winner.")
                else:
                    print(f"Sorry! You lost the bet. The {winner} color turtle is the winner.")
            random_step = random.randint(1, 10)
            turtle.forward(random_step)

screen.exitonclick()