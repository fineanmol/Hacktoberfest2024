"""
Tkinkter is preinstalled with most python distributions, 
but if not, you need to install it via pip
run: pip install tk
"""


from tkinter import *

root = Tk()
root.title('CalCulAtoR !prO')
k = 63
root.minsize(6*k,4*k)

l1=Label(root, text="Perform calculation on 2 numbers: ")
e = Entry(root, borderwidth=4)
l2 = Label(root, text="Made for the sole purpose of learning Tkinter, by Ujjwal",padx=40)
def click_num(num):
    current = e.get()
    e.insert(len(current),string=num)

def click_oprtn(symbol):
    if symbol == "--":
        e.delete(0,END)
        return
    global num1
    num1=float(e.get())
    e.delete(0,END)
    global oprtn
    oprtn = symbol

def click_eq():
    if oprtn=="+":
        ans = num1 + float(e.get())
    if oprtn=="-":
        ans = num1 - float(e.get())
    if oprtn=="x":
        ans = num1 * float(e.get())
    if oprtn=="/":
        ans = num1 / float(e.get())
    e.delete(0,END)
    if float(ans)==int(ans):
        e.insert(0,int(ans))
    else:
        e.insert(0,float(ans))

b1=Button(root,text=1,command=lambda:click_num(1),padx=30,pady=20)
b2=Button(root,text=2,command=lambda:click_num(2),padx=30,pady=20)
b3=Button(root,text=3,command=lambda:click_num(3),padx=30,pady=20)
b4=Button(root,text=4,command=lambda:click_num(4),padx=30,pady=20)
b5=Button(root,text=5,command=lambda:click_num(5),padx=30,pady=20)
b6=Button(root,text=6,command=lambda:click_num(6),padx=30,pady=20)
b7=Button(root,text=7,command=lambda:click_num(7),padx=30,pady=20)
b8=Button(root,text=8,command=lambda:click_num(8),padx=30,pady=20)
b9=Button(root,text=9,command=lambda:click_num(9),padx=30,pady=20)
badd=Button(root,text="+",command=lambda:click_oprtn("+"),padx=30,pady=20)
bsub=Button(root,text="-",command=lambda:click_oprtn("-"),padx=30,pady=20)
bmul=Button(root,text="x",command=lambda:click_oprtn("x"),padx=30,pady=20)
bdiv=Button(root,text="/",command=lambda:click_oprtn("/"),padx=30,pady=20)
bcls=Button(root,text="Clear",command=lambda:click_oprtn("--"),padx=20,pady=20)
beq=Button(root,text="=",command=click_eq,padx=28.5,pady=20)

l1.grid(row=0,column=0,columnspan=3)
e.grid(row=0,column=4,columnspan=2)
b1.grid(row=3,column=0)
b2.grid(row=3,column=1)
b3.grid(row=3,column=2)
b4.grid(row=2,column=0)
b5.grid(row=2,column=1)
b6.grid(row=2,column=2)
b7.grid(row=1,column=0)
b8.grid(row=1,column=1)
b9.grid(row=1,column=2)

badd.grid(row=3,column=4)
bsub.grid(row=3,column=5)
bmul.grid(row=2,column=4)
bdiv.grid(row=2,column=5)
bcls.grid(row=1,column=4)
beq.grid(row=1,column=5)

l2.grid(row=4, column=0, columnspan=6)

root.mainloop()