import speech as sr
import winsound
import datetime
import pyttsx3


engine = pyttsx3.init()


def speech(audio):
    engine.setProperty('rate', 200)
    voices = engine.getProperty('voices')
    engine.setProperty('voice', voices[0].id)
    engine.say(audio)
    engine.runAndWait()


def takeCommand():

    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source, duration=1)
        print()
        print("Listening...")
        print()
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


def alarm(Timing):

    altime = str(datetime.datetime.now().strptime(Timing, "%I:%M %p"))
    altime = altime[11:-3]
    print(altime)
    Horeal = altime[:2]
    Horeal = int(Horeal)
    Mireal = altime[3:5]
    Mireal = int(Mireal)

    print(f"Done, alarm is set for {Timing}")

    while True:
        if Horeal == datetime.datetime.now().hour and Mireal == datetime.datetime.now().minute:
            print("alarm is running please exit the program")
            winsound.PlaySound('abc', winsound.SND_LOOP)

        elif Mireal < datetime.datetime.now().minute:
            break


speech("say set alarm for 5:30 am ")

print("say set alarm for 5:30 am")
tt = takeCommand()
tt = tt.replace("set alarm to ", "")
tt = tt.replace(".", "")
tt = tt.upper()
alarm(tt)