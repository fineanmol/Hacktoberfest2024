import pyttsx3

engine = pyttsx3.init()

inputFile = open("speechInput.txt","r")

engine.say(inputFile.read())
engine.runAndWait()