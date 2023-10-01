import cv2
import time
import numpy as np
#This Projects enables you to draw on your camera screen with a pink object by tracing its movements and drawing on its traversal path.
cap = cv2.VideoCapture(0)
cap.set(3, 600)
cap.set(4, 500)
cap.set(10, 150)

myPoints = []
def findColor(img):
    imgHSV = cv2.cvtColor(img, cv2.COLOR_BGR2HSV) 
    newPoints=[]
    l = np.array([124 , 60 , 124])  
    u = np.array([178 , 255 , 255])
    mask = cv2.inRange(imgHSV,l,u)
    cv2.imshow("img", mask)
    x,y=getcontours(mask)

    cv2.circle(imgmain,(x,y),10,(255,0,0),cv2.FILLED)
    if x!=0 and y!=0:
        newPoints.append([x,y]) 
    
    return newPoints
def getcontours(img):

    contours , hierarchy = cv2.findContours(img , cv2.RETR_EXTERNAL , cv2.CHAIN_APPROX_NONE)
    x , y , w , h = 0 , 0 , 0 , 0 
    
    
    for c in contours:           
        img_cnt = cv2.contourArea(c)
        if img_cnt >500:

            cv2.drawContours(imgmain , c , -1 , ( 255 , 0 , 0 ) , 3 )
            peri = cv2.arcLength(c , True )
            approx = cv2.approxPolyDP(c, 0.02*peri,True)
            x , y , w , h = cv2.boundingRect(approx)
    return x+w//2,y

def draw(myPoints):
    for point in myPoints:
        cv2.circle(imgmain, (point[0], point[1]), 10, [255,0,0], cv2.FILLED)
while True:
    _, img = cap.read()
    imgmain = img.copy()
    npoints = findColor(img)
    if len(npoints)!= 0: 
        for n in npoints:
            myPoints.append(n)
    if len(myPoints)!=0:
        draw(myPoints)
    cv2.imshow("Img", imgmain)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break