import tkinter as tk
from tkinter import font

# Function to handle button clicks
def button_click(number):
    current = entry.get()
    entry.delete(0, tk.END)
    entry.insert(0, current + str(number))

# Function to clear the input field
def clear():
    entry.delete(0, tk.END)

# Function to calculate the result
def calculate():
    try:
        expression = entry.get()
        result = eval(expression)
        result_label.config(text=result)
    except Exception as e:
        result_label.config(text="Error")

# Create the main application window
root = tk.Tk()
root.title("Calculator")

# Customize the font
button_font = font.Font(family='Helvetica', size=16, weight='bold')

# Create an entry widget for input and a label for displaying the result
entry = tk.Entry(root, font=button_font, justify='right', bd=10)
entry.grid(row=0, column=0, columnspan=4)

result_label = tk.Label(root, text="", font=button_font, bd=10)
result_label.grid(row=1, column=0, columnspan=4)

# Define buttons for numbers and operators with custom styling
buttons = [
    ('7', 2, 0), ('8', 2, 1), ('9', 2, 2), ('/', 2, 3),
    ('4', 3, 0), ('5', 3, 1), ('6', 3, 2), ('*', 3, 3),
    ('1', 4, 0), ('2', 4, 1), ('3', 4, 2), ('-', 4, 3),
    ('0', 5, 0), ('.', 5, 1), ('=', 5, 2), ('+', 5, 3)
]

for (text, row, col) in buttons:
    button = tk.Button(root, text=text, font=button_font, padx=20, pady=20, command=lambda t=text: button_click(t), bd=5)
    button.grid(row=row, column=col)

clear_button = tk.Button(root, text="C", font=button_font, padx=20, pady=20, command=clear, bd=5)
clear_button.grid(row=6, column=0, columnspan=2)

calculate_button = tk.Button(root, text="=", font=button_font, padx=20, pady=20, command=calculate, bd=5)
calculate_button.grid(row=6, column=2, columnspan=2)

# Add some padding around buttons for a more attractive appearance
for i in range(2, 7):
    root.grid_rowconfigure(i, pad=10)
    root.grid_columnconfigure(i, pad=10)

# Start the Tkinter main loop
root.mainloop()
