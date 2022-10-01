from graphics import *

def main():
    win = GraphWin("My Car", 1000, 1000)

    poly_points = [Point(200, 50), Point(100, 150), Point(500, 150),Point(300,50)]

    p = Polygon(poly_points)
    p.setFill('red')
    p.draw(win)

    poly_points1 = [Point(300, 150), Point(100, 150), Point(500, 150),Point(300,50)]

    p1= Polygon(poly_points1)
    p1.setFill('blue')
    p1.draw(win)

    poly_points2 = [Point(50, 150), Point(50, 250), Point(650, 250),Point(650,150)]

    p2= Polygon(poly_points2)
    p2.setFill('yellow')
    p2.draw(win)

    c = Circle(Point(200,250), 50)
    c.setFill('black')
    c.draw(win)

    c1 = Circle(Point(200,250), 25)
    c1.setFill('red')
    c1.draw(win)

    c2 = Circle(Point(500,250), 50)
    c2.setFill('black')
    c2.draw(win)

    c3 = Circle(Point(500,250), 25)
    c3.setFill('red')
    c3.draw(win)

    line = Line(Point(50, 200),Point(50,50))
    line.draw(win)

    c4=Circle(Point(50,50),30)
    c4.setFill('Green')
    c4.draw(win)

    for i in range(20):
        c.move(5, 0)
        c1.move(5, 0)
        c2.move(5, 0)
        c3.move(5, 0)
        p.move(5, 0)
        p1.move(5, 0)
        p2.move(5, 0)
        line.move(5,0)
        c4.move(5,0)
        time.sleep(.05)
    for i in range(20):
        c.move(-5, 0)
        c1.move(-5, 0)
        c2.move(-5, 0)
        c3.move(-5, 0)
        p.move(-5, 0)
        p1.move(-5, 0)
        p2.move(-5, 0)
        line.move(-5,0)
        c4.move(-5,0)
        time.sleep(.05)
   
main()
