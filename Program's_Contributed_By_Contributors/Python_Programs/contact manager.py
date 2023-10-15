import tkinter as tk
from tkinter import ttk
import sqlite3
from tkinter import messagebox

class ContactManager:
    def __init__(self, root):
        self.root = root
        self.root.title("Contact Manager")

        # Create a database connection
        self.conn = sqlite3.connect("contacts.db")
        self.cursor = self.conn.cursor()

        # Create the contacts table if it doesn't exist
        self.cursor.execute("""
            CREATE TABLE IF NOT EXISTS contacts (
                id INTEGER PRIMARY KEY,
                name TEXT,
                phone TEXT
            )
        """)
        self.conn.commit()

        # Create and place widgets
        self.name_label = ttk.Label(root, text="Name:")
        self.name_label.grid(row=0, column=0, padx=10, pady=5)
        self.name_entry = ttk.Entry(root)
        self.name_entry.grid(row=0, column=1, padx=10, pady=5)

        self.phone_label = ttk.Label(root, text="Phone:")
        self.phone_label.grid(row=1, column=0, padx=10, pady=5)
        self.phone_entry = ttk.Entry(root)
        self.phone_entry.grid(row=1, column=1, padx=10, pady=5)

        self.add_button = ttk.Button(root, text="Add Contact", command=self.add_contact)
        self.add_button.grid(row=2, column=0, columnspan=2, padx=10, pady=10, sticky="we")

        self.contacts_listbox = tk.Listbox(root, selectmode=tk.SINGLE)
        self.contacts_listbox.grid(row=3, column=0, columnspan=2, padx=10, pady=5, sticky="news")
        self.contacts_listbox.bind("<<ListboxSelect>>", self.load_selected_contact)

        self.edit_button = ttk.Button(root, text="Edit Contact", command=self.edit_contact)
        self.edit_button.grid(row=4, column=0, padx=10, pady=5, sticky="w")

        self.view_button = ttk.Button(root, text="View Contact", command=self.view_contact)
        self.view_button.grid(row=4, column=1, padx=10, pady=5, sticky="e")

        self.delete_button = ttk.Button(root, text="Delete Contact", command=self.delete_contact)
        self.delete_button.grid(row=5, column=0, columnspan=2, padx=10, pady=5, sticky="we")

        self.load_contacts()

    def add_contact(self):
        name = self.name_entry.get()
        phone = self.phone_entry.get()
        if name and phone:
            self.cursor.execute("INSERT INTO contacts (name, phone) VALUES (?, ?)", (name, phone))
            self.conn.commit()
            self.load_contacts()
            self.clear_entries()
        else:
            messagebox.showwarning("Warning", "Name and Phone are required fields!")

    def edit_contact(self):
        selected_index = self.contacts_listbox.curselection()
        if selected_index:
            selected_index = selected_index[0]
            current_contact_id = self.contacts[selected_index][0]
            edited_name = self.name_entry.get()
            edited_phone = self.phone_entry.get()
            if edited_name and edited_phone:
                self.cursor.execute(
                    "UPDATE contacts SET name = ?, phone = ? WHERE id = ?",
                    (edited_name, edited_phone, current_contact_id)
                )
                self.conn.commit()
                self.load_contacts()
                self.clear_entries()
            else:
                messagebox.showwarning("Warning", "Name and Phone are required fields!")

    def view_contact(self):
        selected_index = self.contacts_listbox.curselection()
        if selected_index:
            selected_index = selected_index[0]
            current_contact = self.contacts[selected_index]
            message = f"Name: {current_contact[1]}\nPhone: {current_contact[2]}"
            messagebox.showinfo("Contact Details", message)

    def delete_contact(self):
        selected_index = self.contacts_listbox.curselection()
        if selected_index:
            selected_index = selected_index[0]
            current_contact_id = self.contacts[selected_index][0]
            self.cursor.execute("DELETE FROM contacts WHERE id = ?", (current_contact_id,))
            self.conn.commit()
            self.load_contacts()
            self.clear_entries()

    def load_contacts(self):
        self.contacts_listbox.delete(0, tk.END)
        self.contacts = self.cursor.execute("SELECT * FROM contacts").fetchall()
        for contact in self.contacts:
            self.contacts_listbox.insert(tk.END, contact[1])

    def load_selected_contact(self, event):
        selected_index = self.contacts_listbox.curselection()
        if selected_index:
            selected_index = selected_index[0]
            current_contact = self.contacts[selected_index]
            self.name_entry.delete(0, tk.END)
            self.phone_entry.delete(0, tk.END)
            self.name_entry.insert(0, current_contact[1])
            self.phone_entry.insert(0, current_contact[2])

    def clear_entries(self):
        self.name_entry.delete(0, tk.END)
        self.phone_entry.delete(0, tk.END)

    def close(self):
        self.conn.close()
        self.root.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    app = ContactManager(root)
    root.protocol("WM_DELETE_WINDOW", app.close)
    root.mainloop()
