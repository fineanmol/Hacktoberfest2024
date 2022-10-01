from graphics import *
from random import randint
from math import sin, cos, radians

image_height = 1000
image_height = 1000

def main():
    win = GraphWin("Window", image_height, image_height)
    win.setBackground(color_rgb(255, 255, 255))

    for _ in range(2):
          figure = drawahexagon(80)
          figure = rotatePolygon(figure, randint(0, 90))
          figure.draw(win)
    try:
        win.getMouse()  # causes graphics.GraphicsError: getMouse in closed window
    except GraphicsError:  # ignore error
        pass
    win.close()

def rotatePolygon(polygon, degrees):
    """ Rotate polygon the given angle about its center. """
    theta = radians(degrees)  # Convert angle to radians
    cosang, sinang = cos(theta), sin(theta)

    points = polygon.getPoints()
    # find center point of Polygon to use as pivot
    n = len(points)
    cx = sum(p.getX() for p in points) / n
    cy = sum(p.getY() for p in points) / n

    new_points = []
    for p in points:
        x, y = p.getX(), p.getY()
        tx, ty = x-cx, y-cy
        new_x = ( tx*cosang + ty*sinang) + cx
        new_y = (-tx*sinang + ty*cosang) + cy
        new_points.append(Point(new_x, new_y))

    rotated_ploygon = polygon.clone()  # clone to get current attributes
    rotated_ploygon.points = new_points
    return rotated_ploygon

def drawahexagon(length):
    x = randint(0, image_height-length)
    y = randint(0, image_height-length)
    poly = Polygon(Point(x+getRandom(0), y+getRandom(0)),
                   Point(x+length+getRandom(1), y+getRandom(1)),
                   Point(x+(length*1.5)+getRandom(0), y+(length/2)+getRandom(1)),
                   Point(x+length+getRandom(1), y+length+getRandom(1)),
                   Point(x+getRandom(0), y+length+getRandom(1)),
                   Point(x-(length/2)+getRandom(1), y+(length/2)+getRandom(0)))
    poly.setFill(color_rgb(255, 0, 0))
    return poly

def getRandom(base):
    if base == 0:
        foo = randint(0, 5)
    else:
        foo = randint(3, 10)
    return foo

main()
