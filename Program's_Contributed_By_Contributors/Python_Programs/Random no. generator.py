import customtkinter as ctk 	# install customtkinter using pip
import random

def generator():
	var_st = int(enter_start.get())
	var_end = int(enter_end.get())
	label_result.configure(text = random.randint(var_st, var_end))

window = ctk.CTk()
window.geometry("250x300")
window.title("NO GENE")
window.resizable(False, False)

label_1 = ctk.CTkLabel(window, text = "From:", width = 70, height = 25)
label_1.place(relx = 0.25, rely = 0.07, anchor = ctk.CENTER)

label_2 = ctk.CTkLabel(window, text = "To:", width = 70, height = 25)
label_2.place(relx = 0.75, rely = 0.07, anchor = ctk.CENTER)

enter_start = ctk.CTkEntry(master = window, width = 80, height = 25, corner_radius = 10)
enter_start.place(relx = 0.25, rely = 0.17, anchor = ctk.CENTER)

enter_end = ctk.CTkEntry(master = window, width = 80, height = 25, corner_radius = 10)
enter_end.place(relx = 0.75, rely = 0.17, anchor = ctk.CENTER)

button = ctk.CTkButton(window, text = "Generate", command = generator)
button.place(relx = 0.5, rely = 0.35, anchor = ctk.CENTER)

label_result = ctk.CTkLabel(window, text = "", width = 70, height = 50, font = ("Verdana", 30, "bold"))
label_result.place(relx = 0.5, rely = 0.57, anchor = ctk.CENTER)

window.mainloop()