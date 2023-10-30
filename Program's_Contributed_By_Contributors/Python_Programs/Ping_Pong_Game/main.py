from turtle import Turtle,Screen
from paddle import Paddle
from ball import Ball
import time
from scoreboard import Scoreboard


screen = Screen()
screen.setup(width=800, height=600)
screen.bgcolor("black")
screen.title("Pong")
screen.tracer(0)

r_paddle = Paddle((350, 0))
l_paddle = Paddle((-350, 0))
ball = Ball()
scoreboard = Scoreboard()

line = Turtle()
line.color("white")
line.hideturtle()
line.penup()
line.goto(0, -300)
line.seth(90)
while line.ycor() < 290:
    line.forward(10)
    line.penup()
    line.forward(10)
    line.pendown()
screen.update()

game_on = True


def game_end():
    global game_on
    game_on = False


screen.listen()
screen.onkey(r_paddle.go_up, "Up")
screen.onkey(r_paddle.go_down, "Down")
screen.onkey(l_paddle.go_up, "w")
screen.onkey(l_paddle.go_down, "s")
screen.onkey(game_end,"e")

while game_on:
    screen.update()
    ball.move()
    time.sleep(ball.move_speed)

    # detect collision with wall
    if ball.ycor() >= 280 or ball.ycor() <= -280:
        ball.bounce_y()

    # detect collision with paddle
    if ball.xcor() > 320 and ball.distance(r_paddle) < 50 or ball.xcor()<-320 and ball.distance(l_paddle) < 50:
        ball.bounce_x()

    # detect R paddle miss the ball
    if ball.xcor() > 380:
        ball.reset_position()
        scoreboard.update_l_score()

    # detect L paddle miss the ball
    if ball.xcor() < -380:
        ball.reset_position()
        scoreboard.update_r_score()

    # Game winner result
    if scoreboard.l_score == 5:
        scoreboard.game_over("left")
        game_on=False
    elif scoreboard.r_score == 5:
        scoreboard.game_over("right")
        game_on = False


screen.exitonclick()
