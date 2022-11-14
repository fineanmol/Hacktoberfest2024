import turtle

t=turtle.Turtle()
t.pencolor("green")

s= turtle.Screen()
s.bgcolor("black")

t.penup()
t.goto(0,200)
t.pendown()
a=0
b=0

t.speed(0)

while True:
    t.forward(a)
    t.right(b)
    a+=3
    b+=1
    if b== 210:
        break
    turtle.hideturtle()


turtle.done()