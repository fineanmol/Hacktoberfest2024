import tkinter as tk
import random

# Function to generate a random color
def generate_random_color():
    color = "#{:02x}{:02x}{:02x}".format(random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
    color_label.config(text="Random Color: " + color)
    canvas.config(bg=color)

# Create the main window
window = tk.Tk()
window.title("Random Color Generator")

# Create a button to generate a random color
generate_button = tk.Button(window, text="Generate Random Color", command=generate_random_color)
generate_button.pack(pady=10)

# Create a label to display the generated color
color_label = tk.Label(window, text="Random Color: ")
color_label.pack()

# Create a canvas to display the generated color as the background
canvas = tk.Canvas(window, width=200, height=200, bg="white")
canvas.pack()

# Start the Tkinter main loop
window.mainloop()