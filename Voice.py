import subprocess
import wolframalpha
import wikiquote
import pyttsx3
import json
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import winshell
import pyjokes
import feedparser
import smtplib
import ctypes
import time
import requests
import random
import fileinput
import getpass
import wmi
import os
import pytube
from youtube_search import YoutubeSearch
from pathlib import Path
import tkinter as tk
from tkinter import filedialog
from selenium import webdriver
from bs4 import BeautifulSoup
import win32com.client as wincl
from urllib.request import urlopen


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)

root = tk.Tk()
root.withdraw()

DIRECTORIES = {
    "HTML": [".html5", ".html", ".htm", ".xhtml"],
    "IMAGES": [".jpeg", ".jpg", ".tiff", ".gif", ".bmp", ".png", ".bpg", "svg",
               ".heif", ".psd"],
    "VIDEOS": [".avi", ".flv", ".wmv", ".mov", ".mp4", ".webm", ".vob", ".mng",
               ".qt", ".mpg", ".mpeg", ".3gp", ".mkv"],
    "DOCUMENTS": [".oxps", ".epub", ".pages", ".docx", ".doc", ".fdf", ".ods",
                  ".odt", ".pwi", ".xsn", ".xps", ".dotx", ".docm", ".dox",
                  ".rvg", ".rtf", ".rtfd", ".wpd", ".xls", ".xlsx", ".ppt",
                  "pptx"],
    "ARCHIVES": [".a", ".ar", ".cpio", ".iso", ".tar", ".gz", ".rz", ".7z",
                 ".dmg", ".rar", ".xar", ".zip"],
    "AUDIO": [".aac", ".aa", ".aac", ".dvf", ".m4a", ".m4b", ".m4p", ".mp3",
              ".msv", "ogg", "oga", ".raw", ".vox", ".wav", ".wma"],
    "PLAINTEXT": [".txt", ".in", ".out"],
    "PDF": [".pdf"],
    "PYTHON": [".py"],
    "XML": [".xml"],
    "EXE": [".exe"],
    "SHELL": [".sh"]
}
FILE_FORMATS = {file_format: directory
                for directory, file_formats in DIRECTORIES.items()
                for file_format in file_formats}

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def countdown(n) :
    while n > 0:
        print (n)
        n = n - 1
    if n ==0:
        print('BLAST OFF!')

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning Sir!")

    elif hour>=12 and hour<18:
        speak("Good Afternoon Sir!")   

    else:
        speak("Good Evening Sir!")  

    assname=("Jarvis 1 point o")
    speak("I am your Assistant")
    speak(assname)

def usrname():
    speak("What should i call you sir")
    uname=takeCommandname()
    speak("Welcome Mister")
    speak(uname)
    print("#####################")
    print("Welcome Mr.",uname)
    print("#####################")

def quotaton():
    speak(wikiquote.quote_of_the_day())
    print(wikiquote.quote_of_the_day())

def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        speak("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")
        speak("Recognizing")    
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        print(e)    
        print("Unable to Recognizing your voice.")  
        return "None"
    return query

def takeCommandname():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Username...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Trying to Recognizing Name...")    
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        print(e)    
        print("Unable to Recognizing your name.")
        takeCommandname()  
        return "None"
    return query

def takeCommandmessage():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Enter Your Message")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        query = r.recognize_google(audio, language='en-in')
        print(f'Message to be sent is : {query}\n')

    except Exception as e:
        print (e)
        print("Unable to recognize your message")
        print("Check your Internet Connectivity")
    return query

def takeCommanduser():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Name of User or Group")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        query = r.recognize_google(audio, language='en-in')
        print(f'Client to whome message is to be sent is : {query}\n')

    except Exception as e:
        print (e)
        print("Unable to recognize Client name")
        speak("Unable to recognize Client Name")
        print("Check your Internet Connectivity")
    return query

def organize():
    for entry in os.scandir():
        if entry.is_dir():
            continue
        file_path = Path(entry.name)
        file_format = file_path.suffix.lower()
        if file_format in FILE_FORMATS:
            directory_path = Path(FILE_FORMATS[file_format])
            directory_path.mkdir(exist_ok=True)
            file_path.rename(directory_path.joinpath(file_path))
    try:
        os.mkdir("OTHER")
    except:
        pass
    for dir in os.scandir():
        try:
            if dir.is_dir():
                os.rmdir(dir)
            else:
                os.rename(os.getcwd() + '/' + str(Path(dir)), os.getcwd() + '/OTHER/' + str(Path(dir)))
        except:
            pass

if __name__ == '__main__':
    clear = lambda: os.system('cls')
    clear()
    wishMe()
    usrname()
    speak("Can i tell you a quote of day")
    useropt=takeCommand().lower()
    if 'yes' in useropt or 'sure' in useropt:
        quotaton()
    else:
        speak("Taking you to command Library")

    speak("How can i Help you, Sir")
    while True:
        query = takeCommand().lower()
        assname=("Jarvis 1 point o")
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=3)
            speak("According to Wikipedia")
            print(results)
            speak(results)

        elif "good morning" in query:
            speak("A warm" +query)
            speak("How are you Mister")
            speak(assname)

        elif 'open youtube' in query:
            speak("Here you go to Youtube\n")
            webbrowser.open("youtube.com")
            
        elif "download youtube video" in query or "download a youtube video" in query:
            video_url = input(speak("Enter URL of Youtube Video"))
            youtube = pytube.YouTube(video_url)
            vid_title = pytube.YouTube(video_url).title
            print(vid_title)
            video = youtube.streams.first()
            video.download("C:\\Users\\HP")
            speak("Video Downloaded Succesfully")

        elif 'open google' in query:
            speak("Here you go to Google\n")
            webbrowser.open("google.com")

        elif "change brightness to " in query:
            bright = [int(word) for word in query.split() if word.isdigit()]
            brightness = bright
            c = wmi.WMI(namespace='wmi')
            methods = c.WmiMonitorBrightnessMethods()[0]
            methods.WmiSetBrightness(brightness, 0)

        elif "Organize Files" in query:
            organize()

        elif 'open stackoverflow' in query:
            speak("Here you go to Stack Over flow.Happy coding")
            webbrowser.open("stackoverflow.com")   

        elif "send a whatsaap message" in query or "send WhatsApp message" in query:
            driver = webdriver.Chrome('C:\\Users\\HP\\OneDrive\\Desktop\\Major Project\\Voice Assistant\\chromedriver_win32\\chromedriver.exe')
            driver.get('https://web.whatsapp.com/')
            speak("Scan QR code before proceding")
            tim=10
            time.sleep(tim)
            speak("Enter Name of Group or User")
            name = takeCommanduser()
            speak("Enter Your Message")
            msg = takeCommandmessage()
            user = driver.find_element_by_xpath('//span[@title = "{}"]'.format(name))
            user.click()
            msg_box = driver.find_element_by_class_name('_3u328')
            msg_box.send_keys(msg)
            button = driver.find_element_by_class_name('_3M-N-')
            button.click()

        elif "explorer" in query:
            speak("Opening explorer")
            subprocess.call("explorer")
            
        elif "excel" in query:
            speak("Mention file location")
            file_path = filedialog.askopenfilename()
            os.startfile(file_path)
                        
        elif "word" in query:
            speak("Mention file location")
            file_path = filedialog.askopenfilename()
            os.startfile(file_path)

        elif "stackoverflow " in query:
            speak("Opening Stackoverflow")
            webbrowser.open("stackoverflow.com")   

        elif 'play music' in query or "play song" in query or "gaana"in query or "song" in query:
            speak("Here you go with music")
            username = getpass.getuser()
            try:
                music_dir = "C:\\Users\\"+username+"\\Music"
            except Exception as e:
                print("Following Exception Occured",e)
                speak("Following Exception Occured",e)
                
            finally:            
                songs = os.listdir(music_dir)
                print(songs)    
                random=os.startfile(os.path.join(music_dir, songs[1]))

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")    
            speak(f"Sir, the time is {strTime}")

        elif 'open chrome' in query:
            try:
                subprocess.call("chrome")
            except Exception as e:
                print(e)

        elif 'joke' in query:
            speak(pyjokes.get_joke())

        elif 'add' in query or "subsctract" in query or "multiply" in query or "divide" in query:
            num1,num2 = [int(word) for word in query.split() if word.isdigit()]                        
            if "add" in query or "addition" in query or "plus" in query:
                speak(num1+num2)
                print(num1+num2)
                
            elif "substract" in query or "Sub" in query or "minus" in query:
                speak(num1-num2)
                print(num1-num2)

            elif "multiply" in query:
                speak(num1*num2)
                print(num1*num2)
                
            elif "divide" in query:
                speak(num1/num2)
                print(num1/num2)

        elif 'search' in query or 'play' in query: 
            query = query.replace("search", "") 
            query = query.replace("play", "")
            webbrowser.open(query) 

        elif "boring" in query or "fun" in query:
            speak("Would you like to play RPS")
            opt=takeCommand()
            if "yes" in opt:
                speak("Rock , Paper or Scissor")
                usr=takeCommand()
                usr=takeCommand().lower()
                action=("rock","paper","scissior","rock","paper","scissior","rock","paper","scissior")                
                coom=random.choices(action)
                coom = ' '.join(map(str, coom))
                print("User Symbol : ",usr) 
                print("Computer Symbol : ",coom)
                if coom==usr:
                    speak("Match Draw")

                elif coom=="scissior" and usr=="paper":
                    speak("Computer Won")

                elif usr=="scissior" and coom=="paper":
                    speak("User won")

                elif usr=="rock" and coom=="paper":
                    speak("Computer won")

                elif coom=="rock" and usr=="paper":
                    speak("User won")

                elif coom=="scissior" and usr=="rock":
                    speak("User won")

                elif usr=="scissior" and coom=="rock":
                    speak("Computer won")
                    
            else:
                speak(pyjokes.get_joke())

        elif 'change background' in query:
            ctypes.windll.user32.SystemParametersInfoW(20, 0, "C:\\Users\\HP\\OneDrive\\Minor Project\\Voice\\back.jpg" , 0)
            speak("Background changed succesfully")

        elif 'open bluestack' in query:
            appli= r"C:\\ProgramData\\BlueStacks\\Client\\Bluestacks.exe"
            os.startfile(appli)

        elif 'google news' in query:
            try:
                jsonObj = urlopen('''https://newsapi.org/v2/top-headlines?sources=google-news-in&apiKey=5c06fed7ad3f4c78bb4c3a44255788cd''')
                data = json.load(jsonObj)
                i = 1
                speak('')
                print('''===============Google News============'''+ '\n')
                for item in data['articles']:
                    print(str(i) + '. ' + item['title'] + '\n')
                    print(item['description'] + '\n')
                    speak(str(i) + '. ' + item['title'] + '\n')
                    i += 1
            except Exception as e:
                    print(str(e))

        elif "bbc news" in query:
            try:
                main_url = " https://newsapi.org/v1/articles?source=bbc-news&sortBy=top&apiKey=5c06fed7ad3f4c78bb4c3a44255788cd"
                open_bbc_page = requests.get(main_url).json() 
                article = open_bbc_page["articles"] 
                results = [] 
                for ar in article: 
                    results.append(ar["title"]) 
                for i in range(len(results)): 
                    print(i + 1, results[i])
            except Exception as e:
                print(str(e))

        elif 'news' in query: #samachar
            try:
                jsonObj = urlopen('''https://newsapi.org/v1/articles?source=the-times-of-india&sortBy=top&apiKey=5eeb7514007b4690b7195b4d197a75d4''')
                data = json.load(jsonObj)
                i = 1
                speak('here are some top news from the times of india')
                print('''===============TIMES OF INDIA============'''+ '\n')
                for item in data['articles']:
                    print(str(i) + '. ' + item['title'] + '\n')
                    print(item['description'] + '\n')
                    speak(str(i) + '. ' + item['title'] + '\n')
                    i += 1
            except Exception as e:
                print(str(e))

        elif 'lock window' in query:
            speak("locking the device")
            ctypes.windll.user32.LockWorkStation()

        elif 'shutdown system' in query:
            speak("Hold On a Sec! Your system is on its way to shut down")
            subprocess.call('shutdown /p /f')


        elif 'empty recycle bin' in query:
            winshell.recycle_bin().empty(confirm=False, show_progress=False, sound=True)
            speak("Recycle Bin Recycled")


        elif "don't listen" in query or "stop listening" in query or "do not listen" in query:
            speak("for how much time you want to stop jarvis from listening commands")
            a=int(takeCommand())
            time.sleep(a)
            print(a)

        elif "where is" in query:
            query=query.replace("where is","")
            location = query
            speak("User asked to Locate")
            speak(location)
            webbrowser.open("https://www.google.nl/maps/place/" + location + "")

        elif "restart" in query:
            subprocess.call(["shutdown", "/r"])

        elif "hibernate" in query or "sleep" in query:
            speak("Hibernating")
            subprocess.call("shutdown /i /h")

        elif "log off" in query or "sign out" in query:
            speak("Make sure all the application are closed before sign-out")
            time.sleep(5)
            subprocess.call(["shutdown", "/l"])

        elif "countdown of" in query:
            contt = [int(word) for word in query.split() if word.isdigit()]
            countdown(contt)

        elif "write a note" in query:
            speak("What should i write , sir")
            note= takeCommand()
            file = open('jarvis.txt','w')
            speak("Sir, Should i include date and time")
            snfm = takeCommand()
            if 'yes' in snfm or 'sure' in snfm:
                strTime = datetime.datetime.now().strftime("%H:%M:%S")
                file.write(strTime)
                file.write(" :- ")
                file.write(note)
            else:
                file.write(note)
        
        elif "show note" in query:
            speak("Showing Notes")
            file = open("jarvis.txt", "r") 
            print(file.read())
            speak(file.read(6))

        elif "jarvis" in query:
            wishMe()
            speak("Jarvis 1 point o in your service Mister")
            speak(assname)

        elif "weather" in query:
            api_key = "139ff8e5644894750d3293adb1372433"
            base_url = "http://api.openweathermap.org/data/2.5/weather?"
            speak(" City name ")
            print("City name : ")
            city_name=takeCommand()
            complete_url = base_url + "appid=" + api_key + "&q=" + city_name
            response = requests.get(complete_url) 
            x = response.json() 
            if x["cod"] != "404": 
                y = x["main"] 
                current_temperature = y["temp"] 
                current_pressure = y["pressure"] 
                current_humidiy = y["humidity"] 
                z = x["weather"] 
                weather_description = z[0]["description"] 
                print(" Temperature (in kelvin unit) = " +str(current_temperature)+"\n atmospheric pressure (in hPa unit) ="+str(current_pressure) +"\n humidity (in percentage) = " +str(current_humidiy) +"\n description = " +str(weather_description)) 
            else: 
                speak(" City Not Found ") 

        elif "wikipedia" in query:
            webbrowser.open("wikipedia.com")

        elif "will you be my gf" in query or "will you be my bf" in query:   #most asked question from google Assistant
            speak("I'm not sure about , may be you should give me some time")

        elif "how are you" in query:
            speak("I'm fine, glad you asked me that")

        elif "what is" in query or "who is" in query:
            client= wolframalpha.Client("WTHP37-K6P2X72X3E")
            res = client.query(query)
            try:
                print(next(res.results).text)
                speak(next(res.results).text)
            except StopIteration:
                print ("No results")

        elif "open Gmail" in query:
            webbrowser.open("https://mail.google.com/mail/")

        elif "open yahoo mail" in query:
            webbrowser.open("https://in.mail.yahoo.com")

        elif "Show project Report" in query:
            speak("Opening Major Project Report")
            projectre= r"C:\\Users\\User\\Desktop\\Minor Project\\Presentation\\Project Report.docx"
            os.startfile(projectre)
                    
        elif "who i am" in query:
            speak("If you talk then definately your human.")

        elif 'power point presentation' in query or "PowerPoint presentation" in query:
            speak("opening Power Point presentation")
            file_path = filedialog.askopenfilename()
            os.startfile(file_path)

        elif 'how are you' in query:
            speak("I am fine , Thank you")
            speak("How are you, Sir")

        elif "change my name to" in query:
            query=query.replace("change my name to","")
            assname=query

        elif "change name" in query:
            speak("What would you like to call me ,Sir ")
            assname = takeCommand()
            speak("Thanks for naming me")

        elif "what's your name" in query or "What is your name" in query:
            speak("My friends call me")
            speak(assname)
            print("My friends call me",assname)

        elif 'exit' in query:
            speak("Thanks for giving me your time")
            exit()
