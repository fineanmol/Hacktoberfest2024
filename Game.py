from turtle import *
  
state= {'turn':0 }
   
def spin():
    clear()
   
    angle = state['turn']/10
   
    right(angle)
    forward(100)
    dot(130, 'blue')
   
    back(100)
   
    "second dot"
    right(120)
    forward(100)
    dot(130, 'yellow')
    back(100)
   
    "third dot"
    right(120)
    forward(100)
    dot(130, 'red')
    back(100)
    right(120)
   
    update()
   
def animate():
    if state['turn']>0:
        state['turn']-=1
       
    spin()
    ontimer(animate, 20)
       
def flick():
    state['turn']+=40 #acceleration of spinner
   
setup(600, 400, 370, 0)
bgcolor("black")
   
tracer(False)
   
width(60)
color("orange")
   
onkey(flick,'space')
   
listen()
animate()
done()
