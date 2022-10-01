from graphics import *
win = GraphWin("dda 2", 600, 600)


def DDA(x1, y1, x2, y2):
    x = x1
    y = y1
    dx = x2-x1
    dy = y2-y1
    n = max(abs(dx), abs(dy))
    dt = n
    dxdt = dx//dt
    dydt = dy//dt
    x = x1
    y = y1
    while n != 0:
        pt1 = Point(round(x), round(y))
        pt1.setFill('black')
        pt1.draw(win)
        n = n - 1
        x = x + dxdt
        y = y + dydt

    win.getMouse()
#19BCE1659

def main():
    
    DDA(100,100,400,100)
    DDA(100,400,400,400)
    DDA(100,100,100,400)
    DDA(400,100,400,400)
    DDA(100,250,400,250)
    DDA(100,250,250,100)
    DDA(100,250,250,400)
    DDA(250,100,250,400)


main()
