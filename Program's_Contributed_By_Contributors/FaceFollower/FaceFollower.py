import cv2
import numpy as np

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cap = cv2.VideoCapture(0)

cap.set(3, 480)
cap.set(4, 320)

_, frame = cap.read()
rows, cols, _ = frame.shape

x_medium = int(cols / 2)
center = int(cols / 2)
while True:
    ret, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    
    for (x,y,w,h) in faces:
        
        x_medium = int((x + x + w) / 2)
        break
    
    cv2.line(img, (x_medium, 0), (x_medium, 480), (0, 255, 0), 2)
    
    cv2.imshow("Frame", img)
    
    
    key = cv2.waitKey(1)
    
    if key == 27:
        break
    
    if x_medium < center -30:
        print("Right")

    elif x_medium > center + 30:
        print("Left")

    
           
cap.release()
cv2.destroyAllWindows()
