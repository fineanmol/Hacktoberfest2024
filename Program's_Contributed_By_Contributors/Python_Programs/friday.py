# Video Tutorial - https://www.youtube.com/watch?v=snpkCxIz310&list=PLvYHxAqD3ilSEuU6oIAIa6VPIS33Pk92F

from __future__ import print_function
import warnings
import pyttsx3
import speech_recognition as sr
from gtts import gTTS
import playsound
import os
import datetime
import calendar
import random
import wikipedia
import webbrowser
import ctypes
import winshell
import subprocess
import pyjokes
import smtplib
import requests
import json
import time
from twilio.rest import Client
import wolframalpha
import pickle
import os.path
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request
from selenium import webdriver
from time import sleep

warnings.filterwarnings("ignore")

engine = pyttsx3.init()
voices = engine.getProperty("voices")
engine.setProperty("voice", voices[1].id)

SCOPES = ['https://www.googleapis.com/auth/calendar.readonly']


def talk(audio):
    engine.say(audio)
    engine.runAndWait()


def rec_audio():
    recog = sr.Recognizer()

    with sr.Microphone() as source:
        print("Listening...")
        audio = recog.listen(source)

    data = " "

    try:

        data = recog.recognize_google(audio)
        print("You said: " + data)

    except sr.UnknownValueError:
        print("Assistant could not understand the audio")

    except sr.RequestError as ex:
        print("Request Error from Google Speech Recognition" + ex)

    return data


def response(text):
    print(text)

    tts = gTTS(text=text, lang="en")

    audio = "Audio.mp3"
    tts.save(audio)

    playsound.playsound(audio)

    os.remove(audio)


def call(text):
    action_call = "assistant"

    text = text.lower()

    if action_call in text:
        return True

    return False


def today_date():
    now = datetime.datetime.now()
    date_now = datetime.datetime.today()
    week_now = calendar.day_name[date_now.weekday()]
    month_now = now.month
    day_now = now.day

    months = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ]

    ordinals = [
        "1st",
        "2nd",
        "3rd",
        "4th",
        "5th",
        "6th",
        "7th",
        "8th",
        "9th",
        "10th",
        "11th",
        "12th",
        "13th",
        "14th",
        "15th",
        "16th",
        "17th",
        "18th",
        "19th",
        "20th",
        "21st",
        "22nd",
        "23rd",
        "24th",
        "25th",
        "26th",
        "27th",
        "28th",
        "29th",
        "30th",
        "31st",
    ]

    return "Today is " + week_now + ", " + months[month_now - 1] + " the " + ordinals[day_now - 1] + "."


def say_hello(text):
    greet = ["hi", "hey", "hola", "greetings", "wassup", "hello"]

    response = ["howdy", "whats good", "hello", "hey there"]

    for word in text.split():
        if word.lower() in greet:
            return random.choice(response) + "."

    return ""


def wiki_person(text):
    list_wiki = text.split()
    for i in range(0, len(list_wiki)):
        if i + 3 <= len(list_wiki) - 1 and list_wiki[i].lower() == "who" and list_wiki[i + 1].lower() == "is":
            return list_wiki[i + 2] + " " + list_wiki[i + 3]


def note(text):
    date = datetime.datetime.now()
    file_name = str(date).replace(":", "-") + "-note.txt"
    with open(file_name, "w") as f:
        f.write(text)

    subprocess.Popen(["notepad.exe", file_name])


def google_calendar():
    creds = None
    if os.path.exists('token.pickle'):
        with open('token.pickle', 'rb') as token:
            creds = pickle.load(token)

    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file(
                '../../Voice Assistant/credentials.json', SCOPES)
            creds = flow.run_local_server(port=0)

        with open('token.pickle', 'wb') as token:
            pickle.dump(creds, token)

    service = build('calendar', 'v3', credentials=creds)

    return service


def calendar_events(num, service):
    talk('Hey there! Good Day. Hope you are doing fine. These are the events to do today')
    now = datetime.datetime.utcnow().isoformat() + 'Z'
    print(f'Getting the upcoming {num} events')
    events_result = service.events().list(calendarId='primary', timeMin=now,
                                          maxResults=num, singleEvents=True,
                                          orderBy='startTime').execute()
    events = events_result.get('items', [])

    if not events:
        talk('No upcoming events found.')
    for event in events:
        start = event['start'].get('dateTime', event['start'].get('date'))
        events_today = (event['summary'])
        start_time = str(start.split("T")[1].split("-")[0])
        if int(start_time.split(":")[0]) < 12:
            start_time = start_time + "am"
        else:
            start_time = str(int(start_time.split(":")[0]) - 12)
            start_time = start_time + "pm"
        talk(f'{events_today} at {start_time}')


try:
    service = google_calendar()
    calendar_events(10, service)
except:
    talk("Could not connect to the local wifi network. Please try again later.")
    exit()


def send_email(to, content):
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.ehlo()
    server.starttls()

    server.login("email", "pass")
    server.sendmail("email", to, content)
    server.close()


def pizza():
    driver = webdriver.Chrome(
        r" "
    )
    driver.maximize_window()

    talk("Opening Dominos")
    driver.get('https://www.dominos.co.in/')
    sleep(2)

    talk("Getting ready to order")
    driver.find_element_by_link_text('ORDER ONLINE NOW').click()
    sleep(2)

    talk("Finding your location")
    driver.find_element_by_class_name('srch-cnt-srch-inpt').click()
    sleep(2)

    location = " "

    talk("Entering your location")
    driver.find_element_by_xpath(
        '//*[@id="__next"]/div/div[1]/div[2]/div/div[1]/div/div[3]/div/div[1]/div[2]/div/div[1]/input').send_keys(
        location)
    sleep(2)

    driver.find_element_by_xpath(
        '//*[@id="__next"]/div/div[1]/div[2]/div/div[1]/div/div[3]/div/div[1]/div[2]/div[2]/div/ul/li[1]').click()
    sleep(2)

    try:
        driver.find_element_by_xpath(
            '//*[@id="__next"]/div/div/div[1]/div[1]/div/div[3]/div[3]/div[1]/div[2]').click()
        sleep(2)
    except:
        talk("Your location could not be found. Please try again later.")
        exit()

    talk("Logging in")

    phone_num = " "

    driver.find_element_by_xpath(
        '//*[@id="__next"]/div/div/div[1]/div[1]/div/div[3]/div[3]/div[2]/div/div[3]/div/div/div/div[2]/div/form/div[1]/div[2]/input').send_keys(
        phone_num)
    sleep(2)

    driver.find_element_by_xpath(
        '//*[@id="__next"]/div/div/div[1]/div[1]/div/div[3]/div[3]/div[2]/div/div[3]/div/div/div/div[2]/div/form/div[2]/input').click()
    sleep(2)

    talk("What is your O T P? ")
    sleep(3)

    otp_log = rec_audio()

    driver.find_element_by_xpath(
        '//*[@id="__next"]/div/div/div[1]/div[1]/div/div[3]/div[3]/div[2]/div/div[3]/div/div/div/div[2]/div/div/div/div[1]/input').send_keys(
        otp_log)
    sleep(2)

    driver.find_element_by_xpath(
        '//*[@id="__next"]/div/div/div[1]/div[1]/div/div[3]/div[3]/div[2]/div/div[3]/div/div/div/div[2]/div/div/div/div[2]/div[2]/button/span').click()
    sleep(2)

    talk("Do you want me to order from your favorites?")
    query_fav = rec_audio()

    if "yes" in query_fav:
        try:
            driver.find_element_by_xpath(
                '//*[@id="mn-lft"]/div[6]/div/div[6]/div/div/div[2]/div[3]/div/button/span').click()
            sleep(1)
        except:
            talk("The entered OTP is incorrect.")
            exit()

        talk("Adding your favorites to cart")

        talk("Do you want me to add extra cheese to your pizza?")
        ex_cheese = rec_audio()
        if "yes" in ex_cheese:
            talk("Extra cheese added")
            driver.find_element_by_xpath(
                '//*[@id="mn-lft"]/div[6]/div/div[1]/div/div/div[2]/div[3]/div[2]/button').click()
        elif "no" in ex_cheese:
            driver.find_element_by_xpath(
                '//*[@id="mn-lft"]/div[6]/div/div[1]/div/div/div[2]/div[3]/div[1]/button/span').click()
        else:
            talk("I dont know that")
            driver.find_element_by_xpath(
                '//*[@id="mn-lft"]/div[6]/div/div[1]/div/div/div[2]/div[3]/div[1]/button/span').click()

        driver.find_element_by_xpath(
            '//*[@id="mn-lft"]/div[16]/div/div[1]/div/div/div[2]/div[2]/div/button').click()
        sleep(1)

        talk("Would you like to increase the qty?")
        qty = rec_audio()
        qty_pizza = 0
        qty_pepsi = 0
        if "yes" in qty:
            talk("Would you like to increase the quantity of pizza?")
            wh_qty = rec_audio()
            if "yes" in wh_qty:
                talk("How many more pizzas would you like to add? ")
                try:
                    qty_pizza = rec_audio()
                    qty_pizza = int(qty_pizza)
                    if qty_pizza > 0:
                        talk_piz = f"Adding {qty_pizza} more pizzas"
                        talk(talk_piz)
                        for i in range(qty_pizza):
                            driver.find_element_by_xpath(
                                '//*[@id="__next"]/div/div/div[1]/div[2]/div[2]/div[2]/div[2]/div/div/div[1]/div[1]/div/div/div[2]/div/div/div[2]').click()
                except:
                    talk("I dont know that.")
            else:
                pass

            talk("Would you like to increase the quantity of pepsi?")
            pep_qty = rec_audio()
            if "yes" in pep_qty:
                talk("How many more pepsis would you like to add? ")
                try:
                    qty_pepsi = rec_audio()
                    qty_pepsi = int(qty_pepsi)
                    if qty_pepsi > 0:
                        talk_pep = f"Adding {qty_pepsi} more pepsis"
                        talk(talk_pep)
                        for i in range(qty_pepsi):
                            driver.find_element_by_xpath(
                                '//*[@id="__next"]/div/div/div[1]/div[2]/div[2]/div[2]/div[2]/div/div/div[1]/div[2]/div/div/div[2]/div/div/div[2]').click()
                except:
                    talk("I dont know that.")
            else:
                pass

        elif "no" in qty:
            pass

        total_pizza = qty_pizza + 1
        total_pepsi = qty_pepsi + 1
        tell_num = f"This is your list of order. {total_pizza} Pizzas and {total_pepsi} Pepsis. Do you want to checkout?"
        talk(tell_num)
        check_order = rec_audio()
        if "yes" in check_order:
            talk("Checking out")
            driver.find_element_by_xpath(
                '//*[@id="__next"]/div/div/div[1]/div[2]/div[2]/div[2]/div[2]/div/div/div[2]/div[2]/button').click()
            sleep(1)
            total = driver.find_element_by_xpath(
                '//*[@id="__next"]/div/div[1]/div[2]/div[3]/div[2]/div/div[6]/div/div/div[6]/span[2]/span')
            total_price = f'total price is {total.text}'
            talk(total_price)
            sleep(1)
        else:
            exit()

        talk("Placing your order")
        driver.find_element_by_xpath(
            '//*[@id="__next"]/div/div[1]/div[2]/div[3]/div[2]/div/div[6]/div/div/div[8]/button').click()
        sleep(2)
        try:
            talk("Saving your location")
            driver.find_element_by_xpath(
                '//*[@id="__next"]/div/div[1]/div[2]/div[3]/div[2]/div/div[3]/div/div[3]/div/div/div[3]/div/div/input').click()
            sleep(2)
        except:
            talk("The store is currently offline.")
            exit()

        talk("Do you want to confirm your order?")
        confirm = rec_audio()
        if "yes" in confirm:
            talk("Placing your order")
            driver.find_element_by_xpath(
                '//*[@id="__next"]/div/div[1]/div[2]/div/div[1]/div[2]/div/div[2]/div/div[2]/button').click()
            sleep(2)
            talk("Your order is placed successfully. Wait for Dominos to deliver your order. Enjoy your day!")
        else:
            exit()

    else:
        exit()


while True:

    try:

        text = rec_audio()
        speak = ""

        if call(text):

            speak = speak + say_hello(text)

            if "date" in text or "day" in text or "month" in text:
                get_today = today_date()
                speak = speak + " " + get_today

            elif "time" in text:
                now = datetime.datetime.now()
                meridiem = ""
                if now.hour >= 12:
                    meridiem = "p.m"
                    hour = now.hour - 12
                else:
                    meridiem = "a.m"
                    hour = now.hour

                if now.minute < 10:
                    minute = "0" + str(now.minute)
                else:
                    minute = str(now.minute)
                speak = speak + " " + "It is " + str(hour) + ":" + minute + " " + meridiem + " ."

            elif "wikipedia" in text or "Wikipedia" in text:
                if "who is" in text:
                    person = wiki_person(text)
                    wiki = wikipedia.summary(person, sentences=2)
                    speak = speak + " " + wiki

            elif "who are you" in text or "define yourself" in text:
                speak = speak + """Hello, I am an Assistant. Your Assistant. I am here to make your life easier.  
                You can command me to perform various tasks such as solving mathematical questions or opening 
                applications etcetera."""

            elif "your name" in text:
                speak = speak + "My name is Assistant."

            elif "who am I" in text:
                speak = speak + "You must probably be a human."

            elif "why do you exist" in text or "why did you come" in text:
                speak = speak + "It is a secret."

            elif "how are you" in text:
                speak = speak + "I am fine, Thank you!"
                speak = speak + "\nHow are you?"

            elif "fine" in text or "good" in text:
                speak = speak + "It's good to know that you are fine"

            elif "open" in text.lower():

                if "chrome" in text.lower():
                    speak = speak + "Opening Google Chrome"
                    os.startfile(
                        r"Location of Application"
                    )

                elif "word" in text.lower():
                    speak = speak + "Opening Microsoft Word"
                    os.startfile(
                        r"Location of Application"
                    )

                elif "excel" in text.lower():
                    speak = speak + "Opening Microsoft Excel"
                    os.startfile(
                        r"Location of Application"
                    )

                elif "vs code" in text.lower():
                    speak = speak + "Opening Visual Studio Code"
                    os.startfile(
                        r"Location of Application"
                    )

                elif "youtube" in text.lower():
                    speak = speak + "Opening Youtube\n"
                    webbrowser.open("https://youtube.com/")

                elif "google" in text.lower():
                    speak = speak + "Opening Google\n"
                    webbrowser.open("https://google.com/")

                elif "stackoverflow" in text.lower():
                    speak = speak + "Opening StackOverFlow"
                    webbrowser.open("https://stackoverflow.com/")

            elif "youtube" in text.lower():
                ind = text.lower().split().index("youtube")
                search = text.split()[ind + 1:]
                webbrowser.open(
                    "http://www.youtube.com/results?search_query=" +
                    "+".join(search)
                )
                speak = speak + "Opening " + str(search) + " on youtube"

            elif "search" in text.lower():
                ind = text.lower().split().index("search")
                search = text.split()[ind + 1:]
                webbrowser.open(
                    "https://www.google.com/search?q=" + "+".join(search))
                speak = speak + "Searching " + str(search) + " on google"

            elif "google" in text.lower():
                ind = text.lower().split().index("google")
                search = text.split()[ind + 1:]
                webbrowser.open(
                    "https://www.google.com/search?q=" + "+".join(search))
                speak = speak + "Searching " + str(search) + " on google"

            elif "change background" in text or "change wallpaper" in text:
                img = r"Location of directory"
                list_img = os.listdir(img)
                imgChoice = random.choice(list_img)
                randomImg = os.path.join(img, imgChoice)
                ctypes.windll.user32.SystemParametersInfoW(20, 0, randomImg, 0)
                speak = speak + "Background changed successfully"

            elif "play music" in text or "play song" in text:
                talk("Here you go with music")
                music_dir = r"Location of directory"
                songs = os.listdir(music_dir)
                d = random.choice(songs)
                random = os.path.join(music_dir, d)
                playsound.playsound(random)

            elif "empty recycle bin" in text:
                winshell.recycle_bin().empty(
                    confirm=True, show_progress=False, sound=True
                )
                speak = speak + "Recycle Bin Emptied"

            elif "note" in text or "remember this" in text:
                talk("What would you like me to write down?")
                note_text = rec_audio()
                note(note_text)
                speak = speak + "I have made a note of that."

            elif "joke" in text:
                speak = speak + pyjokes.get_joke()

            elif "where is" in text:
                ind = text.lower().split().index("is")
                location = text.split()[ind + 1:]
                url = "https://www.google.com/maps/place/" + "".join(location)
                speak = speak + "This is where " + str(location) + " is."
                webbrowser.open(url)

            elif "email to computer" in text or "gmail to computer" in text:
                try:
                    talk("What should I say?")
                    content = rec_audio()
                    to = "Receiver email address"
                    send_email(to, content)
                    speak = speak + "Email has been sent !"
                except Exception as e:
                    print(e)
                    talk("I am not able to send this email")

            elif "mail" in text or "email" in text or "gmail" in text:
                try:
                    talk("What should I say?")
                    content = rec_audio()
                    talk("whom should i send")
                    to = input("Enter To Address: ")
                    send_email(to, content)
                    speak = speak + "Email has been sent !"
                except Exception as e:
                    print(e)
                    speak = speak + "I am not able to send this email"

            elif "weather" in text:
                key = "OpenWeatherMap Key"
                weather_url = "http://api.openweathermap.org/data/2.5/weather?"
                ind = text.split().index("in")
                location = text.split()[ind + 1:]
                location = "".join(location)
                url = weather_url + "appid=" + key + "&q=" + location
                js = requests.get(url).json()
                if js["cod"] != "404":
                    weather = js["main"]
                    temperature = weather["temp"]
                    temperature = temperature - 273.15
                    humidity = weather["humidity"]
                    desc = js["weather"][0]["description"]
                    weather_response = " The temperature in Celcius is " + str(temperature) + " The humidity is " + str(
                        humidity) + " and The weather description is " + str(desc)
                    speak = speak + weather_response
                else:
                    speak = speak + "City Not Found"

            elif "news" in text:
                url = (
                    "http://newsapi.org/v2/top-headlines?"
                    "country= &"
                    "apiKey= "
                )

                try:
                    response = requests.get(url)
                except:
                    talk("Please check your connection")

                news = json.loads(response.text)

                for new in news["articles"]:
                    print(str(new["title"]), "\n")
                    talk(str(new["title"]))
                    engine.runAndWait()

                    print(str(new["description"]), "\n")
                    talk(str(new["description"]))
                    engine.runAndWait()
                    time.sleep(2)

            elif "send message" in text or 'send a message' in text:
                account_sid = "Twilio SID"
                auth_token = "Twilio Token"
                client = Client(account_sid, auth_token)

                talk("What should i send")
                message = client.messages.create(
                    body=rec_audio(), from_="from No.", to="to No."
                )

                print(message.sid)
                speak = speak + "Message sent successfully"

            elif "calculate" in text:
                app_id = "Wolfram Alpha ID"
                client = wolframalpha.Client(app_id)
                ind = text.lower().split().index("calculate")
                text = text.split()[ind + 1:]
                res = client.query(" ".join(text))
                answer = next(res.results).text
                speak = speak + "The answer is " + answer

            elif "what is" in text or "who is" in text:
                app_id = "Wolfram Alpha ID"
                client = wolframalpha.Client(app_id)
                ind = text.lower().split().index("is")
                text = text.split()[ind + 1:]
                res = client.query(" ".join(text))
                answer = next(res.results).text
                speak = speak + answer

            elif "don't listen" in text or "stop listening" in text or "do not listen" in text:
                talk("for how many seconds do you want me to sleep")
                a = int(rec_audio())
                time.sleep(a)
                speak = speak + str(a) + " seconds completed. Now you can ask me anything"

            elif "exit" in text or "quit" in text:
                exit()

            elif "order a pizza" in text or "pizza" in text:
                pizza()

            response(speak)

    except:
        talk("I don't know that")

