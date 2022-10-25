import tkinter as tk
from PIL import ImageTk, Image
import os
# from bank import Bank

#Main screen
master = tk.Tk()
master.title('Banking App')


#Image import
raw_img = Image.open('GUI/assests/bank.png')
img = raw_img.resize((150,150))
img = ImageTk.PhotoImage(img)

#Labels
titlelabel= tk.Label(master,text="Custom Banking App", image= img,font=('Calibri',14))
titlelabel.grid(row=0,sticky =None,pady=10)

master.mainloop()

