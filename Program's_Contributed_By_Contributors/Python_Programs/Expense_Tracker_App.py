import tkinter as tk
import customtkinter as ctk
from tkinter import messagebox
from datetime import datetime

# Set the appearance of CustomTkinter (dark/light mode)
ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")

# Main Application
class ExpenseTrackerApp(ctk.CTk):
    def __init__(self):
        super().__init__()

        self.title("Simple Expense Tracker")
        self.geometry("600x500")
        self.configure(padx=20, pady=20)
        
        # Expense list to store entries
        self.expenses = []

        # UI Elements
        self.create_ui()

    def create_ui(self):
        # Title Label
        self.title_label = ctk.CTkLabel(self, text="Expense Tracker", font=("Arial", 24, "bold"))
        self.title_label.grid(row=0, column=0, columnspan=3, pady=(0, 20))

        # Date Entry
        self.date_label = ctk.CTkLabel(self, text="Date (YYYY-MM-DD):", font=("Arial", 14))
        self.date_label.grid(row=1, column=0, pady=(0, 10), sticky="w")
        self.date_entry = ctk.CTkEntry(self, placeholder_text="YYYY-MM-DD", width=200)
        self.date_entry.grid(row=1, column=1, pady=(0, 10), padx=(0, 20))

        # Description Entry
        self.description_label = ctk.CTkLabel(self, text="Description:", font=("Arial", 14))
        self.description_label.grid(row=2, column=0, pady=(0, 10), sticky="w")
        self.description_entry = ctk.CTkEntry(self, placeholder_text="Expense Description", width=200)
        self.description_entry.grid(row=2, column=1, pady=(0, 10), padx=(0, 20))

        # Amount Entry
        self.amount_label = ctk.CTkLabel(self, text="Amount:", font=("Arial", 14))
        self.amount_label.grid(row=3, column=0, pady=(0, 10), sticky="w")
        self.amount_entry = ctk.CTkEntry(self, placeholder_text="Expense Amount", width=200)
        self.amount_entry.grid(row=3, column=1, pady=(0, 10), padx=(0, 20))

        # Add Expense Button
        self.add_button = ctk.CTkButton(self, text="Add Expense", command=self.add_expense, width=150)
        self.add_button.grid(row=4, column=0, pady=10)

        # Delete Expense Button
        self.delete_button = ctk.CTkButton(self, text="Delete Expense", command=self.delete_expense, width=150)
        self.delete_button.grid(row=4, column=1, pady=10)

        # Expense Listbox to display expenses (using tkinter.Listbox)
        self.expense_listbox = tk.Listbox(self, height=10, width=40, font=("Arial", 12))
        self.expense_listbox.grid(row=5, column=0, columnspan=3, pady=20, padx=(0, 20))

        # Total Expense Label
        self.total_label = ctk.CTkLabel(self, text="Total Expenses: ₹0.00", font=("Arial", 16, "bold"))
        self.total_label.grid(row=6, column=0, columnspan=3, pady=10)

    def add_expense(self):
        # Get input values
        date = self.date_entry.get().strip()
        description = self.description_entry.get().strip()
        amount = self.amount_entry.get().strip()

        # Validate the inputs
        if not date or not description or not amount:
            messagebox.showerror("Input Error", "All fields are required.")
            return

        try:
            # Ensure valid date and amount formats
            datetime.strptime(date, "%Y-%m-%d")
            amount = float(amount)
        except ValueError:
            messagebox.showerror("Input Error", "Invalid date or amount format.")
            return

        # Add to expense list
        expense = {"date": date, "description": description, "amount": amount}
        self.expenses.append(expense)

        # Update listbox
        self.update_expense_listbox()

        # Clear input fields
        self.date_entry.delete(0, tk.END)
        self.description_entry.delete(0, tk.END)
        self.amount_entry.delete(0, tk.END)

        # Update total expenses
        self.update_total_expenses()

    def delete_expense(self):
        try:
            # Get selected index
            selected_index = self.expense_listbox.curselection()[0]
            del self.expenses[selected_index]
            
            # Update listbox and total expenses
            self.update_expense_listbox()
            self.update_total_expenses()
        except IndexError:
            messagebox.showerror("Selection Error", "No expense selected.")

    def update_expense_listbox(self):
        # Clear the current listbox
        self.expense_listbox.delete(0, tk.END)

        # Populate listbox with expenses
        for expense in self.expenses:
            display_text = f"{expense['date']} - {expense['description']} - ₹{expense['amount']:.2f}"
            self.expense_listbox.insert(tk.END, display_text)

    def update_total_expenses(self):
        total = sum(expense["amount"] for expense in self.expenses)
        self.total_label.configure(text=f"Total Expenses: ₹{total:.2f}")

# Run the Application
if __name__ == "__main__":
    app = ExpenseTrackerApp()
    app.mainloop()
