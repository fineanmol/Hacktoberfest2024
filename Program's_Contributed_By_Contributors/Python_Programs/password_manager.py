import random
import string
import tkinter as tk
from tkinter import simpledialog
import hashlib
import sqlite3
import os

def generate_strong_password(length=16):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

class PasswordManagerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Password Manager")
        
        self.password_data = {}  # Store app names and passwords
        
        # Customize background colors
        entry_bg_color = "#F0F0F0"  # Light gray
        button_bg_color = "#4CAF50"  # Green
        
        self.app_name_label = tk.Label(root, text="App Name:", font=("Helvetica", 12))
        self.app_name_label.pack(pady=10)
        
        self.app_name_entry = tk.Entry(root, bg=entry_bg_color, font=("Helvetica", 12))
        self.app_name_entry.pack(pady=5)
        
        self.generate_button = tk.Button(root, text="Generate Password", command=self.generate_password, bg=button_bg_color, font=("Helvetica", 12))
        self.generate_button.pack(pady=5)
        
        self.quit_button = tk.Button(root, text="Quit", command=root.quit, bg=button_bg_color, font=("Helvetica", 12))
        self.quit_button.pack(pady=10)
        
        self.conn = sqlite3.connect('passwords.db')
        self.create_table()
    
    def create_table(self):
        cursor = self.conn.cursor()
        cursor.execute('''
                       CREATE TABLE IF NOT EXISTS passwords (
                           app_name TEXT PRIMARY KEY,
                           password_hash TEXT, 
                           password_salt TEXT
                       )
                       ''')
        self.conn.commit()
        
    def generate_password(self):
        app_name = self.app_name_entry.get()
        
        if app_name:
            password = generate_strong_password()
            salt = generate_salt()
            password_hash = hash_password(password, salt)
            
            self.insert_password(app_name, password_hash, salt)
            
            message = f"Password for {app_name} generated ans stored securely."
            simpledialog.messagebox.showinfo("Generated Password", message)
            
            self.app_name_entry.delete(0, tk.END)
            
    def insert_password(self, app_name, password_hash, salt):
        cursor = self.conn.cursor()
        cursor.execute('''
                        INSERT INTO passwords (app_name, password_hash, password_salt)
                        VALUES (?, ?, ?)
                       ''', (app_name, password_hash, salt))
        self.conn.commit()
        
    def check_password(self):
        app_name = self.app_name_entry.get()
        provided_password = self.password_entry.get()
        
        if app_name and provided_password:
            hashed_password, salt = self.retrieve_password_and_salt(app_name)
            
            if hashed_password is None:
                message = f"No password found for {app_name}."
            else:
                hashed_provided_password = hash_password(provided_password, salt)
                if hashed_password == hashed_provided_password:
                    message = f"Password for {app_name} is correct!"
                else:
                    message = f"Invalid Password for {app_name}."
            message.showinfo("Password Check", message)
            
            self.app_name_entry.delete(0, tk.END)
            self.password_entry.delete(0, tk.END)
    
    def retrieve_password_and_salt(self, app_name):
        cursor = self.conn.cursor()
        cursor.execute('SELECT password_hash, password_salt FROM passwords WHERE app_name = ?', (app_name,))
        result = cursor.fetchone()
        
        if result:
            return result
        else:
            return None, None
        
def hash_password(password, salt):
    iterations = 100000
    dk_length = 64
    
    password_bytes = password.encode('utf-8')
    salt_bytes = salt.encode('utf-8')
    
    hashed = hashlib.pbkdf2_hmac('sha256', password_bytes, salt_bytes, iterations, dk_length)
    hashed_password = hashed.hex()
    
    return hashed_password

def generate_salt():
    salt = os.urandom(16).hex()
    return salt

def main():
    root = tk.Tk()
    root.geometry("300x200")
    app = PasswordManagerApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
