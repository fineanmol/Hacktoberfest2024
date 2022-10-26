import time
from turtle import Screen,Turtle
import random

COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 5
STARTING_POSITION = (0, -280)
MOVE_DISTANCE = 10
FINISH_LINE_Y = 280
FONT = ("Courier", 24, "normal")


class Scoreboard(Turtle):

    def __init__(self):
        super().__init__()
        self.penup()
        self.hideturtle()
        self.level = 1

    def update_scoreboard(self):
        self.clear()
        self.goto(-280, 260)
        self.level_string = "Level: " + str(self.level)
        self.write(self.level_string, align="left", font=FONT)

    def update_score(self):
        self.level += 1

class Player(Turtle):

    def __init__(self):
        super().__init__()
        self.penup()
        self.shape("square")
        self.shape("turtle")
        self.goto(STARTING_POSITION)
        self.setheading(90)
        self.finish_line = FINISH_LINE_Y

    def go_up(self):
        self.forward(MOVE_DISTANCE)

    def go_left(self):
        new_x = self.xcor() - MOVE_DISTANCE
        new_pos = (new_x, self.ycor())
        self.goto(new_pos)

    def go_right(self):
        new_x = self.xcor() + MOVE_DISTANCE
        new_pos = (new_x, self.ycor())
        self.goto(new_pos)

    def start_position(self):
        # self.hideturtle()
        self.goto(STARTING_POSITION)
        # self.showturtle()

class CarManager(Turtle):

    # Car Generator
    def __init__(self):
        super().__init__()
        self.y_coor_list = []
        self.x_coor_list = []
        self.coordinate_generator()
        self.move_speed = STARTING_MOVE_DISTANCE
        self.car_generator()
        self.still = True

    # Car Move Algorithm
    def moving(self):
        new_position = (self.xcor() - self.move_speed, self.ycor())
        self.goto(new_position)
        if self.still and self.xcor() < -320:
            self.reset_car()


    def next_level(self):
        self.move_speed += MOVE_INCREMENT

    # List Generator
    def car_generator(self):
        self.shape("square")
        self.shapesize(stretch_wid=1, stretch_len=2)
        self.color(random.choice(COLORS))
        self.penup()
        coordinate = (random.choice(self.x_coor_list), random.choice(self.y_coor_list))
        self.goto(coordinate)
        self.setheading(180)

    def coordinate_generator(self):
        for i in range(50):
            self.y_coor_list.append(10 * (i - 25))
        for i in range(50):
            self.x_coor_list.append(320 + i * 10)

    def reset_car(self):
        # self.hideturtle()
        coordinate = (random.choice(self.x_coor_list), random.choice(self.y_coor_list))
        self.goto(coordinate)
        # self.showturtle()

    def remove_car(self):
        pass


MAX_CAR_ON_SCREEN = 40

screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)
screen.listen()


# Create player variable
player = Player()

# Create Scoreboard Variable
scoreboard = Scoreboard()

# Create Car Obstacle Variable
car_manager = []
for i in range(MAX_CAR_ON_SCREEN):
    car_manager.append(CarManager())

# Listenable Player Variable
screen.onkey(key="Up", fun=player.go_up)
screen.onkey(key="Left", fun=player.go_left)
screen.onkey(key="Right", fun=player.go_right)

game_is_on = True
scoreboard.update_scoreboard()
total_car = len(car_manager)
car_decrease = 0
while game_is_on:

    for car in car_manager:
        car.moving()
        distance_x = car.xcor()-player.xcor()
        distance_y = car.ycor()-player.ycor()
        abs_distance_x = abs(distance_x)
        abs_distance_y = abs(distance_y)
        if player.distance(car) <= 29:
            game_is_on = False
        if distance_y <= -20 and 20 <= player.distance(car) <= 29:
            game_is_on = True

    # Condition Lose And Next Level Recognition
    if player.ycor() > player.finish_line:
        player.start_position()
        # Connecting to Scoreboard
        scoreboard.update_score()
        scoreboard.update_scoreboard()
        # Update Condition
        car_decrease -= 3
        for car in car_manager:
            car.next_level()
        if total_car + car_decrease > 10:
            for car in car_manager[car_decrease:]:
                car.still = False
    time.sleep(0.1)
    screen.update()

# Final Condition
screen.exitonclick()