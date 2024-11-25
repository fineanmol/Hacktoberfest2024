from turtle import *
import turtle

t = turtle.Turtle()
def draw_circle(color, radius, x, y):
  t.penup()
  t.fillcolor(color,)
  t.goto(x,y)
  t.pendown()
  t.begin_fill()
  t.circle(radius)
  t.end_fill()
 

t = turtle.Turtle()
t.color('red', 'blue')

def eye():
    
    draw_circle("Black",210, -22, -150)
    draw_circle("Red", 196, -20, -135)
    draw_circle("Black", 50, -20, 15)

    t.color('Black', 'blue')

    draw_circle("Black",35, -120, -67)
    t.color('red', 'blue')
    draw_circle("Red", 35, -130, -65)
    t.color('Black', 'blue')
    draw_circle("Black",34, -120, -60)


    draw_circle("Black",35, 98, -2)
    t.color('red', 'blue')
    draw_circle("Red", 35, 85, 0)
    t.color('Black', 'blue')
    draw_circle("Black",34, 100, -10)


    draw_circle("Black",35, -40, 155)
    t.color('red', 'blue')
    draw_circle("Red", 35, -55, 150)
    t.color('Black', 'blue')
    draw_circle("Black",34, -37, 148)
    turtle.hideturtle()


if __name__ == '__main__':
    screensize(8000, 6000, "#f0f0f0")
    turtle.Screen().bgcolor("#dceaf6")
  
    pensize(3)
    speed(9)
    eye()
    
 
