import pickle
import datetime
from tkinter import *

year_dict={1:'January',2:'February',3:'March',4:'April',5:'May',6:'June',7:'July',8:'August',9:'September',10:'October',11:'November',12:'December'}

#Adding records
add = Tk()
'''def addrec():
    add = Toplevel()
    add.geometry('1000x600')
    add.config(background = 'deeppink')
    add.title('NEW RECORD')
    add.minsize(1000,600)
    add.maxsize(1000,600)

    try:
        open_bin=open('dbms','rb')  # Regular use
        add_temp=pickle.load(open_bin)
        open_bin.close()
    except:
        open_bin=open('dbms','wb') # If initialising for 1st time
        lst=[]
        pickle.dump(lst,open_bin)
        open_bin.close()
        open_bin=open('dbms','rb')
        add_temp=pickle.load(open_bin)
        open_bin.close()
    open_bin=open('dbms','wb')
    try:
        stu_name=str(input('Enter student name: '))
        stu_roll=int(input('Enter unique examination seat number: '))
        stu_isbn=str(input('Enter ISBN number: '))
        stu_book=(input('Enter Book Name: '))
    except:
        pickle.dump(add_temp,open_bin)
    stu_dateissue=datetime.date.today()
    stu_datedue=datetime.date.today()+datetime.timedelta(days=7)
    stu_name+=' '
    book_count=1
    isbn_count=1
    book_count2=0
    condition='match'
    temp_check=stu_name.partition(' ')
    #use below lines with '#' after every students record is once added.
    try:
        for i in add_temp:
            if i[1]== stu_roll and i[0]==stu_name:
                condition='match'
                book_count+=1
                if book_count>2:
                    break
                else:
                    pass
            else:
                condition='mismatch'
        for i in add_temp:
            if i[2] == stu_isbn:
                isbn_count+=1
        curr_rolls=[]
        for i in add_temp:
            curr_rolls.append(i[1])
        if stu_roll not in curr_rolls:
            condition='match'
            book_count2+=1
    
        if (temp_check[0].isalpha() == True and book_count<=2 and isbn_count==1 and condition=='match') or (temp_check[0].isalpha() == True and book_count2==1 and isbn_count==1 and condition=='match') :
            lst_temp=[stu_name,stu_roll,stu_isbn,stu_book,stu_dateissue,stu_datedue]
            add_temp.append(lst_temp)
            pickle.dump(add_temp,open_bin)
            print('Record added successfully.')
        elif book_count>2:
            print('No more books before return!! Student has already issued 2 books as follows:')
            info3(add_temp,stu_roll,1)
            pickle.dump(add_temp,open_bin)
        elif isbn_count>1:
            print('The book with ISBN number \'',stu_isbn,'\' already issued by:')
            info3(add_temp,stu_isbn,2)
            pickle.dump(add_temp,open_bin)
        elif condition=='mismatch':
            print('Details( Name & Unique ID ) don\'t match !!')
            pickle.dump(add_temp,open_bin)
        else:
            print('Data entries are of wrong format.')
            pickle.dump(add_temp,open_bin)
    except:
        pass
    open_bin.close()'''
    




e1 = StringVar()
def give():
    en1=e1.get()
    print(en1)



label1 = Label(add,text = 'Enter name: ',fg='black',bg='white',relief = ('solid'),font = ('Arial',20,'bold'))
label1.place(x=100,y=100)
entry = Entry(add, textvar = e1)
entry.place(x=500,y=100)
bu1= Button(add,text = 'ADD NAME',command = give)
bu1.place(x=300,y=250)


add.mainloop()