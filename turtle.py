import turtle
import random
s= turtle.getscreen()
t = turtle.Turtle()
t.speed(0.1)
t.width(5)

colors =["red","blue","green","yellow","pink","#4f06bd","#e30031","#eda200"]
def up():
    t.setheading(90)
    t.forward(100)

def down():
    t.setheading(270)
    t.forward(100)
    
def left():
    t.setheading(180)
    t.forward(100)
    
def right():
    t.setheading(0)
    t.forward(100)
    
def clickleft(x,y):
    t.color(random.choice(colors))

def clickright(x,y):
    t.clear()
def home():
    t.penup()
    t.home()
    t.pendown()
turtle.listen()

turtle.onkey(up ,'w')
turtle.onkey(down ,'s')
turtle.onkey(left ,'a')
turtle.onkey(right ,'d')
turtle.onkey(home ,'space')

turtle.onscreenclick(clickleft , 1)
turtle.onscreenclick(clickright, 3)

turtle.mainloop()

