from tkinter import *
from tkinter import messagebox
import random
import pyperclip
import json


# ---------------------------- PASSWORD GENERATOR ------------------------------- #
# Password Generator Project
def password_generator():
    letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
               'v',
               'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
               'R',
               'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

    nr_letters = random.randint(8, 10)
    nr_symbols = random.randint(2, 4)
    nr_numbers = random.randint(2, 4)

    password_letter = [random.choice(letters) for _ in range(nr_letters)]
    password_symbols = [random.choice(symbols) for _ in range(nr_symbols)]
    password_numbers = [random.choice(numbers) for _ in range(nr_numbers)]
    password_list = password_letter + password_symbols + password_numbers
    random.shuffle(password_list)

    password = "".join(password_list)
    pyperclip.copy(password)
    input_password.insert(0, password)


# ---------------------------- SAVE PASSWORD ------------------------------- #
def save():
    website = input_website.get()
    email = input_email.get()
    password = input_password.get()
    new_data = {
        website: {
            "email": email,
            "password": password,
        }
    }
    if not website or not email or not password:
        messagebox.showinfo(title="Oops", message="Please don't leave any field empty!")
    else:
        # is_ok = messagebox.askokcancel(title=website,
        #                                message=f"These are the detail entered:\nEmail: {email}\nPassword: {password}\nIs it ok to save?")
        # if is_ok:
        try:
            with open("data.json", "r") as data_file:
                data = json.load(data_file)
        except FileNotFoundError:
            with open("data.json", "w") as data_file:
                json.dump(new_data, data_file, indent=4)
        else:
            data.update(new_data)
            with open("data.json", "w") as data_file:
                json.dump(data, data_file, indent=4)
        finally:
            input_website.delete(0, END)
            input_password.delete(0, END)

def search_data():
    website = input_website.get()
    if not website:
        messagebox.showinfo(title="Oops", message="Please enter website name.")
    else:
        try:
            with open("data.json", "r") as data_file:
                data = json.load(data_file)
        except FileNotFoundError:
            messagebox.showinfo(title="Oops", message="No data found!")
        else:
            if website in data:
                email = data[website]["email"]
                password = data[website]["password"]
                messagebox.showinfo(title=website, message=f"email: {email}\npassword: {password}")
            else:
                messagebox.showinfo(title="Oops", message=f"No data found related to {website} ")




# ---------------------------- UI SETUP ------------------------------- #
window = Tk()
window.title("Password Manager")
window.config(padx=50, pady=50)

canvas = Canvas(width=200, height=200, )
logo_img = PhotoImage(file="logo.png")
canvas.create_image(100, 100, image=logo_img)
canvas.grid(column=1, row=0)

label_1 = Label(text="Website:")
label_1.grid(column=0, row=1)
label_2 = Label(text="Email/Username:")
label_2.grid(column=0, row=2)
label_3 = Label(text="Password:")
label_3.grid(column=0, row=3)

input_website = Entry(width=42)
input_website.grid(column=1, row=1)
input_website.focus()
search = Button(text="Search",width=14, command=search_data)
search.grid(column=2, row=1)


input_email = Entry(width=62)
input_email.grid(column=1, row=2, columnspan=2)
input_email.insert(0, "himalayapal123@gmail.com")

input_password = Entry(width=42)
input_password.grid(column=1, row=3)
generate_password = Button(text="Generate Password", command=password_generator)
generate_password.grid(column=2, row=3)

add = Button(text="Add", width=52, command=save)
add.grid(column=1, row=4, columnspan=2)

window.mainloop()
