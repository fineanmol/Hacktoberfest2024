# calculator having frame doing following operations
# addition,substraction,division,multiplication
# trignometric value , square root , power

from tkinter import *
from math import *

root= Tk()
root.title("CALCULATOR")
root.geometry("372x367")

back_g = Label(root,bg="#3498DB")
back_g.place(relheight=1,relwidth=1)

frame = Frame(root,bg="#99AAAB")
frame.place(relx=0.049,rely=0.05,relheight=0.9,relwidth=0.9)

var1=var2=operator=0


def number (num) :

    number = str(ent_num.get())+str(num)
    ent_num.delete(0,END)
    ent_num.insert(0,number)


def but_fun (option) :

    if option == 999 :
        
        ent_num.delete(0,END)
    
    elif option == 402 :

        if globals()["operator"] in [101,102,103,104,303,401] :

            globals()["var2"] = int(ent_num.get())
            ent_num.delete(0,END)

            if globals()["operator"] == 101 :
                result = globals()["var1"] + globals()["var2"]
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 102 :
                result = globals()["var1"] - globals()["var2"]
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 103 :
                result = globals()["var1"] * globals()["var2"]
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 104 :
                result = globals()["var1"] / globals()["var2"]
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 303 :
                result = pow(globals()["var1"],globals()["var2"])
                ent_num.insert(0,str(result))

          
            elif globals()["operator"] == 401 :
                result = ( globals()["var1"] * (pow(10,globals()["var2"])))
                ent_num.insert(0,str(result))

        else:

            if globals()["operator"] == 201 :
                result = sin(globals()["var1"])
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 202 :
                result = cos(globals()["var1"])
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 203 :
                result = tan(globals()["var1"])
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 204 :
                result = log10(globals()["var1"])
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 301 :
                result = pow(globals()["var1"],2)
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 302 :
                result = sqrt(globals()["var1"])
                ent_num.insert(0,str(result))

            elif globals()["operator"] == 304 :
                result = factorial(int(globals()["var1"]))
                ent_num.insert(0,str(result))
            
        globals()["operator"] = 0

    else :
        
        if option == 101 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 102 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 103 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 104 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 303 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 304 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 401 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)
        
        elif option == 201 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 202 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 203 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 204 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)

        elif option == 301 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)
            
        elif option == 302 :
            globals()["var1"] = int(ent_num.get())
            globals()["operator"] = option
            ent_num.delete(0,END)


# button and entry creation

but_0 = Button(frame,text="0",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(0))
but_1 = Button(frame,text="1",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(1))
but_2 = Button(frame,text="2",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(2))
but_3 = Button(frame,text="3",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(3))
but_4 = Button(frame,text="4",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(4))
but_5 = Button(frame,text="5",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(5))
but_6 = Button(frame,text="6",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(6))
but_7 = Button(frame,text="7",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(7))
but_8 = Button(frame,text="8",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(8))
but_9 = Button(frame,text="9",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:number(9))

but_add = Button(frame,text="+",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(101))
but_sub = Button(frame,text="-",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(102))
but_mul = Button(frame,text="x",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(103))
but_div = Button(frame,text="÷",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(104))

but_sin = Button(frame,text="sin",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(201))
but_cos = Button(frame,text="cos",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(202))
but_tan = Button(frame,text="tan",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(203))
but_log = Button(frame,text="log",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(204))

but_sqq = Button(frame,text="a²",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(301))
but_sqr = Button(frame,text="√a",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(302))
but_pow = Button(frame,text="aΛn",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(303))
but_fac = Button(frame,text="!",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(304))

but_m10 = Button(frame,text="x10",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(401))
but_equ = Button(frame,text="=",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(402))
but_cle = Button(frame,text="<<",bg="#2C3335",fg="#616C6F",activeforeground="#758AA2",activebackground="#47535E",font=("acme",20),command=lambda:but_fun(999))

ent_num = Entry(frame,bg="#333945",fg="#01CBC6",font=("acme",35))


# button and entry placing

ent_num.place(x=15,y=20,width=250,height=70)
but_cle.place(x=280,y=20,width=50,height=70)

but_7.place(x=5 ,y=110 ,width=50 ,height=50)
but_8.place(x=60 ,y=110 ,width=50 ,height=50)
but_9.place(x=115 ,y=110 ,width=50 ,height=50)
but_add.place(x=170 ,y=110 ,width=50 ,height=50)
but_sin.place(x=225 ,y=110 ,width=50 ,height=50)
but_sqq.place(x=280 ,y=110 ,width=50 ,height=50)

but_4.place(x=5 ,y=165 ,width=50 ,height=50)
but_5.place(x=60 ,y=165 ,width=50 ,height=50)
but_6.place(x=115 ,y=165 ,width=50 ,height=50)
but_sub.place(x=170 ,y=165 ,width=50 ,height=50)
but_cos.place(x=225 ,y=165 ,width=50 ,height=50)
but_sqr.place(x=280 ,y=165 ,width=50 ,height=50)

but_1.place(x=5 ,y=220 ,width=50 ,height=50)
but_2.place(x=60 ,y=220 ,width=50 ,height=50)
but_3.place(x=115 ,y=220 ,width=50 ,height=50)
but_div.place(x=170 ,y=220 ,width=50 ,height=50)
but_tan.place(x=225 ,y=220 ,width=50 ,height=50)
but_pow.place(x=280 ,y=220 ,width=50 ,height=50)

but_0.place(x=5 ,y=275 ,width=50 ,height=50)
but_m10.place(x=60 ,y=275 ,width=50 ,height=50)
but_equ.place(x=115 ,y=275 ,width=50 ,height=50)
but_mul.place(x=170 ,y=275 ,width=50 ,height=50)
but_log.place(x=225 ,y=275 ,width=50 ,height=50)
but_fac.place(x=280 ,y=275 ,width=50 ,height=50)


root.mainloop()
