# Interactive Face Attendance System 📷

An interactive Python program that acts as a face attendance system using the webcam and Firebase integration.

## Features ✨

- 📷 Real-time face recognition
- 📅 Automatic attendance marking
- 📝 Display student information
- 🔄 Dynamic mode selection
- 📊 Firebase integration for data storage
- ⚙️ Easy configuration and setup

## IDE Used ✅

- Pycharm


## Prerequisites ✅

- Python 3.x
- Required libraries: `cv2`, `os`, `pickle`, `numpy`, `face_recognition`, `cvzone`, `datetime`, `firebase_admin`, `storage`
- For face_recognition , two libraries must be installed : `opencv-python` , `dlib`
- For `dlib` , install from `dlib package install` repo by
  ```shell
  pip3 install {copy path of dlib package file from dlib package install repo}

## How to Run ▶️

1. Clone the repository:
   ```shell
   git clone https://github.com/your-username/interactive-face-attendance-system.git
2. Navigate to the project directory:
   ```shell
   cd interactive-face-attendance-system
3. Install the required libraries:
   ```shell
   pip install opencv-python opencv-python-headless face-recognition cvzone firebase-admin
4. Setup Firebase:
   - Create a Firebase project at https://console.firebase.google.com/
   - Generate a new service account key in JSON format and save it as {path}/{from Firebase}.json.
   - Replace 'databaseURL' and 'storageBucket' with your Firebase project details in the code.
5. Prepare the data:
   - Create a Modes folder and place various mode images inside it (e.g., background.png, etc.).
   - Create an EncodeFile.p containing face encodings and student IDs.
6. Run the program:
   ```shell
   python main.py

## Usage 🎯
- The program will open the webcam and display the background image with a mode selection.
- When a recognized face is detected, it will display loading text and fetch student information from Firebase.
- It will download the student image from Firebase Storage.
- It will update the student's attendance data and display it on the screen for a few seconds.
- The mode changes dynamically based on various stages during the attendance process.

## Contributing 👥
Contributions are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request.


## Feel free to further customize the README.md file by adding more emojis, symbols, or any other formatting elements as desired.

```shell
Please note that you should replace `your-username` in the repository URL with your actual GitHub username. Also, make sure to include the correct package names in the "Required libraries" section and update Firebase credentials as per your project details.
