from graphics import *
from random import randint
from math import sin, cos, radians

win = GraphWin("2D Trans", 1000, 1000)

def main():
    
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

main()
