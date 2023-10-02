from tkinter import *
import math

root = Tk()
root.title('CalcX')

e = Entry(root, width=35, borderwidth=4)
e.grid(column=0, row=0, columnspan=3)


def ln():
    s = int(e.get())
    e.delete(0, END)
    try:
        e.insert(0, str(math.log(s)))
    except Exception as z:
        e.insert(0, z)

def fact():
    x = int(e.get())
    e.delete(0, END)
    if x >= 1:
        val = 1
        for i in range(x, 1, -1):
            val *= i
        e.insert(0, str(val))

    else:
        e.insert(0, 'how dumb can you be??!')

def f_num(n):
    x = e.get()
    e.delete(0, END)
    e.insert(0, str(x) + str(n))

def f_clear():
    e.delete(0, END)

def f_op(s = None):
    x = e.get()
    e.delete(0, END)
    global first_n , sign
    try:
        first_n = int(x)
    except:
        e.insert(0, 'Syntax Error')
    sign = s

def f_equal():
    a = e.get()
    e.delete(0, END)
    if a.isnumeric():
        if sign == '+':
                e.insert(0, str(int(a) + first_n))
        elif sign == 'x':
                e.insert(0,str(int(a) * first_n))

        elif sign == '-':
                e.insert(0, str(first_n - int(a)))

        elif sign == '/':
            try:
                e.insert(0, str(first_n/int(a)))
            except:
                e.insert(0, 'Now why would do that..')
        elif sign == 'e':
            e.insert(0, str(first_n**int(a)))

        elif sign == None:
            e.insert(str(a))

    elif a=='':
        pass

    else:
        e.insert(0, 'Syntax Error')


button_1 = Button(root, text='1', command=lambda: f_num(1), padx=40, pady=20)
button_2 = Button(root, text='2', command=lambda: f_num(2), padx=40, pady=20)
button_3 = Button(root, text='3', command=lambda: f_num(3), padx=40, pady=20)
button_4 = Button(root, text='4', command=lambda: f_num(4), padx=40, pady=20)
button_5 = Button(root, text='5', command=lambda: f_num(5), padx=40, pady=20)
button_6 = Button(root, text='6', command=lambda: f_num(6), padx=40, pady=20)
button_7 = Button(root, text='7', command=lambda: f_num(7), padx=40, pady=20)
button_8 = Button(root, text='8', command=lambda: f_num(8), padx=40, pady=20)
button_9 = Button(root, text='9', command=lambda: f_num(9), padx=40, pady=20)
button_0 = Button(root, text='0', command=lambda: f_num(0), padx=40, pady=20)
button_e = Button(root, text='=', command=lambda: f_equal(), padx=39, pady=20)
button_a = Button(root, text='+', command=lambda: f_op('+'), padx=39, pady=20)
button_m = Button(root, text='x', command=lambda: f_op('x'), padx=40, pady=20)
button_d = Button(root, text='/', command=lambda: f_op('/'), padx=40, pady=20)
button_s = Button(root, text='-', command=lambda: f_op('-'), padx=40, pady=20)
button_ln = Button(root, text='ln', command=ln, padx=38, pady=20)
button_fact = Button(root, text='!', command=fact, padx=41, pady=20)
button_exp = Button(root, text='^', command=lambda: f_op('e'), padx=39, pady=20)
button_c = Button(root, text='CLEAR', command=f_clear, padx=125, pady=20)

button_1.grid(column=0, row=1)
button_2.grid(column=1, row=1)
button_3.grid(column=2, row=1)
button_4.grid(column=0, row=2)
button_5.grid(column=1, row=2)
button_6.grid(column=2, row=2)
button_7.grid(column=0, row=3)
button_8.grid(column=1, row=3)
button_9.grid(column=2, row=3)
button_0.grid(column=0, row=4)
button_e.grid(column=1, row=4)
button_a.grid(column=2, row=4)
button_m.grid(column=0, row=5)
button_d.grid(column=1, row=5)
button_s.grid(column=2, row=5)
button_ln.grid(column=0, row=6)
button_fact.grid(column=1, row=6)
button_exp.grid(column=2, row=6)
button_c.grid(column=0, row=7, columnspan=3)

root.mainloop()
