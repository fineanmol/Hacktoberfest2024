import tkinter as tk

# Function to handle the form submission
def submit_form():
    name = name_entry.get()
    email = email_entry.get()
    age = age_entry.get()
    
    result_label.config(text=f"Name: {name}\nEmail: {email}\nAge: {age}")

# Create a new Tkinter window
window = tk.Tk()
window.title("Form Filling Application")

# Create form fields and labels
name_label = tk.Label(window, text="Name:")
name_label.pack()

name_entry = tk.Entry(window)
name_entry.pack()

email_label = tk.Label(window, text="Email:")
email_label.pack()

email_entry = tk.Entry(window)
email_entry.pack()

age_label = tk.Label(window, text="Age:")
age_label.pack()

age_entry = tk.Entry(window)
age_entry.pack()

# Create a submit button
submit_button = tk.Button(window, text="Submit", command=submit_form)
submit_button.pack()

# Display the result
result_label = tk.Label(window, text="")
result_label.pack()

# Start the main loop
window.mainloop()
