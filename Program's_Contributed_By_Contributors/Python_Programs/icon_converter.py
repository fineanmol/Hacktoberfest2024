#             - Rishaw Kumar

# Image to .ico convertor
from tkinter import *
from tkinter import filedialog

# Main Window
App = Tk()
App.title('Icon Creator')
App.geometry('300x200')


# Selecting the image from a file dialog box
def img_choose():
    from PIL import Image
    global img

    App.img_dir = filedialog.askopenfilename(initialdir='C:', title='Choose an image',
                                             filetypes=(('PNG Icons', '*.png'),
                                                        ('JPG Icons', '*.jpg'),
                                                        ('All files', '*.*')))
    img = Image.open(App.img_dir)


# Convert image to .ico and save it
def img_convt():
    try:
        from PIL import Image

        img.save(f'{icon_name.get()}.ico', format='ICO', sizes=[(ico_size.get(), ico_size.get())])

        compl = Toplevel()
        compl.title('Success')

        msg = Label(compl, text='Icon converted successfully!')
        msg.pack()

        compl.mainloop()
    except:
        compl = Toplevel()
        compl.title('Failure')

        msg = Label(compl, text="Somethin' went wrong!")
        msg.pack()

        compl.mainloop()


# Converted .ico preview
def preview():
    prev = Toplevel()
    prev.title('Icon Preview')
    prev.iconbitmap(f'{icon_name.get()}.ico')

    lbl = Label(prev, text='Check your icon!')
    lbl.pack()

    prev.mainloop()


# Choose label and button
pickL = Label(App, text='Select your image: ')
pickL.grid(row=0, column=0, pady=10)

pickB = Button(App, text='Choose', command=img_choose)
pickB.grid(row=0, column=1, pady=10)

# Icon size label and drop down menu
siz_lbl = Label(App, text='Select the icon size:')
siz_lbl.grid(row=1, column=0, pady=10)

ico_size = IntVar()
sizes = [16, 24, 32, 48, 64, 128, 255]
siz_menu = OptionMenu(App, ico_size, *sizes)
siz_menu.grid(row=1, column=1, pady=10)
ico_size.set(32)

# Icon name label and entry field
nam_lbl = Label(App, text='Enter the icon name: ')
nam_lbl.grid(row=2, column=0, pady=10)

icon_name = Entry(App)
icon_name.grid(row=2, column=1, pady=10)

# Convert button
conB = Button(App, text='Convert', command=img_convt)
conB.grid(row=3, column=0, pady=10)

# Preview button
prevB = Button(App, text='Preview', command=preview)
prevB.grid(row=3, column=1, pady=10)

App.mainloop()
