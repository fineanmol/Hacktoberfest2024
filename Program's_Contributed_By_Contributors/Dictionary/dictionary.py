from tkinter import *
import json
import pyttsx3

meaning = json.load(open("words.json"))

def ser1():
    rw = e1.get()
    rw = rw.lower()
    t1.delete("1.0","end")
    print(rw)
    if (rw in meaning):
        m = meaning[rw]
        r,c = 20,262    
        ini = rw + "\n  " 
        t1.insert(END,ini)
        for i in m:
            pri = i + "\n  "
            t1.insert(END,pri)
            print(i,"\n")
        e1.delete(0,END)
    else: 
        t1.insert(END,"Word not Found")

def ser2(e):
    rw = e1.get()
    rw = rw.lower()
    t1.delete("1.0","end")
    print(rw)
    if (rw in meaning):
        m = meaning[rw]
        r,c = 20,262    
        ini = rw + "\n  " 
        t1.insert(END,ini)
        for i in m:
            pri = i + "\n  "
            t1.insert(END,pri)
            print(i,"\n")
        e1.delete(0,END)
    else: 
        t1.insert(END,"Word not Found")

def sp():
    rw = e1.get()
    sd = pyttsx3.init()
    sd.setProperty("rate",110)
    sd.setProperty("volume",2.0)
    sd.say(rw)
    sd.runAndWait()


w = Tk()
w.geometry("415x500")
w.resizable(0,0)
w.title("Dictionary")
w.config(bg="#F8B195")
Label(w,text="DICTIONARY",font=("bold",30),bg="#F8B195",fg="#08165c").pack(anchor="center")

sw = StringVar()
e1 = Entry(w,textvariable=sw,font=("bold",20),width=25)
e1.focus()
e1.place(x=10,y=80)
b1 = Button(w,text = "Search",font=("bold",20),command=ser1,bg="#F67280").place(x=10,y=140)
w.bind('<Return>',ser2)
b2 = Button(w,text = "Pronounce",font=("bold",20),command=sp,bg="#F67280").place(x=235,y=140)

f = Frame(w,height=240,width=380,bg="#6C5B7B").place(x=10,y=250)
sc = Scrollbar(f,orient="vertical",)
t1 = Text(f,height=9,width=30,bg="#355C7D",fg="#f5af47",font=("bold",16),yscrollcommand=sc.set)


sc.pack(side="right",fill="y")
sc.config(command=t1.yview)
t1.place(x=20,y=260)
w.mainloop()