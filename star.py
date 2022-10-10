import turtle
star = turtle.Turtle()
num_of_sides = 5
length_of_side = 50
each_angle = 720.0 / num_of_sides
for i in range(num_of_sides):
    star.forward(length_of_side)
    star.right(each_angle)
turtle.done()