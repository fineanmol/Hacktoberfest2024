import turtle as t
import random

tim = t.Turtle()
s = t.Screen()

colors = ["#0F3460", "#533483", "#E94560", "#59CE8F", "#66BFBF", "#FF0063", "#4C3A51", "#774360", "#B25068"]


def color_gen():
    rand_color = random.choice(colors)
    return rand_color
    
tim.speed("fastest")
tim.hideturtle()


def draw_spirograph(gap):
    for _ in range(360 // gap):
        tim.color(color_gen())
        tim.circle(100)
        tim.setheading(tim.heading() + gap)


draw_spirograph(5)
s.exitonclick()
