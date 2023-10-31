import cv2
import os
import pickle
import numpy as np
import face_recognition
import cvzone
from datetime import datetime
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
from firebase_admin import storage

# Load the Firebase service account key and initialize Firebase Admin SDK with database and storage configuration
cred = credentials.Certificate("C://Users//Mohak//Desktop//NXtech-Python//NXTECH-Python-Task-Number-3//services.json")
firebase_admin.initialize_app(cred, {
    'databaseURL': "https://face-attendace-system-ecbe7-default-rtdb.firebaseio.com/",
    'storageBucket': "face-attendace-system-ecbe7.appspot.com"
})

bucket = storage.bucket()

# Open webcam
cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

# Load the background image
img_background = cv2.imread('C://Users//Mohak//Desktop//NXtech-Python//NXTECH-Python-Task-Number-3//Resources/background.png')

# Importing the mode images into a list
folderModePath = 'C://Users//Mohak//Desktop//NXtech-Python//NXTECH-Python-Task-Number-3//Resources//Modes'
modePathList = os.listdir(folderModePath)
imgmodeList = []
for path in modePathList:
    imgmodeList.append(cv2.imread(os.path.join(folderModePath, path)))

# Load The Encoding File
print("Loading Encode File ...")
file = open('C://Users//Mohak//Desktop//NXtech-Python//NXTECH-Python-Task-Number-3//EncodeFile.p', 'rb')
encodeListKnownWithID = pickle.load(file)
file.close()
encodeListKnown, studentID = encodeListKnownWithID
print("Encode File loaded")

modeType = 0
counter = 0
id = -1
offset = 0
imgStudent = []

while True:
    success, img = cap.read()

    imgS = cv2.resize(img, (0, 0), None, 0.25, 0.25)
    imgS = cv2.cvtColor(imgS, cv2.COLOR_BGR2RGB)

    faceCurFrame = face_recognition.face_locations(imgS)
    encodeCurFrame = face_recognition.face_encodings(imgS, faceCurFrame)

    img_background[162:162 + 480, 55:55 + 640] = img
    img_background[44:44 + 633, 808:808 + 414] = imgmodeList[modeType]

    if faceCurFrame:
        for encoFace, faceLoc in zip(encodeCurFrame, faceCurFrame):
            matches = face_recognition.compare_faces(encodeListKnown, encoFace)
            faceDis = face_recognition.face_distance(encodeListKnown, encoFace)

            matchIndex = np.argmin(faceDis)
            print('Match Index', matchIndex)

            if matches[matchIndex]:
                y1, x2, y2, x1 = faceLoc
                y1, x2, y2, x1 = y1 * 4, x2 * 4, y2 * 4, x1 * 4
                bbox = 55 + x1, 162 + y1, x2 - x1, y2 - y1
                imgbackground = cvzone.cornerRect(img_background, bbox, rt=0)
                id = studentID[matchIndex]
                if counter == 0:
                    cvzone.putTextRect(img_background, "Loading..", (275, 400))
                    cv2.imshow("Face Attendance", img_background)
                    cv2.waitKey(1)
                    counter = 1
                    modeType = 1

        if counter != 0:
            if counter == 1:
                # Get The Data
                studentInfo = db.reference(f'Students/{id}').get()
                print(studentInfo)
                # Get the Image from the storage
                blob = bucket.get_blob(f'Images/{id}.png')
                array = np.frombuffer(blob.download_as_string(), np.uint8)
                imgStudent = cv2.imdecode(array, cv2.COLOR_BGRA2BGR)
                # Update Data of Attendance
                datetimeObject = datetime.strptime(studentInfo['Last_Attendance_Time'],
                                                  "%Y-%m-%d %H:%M:%S")
                secondElapsed = (datetime.now() - datetimeObject).total_seconds()
                print(secondElapsed)
                if secondElapsed > 86400:
                    ref = db.reference(f'Students/{id}')
                    studentInfo['Total_Attendance'] += 1
                    ref.child('Total_Attendance').set(studentInfo['Total_Attendance'])
                    ref.child('Last_Attendance_Time').set(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
                else:
                    modeType = 3
                    counter = 0
                    img_background[44:44 + 633, 808:808 + 414] = imgmodeList[modeType]

            if modeType != 3:
                if 20 < counter < 40:
                    modeType = 2

                img_background[44:44 + 633, 808:808 + 414] = imgmodeList[modeType]

                if counter <= 20:
                    cv2.putText(img_background, str(studentInfo['Total_Attendance']), (861, 125),
                                cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1)

                    (w, h), _ = cv2.getTextSize(studentInfo['Name'], cv2.FONT_HERSHEY_COMPLEX, 1, 1)
                    offset = (414 - w) // 2
                    cv2.putText(img_background, str(studentInfo['Name']), (808 + offset, 445),
                                cv2.FONT_HERSHEY_COMPLEX, 1, (50, 50, 50), 1)

                    cv2.putText(img_background, str(studentInfo['Major']), (1006, 550),
                                cv2.FONT_HERSHEY_COMPLEX, 0.5, (255, 255, 255), 1)
                    cv2.putText(img_background, str(id), (1006, 493),
                                cv2.FONT_HERSHEY_COMPLEX, 0.5, (255, 255, 255), 1)
                    cv2.putText(img_background, str(studentInfo['Standing']), (910, 625),
                                cv2.FONT_HERSHEY_COMPLEX, 0.6, (100, 100, 100), 1)
                    cv2.putText(img_background, str(studentInfo['Year']), (1025, 625),
                                cv2.FONT_HERSHEY_COMPLEX, 0.6, (100, 100, 100), 1)
                    cv2.putText(img_background, str(studentInfo['Starting_Year']), (1125, 625),
                                cv2.FONT_HERSHEY_COMPLEX, 0.6, (100, 100, 100), 1)

                    img_background[175:175 + 216, 909:909 + 216] = imgStudent

                counter += 1

                if counter >= 40:
                    counter = 0
                    modeType = 0
                    studentInfo = []
                    imgStudent = []
                    img_background[44:44 + 633, 808:808 + 414] = imgmodeList[modeType]
    else:
        modeType = 0
        counter = 0

    cv2.imshow("Face Attendance", img_background)
    cv2.waitKey(1)
