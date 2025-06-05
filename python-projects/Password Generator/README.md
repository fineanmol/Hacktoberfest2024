# Password Generator with Tkinter

A simple password generator application built using Python's `Tkinter` library for the graphical user interface. It generates random passwords based on user input for the number of passwords and their length. You can copy the generated password to the clipboard with a single click.

## Features

- Generate multiple passwords with customizable length.
- Copy the selected password to the clipboard.
- User-friendly interface with Tkinter.
- Input validation for number of passwords and password length.

## Requirements

- Python 3.x
- Libraries: 
  - `tkinter` (built-in with Python)
  - `pyperclip` (for copying to clipboard)

To install the required library, run:
```bash
pip install pyperclip
```

## How to Run

- Clone the repository or download the code files.
- Ensure you have Python installed on your machine.
- Run the password_generator.py file using Python:

    ```bash
    python password_generator.py
    ```

## Usage

- Enter the number of passwords you want to generate.
- Specify the length of each password.
- Click "Generate Passwords" to generate a list of random passwords.
- Select a password from the list and click "Copy Selected Password" to copy it to your clipboard.

## Code Overview

- `generate_passwords(num_entry, length_entry, listbox)`: Generates a specified number of passwords with a given length and displays them in the listbox.
- `copy_password(listbox)`: Copies the selected password from the listbox to the clipboard.
- `create_gui()`: Initializes the graphical user interface using Tkinter.
