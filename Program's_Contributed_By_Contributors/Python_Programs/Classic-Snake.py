import time
from turtle import Screen,Turtle
from random import randint

ALIGNMENT = "center"
FONT = ("Arial",20,"normal")
STARTING_POSITION = [(0,0),(-20,0),(-40,0)]
UP = 90
DOWN = 270
LEFT = 180
RIGHT = 0


class Snake:
    def __init__(self):
        self.segments = []
        self.create_snake()
        self.head = self.segments[0]
        self.head.shape("triangle")

    def create_snake(self):
        for position in STARTING_POSITION:
            self.add_segment(position)
    
    def add_segment(self,position):
        new_segment = Turtle("square")
        new_segment.color("white")
        new_segment.penup()
        new_segment.goto(position)
        self.segments.append(new_segment)

    def extend(self):
        self.add_segment(self.segments[-1].position())
            
    def move(self):
        for seg_num in range(len(self.segments)-1,0,-1):
            new_x = self.segments[seg_num-1].xcor()
            new_y = self.segments[seg_num-1].ycor()
            self.segments[seg_num].goto(new_x,new_y)
        self.head.forward(20)

    def up(self):
        if self.head.heading() != DOWN:
            self.head.setheading(UP)

    def down(self):
        if self.head.heading() != UP:
            self.head.setheading(DOWN)

    def left(self):
        if self.head.heading() != RIGHT:
            self.head.setheading(LEFT)

    def right(self):
        if self.head.heading() != LEFT:
            self.head.setheading(RIGHT) 

class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.penup()
        self.color('white')
        self.hideturtle()
        self.goto(0,270)
        self.score = 0
        self.current_score()
    
    def increase_score(self):
        self.score += 1
        self.clear()
        self.current_score()

    def current_score(self):
        self.write(f"Score: {self.score}",align=ALIGNMENT,font=FONT)
    
    def game_over(self):
        self.goto(0,0)
        self.write("Game Over",align=ALIGNMENT,font=FONT)
class Food(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("turtle")
        self.penup()
        self.shapesize(stretch_len=0.5, stretch_wid = 0.5)
        self.color("red")
        self.speed("fastest")
        random_x = randint(-280,280)
        random_y = randint(-280,270)
        self.goto(random_x, random_y)
        self.refresh_food_location()

    def refresh_food_location(self):
        random_x = randint(-280,280)
        random_y = randint(-280,280)
        self.goto(random_x, random_y)


def Screen_setup():
    screen.setup(width=600, height=600)
    screen.bgcolor("black")

def game():
    Screen_setup()
    screen.title("Snake Game")
    screen.tracer(0)

    snake = Snake()
    food = Food()
    score = Score()

    screen.listen()
    screen.onkey(snake.up,'Up')
    screen.onkey(snake.down,'Down')
    screen.onkey(snake.left,'Left')
    screen.onkey(snake.right,'Right')

    game_is_on = True
    while game_is_on:
        screen.update()
        time.sleep(0.1)
        snake.move()

        #Detect the collision with food
        if snake.head.distance(food) < 15:
            food.refresh_food_location()
            score.increase_score()
            snake.extend()
            
        #Detect the collision with wall
        if snake.head.xcor() >280 or snake.head.xcor() <-280 or snake.head.ycor() > 280 or snake.head.ycor() <-280:
            game_is_on = False
            score.game_over()
            
        #Detect the collision with tail
        for segment in snake.segments[1:]:
            if snake.head.distance(segment)<10:
                game_is_on = False
                score.game_over()

screen = Screen()
Screen_setup()

while screen.textinput("Snake Game", "Do you want to play Snake Game? y/n:").lower() == "y":
    game()
    time.sleep(2)
    screen.clearscreen()
    Screen_setup()
