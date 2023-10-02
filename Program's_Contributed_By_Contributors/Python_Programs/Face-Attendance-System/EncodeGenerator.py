import cv2
import face_recognition
import pickle
import os
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

# Importing student images from the specified folder
folderPath = 'Images'
PathList = os.listdir(folderPath)
print(PathList)
imgList = []
studentID = []

# Loop through the image files and load them into a list along with their corresponding student IDs
for path in PathList:
    imgList.append(cv2.imread(os.path.join(folderPath, path)))
    studentID.append(os.path.splitext(path)[0])

    # Upload the image files to Firebase Storage
    filename = f'{folderPath}/{path}'
    bucket = storage.bucket()
    blob = bucket.blob(filename)
    blob.upload_from_filename(filename)

print(studentID)

# Function to find face encodings of images in a list
def findEncodings(imagesList):
    encodeList = []
    for img in imagesList:
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        encode = face_recognition.face_encodings(img)[0]
        encodeList.append(encode)
    return encodeList

print("Encoding Started ...")

# Call the function to find face encodings of the images
encodeListKnown = findEncodings(imgList)

# Combine the list of face encodings with the list of student IDs for future reference
encodeListKnownWithID = [encodeListKnown, studentID]

print("Encoding Complete")

# Save the face encodings along with student IDs to a pickle file
file = open("EncodeFile.p", 'wb')
pickle.dump(encodeListKnownWithID, file)
file.close()
print("File Saved")















