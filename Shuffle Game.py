#Shuffle Game

import tkinter as gui
from tkinter import messagebox;
import random


app=gui.Tk()
app.geometry('650x400')
app.title('Shuffle Game')

app.configure(bg='#ABC8F7')


def check():
    if b1.cget('text')=='1' and b2.cget('text')=='2' and b3.cget('text')=='3'\
        and b4.cget('text')=='4' and b5.cget('text')=='5' and b6.cget('text')=='6'\
        and b7.cget('text')=='7' and b8.cget('text')=='8' and b9.cget('text')=='9'\
        and b10.cget('text')=='10' and b11.cget('text')=='11'\
        and b12.cget('text')=='12' and b13.cget('text')=='13'\
        and b14.cget('text')=='14' and b15.cget('text')=='15'\
        and b16.cget('text')=='':
        
        b16.configure(text='16')
        
        gui.messagebox.showinfo('Shuffle Game','Congratulations! You have won!\nMoves : {}'.format(moves.cget('text')))
        startbtn.configure(text='Play Again')
    else:
        pass

def b1_click():
    if b2.cget('text')=='':
        temp=b1.cget('text')
        b1.configure(text=b2.cget('text'))
        b2.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b5.cget('text')=='':
        temp=b1.cget('text')
        b1.configure(text=b5.cget('text'))
        b5.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    
    check()
    
def b2_click():
    if b1.cget('text')=='':
        temp=b2.cget('text')
        b2.configure(text=b1.cget('text'))
        b1.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b3.cget('text')=='':
        temp=b2.cget('text')
        b2.configure(text=b3.cget('text'))
        b3.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b6.cget('text')=='':
        temp=b2.cget('text')
        b2.configure(text=b6.cget('text'))
        b6.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b3_click():
    if b2.cget('text')=='':
        temp=b3.cget('text')
        b3.configure(text=b2.cget('text'))
        b2.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b4.cget('text')=='':
        temp=b3.cget('text')
        b3.configure(text=b4.cget('text'))
        b4.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b7.cget('text')=='':
        temp=b3.cget('text')
        b3.configure(text=b7.cget('text'))
        b7.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()

def b4_click():
    if b3.cget('text')=='':
        temp=b4.cget('text')
        b4.configure(text=b3.cget('text'))
        b3.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b8.cget('text')=='':
        temp=b4.cget('text')
        b4.configure(text=b8.cget('text'))
        b8.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b5_click():
    if b1.cget('text')=='':
        temp=b5.cget('text')
        b5.configure(text=b1.cget('text'))
        b1.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b9.cget('text')=='':
        temp=b5.cget('text')
        b5.configure(text=b9.cget('text'))
        b9.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b6.cget('text')=='':
        temp=b5.cget('text')
        b5.configure(text=b6.cget('text'))
        b6.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b6_click():
    if b2.cget('text')=='':
        temp=b6.cget('text')
        b6.configure(text=b2.cget('text'))
        b2.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b5.cget('text')=='':
        temp=b6.cget('text')
        b6.configure(text=b5.cget('text'))
        b5.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b7.cget('text')=='':
        temp=b6.cget('text')
        b6.configure(text=b7.cget('text'))
        b7.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b10.cget('text')=='':
        temp=b6.cget('text')
        b6.configure(text=b10.cget('text'))
        b10.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b7_click():
    if b8.cget('text')=='':
        temp=b7.cget('text')
        b7.configure(text=b8.cget('text'))
        b8.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b3.cget('text')=='':
        temp=b7.cget('text')
        b7.configure(text=b3.cget('text'))
        b3.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b6.cget('text')=='':
        temp=b7.cget('text')
        b7.configure(text=b6.cget('text'))
        b6.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b11.cget('text')=='':
        temp=b7.cget('text')
        b7.configure(text=b11.cget('text'))
        b11.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b8_click():
    if b7.cget('text')=='':
        temp=b8.cget('text')
        b8.configure(text=b7.cget('text'))
        b7.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b4.cget('text')=='':
        temp=b8.cget('text')
        b8.configure(text=b4.cget('text'))
        b4.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b12.cget('text')=='':
        temp=b8.cget('text')
        b8.configure(text=b12.cget('text'))
        b12.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b9_click():
    if b5.cget('text')=='':
        temp=b9.cget('text')
        b9.configure(text=b5.cget('text'))
        b5.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b10.cget('text')=='':
        temp=b9.cget('text')
        b9.configure(text=b10.cget('text'))
        b10.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b13.cget('text')=='':
        temp=b9.cget('text')
        b9.configure(text=b13.cget('text'))
        b13.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b10_click():
    if b9.cget('text')=='':
        temp=b10.cget('text')
        b10.configure(text=b9.cget('text'))
        b9.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b11.cget('text')=='':
        temp=b10.cget('text')
        b10.configure(text=b11.cget('text'))
        b11.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b6.cget('text')=='':
        temp=b10.cget('text')
        b10.configure(text=b6.cget('text'))
        b6.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b14.cget('text')=='':
        temp=b10.cget('text')
        b10.configure(text=b14.cget('text'))
        b14.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b11_click():
    if b7.cget('text')=='':
        temp=b11.cget('text')
        b11.configure(text=b7.cget('text'))
        b7.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b10.cget('text')=='':
        temp=b11.cget('text')
        b11.configure(text=b10.cget('text'))
        b10.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b12.cget('text')=='':
        temp=b11.cget('text')
        b11.configure(text=b12.cget('text'))
        b12.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b15.cget('text')=='':
        temp=b11.cget('text')
        b11.configure(text=b15.cget('text'))
        b15.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b12_click():
    if b8.cget('text')=='':
        temp=b12.cget('text')
        b12.configure(text=b8.cget('text'))
        b8.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b11.cget('text')=='':
        temp=b12.cget('text')
        b12.configure(text=b11.cget('text'))
        b11.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b16.cget('text')=='':
        temp=b12.cget('text')
        b12.configure(text=b16.cget('text'))
        b16.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b13_click():
    if b9.cget('text')=='':
        temp=b13.cget('text')
        b13.configure(text=b9.cget('text'))
        b9.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b14.cget('text')=='':
        temp=b13.cget('text')
        b13.configure(text=b14.cget('text'))
        b14.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b14_click():
    if b13.cget('text')=='':
        temp=b14.cget('text')
        b14.configure(text=b13.cget('text'))
        b13.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b10.cget('text')=='':
        temp=b14.cget('text')
        b14.configure(text=b10.cget('text'))
        b10.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b15.cget('text')=='':
        temp=b14.cget('text')
        b14.configure(text=b15.cget('text'))
        b15.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()
    
def b15_click():
    if b14.cget('text')=='':
        temp=b15.cget('text')
        b15.configure(text=b14.cget('text'))
        b14.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b16.cget('text')=='':
        temp=b15.cget('text')
        b15.configure(text=b16.cget('text'))
        b16.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    elif b11.cget('text')=='':
        temp=b15.cget('text')
        b15.configure(text=b11.cget('text'))
        b11.configure(text=temp)
        moves.configure(text= moves.cget('text')+1)
    else:
        pass
    check()

def b16_click():
    if b12.cget('text')=='':
        temp=b16.cget('text')
        b16.configure(text=b12.cget('text'))
        b12.configure(text=temp)
        moves.configure(text=moves.cget('text')+1)
    elif b15.cget('text')=='':
        temp=b16.cget('text')
        b16.configure(text=b15.cget('text'))
        b15.configure(text=temp)
        moves.configure(text=moves.cget('text')+1)
    else:
        pass
    check()

def start():
    nums=['','1','2','3','4','5','6','7','8','9',
          '10','11','12','13','14','15']
    b1.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b1.cget('text'))
    b2.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b2.cget('text'))
    b3.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b3.cget('text'))
    b4.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b4.cget('text'))
    b5.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b5.cget('text'))
    b6.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b6.cget('text'))
    b7.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b7.cget('text'))
    b8.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b8.cget('text'))
    b9.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b9.cget('text'))
    b10.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b10.cget('text'))
    b11.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b11.cget('text'))
    b12.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b12.cget('text'))
    b13.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b13.cget('text'))
    b14.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b14.cget('text'))
    b15.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b15.cget('text'))
    b16.configure(text=random.choice(nums),state=gui.NORMAL)
    nums.remove(b16.cget('text'))
    
    startbtn.configure(text='Restart')
    moves.configure(text=0)
    solvebtn['state']=gui.NORMAL
    
def solve():
    b1.configure(text='1')
    b2.configure(text='2')
    b3.configure(text='3')
    b4.configure(text='4')
    b5.configure(text='5')
    b6.configure(text='6')
    b7.configure(text='7')
    b8.configure(text='8')
    b9.configure(text='9')
    b10.configure(text='10')
    b11.configure(text='11')
    b12.configure(text='12')
    b13.configure(text='13')
    b14.configure(text='14')
    b15.configure(text='15')
    b16.configure(text='')
    check()

b1=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b1_click,state=gui.DISABLED)
b1.place(x=50,y=50)

b2=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b2_click,state=gui.DISABLED)
b2.place(x=120,y=50)

b3=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b3_click,state=gui.DISABLED)
b3.place(x=190,y=50)

b4=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b4_click,state=gui.DISABLED)
b4.place(x=260,y=50)

b5=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b5_click,state=gui.DISABLED)
b5.place(x=50,y=120)

b6=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b6_click,state=gui.DISABLED)
b6.place(x=120,y=120)

b7=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b7_click,state=gui.DISABLED)
b7.place(x=190,y=120)

b8=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b8_click,state=gui.DISABLED)
b8.place(x=260,y=120)

b9=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b9_click,state=gui.DISABLED)
b9.place(x=50,y=190)

b10=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b10_click,state=gui.DISABLED)
b10.place(x=120,y=190)

b11=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b11_click,state=gui.DISABLED)
b11.place(x=190,y=190)

b12=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b12_click,state=gui.DISABLED)
b12.place(x=260,y=190)

b13=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b13_click,state=gui.DISABLED)
b13.place(x=50,y=260)

b14=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b14_click,state=gui.DISABLED)
b14.place(x=120,y=260)

b15=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b15_click,state=gui.DISABLED)
b15.place(x=190,y=260)

b16=gui.Button(app,text='',width=3,height=1,font=('',26),
               command=b16_click,state=gui.DISABLED)
b16.place(x=260,y=260)

moveslbl=gui.Label(app,text='Moves : ',font=('',18))
moveslbl.configure(bg='#ABC8F7',fg='white')
moves=gui.Label(app,text=0,font=('',18))
moves.configure(bg='#ABC8F7',fg='white')
moveslbl.place(x=450,y=50)
moves.place(x=550,y=50)

startbtn=gui.Button(app,text='Start',width=9,height=1,font=('',16),command=start)
startbtn.place(x=450,y=120)

solvebtn=gui.Button(app,text='Solve',width=9,height=1,font=('',16),command=solve,state=gui.DISABLED)
solvebtn.place(x=450,y=190)

app.mainloop()