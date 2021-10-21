import mysql.connector
from datetime import datetime
from selenium import webdriver
from fpdf import FPDF
import selenium

mydb=mysql.connector.connect(user='root',
passwd='dbavenge2015',
                             
host='localhost',
auth_plugin='mysql_native_password',
database='bankDB'
)
mycursor=mydb.cursor(buffered=True)



def MiniStatement():
    from fpdf import FPDF 
    acc=int(input("Enter Account Number: "))
    pdf = FPDF()      
    pdf.add_page()  
    pdf.set_font("Arial", size = 15)
    directory_open = "C:\MiniStatements\\text\\"+str(acc)+".txt"
    directory_save = "C:\MiniStatements\\pdf\\"+str(acc)+".pdf"
    f = open(directory_open, "r") 
    for x in f: 
     pdf.cell(0,10, txt = x, ln = 1, align = 'L') 
    pdf.output(directory_save)
    browser = webdriver.Chrome("C:\\Drivers\\chromedriver.exe")
    browser.get(directory_save)
    print("Successfull")

def Menu(): 
    print("*"*140)
    print("MAIN MENU".center(140))
    print("1. Insert Record/Records".center(114))
    print("2. Display Records as per Account Number".center(130))
    print(" a. Sorted as per Account Number".center(140))
    print(" b. Sorted as per Customer Name".center(140))
    print(" c. Sorted as per Customer Balance".center(142))
    print("3. Search Record Details as per the account number".center(140))
    print("4. Update Record".center(105))
    print("5. Delete Record".center(105))
    print("6. TransactionsDebit/Withdraw from the account".center(135))
    print(" a. Debit/Withdraw from the account".center(145))
    print(" b. Credit into the account".center(138))
    print("7. Get Mini Statement".center(112))
    print("8. Exit".center(98))
    print("*"*140)

def MenuSort():
    print(" a. Sort by Account Number".center(115))
    print(" b. Sort by Customer Name".center(115))
    print(" c. Sort by Customer Balance".center(117))
    print(" d. Back".center(98))

def MenuTransaction():
    print(" a. Debit/Withdraw from the account".center(125))
    print(" b. Credit into the account".center(117))
    print(" c. Back".center(98))

def Create():
    try:
        mycursor.execute('create table bank(ACCNO varchar(10),NAME varchar(20),MOBILE varchar(10),EMAIL varchar(50),ADDRESS varchar(20),CITY varchar(10),COUNTRY varchar(20),BALANCE integer(15))')
        print("Table Created")
        Insert()
    except:
        print("Table Exist")
        Insert()
        
def Insert():
    while True: 
        Acc=input("Enter account no ")
        Name=input("Enter Name ")
        Mob=input("Enter Mobile ")
        email=input("Enter Email ")
        Add=input("Enter Address ")
        City=input("Enter City ")
        Country=input("Enter Country ")
        Bal=float(input("Enter Balance "))
        Rec=[Acc,Name.upper(),Mob,email.upper(),Add.upper(),City.upper(),Country.upper(),Bal]
        Cmd="insert into BANK values(%s,%s,%s,%s,%s,%s,%s,%s)"
        mycursor.execute(Cmd,Rec)
        mydb.commit()
        directory = "C:\MiniStatements\\text\\"+Acc+".txt"
        transaction = open(directory,'w')
        now = datetime.now()
        dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
        new_acc = dt_string+", "+"Account Created, Available balance: Rs."+str(Bal)+"\n"
        transaction.write(new_acc)
        ch=input("Do you want to enter more records")
        if ch=='N' or ch=='n':
            break
        
def DispSortAcc(): 
    try:
        cmd="select * from BANK order by ACCNO"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        F="%15s %7s %20s %20s %20s %10s %17s %15s"
        print(F % ("ACCNO","NAME","MOBILE","EMAIL ADDRESS","COMPLETE ADDRESS","CITY","COUNTRY","BALANCE"))
        print("="*130)
        for i in S:
            for j in i:
                print("%14s" % j, end=' ')
            print()
        print("="*130)
    except:
        print("Table doesn't exist")
                   
def DispSortName(): 
    try:
        cmd="select * from BANK order by NAME"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        F="%15s %7s %20s %20s %20s %10s %17s %15s"
        print(F % ("ACCNO","NAME","MOBILE","EMAIL ADDRESS","COMPLETE ADDRESS","CITY","COUNTRY","BALANCE"))
        print("="*130)
        for i in S:
            for j in i:
                print("%14s" % j, end=' ')
            print()
        print("="*130)
    except:
        print("Table doesn't exist")
                   
def DispSortBal(): #Function to Display records as per ascending order of Balance
    try:
        cmd="select * from BANK order by BALANCE"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        F="%15s %7s %20s %20s %20s %10s %17s %15s"
        print(F % ("ACCNO","NAME","MOBILE","EMAIL ADDRESS","COMPLETE ADDRESS","CITY","COUNTRY","BALANCE"))
        print("="*130)
        for i in S:
            for j in i:
                print("%14s" % j, end=' ')
            print()
        print("="*130)
    except:
        print("Table doesn't exist")
                   
def DispSearchAcc(): 
    try:
        cmd="select * from BANK"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        ch=input("Enter the accountno to be searched ")
        for i in S:
            if i[0]==ch:
                print("="*125)
                F="%15s %7s %20s %20s %20s %10s %17s %15s"
                print(F % ("ACCNO","NAME","MOBILE","EMAIL ADDRESS","COMPLETE ADDRESS","CITY","COUNTRY","BALANCE"))
                print("="*130)
                for j in i:
                    print('%14s' % j,end=' ')
                print()
                break
        else:
            print("Record Not found")
    except:
        print("Table doesn't exist")

def Update(): 
    try:
        k=0
        cmd="select * from BANK"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        A=input("Enter the accound no whose details to be changed")
        for i in S:
            i=list(i)
            if i[0]==A :
              
                ch=input("Change Name(Y/N) ")
                if ch=='y' or ch=='Y':
                    i[1]=input("Enter Name ")
                    i[1]=i[1].upper()
                ch=input("Change Mobile(Y/N) ")
                if ch=='y' or ch=='Y':
                    i[2]=input("Enter Mobile ")
                ch=input("Change Email(Y/N) ")
                if ch=='y' or ch=='Y':
                    i[3]=input("Enter email ")
                    i[3]=i[3].upper()
                ch=input("Change Address(Y/N) ")
                if ch=='y' or ch=='Y':
                    i[4]=input("Enter Address ")
                    i[4]=i[4].upper()
                ch=input("Change city(Y/N) ")
                if ch=='y' or ch=='Y':
                    i[5]=input("Enter City ")
                    i[5]=i[5].upper()
                ch=input("Change Country(Y/N) ")
                if ch=='y' or ch=='Y':
                    i[6]=input("Enter country ")
                    i[6]=i[6].upper()
                cmd="UPDATE BANK SET NAME=%s,MOBILE=%s,EMAIL=%s,ADDRESS=%s,CITY=%s,COUNTRY=%s,BALANCE=%s WHERE ACCNO=%s"
                val=(i[1],i[2],i[3],i[4],i[5],i[6],i[7],i[0])
                mycursor.execute(cmd,val)
                mydb.commit()
                print("Account Updated")
                    

                break
            else:
                 pass
    except:
        print("No such table")
                           
def Delete(): 
    try:
        cmd="select * from BANK"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        A=input("Enter the account no whose account is to be deleted")
        directory = "C:\MiniStatements\\text\\"+A+".txt"
       
        for i in S:
            i=list(i)
            if i[0]==A:
                cmd="delete from bank where accno=%s"
                val=(i[0],)
                mycursor.execute(cmd,val)
                mydb.commit()
                print("Account Deleted")
                now = datetime.now()
                dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
                transaction = open(directory,'a')
                delete = dt_string+", "+"Account was closed."
                transaction.write(delete)
                break
        else:
            print("Record not found")
    except:
        print("No such Table")
                           
def Debit(): 
    try:
        cmd="select * from BANK"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        print("Please Note that the money can only be debited if min balance of Rs 5000 exists ")
        acc=input("Enter the account no from which the money is to be debited ")
        directory = "C:\MiniStatements\\text\\"+acc+".txt"
        
            
        for i in S:
            i=list(i)
            if i[0]==acc:
                Amt=float(input("Enter the amount to be withdrawn "))        
                if i[7]-Amt>=5000:
                    i[7]-=Amt
                    cmd="UPDATE BANK SET BALANCE=%s WHERE ACCNO=%s"
                    val=(i[7],i[0])
                    now = datetime.now()
                    dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
                    debit = dt_string+", "+"Rs."+str(Amt)+" Debited, Available balance: Rs."+str(i[7])+"\n"
                    mycursor.execute(cmd,val)
                    mydb.commit()
                    transaction = open(directory,'a')   
                    transaction.write(debit)
                    print("Amount Debited")
                    
                    break
                else:
                    print("There must be min balance of Rs 5000")
                break
        else:
            print("Record Not found")
        
    except:
        print("Table Doesn't exist")
                           
def Credit(): 
    try:
        cmd="select * from BANK"
        mycursor.execute(cmd)
        S=mycursor.fetchall()
        acc=input("Enter the account no from which the money is to be credited ")
        directory = "C:\MiniStatements\\text\\"+acc+".txt"       
        
        for i in S:
            i=list(i)
            if i[0]==acc:
                Amt=float(input("Enter the amount to be credited "))
                i[7]+=Amt
                cmd="UPDATE BANK SET BALANCE=%s WHERE ACCNO=%s"
                val=(i[7],i[0])
                now = datetime.now()
                dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
                credit = dt_string+", "+"Rs."+str(Amt)+" Credited, Available balance: Rs."+str(i[7])+"\n"
                mycursor.execute(cmd,val)
                mydb.commit()   
                transaction = open(directory,'a')            
                transaction.write(credit)
                print("Amount Credited")
                break
            else:
                pass
    except:
        print("Table Doesn't exist")

while True:
    Menu()
    ch=input("Enter your Choice: ")
    if ch=="1":
        Create()
    elif ch=="2":
        while True:
            MenuSort()
            ch1=input("Enter choice a/b/c/d ")
            if ch1 in ['a','A']:
                DispSortAcc()
            elif ch1 in ['b','B']:
                DispSortName()
            elif ch1 in ['c','C']:
                DispSortBal()
            elif ch1 in ['d','D']:
                print("Back to the main menu ")
                break
            else:
                print("Invalid choice ")
    elif ch=="3":
        DispSearchAcc()
    elif ch=="4":
        Update()
    elif ch=="5":
        Delete()
    elif ch=="6":
        while True:
            MenuTransaction()
            ch1=input("Enter choice a/b/c ")
            if ch1 in ['a','A']:
                Debit()
            elif ch1 in ['b','B']:
                Credit()
            elif ch1 in ['c','C']:
                print("Back to the main menu ")
                break
            else:
                print("Invalid choice ")
    elif ch=="7":
        MiniStatement()
    elif ch=="8":
        print("Exiting...")
        break
    else:
        print("Wrong Choice Entered ")
