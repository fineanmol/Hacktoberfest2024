import speech_recognition as s_r
import win32com.client
import pywhatkit

def text_speech(text):
    speaker=win32com.client.Dispatch("SAPI.SpVoice")
    speaker.Speak(text)
    
def speech_text():
    print("Listening.......")
    sp_recog=s_r.Recognizer()
    with s_r.Microphone() as sp_mic:
        sp_recog.pause_theshold =1
        audio=sp_recog.listen(sp_mic)
        try:
            final_text=sp_recog.recognize_amazon(audio, language="en-in")
            final_text.title()
            print(f"User:- {final_text}")
            return final_text
        except Exception as e:
            print("No Speech Recognised , Plzz Try Again")
            return "No Speech Recognised , Plzz Try Again"

def whatsapp_instant(number,message):
    pywhatkit.sendwhatmsg_instantly(number,message,15 , True , 5)

def whatsapp_instant_gp(group,message):
    pywhatkit.sendwhatmsg_to_group_instantly(group,message,15 , True , 5)

def whatsapp_time(number,message,hr,min):
    pywhatkit.sendwhatmsg(number,message,hr,min,15,True,5)

def whatsapp_time_gp(group,message,hr,min):
    pywhatkit.sendwhatmsg_to_group(group,message,hr,min,15,True,5)

def whatsapp_image_gp(group,path,caption):
    pywhatkit.sendwhats_image(group,path,caption,15,True,5)


def selection():
    print("1.Send Message To Number")
    print("2.Send Message To Group")
    print("3.Send Message To Number In A Specified Time")
    print("4.Send Message To Group In A Specified Time")
    print("5.Send Image To A Group/Number ")
    choice=int(input("Enter Choice 1-5 :-"))
    return choice

def num():
    number = input("Enter Number:-")
    return number

def grp():
    group = input("Enter Group:-")
    return group

def hour():
    hr= int(input("Enter Hours:-"))
    return hr

def mintue():
    min=int(input("Enter Mintue:-"))
    return min

def caption():
    cap=input("Enter Caption:- ")
    return cap

def path():
    ph=input("Enter Path:- ")


if __name__ == '__main__':
        print("Welcome To Swarnadeep Voice To Whatsapp Text Messanger")
        option=selection()
        if(option==1):
            number=num()
            msg=speech_text()
            text_speech(msg)
            whatsapp_instant(number,msg)
        if(option==2):
            group=grp()
            msg=speech_text()
            text_speech(msg)
            whatsapp_instant_gp(group,msg)
        if(option==3):
            number = num()
            hr=hour()
            min=mintue()
            msg=speech_text()
            text_speech(msg)
            whatsapp_time(number,msg,hr,min)
        if(option==4):
            group=grp()
            hr=hour()
            min=mintue()
            msg=speech_text()
            text_speech(msg)
            whatsapp_time_gp(group, msg, hr, min)
        if(option==5):
            group=group()
            caption=caption()
            path=path()
            whatsapp_image_gp(group,path,caption)
        print("Thanks For Using SWL Speech Recogniser")
