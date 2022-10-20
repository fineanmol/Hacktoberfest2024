import datetime
import os
import re
import smtplib
import subprocess
import sys
import urllib
import urllib.request
import webbrowser
from time import strftime
import pafy
import speech_recognition as sr
import vlc
from bs4 import BeautifulSoup as soup
from pyowm import OWM
from speech_recognition.__main__ import source
from youtube_dl.extractor import reddit


def AssistantResponse(audio):
    print(audio)
    for _ in audio.splitlines():
        os.system("say " + audio)


def myCommand():
    r1 = sr.Recognizer()
    with sr.Microphone() as source1:
        print('Say something...')
        r1.pause_threshold = 1
        r1.adjust_for_ambient_noise(source1, duration=1)
        audio = r1.listen(source1)
    try:
        command = r1.recognize_google(audio).lower()
        print('You said: ' + command + '\n')
    # loop back to continue to listen for commands if unrecognizable speech is received
    except sr.UnknownValueError:
        print('....')
        command = myCommand()
    return command

def assistant(command, html_content=(), r1=()):
    if 'shutdown' in command:
        AssistantResponse('Bye bye Sir. Have a nice day')
        sys.exit()
    # open website
    elif 'open' in command:
        reg_ex = re.search('open (.+)', command)
        if reg_ex:
            domain = reg_ex.group(1)
            print(domain)
            url = 'https://www.' + domain
            webbrowser.open(url)
            AssistantResponse('The website you have requested has been opened for you Sir.')
        else:
            pass
    # greetings
    elif 'hello' in command:
        day_time = int(strftime('%H'))
        if day_time < 12:
            AssistantResponse('Hello Sir. Good morning')
        elif 12 <= day_time < 18:
            AssistantResponse('Hello Sir. Good afternoon')
        else:
            AssistantResponse("Hello Sir. Good evening")
    # top stories from google news
    elif 'news for today' in command:
        try:
            news_url = "https://news.google.com/news/rss"
            Client = urllib.request.urlopen(news_url)
            xml_page = Client.read()
            Client.close()
            soup_page = soup(xml_page, "xml")
            news_list = soup_page.findAll("item")
            for news in news_list[:15]:
                AssistantResponse(news.title.text.encode('utf-8'))
        except Exception as e:
            print(e)
    # current weather
    elif 'current weather' in command:
        reg_ex = re.search('current weather in (.*)', command)
        if reg_ex:
            city = reg_ex.group(1)
            owm = OWM(API_key='ab0d5e80e8dafb2cb81fa9e82431c1fa')
            obs = owm.weather_at_place(city)
            w = obs.get_weather()
            k = w.get_status()
            x = w.get_temperature(unit='celsius')
            AssistantResponse(
                'Current weather in %s is %s. The maximum temperature is %0.2f and the minimum temperature is %0.2f '
                'degree celsius' % (
                    city, k, x['temp_max'], x['temp_min']))
    # time
    elif 'time' in command:
        now = datetime.datetime.now()
        AssistantResponse('Current time is %d hours %d minutes' % (now.hour, now.minute))
    # email
    elif 'email' in command:
        AssistantResponse('Who is the recipient?')
        recipient = myCommand()
        if 'rajat' in recipient:
            AssistantResponse('What should I say to him?')
            content = myCommand()
            mail = smtplib.SMTP('smtp.gmail.com', 587)
            mail.ehlo()
            mail.starttls()
            mail.login('your_email_address', 'your_password')
            mail.sendmail('sender_email', 'receiver_email', content)
            mail.close()
            AssistantResponse('Email has been sent successfully. You can check your inbox.')
        else:
            AssistantResponse('I don\'t know what you mean!')
    # launch reddit
    elif 'launch' in command:
        reg_ex = re.search('launch (.*)', command)
        if reg_ex:
            subprocess.Popen(["open", "-n", "/Applications/" + reddit.app], stdout=subprocess.PIPE)
            AssistantResponse('I have launched the desired application')
    # launch song
    elif 'play me a song' in command:
        Assistant_Response('What song should I play Sir?')
        audio2 = r1.listen(source)
        voice_d = r1.recognize_google(audio2)
        search_results = re.findall(r'href=\"/watch\?v=(.{11})', html_content.read().decode())
        t = ("http://www.youtube.com/watch?v=" + search_results[0])
        video = pafy.new(t)
        best = video.getbest()
        playurl = best.url
        Instance = vlc.Instance()
        player = Instance.media_player_new()
        Media = Instance.media_new(playurl)
        Media.get_mrl()
        player.set_media(Media)
        player.play()
        datetime.time.sleep(120)