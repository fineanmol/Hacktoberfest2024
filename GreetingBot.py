import pyttsx3
import datetime
e=pyttsx3.init()
e.setProperty('rate',150)
e.setProperty('volume',50)

def speak(audio):
    e.say(audio)
    e.runAndWait() 

def wishMe():
    hour =int(datetime.datetime.now().hour)
    if hour>= 0 and hour<12:
        speak("Good Morning , have a great day!")
    elif hour>=12 and hour<18:
        speak("Good Afternoon!")
    elif hour>=18 and hour<21:
        speak(" Good Evening")
    else:
        speak("Good night ,have a sweet dream!")

wishMe()
