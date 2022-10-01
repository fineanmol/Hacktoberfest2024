import turtle
import time
import random

delay = 0.1
score = 0
high_score = 0

#Window Screen
wn = turtle.Screen()
wn.title("SNAKE GAME")
wn.bgcolor("black")

wn.setup(width=600,height=600)
wn.tracer(0)

#Head of Snake
head = turtle.Turtle()
head.shape("square")
head.color("green")
head.penup()
head.goto(0, 0)
head.direction = "stop"

#Food in the game
food = turtle.Turtle()
food.speed(0)
food.shape("circle")
food.color("red")
food.penup()
food.goto(0, 100)

#Score
pen = turtle.Turtle()
pen.speed(0)
pen.shape("turtle")
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0, 250)
pen.write("Score : 0  High Score : 0", align="center",
          font=("Times New Roman", 24, "bold"))


#Assigning key values
def goup():
    if head.direction != "down":
        head.direction = "up"

def godown():
    if head.direction != "up":
        head.direction = "down"
        
def goright():
    if head.direction != "left":
        head.direction = "right"
        
def goleft():
    if head.direction != "right":
        head.direction = "left"
        
def move():
    if head.direction == "up":
        y = head.ycor()
        head.sety(y+20)
        
    if head.direction == "down":
        y = head.ycor()
        head.sety(y-20)
        
    if head.direction == "right":
        x = head.xcor()
        head.setx(x+20)
        
    if head.direction == "left":
        x = head.xcor()
        head.setx(x-20)

wn.listen()
wn.onkeypress(goup, "Up")
wn.onkeypress(godown, "Down")
wn.onkeypress(goleft, "Left")
wn.onkeypress(goright, "Right")


#Main Loop
segments = []

while True:
    wn.update()
    #for collisions with border
    if head.xcor() > 290 or head.xcor() < -290 or head.ycor() > 290 or head.ycor() < -290:
        time.sleep(1)
        head.goto(0, 0)
        head.direction = "stop"
        
        #hiding segments of snake
        for segment in segments:
            segment.goto(1000,1000)
        #clearing the segments
        segments.clear()
        
        #reset score
        score = 0
        
        #reset delay
        delay = 0.1
        
        pen.clear()
        pen.write("Score : {} High Score : {} ".format(
            score, high_score), align="center", font=("Times New Roman", 24, "bold"))
        
    #checking collision with food
    if head.distance(food) < 20:
        x = random.randint(-270, 270)
        y = random.randint(-270, 270)
        food.goto(x, y)
        d = ["red","yellow","blue"]
        colors = random.choice(d)
        food.color(colors)
        e = ["circle","square","triangle"]
        shapes = random.choice(e)
        food.shape(shapes)
        
        
        #adding new segment
        new_segment = turtle.Turtle()
        new_segment.speed(0)
        new_segment.color("green")
        new_segment.shape("square")
        new_segment.penup()
        segments.append(new_segment)
        
        delay -= 0.001
        score += 10
        
        if score>high_score:
            high_score = score
        pen.clear()
        pen.write("Score : {} High Score : {} ".format(
            score, high_score), align="center", font=("Times New Roman", 24, "bold"))
        
    #moving segments in reverse order
    for i in range(len(segments)-1,0,-1):
        x = segments[i-1].xcor()
        y = segments[i-1].ycor()
        segments[i].goto(x,y)
    if len(segments) > 0:
        x = head.xcor()
        y = head.ycor()
        segments[0].goto(x, y)
        
    move()
    
    #Checking collisions with body
    for segment in segments:
        if segment.distance(head) < 20:
            time.sleep(1)
            head.goto(0,0)
            head.direction = "stop"
            
            #hide segments
            for segment in segments:
                segment.goto(1000,1000)
            segment.clear()
            
            score = 0
            delay = 0.1
            pen.clear()
            pen.write("Score : {} High Score : {} ".format(
                score, high_score), align="center", font=("Times New Roman", 24, "bold"))
    time.sleep(delay)

turtle.done()

