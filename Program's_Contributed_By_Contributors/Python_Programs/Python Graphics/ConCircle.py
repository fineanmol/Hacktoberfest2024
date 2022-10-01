from graphics import *

def main():
    win = GraphWin("My ConC", 1000, 1000)

    c = Circle(Point(500,500), 50)
    c.setFill('black')
    c.draw(win)

    c1 = Circle(Point(500,500), 25)
    c1.setFill('red')
    c1.draw(win)

    c2 = Circle(Point(500,500), 15)
    c2.setFill('green')
    c2.draw(win)

    for i in range(20):
         c.move(5, 0)
         c1.move(5, 0)
         c2.move(5, 0)
         time.sleep(.005)
         
    for i in range(20):
         c.move(-5, 0)
         c1.move(-5, 0)
         c2.move(-5, 0)
         time.sleep(.005)
    
main()
