from turtle import Turtle, Screen
import random
import time
ALIGNMENT="center"
FONT=("Courier", 20, "normal")

def Screen_setup():
    screen.setup(width=500, height=400)
    screen.title("Turtle Race")
    
def game():
    is_race_on = False
    game_over = Turtle()
    game_over.hideturtle()
    game_over.goto(0,0)
    Screen_setup()
    colors =['violet','indigo','blue','green','yellow','orange','red']
    user_bet = screen.textinput("Make Your Bet",f"Which turtle will win the race: ? Enter a color? {tuple(colors)} ").lower()

    y_start = [180,120,60,0,-60,-120,-180]
    all_turtles =[]

    if user_bet in colors:
        is_race_on = True
    else:
        screen.bye()
        
    for i in range(len(colors)):
        new_turtle = Turtle(shape='turtle')
        new_turtle.color(colors[i])
        new_turtle.penup()
        new_turtle.goto(x=-220,y=y_start[i])
        all_turtles.append(new_turtle)
    while is_race_on:
        for turtle in all_turtles:
            if turtle.xcor()> 230:
                is_race_on = False
                winner =turtle.pencolor()
                if user_bet == winner:
                    game_over.write(f"You've won!\nThe {winner} turtle has won!",align=ALIGNMENT,font=FONT)
                else:
                    game_over.write(f"You lost your bet!\nThe {winner} turtle won!",align=ALIGNMENT,font=FONT)
            movement = random.randint(0,10)
            turtle.forward(movement)

screen = Screen()
Screen_setup()

while screen.textinput("Turtle Race", "Do you want to bet on Turtle Race? y/n:").lower() == "y":
    game()
    time.sleep(3)
    screen.clearscreen()


screen.bye()
screen.exitonclick()