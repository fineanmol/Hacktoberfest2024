pip install tkinter
pip install pypng
pip install pyqrcode
import pyqrcode
import png
from pyqrcode import QRCode
import tkinter as tk
from tkinter import *
window = Tk()  
window.geometry('300x350')
window.title('PythonGeeks')
 
Label(window,text='Let’s Create QR Code',font='arial 15').pack()
def create_qrcode():
    s1=s.get()
    qr = pyqrcode.create(s1)
    qr.png('myqr.png', scale = 6)
    Label(window,text='QR Code is created and saved successfully').pack()
  Entry(window,textvariable=s,font='arial 15').pack()
Button(window,text='create',bg='pink',command=create_qrcode).pack()
window.mainloop()
