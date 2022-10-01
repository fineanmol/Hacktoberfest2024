from graphics import *
from Arc import *

def main():
    win = GraphWin("My Circle", 500, 500)
    c = Circle(Point(250,250), 100)
    c.draw(win)
    c.setOutline('black')
    c.setFill('yellow')
    c1= Circle(Point(200,230),25)
    c2= Circle(Point(300,230),25)
    c1.setOutline('black')
    c1.setFill('white')
    c2.setOutline('black')
    c2.setFill('white')
    c1.draw(win)
    c2.draw(win)
    mouth = Oval(Point(200,270 ), Point(300, 300))
    mouth.setFill("red")
    #mouth.draw(win)
    c12= Circle(Point(200,230),15)
    c22= Circle(Point(300,230),15)
    c12.setFill('black')
    c22.setFill('black')
    c12.draw(win)
    c22.draw(win)
    arc = Arc(Point(220, 300), Point(280, 280), -180)
    arc.setFill("red")
    arc.draw(win)
  
    
    

main()
