from tkscrolledframe import ScrolledFrame
from tkinter import *
from PIL import Image, ImageTk
import tkinter.font
from textblob import TextBlob
from googletrans import Translator
from pycountry import languages
from gtts import gTTS
from playsound import playsound
import os

root = Tk()
root.title("TRANSLATE")
root.geometry("950x750")
root.maxsize(950, 750)
root.minsize(950, 750)
root.config(background="white")

entry = StringVar(root, value="")

mylist = []

language = ["Bengali", "Bulgarian", "English", "French",
            "German", "Gujarati", "Hindi", "Indonesian", "Irish", "Italian",
            "Japanese", "Latin", "Malayalam", "Marathi", "Punjabi",
            "Portuguese", "Romanian", "Russian", "Spanish", "Swedish", "Tamil", "Telugu", "Thai"]


def star():
    global ans, y
    blob = entry.get()
    litem = listbox.curselection()
    de = ",".join([listbox.get(i) for i in litem])
    trans = Translator()
    out = trans.translate(blob, dest=de)
    # detect = trans.detect(blob)
    # lang_name = languages.get(alpha_2=detect.lang).name
    # print(lang_name)
    # print(out.text)  # will print the translated text on the terminal
    # print(detect.lang)
    mylist = []
    x2 = Label(root, text="", fg="black", font=("Comic Sans MS", 20), wraplength=200, justify="center", bg="white")
    x2.place(x=130, y=500, height=170, width=685)
    ans = out.text
    mylist.append(ans)
    text1 = Text(x2, font=("Comic Sans MS", 20))
    scrollbar = Scrollbar(x2, command=text1.yview)
    text1.config(yscrollcommand=scrollbar.set)
    scrollbar.pack(side=RIGHT, fill=Y)
    text1.delete("1.0", "end")
    for y in mylist:
        text1.insert(END, y)

    text1.pack()


f1 = Frame(root, bg="white")
f1.pack(side=TOP, fill="x")

image1 = Image.open("bg.jpg")
image1 = image1.resize((950, 750), Image.ANTIALIAS)
photo1 = ImageTk.PhotoImage(image1)
ph_label1 = Label(image=photo1)
ph_label1.place(x=0, y=0)

x3 = Label(root, text="TRANSLATOR", fg="white", font=("Comic Sans MS", 30), bg="black")
x3.place(x=280, y=10)
# frame_top = Frame(root, width=400, height=250)
# frame_top.place(x=100,y=300)
# sf = ScrolledFrame(frame_top, width=380, height=240)
# sf.pack(side="top", expand=1, fill="both")
# sf.bind_arrow_keys(frame_top)
# sf.bind_scroll_wheel(frame_top)

language_entry = Entry(root, textvariable=entry, font=("Comic Sans MS", 20))
language_entry.place(x=100, y=130, height=50, width=650)
# scroll_bar = Scrollbar(root)
# scroll_bar.pack( side = RIGHT,fill = Y )
# mylist = Listbox(root, yscrollcommand = scroll_bar.set )
x5 = Label(root, text="WRITE HERE", fg="white", font=("Comic Sans MS", 15), bg="black")
x5.place(x=100, y=80, height=50, width=130)

x2 = Label(root, text="", fg="black", font=("Comic Sans MS", 20), wraplength=200, justify="center", bg="white")
x2.place(x=130, y=500, height=170, width=685)


def start():
    global myframe, listbox, my_scroll
    myframe = Label(root, bg="white", fg="black")
    myframe.place(x=160, y=280, width=200, height=150)

    listbox = Listbox(myframe, width=70, font=("Comic Sans MS", 15))
    for i in language:
        listbox.insert(END, i)
    my_scroll = Scrollbar(myframe, orient=VERTICAL, command=listbox.yview)
    listbox.config(yscrollcommand=my_scroll.set)
    my_scroll.pack(side=RIGHT, fill=Y)
    listbox.pack()
    b3 = Button(root, text="OKAY", font=("Comic Sans MS", 10), command=star, width=5, bg='white')
    b3.place(x=230, y=450)


# x4.config(text=lang_name,padx=3,pady=3)


def trans():
    blob = entry.get()
    trans = Translator()
    detect = trans.detect(blob)
    lang_name = languages.get(alpha_2=detect.lang).name
    x4 = Label(root, text=lang_name, fg="black", font=("Comic Sans MS", 15), bg="white")
    x4.place(x=650, y=300, height=50, width=100)


def play():
    message = entry.get()
    speech = gTTS(text=message)
    speech.save('input.mp3')
    playsound('input.mp3')
    os.remove('input.mp3')


def output_play():
    message2 = ans
    speech_2 = gTTS(text=message2)
    speech_2.save('output.mp3')
    playsound('output.mp3')
    os.remove('output.mp3')


b2 = Button(root, text="TRANSLATE", font=("Comic Sans MS", 15), command=start, width=15, bg='white')
b2.place(x=160, y=230)
b3 = Button(root, text="DETECT LANGUAGE", font=("Comic Sans MS", 15), command=trans, width=18, bg='white')
b3.place(x=580, y=230)
b4 = Button(root, text="PRONOUNCE", font=("Comic Sans MS", 15), command=play, height=1, width=11, bg='white')
b4.place(x=755, y=130)
b5 = Button(root, text="PRONOUNCE", font=("Comic Sans MS", 15), command=output_play, height=1, width=11, bg='white')
b5.place(x=673, y=440)

root.mainloop()
