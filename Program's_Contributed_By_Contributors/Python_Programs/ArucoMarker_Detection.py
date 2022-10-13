import cv2 as cv
from cv2 import aruco
import numpy as np


dict = aruco.Dictionary_get(aruco.DICT_4X4_50)
param = aruco.DetectorParameters_create()
cap = cv.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break
    #converting to grayscale
    gray_frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
    corners, marker_ID, reject = aruco.detectMarkers(
        gray_frame, dict, parameters=param
    )
    if corners:
        for ids, corners in zip(marker_ID, corners):
            cv.polylines(
                frame, [corners.astype(np.int32)], True, (0, 255, 255), 4, cv.LINE_AA
            )
            corners = corners.reshape(4, 2)
            corners = corners.astype(int)
            top_right = corners[0].ravel()
            top_left = corners[1].ravel()
            bottom_right = corners[2].ravel()
            bottom_left = corners[3].ravel()
            cv.putText(
                frame,
                f"id: {ids[0]}",
                top_right,
                cv.FONT_HERSHEY_PLAIN,
                1.3,
                (200, 100, 0),
                2,
                cv.LINE_AA,
            )
            
    cv.imshow("frame", frame)
    key = cv.waitKey(1)
    if key == ord("q"):
        break
cap.release()
cv.destroyAllWindows()