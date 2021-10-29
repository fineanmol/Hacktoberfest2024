#Structure is as follows

# importing, defining, audio, Microphone, EMAIL, other commands, dialogues



#Importing
from urllib.parse import quote_from_bytes
import pyttsx3 #pip install pyttsx3
import speech_recognition as sr #pip install speechRecognition
import datetime
import wikipedia #pip install wikipedia
import webbrowser
import pywhatkit as kit
import os
import smtplib
import random
import pyautogui
import psutil
import pyjokes
# import playsound # to play an audio file
# from gtts import gTTS # google text to speech
# import ssl
# import certifi
# from wikipedia.wikipedia import search
# import pyPDF2


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[1].id)
engine.setProperty('voice', voices[0].id)

#For opening the results in Chrome
url1 = 'youtube.com'
url2 = 'google.com'
url3 = 'amazon.in'
url4 = 'code-projects.org'
url5 = 'youtube.com/channel/UCeVMnSShP_Iviwkknt83cww'
url6 = 'stackoverflow.com'
url7 = 'mcs.edunexttechnologies.com/StudentDashboardApp/StudentHome'

chrome_path = r'C:\Program Files\Google\Chrome\Application\chrome.exe'
webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chrome_path))

# For Random Greeting

greetings = ['Hello! I am Jarvis Sir. How may I help you?', 'Sup!', 'Hey', 'Bonjour', 'Everything great..sir?', 'Hope you are great']

value = random.choice(greetings)

#For random songs
songs = ['on my way' , 'kandhon se milte hain', 'Raabta', 'Shiv Tandav Stotram']
gaana = random.choice(songs)

gaane = ['ben 10 theme song guitar' , 'kfir pirates of the caribbean', 'Jai Jai Shivshankar Song']
othersongs = random.choice(gaane)



def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def time():
    Time = datetime.datetime.now().strftime("%I:%M:%S")
    speak("the current time is")
    speak(Time)

def date():
    year = int(datetime.datetime.now().year)
    month = int(datetime.datetime.now().month)
    date = int(datetime.datetime.now().day)
    speak("the current date is")
    speak(date)
    speak(month)
    speak(year)

def wishMe():
    
    # hour = int(datetime.datetime.now().hour)
    # if hour>=0 and hour<12:
    #     speak("Good Morning!")

    # elif hour>=12 and hour<18:
    #     speak("Good Afternoon!")   

    # else:
    #     speak("Good Evening!")  

    speak(value)       

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
    server.login('vanshajpoonia06@gmail.com', 'your-password')
    server.sendmail('vanshajpoonia06@gmail.com', to, content)
    server.close()

def screenShot():
    img = pyautogui.screenshot()
    img.save ("C:\\Users\\vansh\\OneDrive\\Pictures\\Jarvis Shots\\ss.png")

def cpu():
    usage = str(psutil.cpu_percent())
    speak('CPU is at'+ usage)
    battery = psutil.sensors_battery()
    speak("Battery is at")
    speak(battery.percent )

def jokes():
    speak(pyjokes.get_joke())

if __name__ == "__main__":
    wishMe()
    while True:
    # if 1:
        query = takeCommand().lower()

        # Logic for executing tasks based on query
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)
        
        # Logic for opening apps

        elif 'open youtube' in query:
            webbrowser.get('chrome').open_new_tab(url1)
            # webbrowser.open("youtube.com")

        elif 'open google' in query:
            webbrowser.get('chrome').open_new_tab(url2)
            # webbrowser.open("google.com")

        elif 'open amazon' in query:
            webbrowser.get('chrome').open_new_tab(url3)

        elif 'code projects' in query:
            webbrowser.get('chrome').open_new_tab(url4)

        elif 'coding' in query:
            speak('coding mat lab.. harrry bhai')
            webbrowser.get('chrome').open_new_tab(url5)
            

        elif 'open stackoverflow' in query:
            webbrowser.get('chrome').open_new_tab(url6)
            # webbrowser.open("stackoverflow.com")

        elif 'online classes' in query:
            webbrowser.get('chrome').open_new_tab(url7)

        elif 'play music' in query:
            # music_dir = 'D:\\YT Downloads\\Songs\\'
            # songs = os.listdir(music_dir)
            # print(songs)    
            # os.startfile(os.path.join(music_dir, songs[0]))
            kit.playonyt(gaana)

        elif 'change' in query:
            kit.playonyt(othersongs)

        # elif 'change music' in query:
        #     kit.playonyt(othersongs)

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")    
            speak(f"Sir, the time is {strTime}")

            hour = int(datetime.datetime.now().hour)

        elif 'time in detail' in query:
            print(hour)
            year = int(datetime.datetime.now().year)
            month = int(datetime.datetime.now().month)
            date = int(datetime.datetime.now().day)
            Time = datetime.datetime.now().strftime("%I:%M:%S") 
            print(Time)
            print(date)
            print(month)
            print(year)
            speak("the current Time is")
            speak(Time)
            speak("the current Date is")
            speak(date)
            speak(month)
            speak(year)
            

        elif 'open code' in query:
            codePath = "C:\\Users\\vansh\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codePath)

        elif 'screenshot' in query:
                screenShot()
                speak('Done!')

        elif 'cpu' in query:
            cpu()

        elif 'time' in query:
            time()
        elif 'date' in query:
            date()
        
        elif 'log out' in query:
            os.system("shutdown -l")

        elif 'shutdown' in query:
            os.system("shutdown /s /t 1")

        elif 'restart' in query:
            os.system("shutdown /r /t 1")

        elif 'offline' in query:
            quit()
        
        elif 'joke' in query:
            jokes()

        elif 'to do' in query:
            speak("")

        elif 'find location' in query:
            search_term = query.replace("search","")
            # location=query('What is the location?')
            url = 'https://google.com/maps/place' + search_term + '/&amp;'
            webbrowser.get().open(url)
            speak('Here is the location of ' + search_term)

        # elif 'search' in query:
        #     search_term = query.split("for")[-1]
        #     url = f"https://google.com/search?q={search_term}"
        #     webbrowser.get().open(url)
        #     speak(f'Here is what I found for {search_term} on google')

        # elif 'search' in query:
        #     search_term = query.replace("search for","")
        #     url = "https://google.com/search?q=" + search_term
        #     webbrowser.get().open(url)
        #     speak("Here is what I found for" + search_term + "on google")

        elif 'on google' in query:
            # search_term = query.replace("search google for","",)
            search_term = query.split("for")[-1]
            search_term = search_term.replace("on google","").replace("search","")
            url = "https://google.com/search?q=" + search_term
            webbrowser.get().open(url)
            speak("Here is what I found for" + search_term + "on google")

        elif 'search' in query:
            search_term = query.replace("search for","")
            url = "https://moogle.vercel.app/search?term=" + search_term
            webbrowser.get().open(url)
            speak("Here is what I found for" + search_term + "on moogle")

        # elif ' youtube' in query:
        #     search_term = query.split("for")[-1]
        #     url = f"https://www.youtube.com/results?search_query={search_term}"
        #     webbrowser.get().open(url)
        #     speak(f'Here is what I found for {search_term} on youtube')

        elif 'on youtube' in query:
            search_term = query.split("for")[-1]
            search_term = search_term.replace("on youtube","").replace("search","")
            url = "https://www.youtube.com/results?search_query=" + search_term
            webbrowser.get().open(url)
            speak("Here is what I found for " + search_term + "on youtube")

        elif 'on mewtube' in query:
            search_term = query.split("for")[-1]
            search_term = search_term.replace("on mewtube","").replace("search","")
            url = "https://mewtube.web.app/search/" + search_term
            webbrowser.get().open(url)
            speak("Here is what I found for " + search_term + "on mewtube")

        elif'what is my exact location' in query:
            url = "https://www.google.com/maps/search/Where+am+I+?/"
            webbrowser.get().open(url)
            speak("You must be somewhere near here, as per Google maps") 


        elif 'email to vanshaj' in query:
            try:
                speak("What should I say?")
                content = takeCommand()
                to = "vanshajpoonia06@gmail.com"    
                sendEmail(to, content)
                speak("Email has been sent!")
            except Exception as e:
                print(e)
                speak("Sorry my friend Vanshaj. I am not able to send this email")    

        
        
        
        
        
        ############Dialogues####################################
        ##structure##
        #vanshaj
        #about
        #school
        #views
        elif 'who are you' in query:
            speak('I am Jarvis')
            print('I am Jarvis')
        
        elif 'who is vanshaj' in query:
            speak('Vanshaj is the most genius person in the galaxy.. oh sorry in the universe')
            print('Vanshaj is the most genius person in the galaxy.. oh sorry in the universe')
        
        elif 'you seem to be intelligent'  in query:
            speak('Hey you.. Mind your language.. I dont seem to be so, I actually am. Dont reapeat that statement Otherwise you know what can I do.. I can freakin hack your system and then I will tell you how intelligent I am... hun seem to be')



        #############Dialogues end here ##########################


        
