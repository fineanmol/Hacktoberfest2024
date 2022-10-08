#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 14 08:51:44 2020

@author: kandarpsolanki
"""
import csv
import pickle
import datetime
def csvtolst():
    open_csv = open('studentdatabase.csv','r')
    read = csv.reader(open_csv)
    lsttemp=[]
    for i in read:
        a,b,c = i[0],i[1],i[2]
        l = [a,b,c]
        lsttemp.append(l)
    return lsttemp
def lsttocsv(listname):
    open_csv = open('studentdatabase.csv','w')
    write = csv.writer(open_csv,delimiter = ',')
    headers = ['Name','Examination Seat No.','ISBN No.','Book Name','Issue Date','Due Date']
    write.writerow(headers)
    for i in listname:
        write.writerow(i)


year_dict={1:'January',2:'February',3:'March',4:'April',5:'May',6:'June',7:'July',8:'August',9:'September',10:'October',11:'November',12:'December'}


#Adding records
def addrec():
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
    open_bin=open('dbmscsv','wb')
    try:
        stu_name=str(input('Enter student name: '))
        stu_roll=int(input('Enter unique examination seat number: '))
        stu_isbn=str(input('Enter ISBN number: '))
        stu_book=(input('Enter Book Name: '))
    except:
        print('Invalid Datatype !!')
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
            lsttocsv(add_temp)
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
        pickle.dump(add_temp,open_bin)
        pass
    open_bin.close()
    
#Searching for a record
def searchrec():
    open_bin=open('dbmscsv','rb')
    print('\nNOTE: This software is case sensitive. For best results use \'E\' or \'I\' option.')
    usersearch=str(input('\nSearch By: Name(N)/Examination SeatNo.(E)/Due-Date(D)/ISBN No.(I) : '))
    record=pickle.load(open_bin)
    lsttocsv(record)
    if record==[]:
        usersearch='invalid'
    if usersearch.upper()=='N':
        user_find=str(input('\nEnter name of student: '))
        count=0
        stud_count=0
        datetoday=datetime.date.today()
        for i in record:
            if user_find in i[0] and i[5]<datetoday:
                print('\nStudent No.-',stud_count+1)
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            elif user_find in i[0] and i[5]>=datetoday:
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            else:
                count+=1
        print('\n',stud_count,'record(s) found under the word\'',user_find,'\'')
        if count==(len(record)-1):
            pass
        elif count==len(record):
            print('\nStudent not found !!')
        
        else:
            print('\nMore than one student with same name found !!... Try searching again with Examination Seat No. for accurate results.')
    elif usersearch.upper()=='E':
        user_find=int(input('\nEnter examination seat no. of student: '))
        count=0
        stud_count=0
        datetoday=datetime.date.today()
        for i in record:
            if i[1] == user_find and i[5]<datetoday:
                print('\nStudent Record',stud_count+1)
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            elif i[1] == user_find and i[5]>datetoday:
                print('\nStudent Record-',stud_count+1)
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            else:
                count+=1
        print('\n',stud_count,'record(s) found under the unique id \'',user_find,'\'')
        if count==(len(record)-1):
            pass
        elif count==len(record):
            print('\nStudent not found !!')
    elif usersearch.upper()=='D':
        user_find=int(input('\nEnter month number to find which students have due date: '))
        count=0
        stud_count=0
        datetoday=datetime.date.today()
        for i in record:
            if i[5].month == user_find and i[5]<datetoday:
                print('\nStudent No.-',stud_count+1)
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            elif i[5].month == user_find and i[5]>datetoday:
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            else:
                count+=1
        print('\n',stud_count,'record(s) found under the due month of \'',year_dict[int(user_find)],'\'')
        if count==(len(record)-1):
            pass
    elif usersearch.upper()=='I':
        user_find=input('\nEnter ISBN no. of book: ')
        count=0
        stud_count=0
        datetoday=datetime.date.today()
        for i in record:
            if i[2] == str(user_find) and i[5]<datetoday:
                print('\nStudent No.-',stud_count+1)
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            elif i[2] == str(user_find) and i[5]>datetoday:
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            else:
                count+=1
        print('\n',stud_count,'record(s) found under the unique id \'',user_find,'\'')
        if count==(len(record)-1):
            pass
        elif count==len(record):
            print('\nStudent not found !!')
    elif usersearch=='invalid':
        print('\nRecord list empty!! Try adding records first.')
    else:
        print('\nInvalid Input!! Try again.')
    open_bin.close()

#Delete all records
def delrec():
    open_bin=open('dbmscsv','rb')
    record=pickle.load(open_bin)
    open_bin.close()
    confirm=str(input('Are you sure you want to delete all records ? (Y/N)'))
    if record != []:
        if confirm.upper()=='Y':
            open_bin=open('dbmscsv','wb')
            lst_std=[]
            pickle.dump(lst_std,open_bin)
            open_bin.close()
            makenew = [['','','','','','']]
            lsttocsv(makenew)
            print('All records deleted successfully !!')
        else:
            print('Records are safe !!')
    elif record==[]:
        print('No records present !!')

#Deleting particular records
def delparrec():
    open_bin=open('dbmscsv','rb')
    records=pickle.load(open_bin)
    open_bin.close()
    open_bin=open('dbmscsv','wb')  
    usersearch=str(input('\nEnter ISBN number of the book being returned: '))
    lst_temp=[]
    stud_count=0
    confirm=str(input('Are you sure you want to delete record ? (Y/N) '))
    if confirm.upper()=='Y':
        for i in records:
            if i[2]==usersearch:
                stud_count+=1
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                print('+-------------------+')
                pass
            else:
                lst_temp.append(i)
        pickle.dump(lst_temp,open_bin)
        lsttocsv(lst_temp)
    else:
        pickle.dump(records,open_bin)
        lsttocsv(records)
    if confirm.upper()=='Y':
        if stud_count != 0:
            print('\nRecord under ISBN \'',usersearch,'\' deleted successfully.')
        else:
            print('\nNo such record found !!')
    else:
        pass
    open_bin.close()

#Updating records
def updaterec():
    open_bin=open('dbmscsv','rb')
    records=pickle.load(open_bin)
    open_bin.close()
    usersearch='E'
    if usersearch.upper()=='E':
        user_find=''
        list_checknames=[]
        for i in records:
            list_checknames.append(int(i[1]))
        tries=0
        user_find=int(input('Enter exam seat no. of student(presently in records): '))
        while user_find not in list_checknames and tries<2:
                print('Unique ID doesn\'t exist !!')
                user_find=int(input('Enter exam seat no. of student(presently in records): '))
                tries+=1
        if tries<2 and user_find in list_checknames:
            print('N-Name\nE-Examination Seat No.\nI-ISBN No.\nB-Book Name\nIS-Issue-Date(yyyy-mm-dd format)\n')
            user_choose=str(input('\nWhich field you want to update ?'))
            if user_choose.upper() == 'N' or user_choose.upper() == 'E' or user_choose.upper() == 'I' or user_choose.upper() == 'B':
                user_change=str(input('\nEnter updated information: '))
            elif user_choose.upper() == 'IS':
                user_change=datetime.date.today()
        else:
            print('Invalid entries. Exiting session temporarily !!')
            pass

        user_can='yes'
        user_can2='yes'
        try:
            for i in records:
                if user_choose.upper()=='E':
                    user_can='yes'
                    if int(user_change) == (int(i[1])):
                        print('\nCan\'t update..Student already exist with the unique ID !!')
                        info2(records,user_change,1)
                        user_can2='no'
                        break
                    else:
                        user_can2='yes'
                elif user_choose.upper()=='I':
                    user_can2='yes'
                    if user_change == i[2]:
                        print('\nBook with ISBN No.',user_change,'already issued by: ')
                        info2(records,user_change,2)
                        user_can='no'
                        break
                    else:
                        user_can='yes'
                        pass
                else:
                    pass
        except:
            user_can='no'
            user_can2='no'
        if user_can=='yes' and user_can2=='yes': 
            if user_choose.upper()=='N':
                stat=''
                stat2=''
                for i in records:
                    if int(i[1])==user_find:
                        i[0]=user_change
                        print('Record updated successfully !!')
                        info(records,user_change,1)
                        stat2='found'
                        n=0
                    else:
                        stat='notfound'
                if stat=='notfound' and stat2=='':    
                    print('No such record !!')
            elif user_choose.upper()=='E':
                stat=''
                stat2=''
                for i in records:
                    if int(i[1])==user_find:
                        i[1]=user_change
                        print('Record updated successfully !!')
                        info(records,user_find,1)
                        stat2='found'
                        n=1
                    else:
                        stat='notfound'
                if stat=='notfound' and stat2=='':    
                    print('No such record !!')
            elif user_choose.upper()=='I':
                stat=''
                stat2=''
                for i in records:
                    if int(i[1])==user_find:
                        i[2]=user_change
                        print('Record updated successfully !!')
                        info(records,user_find,1)
                        stat2='found'
                        n=2
                    else:
                        stat='notfound'
                if stat=='notfound' and stat2=='':    
                    print('No such record !!')
            elif user_choose.upper()=='B':
                stat=''
                stat2=''
                for i in records:
                    if int(i[1])==user_find:
                        i[3]=user_change
                        print('Record updated successfully !!')
                        info(records,user_find,1)
                        stat2='found'
                        n=3
                    else:
                        stat='notfound'
                if stat=='notfound' and stat2=='':    
                    print('No such record !!')
            elif user_choose.upper()=='IS':
                stat=''
                stat2=''
                n=-1
                for i in records:
                    if int(i[1])==user_find:
                        i[4]=user_change
                        i[5]=user_change+datetime.timedelta(days=7)
                        print('\nRecord updated successfully !!')
                        print('Issue date set to current date.')
                        info(records,user_find,1)
                        stat2='found'
                        n=4
                    else:
                        stat='notfound'
                if stat=='notfound' and stat2=='':    
                    print('No such record !!')
            else:
                print('\nInvalid Input!!')
            open_bin=open('dbmscsv','wb')
            pickle.dump(records,open_bin)
            lsttocsv(records)
        else:
            open_bin=open('dbmscsv','wb')
            pickle.dump(records,open_bin)
            lsttocsv(records)

    open_bin.close()


#Infobar-1
def info(listsearch,searchmaterial,index):
    datetoday=datetime.date.today()
    stud_count=0
    for i in listsearch:
            if searchmaterial==i[index]:
                if i[5]<datetoday:
                    print('\nUpdated information:\n')
                    print('+-------------------+')
                    print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                    print('+-------------------+')
                    stud_count+=1
                else:
                    print('+-------------------+')
                    print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                    print('+-------------------+')


#Infobar-2
def info2(listsearch,searchmaterial,index):
    datetoday=datetime.date.today()
    stud_count=0
    for i in listsearch:
            if searchmaterial==i[index]:
                if i[5]<datetoday:
                    print('\nStudent No.-',stud_count+1)
                    print('+-------------------+')
                    print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                    print('+-------------------+')
                    stud_count+=1
                else:
                    print('+-------------------+')
                    print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                    print('+-------------------+')


#Infobar-3
def info3(listsearch,searchmaterial,index):
    datetoday=datetime.date.today()
    for i in listsearch:
            if searchmaterial==i[index]:
                if i[5]<datetoday:
                    print('+-------------------+')
                    print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                    print('+-------------------+')
                else:
                    print('+-------------------+')
                    print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                    print('+-------------------+')


#All Records
def allrecs():
    try:
        open_bin=open('dbmscsv','rb')  # Regular use
        record=pickle.load(open_bin)
        open_bin.close()
    except:
        open_bin=open('dbmscsv','wb') # If initialising for 1st time
        lst=[]
        pickle.dump(lst,open_bin)
        open_bin.close()
        open_bin=open('dbmscsv','rb')
        record=pickle.load(open_bin)
        open_bin.close()
    stud_count=0
    datetoday=datetime.date.today()
    if record != []:
        lsttocsv(record)
        for i in record:
            if i[5]<datetoday:
                print('\nStudent No.-',stud_count+1)
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date(Overdue) |-->',i[5])
                print('+-------------------+')
                stud_count+=1
            else:
                print('\nStudent No.-',stud_count+1)
                print('+-------------------+')
                print('| Name              |-->',i[0],'\n+-------------------+','\n| Exam Seat No.     |-->',i[1],'\n+-------------------+','\n| ISBN No.          |-->',i[2],'\n+-------------------+','\n| Book Name         |-->',i[3],'\n+-------------------+','\n| Issue Date        |-->',i[4],'\n+-------------------+','\n| Due Date          |-->',i[5])
                print('+-------------------+')
                stud_count+=1
    elif record == []:
        print('\nNo records present !! Try adding entries first.')


