# You can find the entire project here: https://github.com/varshaah2407/Python-Miniproject
# Contributed by Varshaah Shashidhar

import tkinter as tk
from tkinter import *
from  tkinter import messagebox
from tkinter import ttk

def main1():
    global MAIN_WINDOW
    MAIN_WINDOW=Tk()      #after successful this main ui should appear

    MAIN_WINDOW.geometry("600x1000+300+100")
    va = IntVar()
    va.set(1)
    w=Label(MAIN_WINDOW, text = "What do you wish to buy today?")#,justify=LEFT
    w.pack(anchor=W)
    r1=Radiobutton(MAIN_WINDOW, text='Cosmetics', variable=va, value=1,justify=LEFT, command = Cosmetics)
    r2=Radiobutton(MAIN_WINDOW, text='Clothing', variable=va, value=2,justify=LEFT, command = Clothing)
    r1.pack()
    r2.pack()
    
 
    MAIN_WINDOW.mainloop()
       
a=0
b=0
c=0

def c1():
    global a
    a=a+1

def c2():
    global b
    b=b+1
    
def c3():
    global c
    c=c+1
    
    # Function for cosmetics
def Cosmetics():
    l1=Label(MAIN_WINDOW, text = "Select desired product",justify=LEFT)
    l1.pack(anchor=W)
    v1 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Shampoo and Conditioner',variable=v1,value=1, command = Shampoo).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Face wash',variable=v1,value=2, command = Facewash).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Soap',variable=v1,value=3, command = Soap).pack(anchor=W)
        
    #Function for clothing
def Clothing():
    l2=Label(MAIN_WINDOW, text = "Select desired product",justify=LEFT)
    l2.pack(anchor=W)
    v2 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Shirt for men',variable=v2,value=1,command = Shirt_men).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Shirt for women',variable=v2,value=2, command = Shirt_women).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Denim Jeans',variable=v2,value=3, command = Denims).pack(anchor=W)
    
    
#Function for shampoo !!!
def Shampoo():
    #1st
    LA=Label(MAIN_WINDOW, text = "Select the most appropriate answer:",justify=LEFT)
    l3=Label(MAIN_WINDOW, text = "1. What type of hair do u have?",justify=LEFT)
    l3.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Oily',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Normal',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Dry',variable=v3,value=3,command=c3).pack(anchor=W)
        
    #2nd
    l4=Label(MAIN_WINDOW, text = "2. What type of hair do u have?",justify=LEFT)
    l4.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Thick',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Normal',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Fine',variable=v3,value=3,command=c3).pack(anchor=W)
        
        
    #3rd
    l5=Label(MAIN_WINDOW, text = "3. Presently your hair is",justify=LEFT)
    l5.pack(anchor=W)
    v5 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Natural',variable=v5,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Coloured or Highlighted',variable=v5,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Permed',variable=v5,value=3,command=c3).pack(anchor=W)
        
    #4th
    l6=Label(MAIN_WINDOW, text = "4. How frequently do you wash your hair?",justify=LEFT)
    l6.pack(anchor=W)
    v6 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Once a week',variable=v6,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Twice a week',variable=v6,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Everyday',variable=v6,value=3,command=c3).pack(anchor=W)
        
    #5th
    l7=Label(MAIN_WINDOW, text = "5. How often do you use a heat tool?",justify=LEFT)
    l7.pack(anchor=W)
    v7 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Never',variable=v7,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Sometimes',variable=v7,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Everyday',variable=v7,value=3,command=c3).pack(anchor=W)
        
    #6th
    l8=Label(MAIN_WINDOW, text = "6. How often do you use a hair product?",justify=LEFT)
    l8.pack(anchor=W)
    v8 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Never',variable=v8,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Sometimes',variable=v8,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Everyday',variable=v8,value=3,command=c3).pack(anchor=W)
        
    #7th
    l9=Label(MAIN_WINDOW, text = "7. Do you have splitends?",justify=LEFT)
    l9.pack(anchor=W)
    v9 = IntVar()
    Radiobutton(MAIN_WINDOW, text='None',variable=v9,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Few',variable=v9,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Plenty',variable=v9,value=3,command=c3).pack(anchor=W)
    
        
    Button(MAIN_WINDOW, text="Submit", width=10, height=1, bg="white",command=Shampoo_pro).place(x=300,y=700)
    Button(MAIN_WINDOW, text="Buy", width=10, height=1, bg="white",command=Buy).place(x=400,y=700)

def Shampoo_pro():
    if (a>b and a>c):
        messagebox.showinfo("Your ideal Shampoo:","L'Oreal 6 Oil Nourish Shampoo")
    elif (b>c and b>a):
        messagebox.showinfo("Your ideal shampoo " ,"L'Oreal Hair Spa Nourishing Shampoo")
    elif (c>a and c>b):
        messagebox.showinfo("Your ideal shampoo" ,"Dove Intense Repair Shampoo")
    elif (a==b):
        messagebox.showinfo("Your ideal shampoo" ,"L'Oreal Hair Spa Nourishing Shampoo")
    elif (b==c):
        messagebox.showinfo("Your ideal shampoo","Dove Intense Repair Shampoo")
    elif (a==c):
        messagebox.showinfo("Your ideal shampoo" ,"L'Oreal Hair Spa Nourishing Shampoo")
    elif (a==b and b==c):
        messagebox.showinfo("Your ideal shampoo" ,"L'Oreal Hair Spa Nourishing Shampoo")
        

        
#Function for facewash !!!
def Facewash():
    #1st
    LA=Label(MAIN_WINDOW, text = "Select the most appropriate answer:",justify=LEFT)
    l3=Label(MAIN_WINDOW, text = "1. What type of skin do u have?",justify=LEFT)
    l3.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Oily',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Normal',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Dry',variable=v3,value=3,command=c3).pack(anchor=W)
        
    #2nd
    l4=Label(MAIN_WINDOW, text = "2. How often do you have skin problems(pimple,acne)?",justify=LEFT)
    l4.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Frequently',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Sometimes',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Never',variable=v3,value=3,command=c3).pack(anchor=W)
        
        
    #3rd
    l5=Label(MAIN_WINDOW, text = "3. How does your skin react to 2 hours of sun exposure without sunscreen?",justify=LEFT)
    l5.pack(anchor=W)
    v5 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Skin Burns',variable=v5,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Minor Burns',variable=v5,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Never Burns',variable=v5,value=3,command=c3).pack(anchor=W)
        
    #4th
    l6=Label(MAIN_WINDOW, text = "4. Does new skin care often make your skin itch,burn or irritate?",justify=LEFT)
    l6.pack(anchor=W)
    v6 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Yes',variable=v6,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Yes, sometimes',variable=v6,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='No',variable=v6,value=3,command=c3).pack(anchor=W)
        
    #5th
    l7=Label(MAIN_WINDOW, text = "5. How often do you wash your face?",justify=LEFT)
    l7.pack(anchor=W)
    v7 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Once a day',variable=v7,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Twice a day',variable=v7,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='More than twice a day',variable=v7,value=3,command=c3).pack(anchor=W)
        
    #6th
    l8=Label(MAIN_WINDOW, text = "6. How much makeup do you use on a daily basis?",justify=LEFT)
    l8.pack(anchor=W)
    v8 = IntVar()
    Radiobutton(MAIN_WINDOW, text='None',variable=v8,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Little',variable=v8,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Full Coverage',variable=v8,value=3,command=c3).pack(anchor=W)
        
    #7th
    l9=Label(MAIN_WINDOW, text = "7. How often is your skin sensitive?",justify=LEFT)
    l9.pack(anchor=W)
    v9 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Never',variable=v9,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Sometimes',variable=v9,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='All the time',variable=v9,value=3,command=c3).pack(anchor=W)
    
        
    Button(MAIN_WINDOW, text="Submit", width=10, height=1, bg="white",command=Facewash_pro).place(x=300,y=700)
    Button(MAIN_WINDOW, text="Buy", width=10, height=1, bg="white",command=Buy).place(x=400,y=700)

def Facewash_pro():
    if (a>b and a>c):
        messagebox.showinfo("Your ideal Facewash:","Himalaya Herbal Purifying Neem Face Wash")
    elif (b>c and b>a):
        messagebox.showinfo("Your ideal shampoo " ,"Garnier Skin Naturals Light Complete Facewash")
    elif (c>a and c>b):
        messagebox.showinfo("Your ideal shampoo" ,"Biotique Bio Honey Gel Facewash")
    elif (a==b):
        messagebox.showinfo("Your ideal shampoo" ,"Garnier Skin Naturals Light Complete Facewash")
    elif (b==c):
        messagebox.showinfo("Your ideal shampoo","Biotique Bio Honey Gel Facewash")
    elif (a==c):
        messagebox.showinfo("Your ideal shampoo" ,"Garnier Skin Naturals Light Complete Facewash")
    elif (a==b and b==c):
        messagebox.showinfo("Your ideal shampoo" ,"Garnier Skin Naturals Light Complete Facewash")
        
        
        
#Function for soap !!!
def Soap():
    #1st
    LA=Label(MAIN_WINDOW, text = "Select the most appropriate answer:",justify=LEFT)
    l3=Label(MAIN_WINDOW, text = "1. What type of skin you have?",justify=LEFT)
    l3.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Oily',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Normal',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Dry',variable=v3,value=3,command=c3).pack(anchor=W)
        
    #2nd
    l4=Label(MAIN_WINDOW, text = "2. Is your skin sensitive?",justify=LEFT)
    l4.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='No',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Little',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Very much',variable=v3,value=3,command=c3).pack(anchor=W)
        
        
    #3rd
    l5=Label(MAIN_WINDOW, text = "3. How often your skin react to change in skin products?",justify=LEFT)
    l5.pack(anchor=W)
    v5 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Does not react',variable=v5,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Sometimes',variable=v5,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Never',variable=v5,value=3,command=c3).pack(anchor=W)
        
    #4th
    l6=Label(MAIN_WINDOW, text = "4. What fragrance do you like?",justify=LEFT)
    l6.pack(anchor=W)
    v6 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Strawberry',variable=v6,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Cocoa',variable=v6,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Citrus',variable=v6,value=3,command=c3).pack(anchor=W)
        
    #5th
    l7=Label(MAIN_WINDOW, text = "5. How many bathing soaps do you buy per month?",justify=LEFT)
    l7.pack(anchor=W)
    v7 = IntVar()
    Radiobutton(MAIN_WINDOW, text='1-2',variable=v7,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='3-4',variable=v7,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='More',variable=v7,value=3,command=c3).pack(anchor=W)
        
    #6th
    l8=Label(MAIN_WINDOW, text = "6. How satisfied are you with your soap?",justify=LEFT)
    l8.pack(anchor=W)
    v8 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Satisfied',variable=v8,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Neither satisfied nor dissatisfied',variable=v8,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Dissatisfied',variable=v8,value=3,command=c3).pack(anchor=W)
        
    #7th
    l9=Label(MAIN_WINDOW, text = "7. Do you prefer soap with colour and fragrance?",justify=LEFT)
    l9.pack(anchor=W)
    v9 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Yes',variable=v9,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Only fragrance',variable=v9,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='No',variable=v9,value=3,command=c3).pack(anchor=W)
    
        
    Button(MAIN_WINDOW, text="Submit", width=10, height=1, bg="white",command=Soap_pro).place(x=300,y=700)
    Button(MAIN_WINDOW, text="Buy", width=10, height=1, bg="white",command=Buy).place(x=400,y=700)

def Soap_pro():
    if (a>b and a>c):
        messagebox.showinfo("Your ideal Soap:","Dove Cream Beauty Bathing bar")
    elif (b>c and b>a):
        messagebox.showinfo("Your ideal Soap:" ,"Biotique Bio Almond Oil Nourishing Soap")
    elif (c>a and c>b):
        messagebox.showinfo("Your ideal Soap:" ,"Pears Pure and Gentle")
    elif (a==b):
        messagebox.showinfo("Your ideal Soap:" ,"Biotique Bio Almond Oil Nourishing Soap")
    elif (b==c):
        messagebox.showinfo("Your ideal Soap:","Pears Pure and Gentle")
    elif (a==c):
        messagebox.showinfo("Your ideal Soap:" ,"Biotique Bio Almond Oil Nourishing Soap")
    elif (a==b and b==c):
        messagebox.showinfo("Your ideal Soap:" ,"Biotique Bio Almond Oil Nourishing Soap")
        
        
        
#Function for shirt (men) !!!
def Shirt_men():
    #1st
    LA=Label(MAIN_WINDOW, text = "Select the most appropriate answer:",justify=LEFT)
    l3=Label(MAIN_WINDOW, text = "1. What is your size?",justify=LEFT)
    l3.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Small',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Medium',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Large',variable=v3,value=3,command=c3).pack(anchor=W)
        
    #2nd
    l4=Label(MAIN_WINDOW, text = "2. What type of collar?",justify=LEFT)
    l4.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Classic',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Button',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Mandarian',variable=v3,value=3,command=c3).pack(anchor=W)
        
        
    #3rd
    l5=Label(MAIN_WINDOW, text = "3. What kind of shirt do you want?",justify=LEFT)
    l5.pack(anchor=W)
    v5 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Western',variable=v5,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Casual',variable=v5,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Formal',variable=v5,value=3,command=c3).pack(anchor=W)
        
    #4th
    l6=Label(MAIN_WINDOW, text = "4. What kind of sleeve do you prefer?",justify=LEFT)
    l6.pack(anchor=W)
    v6 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Long',variable=v6,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Short',variable=v6,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Sleeveless',variable=v6,value=3,command=c3).pack(anchor=W)
        
    #5th
    l7=Label(MAIN_WINDOW, text = "5. What kind of fabric do you prefer?",justify=LEFT)
    l7.pack(anchor=W)
    v7 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Linen',variable=v7,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Cotton',variable=v7,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Silk',variable=v7,value=3,command=c3).pack(anchor=W)
        
    #6th
    l8=Label(MAIN_WINDOW, text = "6. Select the type of fitting",justify=LEFT)
    l8.pack(anchor=W)
    v8 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Skinny fit',variable=v8,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Classic Fit',variable=v8,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Modern Fit',variable=v8,value=3,command=c3).pack(anchor=W)
        
    #7th
    l9=Label(MAIN_WINDOW, text = "7. For what type of occasion do you need this shirt?",justify=LEFT)
    l9.pack(anchor=W)
    v9 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Formal funcgtion',variable=v9,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Party wear',variable=v9,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Social gathering',variable=v9,value=3,command=c3).pack(anchor=W)
    
        
    Button(MAIN_WINDOW, text="Submit", width=10, height=1, bg="white",command=Shirt_Men_pro).place(x=300,y=700)
    Button(MAIN_WINDOW, text="Buy", width=10, height=1, bg="white",command=Buy).place(x=400,y=700)

def Shirt_Men_pro():
    if (a>b and a>c):
        messagebox.showinfo("Your ideal Shirt:","Peter England Navy Blue Solid Shirt")
    elif (b>c and b>a):
        messagebox.showinfo("Your ideal Shirt:" ,"GAP Olive Solid Shirt")
    elif (c>a and c>b):
        messagebox.showinfo("Your ideal Shirt:" ,"Peter England Black Solid Shirt")
    elif (a==b):
        messagebox.showinfo("Your ideal Shirt:" ,"GAP Olive Solid Shirt")
    elif (b==c):
        messagebox.showinfo("Your ideal Shirt:","Peter England Black Solid Shirt")
    elif (a==c):
        messagebox.showinfo("Your ideal Shirt:" ,"GAP Olive Solid Shirt")
    elif (a==b and b==c):
        messagebox.showinfo("Your ideal Shirt:" ,"GAP Olive Solid Shirt")
        
        
        
#Function for shirt (women) !!!
def Shirt_women():
    #1st
    LA=Label(MAIN_WINDOW, text = "Select the most appropriate answer:",justify=LEFT)
    l3=Label(MAIN_WINDOW, text = "1. What is your size?",justify=LEFT)
    l3.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Small',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Medium',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Large',variable=v3,value=3,command=c3).pack(anchor=W)
        
    #2nd
    l4=Label(MAIN_WINDOW, text = "2. What type of neck do you prefer?",justify=LEFT)
    l4.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='V-neck',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Turtleneck',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Low neck',variable=v3,value=3,command=c3).pack(anchor=W)
        
        
    #3rd
    l5=Label(MAIN_WINDOW, text = "3. What kind of shirt do you want?",justify=LEFT)
    l5.pack(anchor=W)
    v5 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Western',variable=v5,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Casual',variable=v5,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Formal',variable=v5,value=3,command=c3).pack(anchor=W)
        
    #4th
    l6=Label(MAIN_WINDOW, text = "4. What kind of sleeve do you prefer?",justify=LEFT)
    l6.pack(anchor=W)
    v6 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Long',variable=v6,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Short',variable=v6,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Sleeveless',variable=v6,value=3,command=c3).pack(anchor=W)
        
    #5th
    l7=Label(MAIN_WINDOW, text = "5. What kind of fabric do you prefer?",justify=LEFT)
    l7.pack(anchor=W)
    v7 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Linen',variable=v7,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Cotton',variable=v7,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Silk',variable=v7,value=3,command=c3).pack(anchor=W)
        
    #6th
    l8=Label(MAIN_WINDOW, text = "6. Select the type of fitting",justify=LEFT)
    l8.pack(anchor=W)
    v8 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Skinny fit',variable=v8,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Classic Fit',variable=v8,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Modern Fit',variable=v8,value=3,command=c3).pack(anchor=W)
        
    #7th
    l9=Label(MAIN_WINDOW, text = "7. For what type of occasion do you need this shirt?",justify=LEFT)
    l9.pack(anchor=W)
    v9 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Formal funcgtion',variable=v9,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Party wear',variable=v9,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Social gathering',variable=v9,value=3,command=c3).pack(anchor=W)
    
        
    Button(MAIN_WINDOW, text="Submit", width=10, height=1, bg="white",command=Shirt_Women_pro).place(x=300,y=700)
    Button(MAIN_WINDOW, text="Buy", width=10, height=1, bg="white",command=Buy).place(x=400,y=700)

def Shirt_Women_pro():
    if (a>b and a>c):
        messagebox.showinfo("Your ideal Shirt:","GAP Blue Fitted Boyfriend Shirt")
    elif (b>c and b>a):
        messagebox.showinfo("Your ideal Shirt:" ,"H&M Olive Solid Shirt")
    elif (c>a and c>b):
        messagebox.showinfo("Your ideal Shirt:" ,"Vero Moda Black Solid Top")
    elif (a==b):
        messagebox.showinfo("Your ideal Shirt:" ,"H&M Olive Solid Shirt")
    elif (b==c):
        messagebox.showinfo("Your ideal Shirt:","Vero Moda Black Solid Top")
    elif (a==c):
        messagebox.showinfo("Your ideal Shirt:" ,"H&M Olive Solid Shirt")
    elif (a==b and b==c):
        messagebox.showinfo("Your ideal Shirt:" ,"H&M Olive Solid Shirt")
        
        
        
#Function for denims !!!
def Denims():
    #1st
    LA=Label(MAIN_WINDOW, text = "Select the most appropriate answer:",justify=LEFT)
    l3=Label(MAIN_WINDOW, text = "1. What is your size?",justify=LEFT)
    l3.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Small',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Medium',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Large',variable=v3,value=3,command=c3).pack(anchor=W)
        
    #2nd
    l4=Label(MAIN_WINDOW, text = "2. What kind of fitting do you prefer?",justify=LEFT)
    l4.pack(anchor=W)
    v3 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Skinny',variable=v3,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Bootcut',variable=v3,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Pegged',variable=v3,value=3,command=c3).pack(anchor=W)
        
        
    #3rd
    l5=Label(MAIN_WINDOW, text = "3. How often do you wear jeans?",justify=LEFT)
    l5.pack(anchor=W)
    v5 = IntVar()
    Radiobutton(MAIN_WINDOW, text='More than once a week',variable=v5,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Once a week',variable=v5,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Once a month',variable=v5,value=3,command=c3).pack(anchor=W)
        
    #4th
    l6=Label(MAIN_WINDOW, text = "4. What colour do you prefer?",justify=LEFT)
    l6.pack(anchor=W)
    v6 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Blue',variable=v6,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='White',variable=v6,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Black',variable=v6,value=3,command=c3).pack(anchor=W)
        
    #5th
    l7=Label(MAIN_WINDOW, text = "5. How often do you buy jeans?",justify=LEFT)
    l7.pack(anchor=W)
    v7 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Whenever I like',variable=v7,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Every few months',variable=v7,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='When my current pair cannot be worn anymore',variable=v7,value=3,command=c3).pack(anchor=W)
        
    #6th
    l8=Label(MAIN_WINDOW, text = "6. What type of jeans do you buy?",justify=LEFT)
    l8.pack(anchor=W)
    v8 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Cheap',variable=v8,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Moderate',variable=v8,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Expensive',variable=v8,value=3,command=c3).pack(anchor=W)
        
    #7th
    l9=Label(MAIN_WINDOW, text = "7. Which is your favourite brand?",justify=LEFT)
    l9.pack(anchor=W)
    v9 = IntVar()
    Radiobutton(MAIN_WINDOW, text='Levis',variable=v9,value=1,command=c1).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='Mufti',variable=v9,value=2,command=c2).pack(anchor=W)
    Radiobutton(MAIN_WINDOW, text='H&M',variable=v9,value=3,command=c3).pack(anchor=W)
    
        
    Button(MAIN_WINDOW, text="Submit", width=10, height=1, bg="white",command=Denims_pro).place(x=300,y=700)
    Button(MAIN_WINDOW, text="Buy", width=10, height=1, bg="white",command=Buy).place(x=400,y=700)

def Denims_pro():
    if (a>b and a>c):
        messagebox.showinfo("Your ideal Jeans:","Levis Blue Highrise Jeans")
    elif (b>c and b>a):
        messagebox.showinfo("Your ideal Jeans:" ,"H&M White Biker Jeans")
    elif (c>a and c>b):
        messagebox.showinfo("Your ideal Jeans:" ,"Mufti Black Slimfit Jeans")
    elif (a==b):
        messagebox.showinfo("Your ideal Jeans:" ,"Tommy Hilfiger Slimfit Jeans")
    elif (b==c):
        messagebox.showinfo("Your ideal Jeans:","Calvin Klein Slimfit Jeans")
    elif (a==c):
        messagebox.showinfo("Your ideal Jeans:" ,"Tommy Hilfiger Ripped Jeans")
    elif (a==b and b==c):
        messagebox.showinfo("Your ideal Jeans:" ,"H&M distressed Jeans") 
        
        
def Buy():
    print("Visit this link to buy your product: https://www.amazon.in/")
        
        
#Function for login screen
def login():
    uname=username.get()
    pwd=password.get()
    if uname=='' or pwd=='':
        message.set("Fill the empty field!!!")
    else:
      if uname=="Chandler" and pwd=="Monica":
        message.set("Login success")
        login_screen.destroy()
        main1()
      else:
       message.set("Wrong username or password!!!")
global login_screen
login_screen = Tk()
#Setting title of screen
login_screen.title("Login Form")
#setting height and width of screen
login_screen.geometry("300x250")
 #declaring variable
global  message
global username
global password
username = StringVar()
password = StringVar()
message=StringVar()
#Creating layout of login form
Label(login_screen,width="300", text="Please enter details below", bg="deep sky blue",fg="white").pack()
    #Username Label
Label(login_screen, text="Username * ").place(x=20,y=40)
    #Username textbox
Entry(login_screen, textvariable=username).place(x=90,y=42)
    #Password Label
Label(login_screen, text="Password * ").place(x=20,y=80)
    #Password textbox
Entry(login_screen, textvariable=password ,show="*").place(x=90,y=82)
 #Label for displaying login status[success/failed]
Label(login_screen, text="",textvariable=message).place(x=95,y=100)
    #Login button
Button(login_screen, text="Login", width=10, height=1, bg="white",command=login).place(x=105,y=130)
login_screen.mainloop()
#calling function Loginform