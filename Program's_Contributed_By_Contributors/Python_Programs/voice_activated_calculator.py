import speech_recognition as sr
import datetime
import webbrowser as wb
import os
import pyttsx3
import wikipedia
import pywhatkit
import pyjokes as pj
import smtplib
import requests
from bs4 import BeautifulSoup
import winsound
import operator
import random

def speech(audio):
    engine.setProperty('rate', 175)
    voices = engine.getProperty('voices')  # getting details of current voice
    # engine.setProperty('voice', voices[1].id)  # changing index, changes voices. o for male
    engine.setProperty('voice', voices[0].id)
    engine.say(audio)
    engine.runAndWait()

def takeCommand():
    # It takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source, duration=1)
        print()
        print("Listening...")
        print()
        # r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")
        print()
        query = r.recognize_google(audio, language='en-in')
        print(f"you said: {query}\n")

    except Exception as e:
        print("Say that again please...")
        print()
        print(e)
        return "None"
    return query
    
    def calculate():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        speech("say what you want to calculate, example 3 plus 3")
        print("Listening...")
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source)
        my_string = r.recognize_google(audio)
        print(my_string)

        def get_operator_fn(op):
            return {
                '+': operator.add,
                '-': operator.sub,
                '*': operator.mul,
                'divided': operator.__truediv__,
            }[op]

        def evel_binary(op1, oper, op2):
            op1, op2 = int(op1), int(op2)
            return get_operator_fn(oper)(op1, op2)

        speech("your result is ")
        speech(evel_binary(*(my_string.split())))


while True:

    speechInput = takeCommand().lower()
    
    calculate()
       
    
    
