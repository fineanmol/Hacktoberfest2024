from tkinter import *

window = Tk()
window.title("Multipurpose Calculator")
window.configure(bg="black")

l1 = Label(bg="black", fg="orange", width=40,  text="What would u like to do?", font=("Arial", 15))
l1.grid(row=0, column=0, pady=10)


def opencalci():
    windo = Toplevel()
    windo.title("Calculator")
    windo.configure(bg="cyan")
    work = Entry(windo, width=39, bg="black", fg="white", font=("arial", 15))
    work.grid(row=0, column=0, columnspan=5, pady=7, padx=5, sticky=W)

    def nubtn(x):
        curr = work.get()
        work.delete(0, END)
        work.insert(0, str(curr) + str(x))

    but1 = Button(windo, text="1", font=(None, 15), bg="black", fg="magenta", padx=30, pady=17,
                  command=lambda: nubtn(1))
    but2 = Button(windo, text="2", font=(None, 15), bg="black", fg="magenta", padx=30, pady=17,
                  command=lambda: nubtn(2))
    but3 = Button(windo, text="3", bg="black", font=(None, 15), fg="magenta", padx=30, pady=17,
                  command=lambda: nubtn(3))
    but4 = Button(windo, text="4", bg="black", font=(None, 15), fg="magenta", padx=30, pady=17,
                  command=lambda: nubtn(4))
    but5 = Button(windo, text="5", bg="black", font=(None, 15), fg="magenta", padx=30, pady=17,
                  command=lambda: nubtn(5))
    but6 = Button(windo, text="6", bg="black", font=(None, 15), fg="magenta", padx=30, pady=17,
                  command=lambda: nubtn(6))
    but7 = Button(windo, text="7", bg="black", font=(None, 15), fg="magenta", padx=30, pady=18,
                  command=lambda: nubtn(7))
    but8 = Button(windo, text="8", bg="black", font=(None, 15), fg="magenta", padx=30, pady=18,
                  command=lambda: nubtn(8))
    but9 = Button(windo, text="9", bg="black", font=(None, 15), fg="magenta", padx=30, pady=18,
                  command=lambda: nubtn(9))
    but0 = Button(windo, text="0", bg="black", font=(None, 15), fg="magenta", padx=30, pady=17,
                  command=lambda: nubtn(0))

    but1.grid(row=3, column=0)
    but2.grid(row=3, column=1)
    but3.grid(row=3, column=2)

    but4.grid(row=2, column=0)
    but5.grid(row=2, column=1)
    but6.grid(row=2, column=2)

    but7.grid(row=1, column=0)
    but8.grid(row=1, column=1)
    but9.grid(row=1, column=2)

    but0.grid(row=4, column=0)

    def clrb():
        work.delete(0, END)

    butc = Button(windo, text="CLEAR", bg="black", font=(None, 16), fg="magenta", padx=41, pady=18, command=clrb)
    butc.grid(row=1, column=3, columnspan=2)

    fn = None
    sta = 0

    def addb():
        global fn
        global sta
        sta = float(work.get())
        work.delete(0, END)
        fn = "+"

    butad = Button(windo, text="+", bg="black", fg="magenta", font=(None, 22), padx=22, pady=45, command=addb)
    butad.grid(row=2, column=3, rowspan=2, columnspan=1)

    def minb():
        global fn
        global sta
        sta = float(work.get())
        work.delete(0, END)
        fn = "-"

    butmn = Button(windo, text="-", bg="black", fg="magenta", font=(None, 25), padx=20, pady=4, command=minb)
    butmn.grid(row=2, column=4, rowspan=1, columnspan=1)

    def divb():
        global fn
        global sta
        sta = float(work.get())
        work.delete(0, END)
        fn = "/"

    butdiv = Button(windo, text="DIVIDE", bg="black", font=(None, 16), fg="magenta", padx=40, pady=17, command=divb)
    butdiv.grid(row=4, column=3, columnspan=2)

    def multb():
        global fn
        global sta
        sta = float(work.get())
        work.delete(0, END)
        fn = "X"

    butmult = Button(windo, text="X", bg="black", fg="magenta", font=(None, 15), padx=25, pady=17, command=multb)
    butmult.grid(row=3, column=4, rowspan=1, columnspan=1)

    def eqb():
        global fn
        global sta
        later = float(work.get())
        if fn == "+":
            final = sta + later
        elif fn == "-":
            final = sta - later
        elif fn == "/":
            final = sta / later
        elif fn == "X":
            final = sta * later
        final = round(final, 4)
        work.delete(0, END)
        work.insert(0, final)
        sta = 0
        fn = None

    buteq = Button(windo, text="=", bg="black", fg="magenta", font=(None, 16), padx=73, pady=16, command=eqb)
    buteq.grid(row=4, column=1, rowspan=1, columnspan=2)



butcalc = Button(window, bg="red", fg="white", text="Open Calculator", font=("Arial", 15), padx=6, pady=2, command=opencalci)
butcalc.grid(row=1, column=0)


def open3x3():
    windo3 = Toplevel()
    windo3.title("Equation Solver(3x3)")
    windo3.configure(background="red")

    intro = Label(windo3, width=32, background="blue", fg="yellow", text="Enter The Equation Parameters",
                  font=(None, 16))
    intro.grid(row=0, column=0, columnspan=8)

    a1 = Entry(windo3, width=3, background="white")
    a2 = Entry(windo3, width=3, background="white")
    a3 = Entry(windo3, width=3, background="white")
    a4 = Entry(windo3, width=3, background="white")
    a5 = Entry(windo3, width=3, background="white")
    a6 = Entry(windo3, width=3, background="white")
    a7 = Entry(windo3, width=3, background="white")
    a8 = Entry(windo3, width=3, background="white")
    a9 = Entry(windo3, width=3, background="white")
    a10 = Entry(windo3, width=3, background="white")
    a11 = Entry(windo3, width=3, background="white")
    a12 = Entry(windo3, width=3, background="white")

    lx = Label(windo3, width=4, background="red", fg="black", text="x  +", font=(None, 19))
    ly = Label(windo3, width=4, background="red", fg="black", text="y  +", font=(None, 19))
    lz = Label(windo3, width=2, background="red", fg="black", text=" z", font=(None, 19))
    le = Label(windo3, width=2, background="red", fg="black", text="= ", font=(None, 19))

    lx1 = Label(windo3, width=4, background="red", fg="black", text="x  +", font=(None, 19))
    ly1 = Label(windo3, width=4, background="red", fg="black", text="y  +", font=(None, 19))
    lz1 = Label(windo3, width=2, background="red", fg="black", text=" z", font=(None, 19))
    le1 = Label(windo3, width=2, background="red", fg="black", text="= ", font=(None, 19))

    lx2 = Label(windo3, width=4, background="red", fg="black", text="x  +", font=(None, 19))
    ly2 = Label(windo3, width=4, background="red", fg="black", text="y  +", font=(None, 19))
    lz2 = Label(windo3, width=2, background="red", fg="black", text=" z", font=(None, 19))
    le2 = Label(windo3, width=2, background="red", fg="black", text="= ", font=(None, 19))

    a1.grid(row=1, column=0)
    lx.grid(row=1, column=1)
    a2.grid(row=1, column=2)
    ly.grid(row=1, column=3)
    a3.grid(row=1, column=4)
    lz.grid(row=1, column=5)
    le.grid(row=1, column=6)
    a4.grid(row=1, column=7)

    a5.grid(row=2, column=0)
    lx1.grid(row=2, column=1)
    a6.grid(row=2, column=2)
    ly1.grid(row=2, column=3)
    a7.grid(row=2, column=4)
    lz1.grid(row=2, column=5)
    le1.grid(row=2, column=6)
    a8.grid(row=2, column=7)

    a9.grid(row=3, column=0)
    lx2.grid(row=3, column=1)
    a10.grid(row=3, column=2)
    ly2.grid(row=3, column=3)
    a11.grid(row=3, column=4)
    lz2.grid(row=3, column=5)
    le2.grid(row=3, column=6)
    a12.grid(row=3, column=7)

    global answr
    answr = Entry(windo3, width=21, background="blue", fg="yellow", font=(None, 13))
    answr.grid(row=4, column=2, columnspan=4)

    def calci():
        x1 = int(a1.get())
        y1 = int(a2.get())
        z1 = int(a3.get())
        x2 = int(a5.get())
        y2 = int(a6.get())
        z2 = int(a7.get())
        x3 = int(a9.get())
        y3 = int(a10.get())
        z3 = int(a11.get())

        d1 = int(a4.get())
        d2 = int(a8.get())
        d3 = int(a12.get())

        D = x1 * ((y2 * z3) - (z2 * y3)) - y1 * ((x2 * z3) - (x3 * z2)) + z1 * ((x2 * y3) - (y2 * x3))
        D1 = d1 * ((y2 * z3) - (z2 * y3)) - y1 * ((d2 * z3) - (d3 * z2)) + z1 * ((d2 * y3) - (y2 * d3))
        D2 = x1 * ((d2 * z3) - (z2 * d3)) - d1 * ((x2 * z3) - (x3 * z2)) + z1 * ((x2 * d3) - (d2 * x3))
        D3 = x1 * ((y2 * d3) - (d2 * y3)) - y1 * ((x2 * d3) - (x3 * d2)) + d1 * ((x2 * y3) - (y2 * x3))

        x = round(D1 / D, 2)
        y = round(D2 / D, 2)
        z = round(D3 / D, 2)
        answer = f"x = {x}, y = {y}, z = {z}"
        answr.insert(0, answer)

        print(D, D1, D2, D3)

    calcb = Button(windo3, text="CALCULATE", bg="black", font=(None, 9), fg="cyan", padx=1, pady=3, command=calci)
    calcb.grid(row=4, column=0, columnspan=2)

    def clear():
        a1.delete(0, END)
        a2.delete(0, END)
        a3.delete(0, END)
        a4.delete(0, END)
        a5.delete(0, END)
        a6.delete(0, END)
        a7.delete(0, END)
        a8.delete(0, END)
        a9.delete(0, END)
        a10.delete(0, END)
        a11.delete(0, END)
        a12.delete(0, END)
        answr.delete(0, END)

    clearb = Button(windo3, text="CLEAR", bg="black", font=(None, 9), fg="cyan", padx=1, pady=3, command=clear)
    clearb.grid(row=4, column=7, columnspan=2)

but3x3 = Button(window, bg="red", fg="white", text="Solve a 3 Variable Equation", font=("Arial", 15), padx=6, pady=2, command=open3x3)
but3x3.grid(row=2, column=0, pady=10)

def open2x2():
    windo2 = Toplevel()
    windo2.title("Equation Solver(2X2")
    windo2.configure(bg="blue")

    intro = Label(windo2, width=28, background="pink", fg="black", text="Enter The Equation Parameters",
                  font=(None, 14))
    intro.grid(row=0, column=0, columnspan=9)
    a1 = Entry(windo2, width=3, background="white")
    a2 = Entry(windo2, width=3, background="white")
    a3 = Entry(windo2, width=3, background="white")
    a4 = Entry(windo2, width=3, background="white")
    a5 = Entry(windo2, width=3, background="white")
    a6 = Entry(windo2, width=3, background="white")

    lx = Label(windo2, width=4, background="blue", fg="lime", text="x  +", font=(None, 23))
    ly = Label(windo2, width=3, background="blue", fg="lime", text="y  =", font=(None, 23))

    lx1 = Label(windo2, width=4, background="blue", fg="lime", text="x  +", font=(None, 23))
    ly1 = Label(windo2, width=3, background="blue", fg="lime", text="y  =", font=(None, 23))

    a1.grid(row=1, column=0)
    lx.grid(row=1, column=1)
    a2.grid(row=1, column=2)
    ly.grid(row=1, column=3)
    a3.grid(row=1, column=4)

    a4.grid(row=2, column=0)
    lx1.grid(row=2, column=1)
    a5.grid(row=2, column=2)
    ly1.grid(row=2, column=3)
    a6.grid(row=2, column=4)
    global answr2
    answr2 = Entry(windo2, width=17, background="pink", fg="black", font=(None, 10))
    answr2.grid(row=3, column=1, columnspan=8)

    def calci2():
        x1 = int(a1.get())
        y1 = int(a2.get())
        d1 = int(a3.get())
        x2 = int(a4.get())
        y2 = int(a5.get())
        d2 = int(a6.get())

        D = x1 * y2 - x2 * y1
        D1 = d1 * y2 - d2 * y1
        D2 = x1 * d2 - x2 * d1

        x = round(D1 / D, 2)
        y = round(D2 / D, 2)
        answer2 = f"x={x}, y={y}"
        answr2.insert(0, answer2)

    butcal = Button(windo2, text="CALCULATE", bg="black", font=(None, 9), fg="magenta", padx=1, pady=1, command=calci2)
    butcal.grid(row=3, column=0, columnspan=2)

    def clear2():
        a1.delete(0, END)
        a2.delete(0, END)
        a3.delete(0, END)
        a4.delete(0, END)
        a5.delete(0, END)
        a6.delete(0, END)

    butclr2 = Button(windo2, bg="black", fg="magenta", text="CLEAR", padx=1, pady=1, font=(None, 10), command=clear2)
    butclr2.grid(row=3, column=5)
but2x2 = Button(window, bg="red", fg="white", text="Solve a 2 Variable Equation", font=("Arial", 15), padx=6, pady=2, command=open2x2)
but2x2.grid(row=3, column=0)


def hcf():
    windoh = Toplevel()
    windoh.title("Find HCF")
    windoh.configure(bg="violet")

    l1h = Label(windoh, bg="brown", fg="pink", text="Enter the Space Separated Numbers Below :", width=39,
                font=(None, 12))
    l1h.grid(row=0, column=0, columnspan=2)

    global findh
    findh = Entry(windoh, width=30, font=(None, 13), fg="brown", bg="pink")
    findh.grid(row=1, column=0, pady=20, columnspan=2)

    answrh = Entry(windoh, width=10, font=(None, 13), fg="pink", bg="brown")
    answrh.grid(row=2, column=1)

    def calcih():
        numsh = findh.get()
        a = numsh.split(" ")
        b = list(map(int, a))

        b.sort()
        i = 1
        global hcf
        hcf = 1

        while i <= b[0]:
            cnt = 0

            for j in b:
                if j % i == 0:
                    cnt += 1

            if cnt == len(b):
                hcf = i

            i += 1

        answrh.delete(0, END)
        answrh.insert(0, hcf)

    hcfcalc = Button(windoh, text="CALCULATE", bg="black", font=(None, 10), fg="lime", padx=1, pady=1, command=calcih)
    hcfcalc.grid(row=2, column=0)

findhb = Button(window, bg="red", fg="white", text="Find an HCF", font=("Arial", 15), padx=6, pady=2, command=hcf)
findhb.grid(row=4, column=0, pady=10)


def lcm():
    windol = Toplevel()
    windol.title("Find LCM")
    windol.configure(bg="lime")

    l1l = Label(windol, bg="green", fg="yellow", text="Enter the Space Separated Numbers Below :", width=39,
                font=(None, 12))
    l1l.grid(row=0, column=0, columnspan=2)

    global findl
    findl = Entry(windol, width=30, font=(None, 13), fg="green", bg="yellow")
    findl.grid(row=1, column=0, pady=20, columnspan=2)

    global answrl
    answrl = Entry(windol, width=10, font=(None, 13), fg="yellow", bg="green")
    answrl.grid(row=2, column=1)

    def calcil():
        numsh = findl.get()
        a = numsh.split(" ")
        b = list(map(int, a))

        b.sort()

        bigg = b[len(b) - 1]

        i = bigg

        prod = 1
        for j in b:
            prod *= j

        while i <= prod:
            cnt = 0

            for j in b:
                if i % j == 0:
                    cnt += 1

            if cnt == len(b):
                lm = i
                break

            i += bigg

        answrl.delete(0, END)
        answrl.insert(0, lm)

    lcmb = Button(windol, text="CALCULATE", bg="black", font=(None, 10), fg="pink", padx=1, pady=1, command=calcil)
    lcmb.grid(row=2, column=0)

findlb = Button(window, bg="red", fg="white", text="Find an LCM", font=("Arial", 15), padx=6, pady=2, command=lcm)
findlb.grid(row=5, column=0)



window.mainloop()
