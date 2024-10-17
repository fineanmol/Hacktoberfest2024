import tkinter as tk
from tkinter import messagebox
import random
import string
import pyperclip  # For copying to clipboard

def generate_passwords(num_entry, length_entry, listbox):
    try:
        num_passwords = int(num_entry.get())
        length_password = int(length_entry.get())
        
        if num_passwords <= 0 or length_password <= 0:
            raise ValueError
        
        passwords = []
        for _ in range(num_passwords):
            password = ''.join(random.choice(string.ascii_letters + string.digits + string.punctuation) for _ in range(length_password))
            passwords.append(password)
        
        # Clear the listbox before adding new passwords
        listbox.delete(0, tk.END)
        
        # Insert passwords into the listbox
        for pwd in passwords:
            listbox.insert(tk.END, pwd)
    
    except ValueError:
        messagebox.showerror("Invalid Input", "Please enter valid numbers for both fields.")

def copy_password(listbox):
    try:
        selected_password = listbox.get(listbox.curselection())
        pyperclip.copy(selected_password)
        messagebox.showinfo("Copied", f"Password '{selected_password}' copied to clipboard!")
    except tk.TclError:
        messagebox.showerror("Selection Error", "Please select a password from the list.")

def create_gui():
    window = tk.Tk()
    window.title("Password Generator")
    window.geometry("500x300")

    # Labels
    label1 = tk.Label(window, text="Number of Passwords:")
    label1.pack(pady=10)

    label2 = tk.Label(window, text="Length of Password:")
    label2.pack(pady=10)

    # Entries
    num_entry = tk.Entry(window)
    num_entry.pack(pady=5)

    length_entry = tk.Entry(window)
    length_entry.pack(pady=5)

    # Listbox to display passwords
    listbox = tk.Listbox(window, height=10, width=50)
    listbox.pack(pady=10)

    # Generate Button
    generate_button = tk.Button(window, text="Generate Passwords", command=lambda: generate_passwords(num_entry, length_entry, listbox))
    generate_button.pack(pady=5)

    # Copy Button
    copy_button = tk.Button(window, text="Copy Selected Password", command=lambda: copy_password(listbox))
    copy_button.pack(pady=5)

    window.mainloop()

if __name__ == "__main__":
    create_gui()