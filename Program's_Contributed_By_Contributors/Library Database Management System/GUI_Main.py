
from tkinter import *
from tkinter import messagebox
from DBMSlibrary import addrec,searchrec,delrec,delparrec,updaterec,allrecs
from PIL import ImageTk,Image





def library():
    global homepage
    window = Toplevel(homepage) 
    window.geometry('1000x600')
    window.config(background = 'deeppink')
    window.title('Library Database Management System')
    window.minsize(1000,600)
    window.maxsize(1000,600)


    def exitout():
        w = messagebox.askyesno('Quit','Are you sure you want to quit?')
        if w:
            window.destroy()
        else:
            pass

    photo=ImageTk.PhotoImage(Image.open('logo.png'))
    lab_pic = Label(window,image = photo)
    lab_pic.image = photo
    lab_pic.config(image = photo)
    lab_pic.pack(fill=BOTH)


    label_entry = Label(window,text='Welcome to Library Database Management System',fg='blue',bg='white',relief = ('solid'),font = ('Calibri',20))
    label_entry.pack(fill=BOTH,padx=220,pady=30)

    

    button1 = Button(window,text='VIEW ALL RECORDS',fg='black',bg='white',relief = 'sunken',borderwidth = 500000,font = ('Courier New',20,'bold'),command=allrecs)
    button1.pack(fill=BOTH,padx=220,pady=10)



    '''photo=ImageTk.PhotoImage(Image.open('logo.png'))
    lab_pic = Label(window,image = photo)
    lab_pic.image = photo
    lab_pic.config(image = photo)
    lab_pic.pack()'''


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


    '''img=Image.open('library.jpg')
    photo=ImageTk.PhotoImage(img,size=10)
    lab_pic = Label(window,image = photo)
    lab_pic.image = photo
    lab_pic.place(x=200,y=400)'''

    #window.mainloop()



homepage = Tk()

homepage.config(background = 'deeppink')
chk1 = 'New User Entry'
chk2= 'Old User Entry'

homepage.geometry('1000x600')
homepage.minsize(1000,600)
homepage.maxsize(1000,600)
homepage.title('BRIGHT DAY SCHOOL')



imglogo = Image.open('logo.png')
imglogo = imglogo.resize((250,110),Image.ANTIALIAS)
photo=ImageTk.PhotoImage(imglogo)
lab_pic = Label(homepage,image = photo,borderwidth = 1,relief = 'sunken')
lab_pic.image = photo
lab_pic.config(image = photo)
lab_pic.pack(fill=BOTH)


img=Image.open('library.jpg')
img = img.resize((165,80), Image.ANTIALIAS)
photo=ImageTk.PhotoImage(img)


but_lib = Button(homepage,image = photo,borderwidth=25,command=library,relief='solid')
but_lib.place(x=90,y=220)

imgother2=Image.open('otherapp.png')
imgother2 = imgother2.resize((145,100), Image.ANTIALIAS)
photo2=ImageTk.PhotoImage(imgother2)


but_app1 = Button(homepage,image = photo2,borderwidth=25,relief='solid')
but_app1.place(x=425,y=220)

imgother3=Image.open('otherapp.png')
imgother3 = imgother3.resize((145,100), Image.ANTIALIAS)
photo3=ImageTk.PhotoImage(imgother3)


but_app2 = Button(homepage,image = photo3,borderwidth=25,relief='solid')
but_app2.place(x=760,y=220)

imgother4=Image.open('otherapp.png')
imgother4 = imgother4.resize((145,100), Image.ANTIALIAS)
photo4=ImageTk.PhotoImage(imgother4)


but_app3 = Button(homepage,image = photo4,borderwidth=25,relief='solid')
but_app3.place(x=760,y=420)

imgother5=Image.open('otherapp.png')
imgother5 = imgother5.resize((145,100), Image.ANTIALIAS)
photo5=ImageTk.PhotoImage(imgother5)



but_app4 = Button(homepage,image = photo5,borderwidth=25,relief='solid')
but_app4.place(x=100,y=420)

imgother6=Image.open('otherapp.png')
imgother6 = imgother6.resize((145,100), Image.ANTIALIAS)
photo6=ImageTk.PhotoImage(imgother6)

but_app5 = Button(homepage,image = photo6,borderwidth=25,relief='solid')
but_app5.place(x=425,y=420)


homepage.mainloop()

      
