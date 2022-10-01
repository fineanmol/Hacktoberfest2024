from graphics import *

win = GraphWin("Polygon Clip", 500, 500)


def polyclip(x1, y1, x2, y2, xwmin, ywmin, xwmax, ywmax, finarr):
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
        if parr[i] == 0:

            if qarr[i]<0:

                finarr.append(Point(x1, y1))
                finarr.append((Point(x2, y2)))
            if qarr[i]>=0:

                finarr.append(Point(x1, y1))
                finarr.append((Point(x2, y2)))
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
        finarr.append(pt1)
        finarr.append(pt2)
def main():

    arr = [[202, 128], [266, 136], [299, 81], [334, 136], [395, 128], [364, 176], [395, 224], [333, 216], [300, 272],
           [262, 216], [203, 224], [232, 176]
           ]
    arrdraw = [Point(202, 128), Point(266, 136), Point(299, 81), Point(334, 136), Point(395, 128), Point(364, 176), Point(395, 224),
           Point(333, 216), Point(300, 272),
           Point(262, 216), Point(203, 224), Point(232, 176)]
    arr2 = [[219, 99], [376, 99], [376, 242], [219, 242]]

    finarr = []

    for i in range(len(arr2)):
        k = (i+1) % len(arr2)
        ppt1 = Point(arr2[i][0], arr2[i][1])
        ppt2 = Point(arr2[k][0], arr2[k][1])
        line = Line(ppt1, ppt2)
        line.setFill('BLACK')
        line.draw(win)
        win.getMouse()

    poly1 = Polygon(arrdraw)
    poly1.setFill('GREEN')
    poly1.draw(win)
    win.getMouse()

    for i in range(len(arr)):
        k = (i+1) % len(arr)
        ix = arr[i][0]
        iy = arr[i][1]
        kx = arr[k][0]
        ky = arr[k][1]
        polyclip(ix, iy, kx, ky, 219, 99, 376, 242, finarr)


    poly1.undraw()
    win.getMouse()

    poly1 = Polygon(finarr)
    poly1.setFill('YEllow')
    poly1.draw(win)
    win.getMouse()


main()
