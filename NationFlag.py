from tkinter import *
from tkinter.messagebox import *

fw = Tk()
fw.title("Weight Converter!")
fw.geometry("600x600+100+100")
f = ("Arial", 20, "bold")
fw.configure(bg="powder blue")

def f1():
    fw.withdraw()
    sw.deiconify()

def f2():
    sw.withdraw()
    fw.deiconify()

def f3():
    fw.withdraw()
    pw.deiconify()

def f4():
    pw.withdraw()
    fw.deiconify()

def convert():
    input_value = ent_value.get()
    if not input_value or input_value == "":
        showerror("Issue", "Weight cannot be empty")
        return
    try:
        pound = float(input_value)
        if pound < 0:
            showerror("Issue", "Weight cannot be negative")
            return
        if pound < 0.01 or pound > 1000:
            showerror("Issue", "Weight should be between 0.01 to 1000")
            return
    except ValueError:
        showerror("Issue", "It must be a valid number.")  #this is for special characters
        return

    kilograms = pound * 0.453592
    ent_pnd.delete(0, END)
    ent_pnd.insert(0, kilograms)

def convert1():
    input_value = ent_value1.get()
    if not input_value:
        showerror("Issue", "Kilograms cannot be empty")
        return
    try:
        kilogram = float(input_value)
        if kilogram < 0:
            showerror("Issue", "Kilograms cannot be negative")
            return
        if kilogram < 0.01 or kilogram > 1000:
            showerror("Issue", "Weight should be between 0.01 to 1000")
            return
    except ValueError:
        showerror("Issue", "Kilograms must be a valid number.")
        return

    pounds = kilogram * 2.20462
    ent_kg.delete(0, END)
    ent_kg.insert(0, pounds)

lab_head = Label(fw, text="Weight Converter!", font=f)
lab_head.pack(pady=10)
btn_ptg = Button(fw, text="Pounds to Kilograms", font=f, command=f1)
btn_ptg.pack(pady=20)
btn_ktl = Button(fw, text="Kilograms to Pounds", font=f, command=f3)
btn_ktl.pack(pady=20)

sw = Tk()
sw.title("Pounds to Kilograms")
sw.geometry("600x600+100+100")
f = ("Arial", 20, "bold")
sw.configure(bg="light yellow")

lab_ptg = Label(sw, text="Pounds to Kilograms", font=f)
lab_ptg.pack(pady=20)
lab_value = Label(sw, text="Enter the Value in Pounds:", font=f)
lab_value.pack(pady=20)
ent_value = Entry(sw, font=f)
ent_value.pack(pady=20)
btn_convert = Button(sw, text="Convert", font=f, command=convert)
btn_convert.pack(pady=20)
btn_back = Button(sw, text="Back", font=f, command=f2)
btn_back.pack(pady=20)
lab_kg = Label(sw, text="In Kilograms:", font=f)
lab_kg.pack(pady=20)
ent_pnd = Entry(sw, font=f)
ent_pnd.pack(pady=20)

pw = Tk()
pw.title("Kilograms to Pounds")
pw.geometry("600x600+100+100")
f = ("Arial", 20, "bold")
pw.configure(bg="light gray")

lab_ptl = Label(pw, text="Kilograms to Pounds", font=f)
lab_ptl.pack(pady=20)
lab_value1 = Label(pw, text="Enter the Value in Kilograms:", font=f)
lab_value1.pack(pady=20)
ent_value1 = Entry(pw, font=f)
ent_value1.pack(pady=20)
btn_convert1 = Button(pw, text="Convert", font=f, command=convert1)
btn_convert1.pack(pady=20)
btn_back = Button(pw, text="Back", font=f, command=f4)
btn_back.pack(pady=20)
lab_pnd = Label(pw, text="In Pounds:", font=f)
lab_pnd.pack(pady=20)
ent_kg = Entry(pw, font=f)
ent_kg.pack(pady=20)

def f():
    if askokcancel("Quit", "Do you want to exit?"):
        fw.destroy()
        sw.destroy()
        pw.destroy()

fw.protocol("WM_DELETE_WINDOW", f)
sw.protocol("WM_DELETE_WINDOW", f)
pw.protocol("WM_DELETE_WINDOW", f)

fw.mainloop()
