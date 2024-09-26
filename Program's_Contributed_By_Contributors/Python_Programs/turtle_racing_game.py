 # importing modules
import random as r
import turtle


# one turtle for making tracks.
t = turtle.Turtle()
turtle.title(" Turtle Racing Game ")
turtle.bgcolor("black")
t.speed(0)
t.penup()


# Text at top of  the track.
t.goto(-160,220)
t.color("white")
t.write("Turtle    Racing    Game",font=('Algerian',20,'normal'))

# making tracks.
x = -190
y = 190
for i in range(21):
    t.goto(x,y)
    t.pendown()
    t.write(i)
    t.right(90)
    t.forward(400)
    t.left(90)

    x = x+20
    t.penup()
t.hideturtle()



# creating participating turtles

t1 = turtle.Turtle()
t1.color("red")
t1.shape("turtle")
t1.penup()
t1.goto(-210,120)

t2 = turtle.Turtle()
t2.color("lime")
t2.shape("turtle")
t2.penup()
t2.goto(-210,40)

t3 = turtle.Turtle()
t3.color("sky blue")
t3.shape("turtle")
t3.penup()
t3.goto(-210,-40)

t4 = turtle.Turtle()
t4.color("yellow")
t4.shape("turtle")
t4.penup()
t4.goto(-210,-120)



# movement of each turtle.
for i in range(140):

    t1.forward(r.randint(1,5))
    t2.forward(r.randint(1,5))
    t3.forward(r.randint(1,5))
    t4.forward(r.randint(1,5))

    