import csv
from datetime import datetime

# File to store expenses
EXPENSES_FILE = "expenses.csv"

# Function to add an expense
def add_expense(amount, category, date=None):
    if not date:
        date = datetime.now().strftime('%Y-%m-%d')  # Default to today's date
    with open(EXPENSES_FILE, mode='a', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([date, amount, category])
    print(f"Added expense: {amount} for {category} on {date}")

# Function to view expenses
def view_expenses(filter_category=None, filter_date=None):
    try:
        with open(EXPENSES_FILE, mode='r') as file:
            reader = csv.reader(file)
            total_expense = 0
            print(f"\n{'Date':<12}{'Amount':<10}{'Category':<15}")
            print("-" * 37)
            for row in reader:
                date, amount, category = row
                if (filter_category and category != filter_category) or (filter_date and date != filter_date):
                    continue
                total_expense += float(amount)
                print(f"{date:<12}{amount:<10}{category:<15}")
            print("-" * 37)
            print(f"Total Expense: {total_expense}")
    except FileNotFoundError:
        print("No expenses recorded yet.")

# Function to edit or delete an expense
def edit_delete_expense(index, action, new_data=None):
    try:
        with open(EXPENSES_FILE, mode='r') as file:
            rows = list(csv.reader(file))
        if index < 0 or index >= len(rows):
            print("Invalid index")
            return
        if action == 'edit':
            date, amount, category = new_data
            rows[index] = [date, amount, category]
            print("Expense updated.")
        elif action == 'delete':
            rows.pop(index)
            print("Expense deleted.")
        with open(EXPENSES_FILE, mode='w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows(rows)
    except FileNotFoundError:
        print("No expenses to edit/delete.")

# Example usage
if __name__ == "__main__":
    while True:
        print("\nExpense Tracker Menu:")
        print("1. Add Expense")
        print("2. View Expenses")
        print("3. Edit/Delete Expense")
        print("4. Exit")
        choice = input("Choose an option: ")
        
        if choice == '1':
            amount = input("Enter amount: ")
            category = input("Enter category (e.g., Food, Rent): ")
            date = input("Enter date (YYYY-MM-DD) or leave blank for today: ")
            add_expense(amount, category, date)
        
        elif choice == '2':
            filter_cat = input("Enter category to filter or leave blank for all: ")
            filter_date = input("Enter date (YYYY-MM-DD) to filter or leave blank for all: ")
            view_expenses(filter_cat if filter_cat else None, filter_date if filter_date else None)
        
        elif choice == '3':
            view_expenses()
            idx = int(input("Enter the index of the expense to edit/delete: ")) - 1
            action = input("Type 'edit' to modify or 'delete' to remove: ").lower()
            if action == 'edit':
                new_date = input("Enter new date (YYYY-MM-DD): ")
                new_amount = input("Enter new amount: ")
                new_category = input("Enter new category: ")
                edit_delete_expense(idx, action, (new_date, new_amount, new_category))
            elif action == 'delete':
                edit_delete_expense(idx, action)
        
        elif choice == '4':
            break
        
        else:
            print("Invalid choice! Try again.")
