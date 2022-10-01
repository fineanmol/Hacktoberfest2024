from graphics import *
from random import randint
from math import sin, cos, radians

win = GraphWin("2D Trans", 1000, 1000)
points = [Point(100,50),Point(200,50),Point(150,200),Point(300,250)]
p = Polygon(points)
p.setFill('red')
p.draw(win)
win.getMouse()
p.undraw()
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
pt = [pt1, pt2, pt3, pt4]
def main():
    print("1- translation, 2-Scaling, 3-Rotation")
    x = int(input())
    if x == 1:
        print("Enter x-value for moving")
        xt = int(input())
        print("Enter y-value for moving")
        yt = int(input())
        tran(xt, yt, pt)
        win.getMouse()
        print("Enter scaling factor of x axis")
        Sx = int(input())
        print("Enter scaling factor of y axis")
        Sy = int(input())
        scale(Sx,Sy,pt)
        win.getMouse()
        print("Enter angle of rotation")
        angle = int(input())
        # rotation function called using angle
        for _ in range(1):
            points4 = [Point(100,50),Point(200,50),Point(150,200),Point(300,250)]
            p3 = Polygon(points4)
            figure = rotatePolygon(p3, randint(0, angle))
            figure.setFill('yellow')
            figure.draw(win)

    
def tran(xt, yt, pt):
    print(pt)
    for i in range(len(pt)):
        new_x = pt[i].getX() + xt
        new_y = pt[i].getY() + yt
        pt[i] = Point(new_x, new_y)

    print(pt)
    new_poly = Polygon(pt)
    new_poly.setFill('blue')
    new_poly.setOutline('black')
    new_poly.draw(win)

    #win.getMouse()
  
    
def scale(Sx, Sy, pt):
    new_points = []
    xt=10
    yt=10
    for i in range(len(pt)):
        new_x = pt[i].getX() + xt
        new_y = pt[i].getY() + yt
        pt[i] = Point(new_x, new_y)

    print(pt)
    for i in range(len(pt)):
        x_new = pt[i].getX() * Sx
        y_new = pt[i].getY() * Sy
        new_points.append(Point(x_new, y_new))
    print(new_points)
    new_poly = Polygon(new_points)
    new_poly.setFill('green')
    new_poly.setOutline('black')
    #new_poly.draw(win)
    win.getMouse()
    
def rotatePolygon(new_poly, degrees):

    theta = radians(degrees)  
    cosang, sinang = cos(theta), sin(theta)

    points = new_poly.getPoints()
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

    rotated_ploygon = new_poly.clone() 
    rotated_ploygon.points = new_points
    return rotated_ploygon


main()

