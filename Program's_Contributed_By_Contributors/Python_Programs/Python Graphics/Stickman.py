from graphics import *
from random import randint
import math


def main():
    win = GraphWin("My Stickman", 1500, 1500)
    
    c = Circle(Point(500,650), 50)
    c.setFill('black')
    c.draw(win)

    line1 = Line(Point(500,700),Point(500,800))
    line1.draw(win)

    p1=Point(500,750)
    p2=Point(400,800)
    p9=Point(750,500)
    p10=Point(650,450)
    p17=Point(1000,750)
    p18=Point(900,800)
    line2 = Line(p1,p2)
    line2.draw(win)
    
    
    p3=Point(500,750)
    p4=Point(600,800)
    p11=Point(750,500)
    p12=Point(850,450)
    p19=Point(1000,750)
    p20=Point(1100,800)
    line3 = Line(p3,p4)
    line3.draw(win)

    
    p5=Point(500,800)
    p6=Point(450,900)
    p13=Point(750,550)
    p14=Point(650,500)
    p21=Point(1000,800)
    p22=Point(950,900)
    line4 = Line(p5,p6)
    line4.draw(win)
    
    p7=Point(500,800)
    p8=Point(550,900)
    p15=Point(750,550)
    p16=Point(850,500)
    p23=Point(1000,800)
    p24=Point(1050,900)
    line5 = Line(p7,p8)
    line5.draw(win)

    for i in range(50):
        c.move(5,-5)
        line1.move(5,-5)
        line2.move(5,-5)
        line3.move(5,-5)
        line4.move(5,-5)
        line5.move(5,-5)
        time.sleep(.001)

    line2.undraw()
    line6= Line(p9,p10)
    line6.draw(win)
    line3.undraw()
    line7= Line(p11,p12)
    line7.draw(win)
    line4.undraw()
    line8= Line(p13,p14)
    line8.draw(win)
    line5.undraw()
    line9= Line(p15,p16)
    line9.draw(win)

    for i in range(50):  
        c.move(5,5)
        line1.move(5,5)
        line6.move(5,5)
        line7.move(5,5)
        line8.move(5,5)
        line9.move(5,5)
        time.sleep(.001)

    line6.undraw()
    line10= Line(p17,p18)
    line10.draw(win)
    line7.undraw()
    line11= Line(p19,p20)
    line11.draw(win)
    line8.undraw()
    line12= Line(p21,p22)
    line12.draw(win)
    line9.undraw()
    line13= Line(p23,p24)
    line13.draw(win)
 
main()
