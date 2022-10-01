from graphics import *
win = GraphWin("MPC", 1000, 1000)


def draw1(x, y, x_center, y_center):
    pt1 = Point(x + x_center, y + y_center)
    pt1.setFill('black')
    pt1.draw(win)

    pt1 = Point(y + x_center, x + y_center)
    pt1.setFill('black')
    pt1.draw(win)

    
def draw2(x, y, x_center, y_center):
    pt1 = Point(-x + x_center, -y + y_center)
    pt1.setFill('black')
    pt1.draw(win)

    pt1 = Point(-y + x_center, -x + y_center)
    pt1.setFill('black')
    pt1.draw(win)


def circledraw1(x_center1, y_center1, r):
    x=0
    y=r

    draw1(x, y, x_center1, y_center1)


    p=1-r

    while x < y:
        x+=1
        if p<0:
            p+=2*x+1
        else:
            y-=1
            p+=2*(x-y)+1
        draw1(x, y, x_center1, y_center1)
        
def circledraw2(x_center, y_center, r):
    x=0
    y=r

    draw2(x, y, x_center, y_center)


    p=1-r

    while x < y:
        x+=1
        if p<0:
            p+=2*x+1
        else:
            y-=1
            p+=2*(x-y)+1
        draw2(x, y, x_center, y_center)


def main():
    x=int(input("Enter x value "))
    y=int(input("Enter y value "))
    r=int(input("Enter radius "))
    circledraw1(x, y, r)     #circle 1 draw for the x y r
    circledraw2(x+2*r, y, r)   #circle 2 draw for the new circle accordingly
    win.getMouse()

main()
#Code by Rishi Saxena - 19BCE1659
