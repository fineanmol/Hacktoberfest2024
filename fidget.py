from turtle import *
  
state= {'turn':0 }
   
def spin():
    clear()
    
    
    angle = state['turn']/10
    
    right(angle)
    forward(20)
    penup()
    forward(60)
    dot(130, 'orange')
    dot(80, 'red')
    dot(50,'lightblue')
    back(60)
    pendown()
    back(20)
    
    "second dot"
    right(120)
    forward(20)
    penup()
    forward(60)
    dot(130, 'orange')
    dot(80, 'red')
    dot(50,'lightblue')
    back(60)
    pendown()
    back(20)
   
    "third dot"
    right(120)
    forward(20)
    penup()
    forward(60)
    dot(130, 'orange')
    dot(80, 'red')
    dot(50,'lightblue')
    back(60)
    pendown()
    back(20)
   
    update()
    dot(45,'red')
   
def animate():
    if state['turn']>0:
        state['turn']-=1
       
    spin()
    ontimer(animate, 20)
       
def flick():
    state['turn']+=40 #acceleration of spinner
   
setup(600, 400, 400, 0)
bgcolor('lightblue')
   
tracer(False)
   
width(60)
color("orange")

   
onkey(flick,'space')
   
listen()
animate()
done()