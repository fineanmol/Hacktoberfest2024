# CS Project - Session - 2020-21
from tkinter import *
from tkinter import messagebox
from DBMSlibrary_CSV import addrec,searchrec,delrec,delparrec,updaterec,allrecs,info,info2,info3,lsttocsv
from PIL import ImageTk,Image
import pickle
import datetime
import time
from DBMSlibrary_CSV import csvtolst,lsttocsv
import subprocess

class GUI():


    # Authorised Login #
    def loginscreen(self):
        authname = 'admin'       #Authentification ADMIN_ID to be written here
        authpass = '123456'   #Authentification ADMIN_PASSWORD to be written here
        

        self.authlogin = Tk()
        self.authlogin.geometry('1000x320')
        self.authlogin.config(background = 'deeppink')
        self.authlogin.title('LOGIN')
        self.authlogin.minsize(650,420)
        self.authlogin.maxsize(650,420)


        passwordentry = StringVar()
        usernameentry = StringVar()


        imglogo = Image.open('/Users/kandarpsolanki/Desktop/Codings/logo.png')
        imglogo = imglogo.resize((250,110),Image.ANTIALIAS)
        photo = ImageTk.PhotoImage(imglogo)
        self.lab_pic = Label(self.authlogin,image = photo,borderwidth = 1,relief = 'sunken')
        self.lab_pic.image = photo
        self.lab_pic.config(image = photo)
        self.lab_pic.pack(fill=BOTH)
        def authorise():
            uid = self.username.get()
            upass = self.password.get()
            if uid == authname and upass == authpass:
                messagebox.showinfo('Welcome','You are successfully logged in !!')
                self.authlogin.destroy()
                self.homepge()
            else:
                messagebox.showwarning('Access Denied','Incorrect ID/Password !!')
                usernameentry.set(uid)
                passwordentry.set('')

        def hide(event):
            tempvar = self.password.get()
            passwordentry.set(tempvar)
            self.password = Entry(self.authlogin,textvariable = passwordentry,bg = 'grey',fg = 'white',\
                            font = ('Operator Mono', 20 ,'bold'),show = '*',width = '15')
            self.password.place(x=241,y=230)


        def show(event):
            tempvar = self.password.get()
            passwordentry.set(tempvar)
            self.password = Entry(self.authlogin,textvariable = passwordentry,bg = 'grey',fg = 'white',\
                            font = ('Operator Mono', 20 ,'bold'),show = '',width = '15')
            self.password.place(x=241,y=230)
        
        self.usernamelab = Label(self.authlogin,text = 'Username :',bg = 'deeppink',font = ('Arial', 19))
        self.usernamelab.place(x=91,y=164)

        self.passwordlab = Label(self.authlogin,text = 'Password :',bg = 'deeppink',font = ('Arial', 19))
        self.passwordlab.place(x=91,y=234)

        self.username = Entry(self.authlogin,textvariable = usernameentry,bg = 'grey',fg = 'white',\
                        font = ('Operator Mono', 20 ,'bold'),show = '',width = '15')
        self.username.place(x=241,y=160)

        self.password = Entry(self.authlogin,textvariable = passwordentry,bg = 'grey',fg = 'white',\
                        font = ('Operator Mono', 20 ,'bold'),show = '*',width = '15')
        self.password.place(x=241,y=230)

        self.show = Button(self.authlogin,text = 'Show Password',command = hide,relief = 'sunken',width = 13,\
                    height = 1,font = ('Arial',14))
        self.show.place(x=450,y=237)
        self.show.bind('<ButtonPress-1>',show)
        self.show.bind('<ButtonRelease-1>',hide)

        self.loginbut = Button(self.authlogin,text = 'Login',command = authorise,width = 7,height = 1,\
                        font = ('Arial',16))
        self.loginbut.place(x=295,y=300)

        self.case = Label(self.authlogin,text='*Username/Password is case-sensitive.',fg='black',bg='deeppink',\
                    font = ('Arial',17))
        self.case.place(x=170,y=340)

        self.labelackn = Label(self.authlogin,text='Designed and Developed by: KANDARP SOLANKI',fg='black',\
                         bg='deeppink',font = ('Operator Mono Medium',13,'italic'))
        self.labelackn.place(x=340,y=395)

        self.authlogin.mainloop()


    # Library App #
    def library(self):
        self.window = Toplevel(self.homepage)
        self.window.geometry('1000x600')
        self.window.config(background = 'deeppink')
        self.window.title('Library Database Management System')
        self.window.minsize(1000,600)
        self.window.maxsize(1000,600)

        #Exitting Window
        def exitout():
            w = messagebox.askyesno('Quit','Are you sure you want to quit?')
            if w:
                self.window.destroy()
            else:
                pass


        # Open document with default application in Python.
        def opencsv():
            subprocess.call(['open', 'studentdatabase.csv'])
        

        photo=ImageTk.PhotoImage(Image.open('logo.png'))
        lab_pic = Label(self.window,image = photo)
        lab_pic.image = photo
        lab_pic.config(image = photo)
        lab_pic.pack(fill=BOTH)


        self.label_entry = Label(self.window,text='Welcome to Library Database Management System',\
                           fg='blue',bg='white',relief = ('solid'),font = ('Arial',21,'bold'))
        self.label_entry.pack(fill=BOTH,padx=180,pady=30)
 
        self.button1 = Button(self.window,text='VIEW ALL RECORDS',fg='black',bg='white',relief = ('sunken'),\
                       font = ('Operator Mono',20,'bold'),command=opencsv)
        self.button1.pack(fill=BOTH,padx=220,pady=10)



        self.button2 = Button(self.window,text='ADD NEW RECORD',fg='black',bg='white',relief = ('sunken'),\
                       font = ('Operator Mono',20,'bold'),command=self.adding)
        self.button2.pack(fill=BOTH,padx=220,pady=10)


        self.button4 = Button(self.window,text='UPDATE A RECORD',fg='black',bg='white',relief = ('sunken'),\
                       font = ('Operator Mono',20,'bold'),command=self.updating)
        self.button4.pack(fill=BOTH,padx=220,pady=10)


        self.button5 = Button(self.window,text='RETURN A BOOK',fg='black',bg='white',relief = ('sunken'),\
                       font = ('Operator Mono',20,'bold'),command=self.deletingparticular)
        self.button5.pack(fill=BOTH,padx=220,pady=10)


        self.button6 = Button(self.window,text='DELETE ALL RECORDS',fg='black',bg='white',relief = ('sunken'),\
                       font = ('Operator Mono',20,'bold'),command=self.deletingall)
        self.button6.pack(fill=BOTH,padx=220,pady=10)


        self.button7 = Button(self.window,text='EXIT',fg='black',bg='white',relief = ('sunken'),\
                       font = ('Operator Mono',20,'bold'),command=exitout)
        self.button7.pack(fill=BOTH,padx=470,pady=10)


        self.labelackn = Label(self.window,text='Designed and Developed by: KANDARP SOLANKI',fg='black',\
                         bg='deeppink',font = ('Operator Mono Medium',13,'italic'))
        self.labelackn.place(x=678,y=574)

        self.label_caution = Label(self.window,text='NOTE: Open only one window at a time for best results.',\
                           fg='black',bg='deeppink',relief = ('solid'),font = ('Arial 17 italic'))
        self.label_caution.pack(fill=BOTH,padx=180,pady=30)


    # School Homepage #
    def homepge(self):
        self.homepage = Tk()

        self.homepage.config(background = 'deeppink')


        self.homepage.geometry('1000x600')
        self.homepage.minsize(1000,600)
        self.homepage.maxsize(1000,600)
        self.homepage.title('BRIGHT DAY SCHOOL')

        def logout():
            final = messagebox.askyesno('Confirm','Are you sure you want to logout ?')
            if final:
                self.homepage.destroy()
                self.loginscreen()
            else:
                pass

        imglogo = Image.open('logo.png')
        imglogo = imglogo.resize((250,110),Image.ANTIALIAS)
        photo=ImageTk.PhotoImage(imglogo)
        self.lab_pic = Label(self.homepage,image = photo,borderwidth = 1,relief = 'sunken')
        self.lab_pic.image = photo
        self.lab_pic.config(image = photo)
        self.lab_pic.pack(fill=BOTH)


        img=Image.open('library.jpg')
        img = img.resize((180,100), Image.ANTIALIAS)
        photo=ImageTk.PhotoImage(img)


        self.but_lib = Button(self.homepage,image = photo,command = self.library,borderwidth=25,relief='solid')
        self.but_lib.place(x=90,y=220)

        imgother2=Image.open('otherapp.png')
        imgother2 = imgother2.resize((145,100), Image.ANTIALIAS)
        photo2=ImageTk.PhotoImage(imgother2)


        self.but_app1 = Button(self.homepage,image = photo2,borderwidth=25,relief='solid')
        self.but_app1.place(x=425,y=220)

        imgother3=Image.open('otherapp.png')
        imgother3 = imgother3.resize((145,100), Image.ANTIALIAS)
        photo3=ImageTk.PhotoImage(imgother3)


        self.but_app2 = Button(self.homepage,image = photo3,borderwidth=25,relief='solid')
        self.but_app2.place(x=760,y=220)

        imgother4=Image.open('otherapp.png')
        imgother4 = imgother4.resize((145,100), Image.ANTIALIAS)
        photo4=ImageTk.PhotoImage(imgother4)


        self.but_app3 = Button(self.homepage,image = photo4,borderwidth=25,relief='solid')
        self.but_app3.place(x=760,y=420)

        imgother5=Image.open('otherapp.png')
        imgother5 = imgother5.resize((145,100), Image.ANTIALIAS)
        photo5=ImageTk.PhotoImage(imgother5)



        self.but_app4 = Button(self.homepage,image = photo5,borderwidth=25,relief='solid')
        self.but_app4.place(x=100,y=420)

        imgother6=Image.open('otherapp.png')
        imgother6 = imgother6.resize((145,100), Image.ANTIALIAS)
        photo6=ImageTk.PhotoImage(imgother6)

        self.but_app5 = Button(self.homepage,image = photo6,borderwidth=25,relief='solid')
        self.but_app5.place(x=425,y=420)

        self.logout = Button(self.homepage,text = 'Logout',bg = 'deeppink',command = logout,relief='sunken',\
                      borderwidth=5,font = ('Arial',20)) 
        self.logout.place(x=930,y=114)

        self.labelackn = Label(self.homepage,text='Designed and Developed by: KANDARP SOLANKI',fg='black',\
                         bg='deeppink',font = ('Operator Mono Medium',13,'italic'))
        self.labelackn.place(x=678,y=574)

        self.homepage.mainloop()
    

    # Add Record ~ Library App #
    def adding(self):
        name = StringVar()
        roll = None
        isbn = StringVar()
        book = StringVar()


        self.add = Toplevel(self.window)
        self.add.geometry('1000x600')
        self.add.config(background = 'deeppink')
        self.add.title('NEW RECORD')
        self.add.minsize(1000,600)
        self.add.maxsize(1000,600)

        imglogo = Image.open('/Users/kandarpsolanki/Desktop/Codings/logo.png')
        imglogo = imglogo.resize((250,110),Image.ANTIALIAS)
        photo = ImageTk.PhotoImage(imglogo)
        self.lab_pic = Label(self.add,image = photo,borderwidth = 1,relief = 'sunken')
        self.lab_pic.image = photo
        self.lab_pic.config(image = photo)
        self.lab_pic.pack(fill=BOTH)

        self.namelabel = Label(self.add,text = 'Student Name :',bg = 'deeppink',font = ('Arial 20 bold'))
        self.namelabel.place(x=200,y=200)
        self.stu_name = Entry(self.add,textvariable = name,font = ('Arial 20 italic'))
        self.stu_name.place(x=500,y=200)


        self.rolllabel = Label(self.add,text = 'Examination Seat No :',bg = 'deeppink',font = ('Arial 20 bold'))
        self.rolllabel.place(x=200,y=240)
        self.stu_roll = Entry(self.add,textvariable = roll,font = ('Arial 20 italic'))
        self.stu_roll.place(x=500,y=240)

        self.isbnlabel = Label(self.add,text = 'ISBN No. :',bg = 'deeppink',font = ('Arial 20 bold'))
        self.isbnlabel.place(x=200,y=280)
        self.stu_isbn = Entry(self.add,textvariable = isbn,font = ('Arial 20 italic'))
        self.stu_isbn.place(x=500,y=280)
    
        self.booklabel = Label(self.add,text = 'Book Name :',bg = 'deeppink',font = ('Arial 20 bold'))
        self.booklabel.place(x=200,y=320)
        self.stu_book = Entry(self.add,textvariable = book,font = ('Arial 20 italic'))
        self.stu_book.place(x=500,y=320)

        self.labelackn = Label(self.add,text='Designed and Developed by: KANDARP SOLANKI',fg='black',\
                         bg='deeppink',font = ('Operator Mono Medium',13,'italic'))
        self.labelackn.place(x=678,y=574)

        def restore():
            isbn.set('')
            book.set('')
        
        try:
            open_bin=open('dbmscsv','rb')  # Regular use
            add_temp=pickle.load(open_bin)
            open_bin.close()
        except:
            open_bin=open('dbmscsv','wb') # If initialising for 1st time
            lst=[]
            pickle.dump(lst,open_bin)
            open_bin.close()
            open_bin=open('dbmscsv','rb')
            add_temp=pickle.load(open_bin)
            open_bin.close()
        



        def printt():
            letpass1 = True
            letpass2 = False
            tryother = True
            userallow = True
            open_bin=open('dbmscsv','wb')
            try:
                name = self.stu_name.get()
                roll = self.stu_roll.get()
                isbn = self.stu_isbn.get()
                book = self.stu_book.get()
            except:
                pass
            try:
                name = int(name)
                letpass1 = False
            except:
                pass
            try:
                roll = int(roll)
                letpass2 = True
            except:
                pass
            if name == '' or roll == ''  or book == '' or isbn == '':
                messagebox.showerror('Error Message','Fill all the information !!')
                tryother = False
                userallow = False
                
            if (letpass1 == False or letpass2 == False) and tryother == True:
                messagebox.showerror('Error Message','Enter correct datatype !!')
                userallow = False
                   

            stu_dateissue=datetime.date.today()
            stu_datedue=datetime.date.today()+datetime.timedelta(days=7)
            book_count = 0
            isbn_count = 1
            book_count2 = 0
            condition = 'match'
            

            try:
                for i in add_temp:
                    if int(i[1]) == roll and i[0] == name:
                        condition = 'match'
                        for i in add_temp:
                            if int(i[1]) == roll and i[0] == name:
                                book_count += 1
                        break
                    else:
                        condition = 'mismatch'
                for i in add_temp:
                    if i[2] == isbn:
                        isbn_count += 1
                curr_rolls = []
                for i in add_temp:
                    curr_rolls.append(str(i[1]))
                if str(roll) not in curr_rolls:
                    condition = 'match'
                    book_count2 += 1
                
            
                if (book_count < 2 and isbn_count == 1 and condition == 'match' and userallow == True) or \
                   (book_count2 == 1 and isbn_count == 1 and condition == 'match' and userallow == True):
                    lst_temp = [name,roll,isbn,book,stu_dateissue,stu_datedue]
                    add_temp.append(lst_temp)
                    pickle.dump(add_temp,open_bin)
                    lsttocsv(add_temp)
                    messagebox.showinfo('Message','Record added successfully.')
                    restore()
                elif book_count >= 2:
                    messagebox.showinfo('Error','Student has already issued 2 books !!')
                    info3(add_temp,stu_roll,1)
                    pickle.dump(add_temp,open_bin)
                    restore()
                elif isbn_count > 1:
                    messagebox.showinfo('Error','The book with ISBN number already issued.')
                    info3(add_temp,stu_isbn,2)
                    pickle.dump(add_temp,open_bin)
                    restore()
                elif condition=='mismatch':
                    messagebox.showinfo('Error','Details( Name & Unique ID ) don\'t match !!')
                    restore()
                    pickle.dump(add_temp,open_bin)
                else:
                    pickle.dump(add_temp,open_bin)
            except:
                pickle.dump(add_temp,open_bin)
                pass
            open_bin.close()

        self.tbut = Button(self.add,text = 'Add',command = printt,width = 25,height = 2,font = ('Arial 20 bold'))
        self.tbut.place(x=350,y=400)


    # Update Record ~ Library App #
    def updating(self):

        exseat = ''
        updainfo = ''
        name = 'N'
        exam = 'E'
        isbn = 'I'
        book = 'B'
        


        self.updat = Toplevel(self.window)
        self.updat.geometry('1000x600')
        self.updat.config(background ='deeppink')
        self.updat.title('UPDATE RECORD')
        self.updat.minsize(1000,600)
        self.updat.maxsize(1000,600)

        def updateahead():

            open_bin=open('dbmscsv','rb')
            records=pickle.load(open_bin)
            open_bin.close()

            exseat = self.stu_es.get()

            updatedinfo = self.newlabelentry.get()

            user_choose = v.get()
            user_can = 'yes'
            user_can2 = 'yes'
            user_can3 = 'yes'
            
            for i in records:
                if updatedinfo == '':
                    user_can3 = 'no'
                    break
                elif user_choose == 'E':
                    user_can='yes'
                    allow = True
                    try:
                        updatedinfo = int(updatedinfo)
                    except:
                        allow = False
                    if updatedinfo == (int(i[1])) and allow == True and updatedinfo !='':
                        messagebox.showinfo('Error','Can\'t update. Student already exist with the unique ID !!')
                        user_can2 = 'no'
                        break
                    elif allow == False and updatedinfo != '':
                        messagebox.showinfo('Error','Enter only numeric type !!')
                        user_can2 = 'no'
                        user_can3 = 'no'
                        break
                    elif updatedinfo == '' and allow == False:
                        messagebox.showinfo('Error','Can\'t keep the field empty !!')
                        user_can2='no'
                        break
                elif user_choose == 'I':
                    user_can2='yes'
                    if updatedinfo == i[2] and updatedinfo != '':
                        messagebox.showinfo('Error','Book with ISBN No.already issued.')
                        user_can='no'
                        break
                    elif updatedinfo == '':
                        messagebox.showinfo('Error','Can\'t keep the field empty !!')
                        user_can='no'
                        user_can3 = 'no'
                        break
                    else:
                        user_can='yes'
                        pass
                else:
                    pass
            if user_can != 'no' and user_can2 != 'no' and user_can3 != 'no': 
                if user_choose == 'N':
                    stat=''
                    stat2=''
                    count = 0
                    for i in records:
                        if int(i[1]) == int(exseat):
                            i[0] = updatedinfo
                            stat2='found'
                            count += 1
                        else:
                            stat='notfound'
                    if stat=='notfound' and stat2=='' and count == 0:    
                        messagebox.showinfo('Error','No such record !!')
                    elif count > 0:
                        messagebox.showinfo('Message','Record updated successfully !!')
                elif user_choose == 'E':
                    stat=''
                    stat2=''
                    count = 0
                    for i in records:
                        if int(i[1]) == int(exseat):
                            i[1]=updatedinfo
                            stat2='found'
                            count += 1
                        else:
                            stat='notfound'
                    if stat=='notfound' and stat2=='' and count == 0:    
                        messagebox.showinfo('Error','No such record !!')
                    elif count > 0:
                        messagebox.showinfo('Message','Record updated successfully !!')
                elif user_choose.upper()=='I':
                    stat=''
                    stat2=''
                    count = 0
                    for i in records:
                        if int(i[1]) == int(exseat):
                            i[2]=updatedinfo
                            stat2='found'
                            count += 1
                        else:
                            stat='notfound'
                    if stat=='notfound' and stat2=='' and count == 0:    
                        messagebox.showinfo('Error','No such record !!')
                    elif count > 0:
                        messagebox.showinfo('Message','Record updated successfully !!')
                elif user_choose == 'B':
                    stat=''
                    stat2=''
                    count = 0
                    for i in records:
                        if int(i[1]) == int(exseat):
                            i[3]=updatedinfo
                            stat2='found'
                            count += 1
                        else:
                            stat='notfound'
                    if stat=='notfound' and stat2=='' and count == 0:    
                        messagebox.showinfo('Error','No such record !!')
                    elif count > 0:
                        messagebox.showinfo('Message','Record updated successfully !!')
                elif user_choose == 'IS':
                    stat=''
                    stat2=''
                    n=-1
                    count = 0
                    for i in records:
                        if int(i[1])==user_find:
                            i[4]=user_change
                            i[5]=user_change+datetime.timedelta(days=7)
                            print('\nRecord updated successfully !!')
                            print('Issue date set to current date.')
                            info(records,user_find,1)
                            stat2='found'
                            count += 1
                            n=4
                        else:
                            stat='notfound'
                    if stat=='notfound' and stat2=='' and count == 0:    
                        print('No such record !!')
                    elif count > 0:
                        messagebox.showinfo('Message','Record updated successfully !!')

                open_bin=open('dbmscsv','wb')
                pickle.dump(records,open_bin)
                lsttocsv(records)
            elif updatedinfo == '' and user_can == 'yes' and user_can2 == 'yes':
                messagebox.showinfo('Error','Can\'t keep the updated information field empty !!')
                open_bin=open('dbmscsv','wb')
                pickle.dump(records,open_bin)
                lsttocsv(records)

            open_bin.close()



        def updatt():
            self.clearlabel = Label(self.updat,text = '                                                                                                                                                                                \n                                                                                                                                                                                \n                                                                                                                                                                                \n                                                                                                                                                                                \n                                                                                                                                                                                \n                                                                                                                                                                                ',bg = 'deeppink')
            self.clearlabel.place(x=150,y=450)
            exseatno = self.stu_es.get()
            user_choose = v.get()
            
            letpass = True
            try:
                exseatno = int(exseatno)
            except:
                letpass = False
            open_bin=open('dbmscsv','rb')
            records=pickle.load(open_bin)
            open_bin.close()
            usersearch='E'
            if usersearch.upper()=='E' and letpass == True:
                list_checknames=[]
                for i in records:
                    list_checknames.append(int(i[1]))

                
                if exseatno not in list_checknames:
                        messagebox.showinfo('Error','Unique ID doesn\'t exist !!')
                elif exseatno in list_checknames:
                    if user_choose == 'N':
                        self.newlabel = Label(self.updat, text = 'Enter updated name :                ',\
                                        bg = 'deeppink',font = ('Arial 20 bold'))
                        self.newlabel.place(x=150,y=450)
                        self.newlabelentry = Entry(self.updat,textvariable = updainfo,font = ('Arial 20 italic'))
                        self.newlabelentry.place(x=500,y=450)
                        self.tbutupd = Button(self.updat,text = 'Update',command = updateahead,width = 25,\
                                       height = 2,font = ('Arial 20 bold') )
                        self.tbutupd.place(x=350,y=500)
                    elif user_choose == 'E':
                        self.newlabel = Label(self.updat, text = 'Enter updated Exam Seat No. :',\
                                        bg = 'deeppink',font = ('Arial 20 bold'))
                        self.newlabel.place(x=150,y=450)
                        self.newlabelentry = Entry(self.updat,textvariable = updainfo,\
                                             font = ('Arial 20 italic'))
                        self.newlabelentry.place(x=500,y=450)
                        self.tbutupd = Button(self.updat,text = 'Update',command = updateahead,width = 25,\
                                       height = 2,font = ('Arial 20 bold') )
                        self.tbutupd.place(x=350,y=500)
                    elif user_choose == 'I':
                        self.newlabel = Label(self.updat, text = 'Enter updated ISBN No. :         ',\
                                        bg = 'deeppink',font = ('Arial 20 bold'))
                        self.newlabel.place(x=150,y=450)
                        self.newlabelentry = Entry(self.updat,textvariable = updainfo,font = ('Arial 20 italic'))
                        self.newlabelentry.place(x=500,y=450)
                        self.tbutupd = Button(self.updat,text = 'Update',command = updateahead,width = 25,\
                                       height = 2,font = ('Arial 20 bold') )
                        self.tbutupd.place(x=350,y=500)
                    elif user_choose == 'B':
                        self.newlabel = Label(self.updat, text = 'Enter updated Book Name :    ',bg = 'deeppink'\
                                        ,font = ('Arial 20 bold'))
                        self.newlabel.place(x=150,y=450)
                        self.newlabelentry = Entry(self.updat,textvariable = updainfo,font = ('Arial 20 italic'))
                        self.newlabelentry.place(x=500,y=450)
                        self.tbutupd = Button(self.updat,text = 'Update',command = updateahead,width = 25,\
                                       height = 2,font = ('Arial 20 bold') )
                        self.tbutupd.place(x=350,y=500)
                    elif user_choose.upper() == 'IS':
                        user_change=datetime.date.today()
                else:
                    pass
            elif letpass == False and exseatno == '':
                messagebox.showinfo('Error','Can\'t keep the \'Seat No.\' field empty !!')
            else:
                messagebox.showinfo('Error','Enter only numeric type !!')

            

        imglogo = Image.open('/Users/kandarpsolanki/Desktop/Codings/logo.png')
        imglogo = imglogo.resize((250,110),Image.ANTIALIAS)
        photo = ImageTk.PhotoImage(imglogo)
        self.lab_pic = Label(self.updat,image = photo,borderwidth = 1,relief = 'sunken')
        self.lab_pic.image = photo
        self.lab_pic.config(image = photo)
        self.lab_pic.pack(fill=BOTH)


        v = StringVar()
        v.set(name)


        self.uplab = Label(self.updat,text = 'What to Update ?',bg = 'deeppink',font = ('Arial 20 bold'))
        self.uplab.place(x=377,y=265)


        self.eslabel = Label(self.updat,text = 'Exam Seat no. of student (presently in records) :',\
                       bg = 'deeppink',font = ('Arial 20 bold'))
        self.eslabel.place(x=51,y=200)

        self.stu_es = Entry(self.updat,textvariable = exseat,font = ('Arial 20 bold'))
        self.stu_es.place(x=600,y=200)


        self.r1 = Radiobutton(self.updat,text = 'Name',variable = v,value = name,bg = 'deeppink',\
                  font = ('Arial 20 bold'))
        self.r1.place(x=180,y=300)


        self.r2 = Radiobutton(self.updat,text = 'Exam Seat No.',variable = v,value = exam,bg = 'deeppink',\
                  font = ('Arial 20 bold'))
        self.r2.place(x=287,y=300)


        self.r3 = Radiobutton(self.updat,text = 'ISBN No.',variable = v,value = isbn,bg = 'deeppink',\
                  font = ('Arial 20 bold'))
        self.r3.place(x=475,y=300)
    
        self.r4 = Radiobutton(self.updat,text = 'Book Name',variable = v,value = book,bg = 'deeppink',\
                  font = ('Arial 20 bold'))
        self.r4.place(x=610,y=300)

        self.tbutchoose = Button(self.updat,text = 'Choose',command = updatt,width = 7,height = 1,\
                          font = ('Arial 20 bold'))
        self.tbutchoose.place(x=430,y=350)

        self.infolabel = Label(self.updat,text = '*Press CHOOSE to enter the updated information',\
                         bg = 'deeppink',font = ('Arial 18 italic'))
        self.infolabel.place(x=280,y=385)

        self.labelackn = Label(self.updat,text='Designed and Developed by: KANDARP SOLANKI',fg='black',\
                         bg='deeppink',font = ('Operator Mono Medium',13,'italic'))
        self.labelackn.place(x=678,y=574)


    # Delete All Records ~ Library App #
    def deletingall(self):
        open_bin=open('dbmscsv','rb')
        record=pickle.load(open_bin)
        open_bin.close()
        
        if record != []:
            final = messagebox.askyesno('Warning','Are you sure you want to delete all records ? (Y/N)')
            if final:
                open_bin=open('dbmscsv','wb')
                lst_std=[]
                pickle.dump(lst_std,open_bin)
                open_bin.close()
                makenew = [['','','','','','']]
                lsttocsv(makenew)
                messagebox.showinfo('Status','All records deleted successfully !!')
            else:
                messagebox.showinfo('Status','Records are safe !!')
        elif record==[]:
            messagebox.showinfo('Error','No records present !!')


    # Delete Particular Record ~ Library App #
    def deletingparticular(self):

        isbnreturn = StringVar()
        isbnreturn.set('')
        
        
        def delparcmd():
            open_bin=open('dbmscsv','rb')
            records=pickle.load(open_bin)
            open_bin.close()
            open_bin=open('dbmscsv','wb')  
            usersearch = isbnreturn.get()
            lst_temp=[]
            stud_count=0

            if usersearch != '':
                confirm = messagebox.askyesno('Confirm','Are you sure you want to delete record ?')
                confirm2 = False
                if confirm:
                    for i in records:
                        if i[2] == usersearch:
                            stud_count+=1
                            labeltext = ('+-------------------+\n'+'| Name                          |-->'+\
                            i[0]+'\n+-------------------+'+'\n| Exam Seat No.         |-->'+str(i[1])+\
                            '\n+-------------------+'+'\n| ISBN No.                    |-->'+i[2]+\
                            '\n+-------------------+'+'\n| Book Name               |-->'+i[3]+\
                            '\n+-------------------+'+'\n| Issue Date                |-->'+str(i[4])+\
                            '\n+-------------------+'+'\n| Due Date                   |-->'+str(i[5])+\
                            '\n+-------------------+\n')
                            messagebox.showinfo('Student Record',labeltext)
                            confirm2 = messagebox.askyesno('Attention','Once deleted, it can\'t be restored !!\
                            \nAre you sure you want to permanently delete the record ?')
                            if confirm2:
                                pass
                            else:
                                lst_temp.append(i)
                        else:
                            lst_temp.append(i)
                    pickle.dump(lst_temp,open_bin)
                    lsttocsv(lst_temp)
                else:
                    pickle.dump(records,open_bin)
                    lsttocsv(records)
                
                if confirm and confirm2:
                    show = '\nRecord under ISBN \''+usersearch+'\' deleted successfully.'
                    messagebox.showinfo('Status',show)
                elif stud_count == 0 and confirm == True:
                    show = 'No record found under ISBN No. \''+usersearch+'\' !!'
                    messagebox.showerror('Status',show)
                else:
                    pass
            else:
                messagenew = 'Can\'t keep the ISBN No. field empty !!'
                messagebox.showerror('Error',messagenew)
                pickle.dump(records,open_bin)
                lsttocsv(records)
            open_bin.close()


        self.delpar = Toplevel(self.window)
        self.delpar.geometry('1000x600')
        self.delpar.config(background ='deeppink')
        self.delpar.title('DELETE PARTICULAR RECORD')
        self.delpar.minsize(1000,600)
        self.delpar.maxsize(1000,600)



        photo=ImageTk.PhotoImage(Image.open('logo.png'))
        lab_pic = Label(self.delpar,image = photo)
        lab_pic.image = photo
        lab_pic.config(image = photo)
        lab_pic.pack(fill=BOTH)

        self.isbnlab = Label(self.delpar,text = 'Enter ISBN No. of book being returned :',bg = 'deeppink',\
                       font = ('Arial 20 bold'))
        self.isbnlab.place(x=100,y=200)


        self.isbnentry = Entry(self.delpar,textvariable = isbnreturn,font = ('Arial 20 italic'))
        self.isbnentry.place(x=600,y=200)

        self.butdel = Button(self.delpar,text = 'DELETE',command = delparcmd,width = 9,height = 2,\
                      font = ('Arial 20 bold') )
        self.butdel.place(x=430,y=350)

        self.labelackn = Label(self.delpar,text='Designed and Developed by: KANDARP SOLANKI',fg='black',\
                         bg='deeppink',font = ('Operator Mono Medium',13,'italic'))
        self.labelackn.place(x=678,y=574)

    

    # Initialising of Class #
    def __init__(self):
        self.loginscreen()
        
GUI()





#Transparent Window ~ self.window.attributes('-alpha',0.95)
# School Page ~ Add it while giving to school #
'''def schoolpage(self):
    self.school = Tk()
    self.school.geometry('1000x320')
    self.school.config(background = 'deeppink')
    self.school.title('BRIGHT DAY SCHOOL CBSE (UNIT HARNI)')
    self.school.minsize(1440,800)
    self.school.maxsize(1440,800)

    photo=ImageTk.PhotoImage(Image.open('logo.png'))
    lab_pic = Label(self.school,image = photo)
    lab_pic.image = photo
    lab_pic.config(image = photo)
    lab_pic.pack(fill=BOTH)

    def login():
        self.loginscreen()

    self.loginbut = Button(self.school,text = 'LOGIN',command = login,\
                    width = 7,height = 1,font = ('Operator Mono',20))
    self.loginbut.place(x=1350,y=120)

    self.appdev = Label(self.school,text='HomePage under development !!',fg='black',\
                    bg='deeppink',font = ('Operator Mono Medium',56,'italic'))
    self.appdev.place(x=310,y=400)

    self.school.mainloop()'''

