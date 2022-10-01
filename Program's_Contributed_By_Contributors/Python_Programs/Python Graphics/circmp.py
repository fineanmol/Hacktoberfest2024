from graphics import *
win = GraphWin("DDA", 1000, 1000)


def midpoint(x1, y1, x2, y2):
    dx=x2-x1
    dy=y2-y1
    d=2*dy-dx
    incE=2*dy
    incNE=2*(dy-dx)
    x=x1
    y=y1
    pt1 = Point(x, y)
    pt1.setFill('red')
    pt1.draw(win)
    while x < x2:
        if d <=0:
            d+=incE
            x+=1
        else:
            d+=incNE
            x+=1
            y+=1
        pt2 = Point(x, y)
        pt2.setFill('blue')
        pt2.draw(win)

def main():
    x1=200
    y1=400
    x2=500
    y2=300
    x3=400
    y3=0
    x4=100
    y4=100
    midpoint(x1, y1, x2, y2)
    midpoint(x1, y1, x3, y3)
    #midpoint(x4, y4, x3, y3)
    #midpoint(x2, y2, x4, y4)

    win.getMouse()


main()
