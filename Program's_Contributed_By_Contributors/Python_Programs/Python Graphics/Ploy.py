from graphics import *

def main():
    win = GraphWin("My Canvas", 300, 300)

    poly_points = [Point(100, 50), Point(200, 50), Point(150, 200),Point(300,250)]

    p = Polygon(poly_points)
    p.setFill('red')
    p.draw(win)

    c = Circle(Point(150,150), 25)
    c.setFill('blue')
    c.draw(win)

    c = Circle(Point(150,150), 15)
    c.setFill('yellow')
    c.draw(win)
    
    win.getMouse() 
    win.close() 

main()
