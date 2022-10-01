import time

from graphics import *
import math

win = GraphWin("Polygon Rotation", 1000, 1000)

x1 = 150
y1 = 100
x2 = 50
y2 = 200
x3 = 100
y3 = 300
x4 = 200
y4 = 300
x5 = 300
y5= 200
pt1 = Point(x1, y1)
pt2 = Point(x2, y2)
pt3 = Point(x3, y3)
pt4 = Point(x4, y4)
pt5 = Point(x5, y5)
ptarr = [pt1, pt2, pt3, pt4, pt5]

angle = 0
Sx = 0
Sy = 0


def translation(xt, yt, ptarr):
    print(ptarr)
    for i in range(len(ptarr)):
        new_x = ptarr[i].getX() + xt
        new_y = ptarr[i].getY() + yt
        ptarr[i] = Point(new_x, new_y)

    # print(ptarr)
    # new_poly = Polygon(ptarr)
    # new_poly.setFill('green')
    # new_poly.setOutline('black')
    # new_poly.draw(win)

    rotation(angle, ptarr)


def rotation(theta, ptarr):

    theta = math.radians(theta)
    cosang, sinang = math.cos(theta), math.sin(theta)

    points = ptarr
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
        # new_poly = Polygon(new_points)
        # new_poly.setFill('red')
        # new_poly.setOutline('black')
        # new_poly.draw(win)


    scale(Sx, Sy, new_points)


def scale(sx, sy, ptarr):
    new_points = []
    for i in range(len(ptarr)):
        x_new = ptarr[i].getX() * sx
        y_new = ptarr[i].getY() * sy
        new_points.append(Point(int(x_new), int(y_new)))
    print(new_points)
    new_poly = Polygon(new_points)
    #new_poly.setFill('blue')
    #new_poly.setOutline('black')
    #new_poly.draw(win)
    win.getMouse()


def main():
    poly1 = Polygon(pt1, pt2, pt3, pt4, pt5)
    poly1.setFill('yellow')
    poly1.setOutline('red')
    poly1.draw(win)
    win.getMouse()

    print("Enter x-offset for moving the points")
    xt = int(input())
    print("Enter y-offset for moving the points")
    yt = int(input())
    print("Enter angle of rotation")
    angle = int(input())
    print("Enter scaling factor of x")
    Sx = int(input())
    print("Enter scaling factor of y")
    Sy = int(input())
    translation(xt, yt, ptarr)


    #translation
    for i in range(20):
        poly1.move(xt,yt)
        time.sleep(0.05)
    transarr = poly1.getPoints()
    poly1.undraw()

    #rotation
    for i in range(angle):
        theta = math.radians(i)
        cosang, sinang = math.cos(theta), math.sin(theta)

        points = transarr
        n = len(points)
        cx = sum(p.getX() for p in points) / n
        cy = sum(p.getY() for p in points) / n

        rotated_points = []
        for p in points:
            x, y = p.getX(), p.getY()
            tx, ty = x - cx, y - cy
            new_x = (tx * cosang + ty * sinang) + cx
            new_y = (-tx * sinang + ty * cosang) + cy
            rotated_points.append(Point(new_x, new_y))
        new_poly = Polygon(rotated_points)
        new_poly.setFill('yellow')
        new_poly.setOutline('red')
        new_poly.draw(win)
        time.sleep(0.05)
        new_poly.undraw()
    #scaling
    for i in range(30):
        new_points = []

        for j in range(len(ptarr)):
            
            x_new = ptarr[j].getX() * Sx
            y_new = ptarr[j].getY() * Sy
            new_points.append(Point(int(x_new), int(y_new)))
        print(new_points)
        new_poly = Polygon(new_points)
main()
