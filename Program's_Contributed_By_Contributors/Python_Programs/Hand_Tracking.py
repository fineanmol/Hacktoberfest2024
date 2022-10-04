# This is My Perosnal Project I Hope this gets accepted for Hacktoberfest2022

import cv2
import mediapipe as mp
# Install these Libraries to Run the program on your local machine
# pip install cv2
# pip install mediapipe

mpHands = mp.solutions.hands
Hands = mpHands.Hands()
mpDraw = mp.solutions.drawing_utils
fingersCoordinate=[(8,6),(12,10),(16,14),(20,18)]
thumbCoordinate=(4,3)
cap = cv2.VideoCapture(0)

while (cap.isOpened()):
    upcount=0
    success , img = cap.read() 
    converted_image = cv2.cvtColor(img,cv2.COLOR_BGR2RGB) # converting BGR to RGB
    results = Hands.process(converted_image) # Processing Image for Tracking 
    handNo=0
    lmList=[]

    if results.multi_hand_landmarks: # Getting Landmark(location) of Hands if Exists 
        for id,lm in enumerate(results.multi_hand_landmarks[handNo].landmark):
            h,w,c=img.shape
            cx,cy=int(lm.x*w),int(lm.y*h)
            lmList.append((cx,cy))
        for hand_in_frame in results.multi_hand_landmarks: # looping through hands exists in the Frame 
            mpDraw.draw_landmarks(img,hand_in_frame, mpHands.HAND_CONNECTIONS) # drawing Hand Connections  
        for point in lmList:
            cv2.circle(img,point,5,(0,255,0),cv2.FILLED) 
        for coordinate in fingersCoordinate:
            if lmList[coordinate[0]][1] < lmList[coordinate[1]][1]:
                upcount+=1
        if lmList[thumbCoordinate[0]][0] > lmList[thumbCoordinate[1]][0]:
            upcount+=1
        cv2.putText(img,str(upcount),(150,150),cv2.FONT_HERSHEY_PLAIN,12,(0,0,255),12)

    cv2.imshow("Hand Tracking", img) # showing Video 

    if cv2.waitKey(1) == 113: # Press Q to Exit the Program
        break