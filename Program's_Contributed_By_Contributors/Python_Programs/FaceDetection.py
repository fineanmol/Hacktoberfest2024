import cv2 as cv
from cv2 import flip
import mediapipe as mp
import time

cap = cv.VideoCapture(0)
pTime = 0
mpFaceDetection = mp.solutions.face_detection
faceDetection = mpFaceDetection.FaceDetection()
mpDraw = mp.solutions.drawing_utils

while True:
    success, img = cap.read()
    flipped = cv.flip(img, 1)
    imgRGB = cv.cvtColor(flipped, cv.COLOR_BGR2RGB)
    results = faceDetection.process(imgRGB)
    # print(results.detections)
    if results.detections:
        for id, detection in enumerate(results.detections):
            # print(detection.score)
            boundBoxC = detection.location_data.relative_bounding_box
            h, w, c = flipped.shape
            boundBoxX = int(boundBoxC.xmin * w), int(boundBoxC.ymin *
                                                     h), int(boundBoxC.width * w), int(boundBoxC.height * h)
            cv.rectangle(flipped, (boundBoxX), (0, 255, 0), 2)
            cv.putText(flipped, f'{int(detection.score[0]*100)}%', (boundBoxX[0],
                       boundBoxX[1]), cv.FONT_HERSHEY_PLAIN, 2, (255, 0, 255), 2)

    cTime = time.time()
    fps = 1 / (cTime-pTime)
    pTime = cTime
    cv.putText(flipped, f'FPS:{int(fps)}', (10, 70),
               cv.FONT_HERSHEY_PLAIN, 3, (0, 255, 0), 2)
    cv.imshow("Video", flipped)
    cv.waitKey(1)
