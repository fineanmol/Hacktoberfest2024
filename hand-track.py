import cv2
import mediapipe as mp
import time



# Capture the video from webcam
cap = cv2.VideoCapture(0)

# import the hand detection model
mpHands = mp.solutions.mediapipe.python.solutions.hands
hands = mpHands.Hands()
mpDraw = mp.solutions.mediapipe.python.solutions.drawing_utils

# To check the frame rate
prevTime = 0
CurrentTime = 0

while True:
    success, img = cap.read()
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(imgRGB)

    # lets open the processed object and extract the information
    # print(results.multi_hand_landmarks)

    if results.multi_hand_landmarks:
        # Check for every hands in the image
        for handLMS in results.multi_hand_landmarks:
            # Draw thw hands using built in drawing utilities
            mpDraw.draw_landmarks(img, handLMS, mpHands.HAND_CONNECTIONS)

            # Get all the info about each hands
            for id, lm in enumerate(handLMS.landmark):
                # print(id, lm)
                h, w, c = img.shape
                cx, cy = int(lm.x*w), int(lm.y*h)
                print(id, cx, cy)

                # Draw a circle for id=0 wrist
                if id == 4:
                    cv2.circle(img, (cx, cy), 15, (255, 0, 255), cv2.FILLED)

    # Calculate the FPS
    currentTime = time.time()
    fps = 1/(currentTime - prevTime)
    prevTime = currentTime

    # Write the fps into the image
    cv2.putText(img, str(int(fps)), (10, 78),
                cv2.FONT_HERSHEY_TRIPLEX, 3, (255, 0, 255), 3)

    cv2.imshow("Image", img)
    cv2.waitKey(1)


# if __name__ == "__main__":
#     main()
