from turtle import Turtle, Screen
import random
print("Welcome to Turtle Race  🐢 🐢 🐢 🐢")
t = Turtle()
s = Screen()
s.setup(width=500, height=400)  # Setting up Screen Size
# Pop Up Window
bet = s.textinput(title=" Make your Bet: ", prompt="Which Turtle will Win the Race? Enter a Color: ")
s.title("Turtle Race 🏁")
colors = ["red", "orange", "yellow", "green", "blue", "purple"]
y_pos = [-70, -40, -10, 20, 50, 80]
all_tur = []
t.hideturtle()
print("Race Started 🏁 🏁 🏁")
for t_ind in range(0, 6):
    # Goto allows to define x and y coordinates
    t = Turtle("turtle")
    t.color(colors[t_ind])
    t.penup()
    t.goto(x=-230, y=y_pos[t_ind])
    all_tur.append(t)

is_race = False
if bet:
    is_race = True
while is_race:
    for tur in all_tur:
        if tur.xcor() > 230:
            is_race = False
            w_col = (tur.pencolor())
            if w_col == bet:
                print(f"You Have Won! Turtle with {w_col} color is the Winner! ")
            else:
                print(f"You Have Lost!  Turtle with {w_col} color is the Winner!")

        d = random.randint(0, 10)
        tur.forward(d)
s.exitonclick()