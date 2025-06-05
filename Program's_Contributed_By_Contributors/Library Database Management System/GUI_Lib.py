from DBMSlibrary import addrec,searchrec,delrec,delparrec,updaterec,allrecs
from tkinter import *
from tkinter import messagebox
from PIL import Image,ImageTk
import sys



def library():
    window = Tk() 
    window.geometry('1000x600')
    window.title('Library Database Management System')
    window.minsize(1000,600)

    img=Image.open('logo.png')
    photo=ImageTk.PhotoImage(img)
    lab_pic = Label(window,image = photo)
    lab_pic.pack()

    var = StringVar()

    def exitout():
        w = messagebox.askyesno('Quit','Are you sure you want to quit?')
        if w:
            window.destroy()
        else:
            pass

    def printt():
        v = var.get()
        print(v)
    label_entry = Label(window,text='Welcome to Library Database Management System',fg='blue',bg='white',relief = ('solid'),font = ('Noteworthy',20,'bold'))
    label_entry.pack(fill=BOTH,padx=220,pady=30)

    button1 = Button(window,text='VIEW ALL RECORDS',fg='black',bg='white',relief = ('sunken'),font = ('Courier New',20,'bold'),command=allrecs)
    button1.pack(fill=BOTH,padx=220,pady=10)

    button2 = Button(window,text='ADD NEW RECORD',fg='black',bg='white',relief = ('sunken'),font = ('Courier New',20,'bold'),command=addrec)
    button2.pack(fill=BOTH,padx=220,pady=10)

    button3 = Button(window,text='SEARCH A RECORD',fg='black',bg='white',relief = ('sunken'),font = ('Courier New',20,'bold'),command=searchrec)
    button3.pack(fill=BOTH,padx=220,pady=10)

    button4 = Button(window,text='UPDATE A RECORD',fg='black',bg='white',relief = ('sunken'),font = ('Courier New',20,'bold'),command=updaterec)
    button4.pack(fill=BOTH,padx=220,pady=10)

    button5 = Button(window,text='DELETE A PARTICULAR RECORD',fg='black',bg='white',relief = ('sunken'),font = ('Courier New',20,'bold'),command=delparrec)
    button5.pack(fill=BOTH,padx=220,pady=10)

    button6 = Button(window,text='DELETE ALL RECORDS',fg='black',bg='white',relief = ('sunken'),font = ('Courier New',20,'bold'),command=delrec)
    button6.pack(fill=BOTH,padx=220,pady=10)

    button7 = Button(window,text='EXIT',fg='black',bg='white',relief = ('sunken'),font = ('Courier New',20,'bold'),command=exitout)
    button7.pack(fill=BOTH,padx=220,pady=10)

    ent = Entry(window,textvariable = var)
    ent.pack()

    but = Button(window,text='ADDNAME',command = printt)
    but.pack()

    window.mainloop()
library()