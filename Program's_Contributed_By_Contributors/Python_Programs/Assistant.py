import pyttsx3 #pip install pyttsx3
import speech_recognition as sr #pip install speechRecognition
import datetime
import wikipedia #pip install wikipedia
import webbrowser
import os
import smtplib
import pyautogui #pip install PyAutoGUI
import time


#Dictionary for emails
dict = {'Name of user you want to send emails to':'Email of that user','Example':'example@gmail.com'}



 
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[1].id)
engine.setProperty('voice', voices[1].id)
 
 
def speak(audio):
    engine.say(audio)
    engine.runAndWait()
    
def substring_after(s, delim):
    return s.partition(delim)[2]
 
 
def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning!")
 
    elif hour>=12 and hour<18:
        speak("Good Afternoon!")   
 
    else:
        speak("Good Evening!")  
 
   # speak("how may I help you")       
 
def takeCommand():
    #It takes microphone input from the user and returns string output
 
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)
 
    try:
        print("Recognizing...")    
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")
 
    except Exception as e:
        # print(e)    
        print("Say that again please...")  
        return "None"
    return query
 
def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.ehlo()
    # Only change Your Mail, Your Password, Your Name DONOT CHANGE ANY SYNTAX
    server.login('Your Email', 'Your Password')
    server.sendmail('Your Name<Your Email>', to, content)
    server.close()
 
if __name__ == "__main__":
    wishMe()
    while True:
    # if 1:
        query = takeCommand().lower()
 
        # Logic for executing tasks based on query
        if 'wikipedia' in query:
            wiki = substring_after(query, "wikipedia")
            speak('Searching Wikipedia...')
            query = wiki
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)
            
            
        elif 'check email' in query:
            webbrowser.open("https://mail.google.com/mail/u/1/#inbox")
 
        elif 'open youtube' in query:
            webbrowser.open("youtube.com")
            
                
                
        elif 'youtube' in query:
            search = substring_after(query, "youtube")
            if search:
                webbrowser.open("https://www.youtube.com/results?search_query="+search)
            else:
               speak("Sorry. I could not get it")
                      
        elif 'play' in query:
            search = substring_after(query, "play")
            if search:
                webbrowser.open("https://www.youtube.com/results?search_query="+search)
                # Change time and click position as required
                time.sleep(4.5)
                pyautogui.click(639, 428,1,1, button="left")
               
            else:
               speak("Sorry. I could not get it")

                      
        elif 'google' in query:
            search = substring_after(query, "google")
            if search:
                webbrowser.open("https://www.google.com/search?q="+search+"&source=hp&ei=IIvWYr3WDO-ZseMPlPqikAw&iflsig=AJiK0e8AAAAAYtaZMLg7j7tDRhiiA5fYF26qAx3f92Fs&ved=0ahUKEwi95pDj4oT5AhXvTGwGHRS9CMIQ4dUDCAc&uact=5&oq=hello&gs_lcp=Cgdnd3Mtd2l6EAMyCwguEIAEELEDENQCMggIABCABBCxAzILCC4QgAQQsQMQ1AIyCAgAEIAEELEDMggIABCABBCxAzIFCAAQgAQyDgguEIAEELEDEIMBENQCMggILhCABBDUAjILCAAQgAQQsQMQgwEyCwguEIAEELEDEIMBOg4IABCPARDqAhCMAxDlAjoOCC4QjwEQ6gIQjAMQ5QI6CAgAELEDEIMBOggILhCABBCxAzoOCC4QsQMQgwEQxwEQrwE6BQguELEDOggILhCxAxDUAlDtDljtE2CiFmgBcAB4AIABfogB1gSSAQMwLjWYAQCgAQGwAQU&sclient=gws-wiz")
            else:
                speak("Sorry. I could not get it")
    
        # Change Path to the files as in your computer
 
 
        elif 'play music' in query:
            music_dir = 'D:\Music'
            songs = os.listdir(music_dir)
            print(songs)    
            os.startfile(os.path.join(music_dir, songs[4]))
 
        elif 'time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")    
            speak(f"the time is {strTime}")

        elif 'open code' in query:
            codePath = "C:\\Users\\Lenovo\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codePath)

        elif 'open notes' in query:
            notesPath = "F:\\Python Projects\\Python\\Diwas Notes.exe"
            os.startfile(notesPath)

        elif 'open note' in query:
            notePath = "F:\\Python Projects\\Python\\Diwas Notes.exe"
            os.startfile(notePath)
 
        elif 'email' in query:
            try:
                name = list(query.split()) # extract receiver's name
                name = name[name.index('email')+1]
                speak("What should be the subject?")
                SUBJECT = takeCommand()
                speak("What should I say?")
                TEXT = takeCommand()
                content = 'Subject: {}\n\n{}'.format(SUBJECT, TEXT)
                to =dict[name]
                sendEmail(to, content)
                speak("Email has been sent!")
            except Exception as e:
                print(e)
                speak("Sorry. I am not able to send this email")   
                
                
        elif 'close' in query:
            break