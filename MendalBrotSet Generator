import turtle

# Function to check if a point is in the Mandelbrot set
def mandelbrot(c, max_iter):
    z = 0
    n = 0
    while abs(z) <= 2 and n < max_iter:
        z = z*z + c
        n += 1
    return n

# Function to map pixel coordinates to the complex plane
def map_to_complex(x, y, width, height, x_min, x_max, y_min, y_max):
    real = x * (x_max - x_min) / (width - 1) + x_min
    imag = y * (y_max - y_min) / (height - 1) + y_min
    return complex(real, imag)

# Configure the Turtle screen
screen = turtle.Screen()
screen.setup(width=800, height=800)
screen.tracer(0)

# Set the complex plane boundaries and maximum number of iterations
x_min, x_max = -2.0, 1.0
y_min, y_max = -1.5, 1.5
max_iter = 100

# Create the Turtle object
t = turtle.Turtle()
t.penup()
t.speed(0)

# Iterate through each pixel and draw the Mandelbrot set
for x in range(800):
    for y in range(800):
        c = map_to_complex(x, y, 800, 800, x_min, x_max, y_min, y_max)
        color = mandelbrot(c, max_iter)
        t.goto(x - 400, y - 400)  # Center the drawing on the screen
        t.pendown()
        t.pencolor(0, 0, color / max_iter)
        t.forward(1)
        t.penup()

# Close the Turtle graphics window on click
screen.exitonclick()
