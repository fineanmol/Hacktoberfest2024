from graphics import *
win = GraphWin("Figure", 1000, 1000)


def draw(x,y,x_center,y_center):
    pt1 = Point(x + x_center, y + y_center)
    pt1.setFill('blue')
    pt1.draw(win)
    pt1 = Point(-x + x_center, y + y_center)
    pt1.setFill('blue')
    pt1.draw(win)
    pt1 = Point(x + x_center, -y + y_center)
    pt1.setFill('black')
    pt1.draw(win)
    pt1 = Point(-x + x_center, -y + y_center)
    pt1.setFill('black')
    pt1.draw(win)
    pt1 = Point(y + x_center, x + y_center)
    pt1.setFill('black')
    pt1.draw(win)
    pt1 = Point(-y + x_center, x + y_center)
    pt1.setFill('black')
    pt1.draw(win)
    pt1 = Point(y + x_center, -x + y_center)
    pt1.setFill('blue')
    pt1.draw(win)
    pt1 = Point(-y + x_center, -x + y_center)
    pt1.setFill('blue')
    pt1.draw(win)


def circledraw(x_center,y_center,r):
    x=0
    y=r

    draw(x,y,x_center,y_center)


    p=1-r

    while x < y:
        x+=1
        if p<0:
            p+=2*x+1
        else:
            y-=1
            p+=2*(x-y)+1
        draw(x,y,x_center,y_center)

def bresenham(x1,y1,x2, y2):  
  
    m_new = 2 * (y2 - y1)  
    slope_error_new = m_new - (x2 - x1) 
  
    y=y1 
    for x in range(x1,x2+1):  
      
        #print("(",x ,",",y ,")\n")
        pt1 = Point(x,y)
        pt1.setFill('black')
        pt1.draw(win)

  
        
        slope_error_new =slope_error_new + m_new  
  
     
        if (slope_error_new >= 0):  
            y=y+1
            slope_error_new =slope_error_new - 2 * (x2 - x1)

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




def main():
    circledraw(500,500,40)
    circledraw(500,500,60)
    circledraw(500,500, 80)
    circledraw(500,500, 20)
    bresenham(420,420,580,420)
    bresenham(420,580,580,580)
    DDA(420,420,420,580)
    DDA(580,420,580,580)
    circledraw(420,420,32)
    circledraw(420,580,32)
    circledraw(580,420,32)
    circledraw(580,580,32)
    
    


main()
