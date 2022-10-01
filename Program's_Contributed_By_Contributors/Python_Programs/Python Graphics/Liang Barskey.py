from graphics import *

win = GraphWin("Clipping", 500, 500)


def liangbarsky(x1, y1, x2, y2, xwmin, ywmin, xwmax, ywmax):
    p1 = -(x2-x1)
    q1 = x1-xwmin
    p2 = x2-x1
    q2 = xwmax-x1
    p3 = -(y2-y1)
    q3 = y1-ywmin
    p4 = y2-y1
    q4 = ywmax-y1

    tmin=0
    tmax=1

    parr = [p1, p2, p3, p4]
    qarr = [q1, q2, q3, q4]

    for i in range(4):
        print(parr[i])
        print(qarr[i])
        if parr[i] == 0:

            if qarr[i]<0:
                line1 = Line(Point(x1, y1), Point(x2, y2))
                line1.setFill('white')
                line1.draw(win)
            if qarr[i]>=0:
                line1 = Line(Point(x1, y1), Point(x2, y2))
                line1.setFill('green')
                line1.draw(win)
        else:
            temp = qarr[i] / parr[i]
            if parr[i]<0:
                if tmin<=temp:
                    tmin=temp
            else:
                if tmax>temp:
                    tmax=temp

    if tmin < tmax:
        xx1 = x1+tmin*parr[1]
        xx2 = x1+tmax*parr[1]
        yy1 = y1+tmin*parr[3]
        yy2 = y1+tmax*parr[3]
        pt1 = Point(xx1, yy1)
        pt2 = Point(xx2, yy2)
        line = Line(pt1, pt2)
        line.setFill('Blue')
        line.draw(win)

def main():
    arr =[150, 150, 250, 150, 200, 300, 300, 200, 450, 250, 170, 70]

    rect = Rectangle(Point(100, 100), Point(400, 400))
    rect.draw(win)
    win.getMouse()

    pt1 = Point(150, 150)
    pt2 = Point(250, 150)
    line = Line(pt1, pt2)
    line.setFill('black')
    line.draw(win)
    win.getMouse()

    pt3 = Point(200, 300)
    pt4 = Point(300, 200)
    line2 = Line(pt3, pt4)
    line2.setFill('black')
    line2.draw(win)
    win.getMouse()

    pt5 = Point(450, 250)
    pt6 = Point(170, 70)
    line3 = Line(pt5, pt6)
    line3.setFill('black')
    line3.draw(win)
    win.getMouse()

    for i in range(0, len(arr), 4):
        liangbarsky(arr[i], arr[i+1], arr[i+2], arr[i+3], 100, 100, 400, 400)
        print(arr[i], arr[i+1], arr[i+2], arr[i+3])
        win.getMouse()




main()
