from graphics import *
win = GraphWin("Bresenham",1000,1000)

# function for line generation  
def bresenham(x1,y1,x2, y2):  
  
    m_new = 2 * (y2 - y1)  
    slope_error_new = m_new - (x2 - x1) 
  
    y=y1 
    for x in range(x1,x2+1):  
      
        #print("(",x ,",",y ,")\n")
        pt1 = Point(x,y)
        pt1.setFill('blue')
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
        pt1.setFill('red')
        pt1.draw(win)
        n = n - 1
        x = x + dxdt
        y = y + dydt
          
      

def main():
    bresenham(100,100,200,100)
    bresenham(100,200,200,200)
    DDA(100,100,100,200)
    DDA(200,100,200,200)


main()
