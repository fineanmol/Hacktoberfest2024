#






import matplotlib.pyplot as plt
def bresenham(x1,y1,x2, y2):

	m = 2 * (y2 - y1)
	slope_error = m - (x2 - x1)

	y=y1
	for x in range(x1,x2+1):
	
		print("(",x ,",",y ,")\n")

		slope_error =slope_error + m

		
		if (slope_error >= 0):
			y=y+1
			slope_error =slope_error - 2 * (x2 - x1)
		
	

x1= int(input())
x2= int(input())
y1= int(input())
y2= int(input())

point1 = [x1,y1]
point2 = [x2, y2]

x_values = [point1[0], point2[0]]


y_values = [point1[1], point2[1]]


plt.plot(x_values,y_values)
plt.show()

