import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

# Load the Firebase service account key
cred = credentials.Certificate("C://Users//Mohak//Desktop//NXtech-Python//NXTECH-Python-Task-Number-3//services.json")

# Initialize the Firebase Admin SDK with the service account key and the database URL
firebase_admin.initialize_app(cred, {
    'databaseURL' : "https://face-attendace-system-ecbe7-default-rtdb.firebaseio.com/"
})

# Get a reference to the 'Students' node in the Firebase Realtime Database
ref = db.reference('Students')

# Data to be added to the 'Students' node
data = {
    "DS1913828" : {
        "Name" : "Mohak Singhania",
        "Major" : "MSC DSA",
        "Starting_Year" : 2022,
        "Total_Attendance": 0,
        "Standing": "G",
        "Year": 2,
        "Last_Attendance_Time": "2023-05-10 23:59:59"
    },
    "DS1808679" : {
        "Name" : "Vaishnavi Singh",
        "Major" : "MSC DSA",
        "Starting_Year" : 2022,
        "Total_Attendance": 0,
        "Standing": "G",
        "Year": 2,
        "Last_Attendance_Time": "2023-05-10 23:59:59"
    },
    "DS1910512" : {
        "Name" : "Sudhir Patidar",
        "Major" : "MSC DSA",
        "Starting_Year" : 2022,
        "Total_Attendance":0,
        "Standing": "G",
        "Year":2,
        "Last_Attendance_Time":"2023-05-10 23:59:59"
    },
    "DS2200004" : {
        "Name" : "Jay Singh",
        "Major" : "MSC DSA",
        "Starting_Year" : 2022,
        "Total_Attendance":0,
        "Standing": "G",
        "Year":2,
        "Last_Attendance_Time":"2023-05-10 23:59:59"
    },
    "DS2200069" : {
        "Name" : "Prachi Khumbhkar",
        "Major" : "MSC DSA",
        "Starting_Year" : 2022,
        "Total_Attendance":0,
        "Standing": "G",
        "Year":2,
        "Last_Attendance_Time":"2023-05-10 23:59:59"
    },
    "DS1914364" : {
        "Name" : "Neeraj Gupta",
        "Major" : "MSC DSA",
        "Starting_Year" : 2022,
        "Total_Attendance":0,
        "Standing": "G",
        "Year":2,
        "Last_Attendance_Time":"2023-05-10 23:59:59"
    }
}

# Loop through the data dictionary and set each student's information in the database
for key, value in data.items():
    ref.child(key).set(value)

# Note: The code above sets the data for each student using their unique ID (e.g., "DS1913828") as the key.
# The data for each student will be stored under their respective keys in the 'Students' node in the database.
# Make sure to replace the existing data with actual data for each student.

# The above code will write the following structure in the Firebase Realtime Database:
# - Students
#   |- DS1913828
#   |    |- Name: "Mohak Singhania"
#   |    |- Major: "MSC DSA"
#   |    |- Starting_Year: 2022
#   |    |- Total_Attendance: 0
#   |    |- Standing: "G"
#   |    |- Year: 2
#   |    |- Last_Attendance_Time: "2023-05-10 23:59:59"
#   |
#   |- DS1808679
#   |    |- Name: "Vaishnavi Singh"
#   |    |- Major: "MSC DSA"
#   |    |- Starting_Year: 2022
#   |    |- Total_Attendance: 0
#   |    |- Standing: "G"
#   |    |- Year: 2
#   |    |- Last_Attendance_Time: "2023-05-10 23:59:59"
#   |
#   |- DS1910512
#   ... and so on for other students

























