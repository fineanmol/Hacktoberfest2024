#importing the module
from turtle import *

#width of the pen
width(30)

#backgroround of the gui
bgcolor("black")

#red color type part of logo
up()
goto(0,0)
down()
color("#db0f3c")
left(180)
circle(50,270)
forward(120)
left(180)
circle(50,90)

#sky blue part of logo 
up()
goto(-5,13)
down()
color("#50ebe7")
left(180)
circle(50,270)
forward(120)
left(180)
circle(50,90)

#white part of logo
up()
goto(-5,5)
down()
color("white")
left(180)
circle(50,270)
forward(120)
left(180)
circle(50,90)

#end of the program
done()