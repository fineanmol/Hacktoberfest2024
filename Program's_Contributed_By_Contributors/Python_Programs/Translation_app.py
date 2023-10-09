#import necessary libraries and packages

import tkinter as tk
from tkinter import ttk
from translate import Translator
from gtts import gTTS
import pygame
from io import BytesIO

# Initialize pygame mixer
pygame.mixer.init()

# Mapping of language names to language codes
languages = {
    "English": "en",
    "Spanish": "es",
    "Portuguese": "pt",
    "Chinese": "zh",
    "French": "fr",
    "German": "de",
    "Hindi": "hi",
}

# Store the translation audio in a variable
translation_audio = None

# Function to handle translation
def translate_text():
    global translation_audio
    user_input = input_entry.get()
    selected_lang_name = language_var.get()

    if selected_lang_name in languages:
        selected_lang_code = languages[selected_lang_name]
        translator = Translator(to_lang=selected_lang_code)
        translation = translator.translate(user_input)
        result_label.config(text=translation, background="light blue")  # Set background color here

        # Use gTTS to convert translation to speech and save to an in-memory file
        tts = gTTS(text=translation, lang=selected_lang_code)
        translation_audio = BytesIO()
        tts.write_to_fp(translation_audio)
        translation_audio.seek(0)
    else:
        result_label.config(text="Please select a valid language", background="light blue")  # Set background color here

# Function to play the audio
def play_audio():
    if translation_audio:
        pygame.mixer.music.load(translation_audio)
        pygame.mixer.music.play()

# Create the main application window
app = tk.Tk()
app.title("Text Translator with Audio")
app.geometry("400x300")
app.configure(background="light blue")  # Set background color for the main window

# Create and configure widgets
input_label = ttk.Label(app, text="Enter the text:", background="light blue")  # Set background color here
input_entry = ttk.Entry(app, width=30)
language_label = ttk.Label(app, text="Select a language:", background="light blue")  # Set background color here
language_var = tk.StringVar()
language_dropdown = ttk.Combobox(app, textvariable=language_var, values=list(languages.keys()))
translate_button = ttk.Button(app, text="Translate", command=translate_text)
play_button = ttk.Button(app, text="Play Audio", command=play_audio)
result_label = ttk.Label(app, text="Translation will appear here", wraplength=280, background="light blue")  # Set background color here

# Arrange widgets in the grid
input_label.grid(row=0, column=0, padx=10, pady=10, sticky="w")
input_entry.grid(row=0, column=1, padx=10, pady=10)
language_label.grid(row=1, column=0, padx=10, pady=10, sticky="w")
language_dropdown.grid(row=1, column=1, padx=10, pady=10)
translate_button.grid(row=2, column=0, columnspan=2, padx=10, pady=10)
play_button.grid(row=3, column=0, columnspan=2, padx=10, pady=10)
result_label.grid(row=4, column=0, columnspan=2, padx=10, pady=10)

# Start the Tkinter main loop
app.mainloop()
