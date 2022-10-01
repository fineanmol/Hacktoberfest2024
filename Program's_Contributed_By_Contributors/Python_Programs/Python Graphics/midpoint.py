from graphics import *
win = GraphWin("Bresenham",1000,1000)

def midPoint(X1,Y1,X2,Y2): 
    # calculate dx & dy 
    dx = X2 - X1 
    dy = Y2 - Y1 
 
  
    d = dy - (dx/2) 
    x = X1
    y = Y1 
 

    #print(x,",",y,"\n")
    
    while (x < X2):
        x=x+1
        
        if(d < 0):
            d = d + dy 
 
       
        else:
            d = d + (dy - dx) 
            y=y+1
     
 

        #print(x,",",y,"\n")
        pt= Point(round(x),round(y))
        pt.setFill('blue')
        pt.draw(win)
def main():
    midPoint(420,410,410,570)

main()

