import matplotlib.pyplot as plt

plt.title("Ellipse Drawing  Algorithm")
plt.xlabel("X Axis")
plt.ylabel("Y Axis")


def midptellipse(rx, ry, xc, yc):
 
    x = 0;
    y = ry;
 

    d1 = ((ry * ry) - (rx * rx * ry) +
                      (0.25 * rx * rx));
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    print("Points in Region 1");
 
    xcoordinates = []
    ycoordinates = []
    while (dx < dy):
 
        xcoordinates.extend([xc+x, xc-x, xc+x, xc-x])
        ycoordinates.extend([yc+y, yc+y, yc-y, yc-y])
        print("(", x + xc, ",", y + yc, ")");
        print("(",-x + xc,",", y + yc, ")");
        print("(",x + xc,",", -y + yc ,")");
        print("(",-x + xc, ",", -y + yc, ")");
 
       
        if (d1 < 0):
            x += 1;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        else:
            x += 1;
            y -= 1;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);

    print("Points in Region 2");
 
    d2 = (((ry * ry) * ((x + 0.5) * (x + 0.5))) +
          ((rx * rx) * ((y - 1) * (y - 1))) -
           (rx * rx * ry * ry));
 
  
    while (y >= 0):
 
        xcoordinates.extend([xc+x, xc-x, xc+x, xc-x])
        ycoordinates.extend([yc+y, yc+y, yc-y, yc-y])
        print("(", x + xc, ",", y + yc, ")");
        print("(", -x + xc, ",", y + yc, ")");
        print("(", x + xc, ",", -y + yc, ")");
        print("(", -x + xc, ",", -y + yc, ")");
 
   
        if (d2 > 0):
            y -= 1;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        else:
            y -= 1;
            x += 1;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);

    plt.scatter(xcoordinates, ycoordinates, marker='.')
    plt.gca().set_aspect('equal', adjustable='box')
    plt.show()        




def main():
    rx = int(input("Enter the radius in x direction:"))
    ry = int(input("Enter the radius in y direction"))
    xc = int(input("Enter the center point of x:"))
    yc = int(input("Enter the center point of y:"))
   

    midptellipse(rx, ry, xc, yc)

main()