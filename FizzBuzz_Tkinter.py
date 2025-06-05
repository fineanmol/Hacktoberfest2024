"""

Fizzbuzz implenetation with GUI with the help of Tkinter

Author: @VincentVanTaro

Note: Make sure you have the module Pillow installed.



"""

# initialising the code

from tkinter import *

from tkinter.ttk import *

import time, urllib.request, threading, os, random

from PIL import ImageTk, Image

# configuring the display window

root = Tk()

root.title("Vincent's FizzBuzz")

root.geometry("600x300")

root.resizable(False, False)

root.configure(background="#22d1ee")

# https://imgur.com/a/Qa8mqUG

fizzBuzz = (

    ("Fizz", 23, "#fc5185", "https://i.imgur.com/9KSOPuQ.png"),

    ("Buzz", 25, "#2d6cdf", "https://i.imgur.com/IoLIUyO.png"),

    ("FIZZBUZZ!!", 30, "#fff98c", "https://i.imgur.com/J7VtGjD.png"),

)

# initialsiing the images

directory = os.path.join(os.getcwd(), r"Vincent's FizzyBuzz")

if not os.path.exists(directory):

    os.makedirs(directory)

for i in fizzBuzz:

    urllib.request.urlretrieve(i[3], f"{directory}\{i[0]}.gif")

# choosing the icon randomly from the pictures

iconIMG = ImageTk.PhotoImage(

    Image.open(f"{directory}\{random.choice(fizzBuzz)[0]}.gif")

)

root.iconphoto(False, iconIMG)

# the second in which you want to display the numbers

second = 0.5

# finding all the multiples of 3, 5 and 15

threeMult = []

fiveMult = []

fifteenMult = []

for i in range(1, 100 + 1, 1):

    if i % 3 == 0 and i % 5 != 00:

        threeMult.append(int(i))

    elif i % 5 == 0 and i % 3 != 00:

        fiveMult.append(int(i))

    elif i % 5 == 0 and i % 3 == 00:

        fifteenMult.append(i)

# representing in tkinter

def onClick():

    count = 0

    if count + 1 != 100:

        for i in range(count + 1, 100 + 1, 1):

            count += 1

            time.sleep(second)

            progress["value"] = i

            root.update_idletasks()

            start["state"] = "disabled"

            # stating the fizzbuzz numbers

            if i in threeMult:

                img = ImageTk.PhotoImage(

                    Image.open(f"{directory}\{fizzBuzz[0][0]}.gif").resize(

                        (100, 100), Image.ANTIALIAS

                    )

                )

                number["image"] = img

                number["text"] = fizzBuzz[0][0]

                number["font"] = f"Roboto {str(fizzBuzz[0][1])} bold"

                number["foreground"] = str(fizzBuzz[0][2])

                number["compound"] = BOTTOM

            elif i in fiveMult:

                img = ImageTk.PhotoImage(

                    Image.open(f"{directory}\{fizzBuzz[1][0]}.gif").resize(

                        (100, 100), Image.ANTIALIAS

                    )

                )

                number["image"] = img

                number["text"] = fizzBuzz[1][0]

                number["font"] = f"Roboto {str(fizzBuzz[1][1])} bold"

                number["foreground"] = str(fizzBuzz[1][2])

                number["compound"] = BOTTOM

            elif i in fifteenMult:

                img = ImageTk.PhotoImage(

                    Image.open(f"{directory}\{fizzBuzz[2][0]}.gif").resize(

                        (150, 150), Image.ANTIALIAS

                    )

                )

                number["image"] = img

                number["text"] = fizzBuzz[2][0]

                number["font"] = f"Roboto {str(fizzBuzz[2][1])} bold"

                number["foreground"] = str(fizzBuzz[2][2])

                number["compound"] = BOTTOM

            else:

                number["image"] = ""

                number["text"] = str(i)

                number["font"] = f"Roboto 20"

                number["foreground"] = "black"

    elif count + 1 == 100:

        count = 0

progress = Progressbar(root, orient=HORIZONTAL, length=600)

number = Label(root, text="0", font=("Roboto", 20), background="#22d1ee")

start = Button(root, text="START", command=threading.Thread(target=onClick).start)

# running the main program

try:

    progress.pack(padx=10, pady=10)

    number.place(relx=0.5, rely=0.5, anchor=CENTER)

    start.pack(side=BOTTOM, pady=10)

    root.mainloop()

except:

    print("Program Closed!")
