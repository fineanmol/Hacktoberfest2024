#pip install opencv-python

import cv2

# Load the pre-trained face detection classifier
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Load an image from file or use your webcam
# Replace 'your_image.jpg' with the path to your image file
# Alternatively, you can use the webcam by setting the argument to 0 (e.g., cv2.VideoCapture(0))
image_path = 'your_image.jpg'
image = cv2.imread(image_path)

# Convert the image to grayscale for face detection
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Perform face detection
faces = face_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=5, minSize=(30, 30))

# Draw rectangles around the detected faces
for (x, y, w, h) in faces:
    cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

# Display the image with faces detected
cv2.imshow('Face Detection', image)

# Wait for a key press and then close the window
cv2.waitKey(0)
cv2.destroyAllWindows()
