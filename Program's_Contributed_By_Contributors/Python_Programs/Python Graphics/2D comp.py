import time

from graphics import *
import math

win = GraphWin("comp trans 2D", 1000, 1000)

x1 = 100
y1 = 50
x2 = 200
y2 = 50
x3 = 150
y3 = 200
x4 = 300
y4 = 250
pt1 = Point(x1, y1)
pt2 = Point(x2, y2)
pt3 = Point(x3, y3)
pt4 = Point(x4, y4)
ptarr = [pt1, pt2, pt3, pt4]

angle = 0
Sx = 0
Sy = 0


def translation(xt, yt, ptarr, ang, sx, sy):
    rtarr = []
    for i in range(len(ptarr)):
        new_x = ptarr[i].getX() + xt
        new_y = ptarr[i].getY() + yt
        rtarr.append(Point(new_x, new_y))
        #ptarr[i] = Point(new_x, new_y)

    # print(ptarr)
    # new_poly = Polygon(ptarr)
    # new_poly.setFill('green')
    # new_poly.setOutline('black')
    # new_poly.draw(win)

    rotation(ang, rtarr, sx, sy)


def rotation(theta, rtarr, sx, sy):

    theta = math.radians(theta)
    cosang, sinang = math.cos(theta), math.sin(theta)

    points = rtarr
    n = len(points)
    cx = sum(p.getX() for p in points) / n
    cy = sum(p.getY() for p in points) / n

    new_points = []
    for p in points:
        x, y = p.getX(), p.getY()
        tx, ty = x-cx, y-cy
        new_x = (tx*cosang + ty*sinang) + cx
        new_y = (-tx*sinang + ty*cosang) + cy
        new_points.append(Point(new_x, new_y))

    print('rotated arr')
    print(new_points)
    scale(sx, sy, new_points)


def scale(sx, sy, rotated_points):
    new_points = []
    for i in range(len(rotated_points)):
        x_new = rotated_points[i].getX() * sx
        y_new = rotated_points[i].getY() * sy
        new_points.append(Point(int(x_new), int(y_new)))
    print('new points:')
    print(new_points)
    new_poly = Polygon(new_points)
    new_poly.setFill('blue')
    new_poly.setOutline('green')
    new_poly.draw(win)
    win.getMouse()


def main():
    poly1 = Polygon(pt1, pt2, pt3, pt4)
    poly1.setFill('red')
    poly1.setOutline('yellow')
    poly1.draw(win)

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
    translation(xt, yt, ptarr, angle,  Sx, Sy)

    print("translation going on...")
    #translation

    poly1.move(xt, yt)
    time.sleep(0.05)
    transarr = poly1.getPoints()
    poly1.undraw()
    rot_poly = Polygon(pt1, pt2, pt3, pt4)
    #rotation
    print("rotation going on...")
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
        rot_poly = Polygon(rotated_points)
        rot_poly.setFill('yellow')
        rot_poly.setOutline('red')
        rot_poly.draw(win)
        time.sleep(0.05)
        rot_poly.undraw()
    #scaling
    print("scaling going on...")
    new_points = []
    rot_arr = rot_poly.getPoints()
    print('passed rotated arr')
    print(rot_arr)
    for i in range(len(rot_arr)):
        x_new = rot_arr[i].getX() * Sx
        y_new = rot_arr[i].getY() * Sy
        new_points.append(Point(int(x_new), int(y_new)))
    print(new_points)
    new_poly = Polygon(new_points)
    new_poly.setFill('yellow')
    new_poly.setOutline('red')
    new_poly.draw(win)
    win.getMouse()
main()
