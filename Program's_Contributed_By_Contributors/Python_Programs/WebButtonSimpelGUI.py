#Dont forget to import icon path
import webbrowser as wb
import tkinter as tk
from PIL import Image, ImageTk

def button1_click():
    print("Button 1 clicked!")
    wb.open("https://www.google.com/")
def button2_click():
    print("Button 2 clicked!")
    wb.open("https://www.youtube.com/")
def button3_click():
    print("Button 3 clicked!")
    wb.open("https://github.com/")

# Create the main window
window = tk.Tk()

# Load the button icons
button1_icon = ImageTk.PhotoImage(Image.open("<ICON1_PATH>"))
button2_icon = ImageTk.PhotoImage(Image.open("<ICON2_PATH>"))
button3_icon = ImageTk.PhotoImage(Image.open("<ICON3_PATH>"))

# Create the buttons with custom icons
button1 = tk.Button(window, image=button1_icon, command=button1_click)
button2 = tk.Button(window, image=button2_icon, command=button2_click)
button3 = tk.Button(window, image=button3_icon, command=button3_click)

# Pack the buttons to add them to the window
button1.pack()
button2.pack()
button3.pack()

# Start the main event loop
window.mainloop()

