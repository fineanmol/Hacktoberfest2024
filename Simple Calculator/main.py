import tkinter as tk

calculation = ""


def add_to_calculation(symbol):
    global calculation
    calculation += str(symbol)
    # now we have to clear the text field
    text_field.delete(1.0, "end")
    # later we will insert the results
    text_field.insert(1.0, calculation)


def evaluate():
    global calculation
    try:
        calculation = str(eval(calculation))
        text_field.delete(1.0, "end")
        text_field.insert(1.0, calculation)
    except:
        clear_field()
        text_field.insert(1.0, "ERROR")


def clear_field():
    global calculation
    calculation = ""
    text_field.delete(1.0, "end")


# ------------------------------- UI -------------------------------------------------- #

window = tk.Tk()
window.geometry("340x370")
window.title("My Calculator")
window.config(background="black", highlightthickness=0)
text_field = tk.Text(window, height=2, width=20, font=("Helvetica", 24), background="black", foreground="white", highlightthickness=0)
text_field.grid(columnspan=5)

# button - AC
btn_ac = tk.Button(window, text="AC", command=lambda: clear_field(), width=5, font=("Helvetica", 14), background="#5f5f5f", foreground="black")
btn_ac.grid(row=1, column=0,padx=5, pady=10)
# button brackets
btn_bracket1 = tk.Button(window, text="(", command=lambda: add_to_calculation('('), width=5, font=("Helvetica", 14), background="#5f5f5f", foreground="black")
btn_bracket1.grid(row=1, column=1)

btn_bracket2 = tk.Button(window, text=")", command=lambda: add_to_calculation(')'), width=5, font=("Helvetica", 14), background="#5f5f5f", foreground="black")
btn_bracket2.grid(row=1, column=2)

# division
btn_div = tk.Button(window, text="÷", command=lambda: add_to_calculation('/'), width=5, font=("Helvetica", 14), background="#FFA700", foreground="white")
btn_div.grid(row=1, column=3)

# buttons 7 - 9
btn_7 = tk.Button(window, text="7", command=lambda: add_to_calculation(7), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_7.grid(row=2, column=0, padx=5, pady=10)

btn_8 = tk.Button(window, text="8", command=lambda: add_to_calculation(8), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_8.grid(row=2, column=1)

btn_9 = tk.Button(window, text="9", command=lambda: add_to_calculation(9), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_9.grid(row=2, column=2)

# multiplication
btn_mul = tk.Button(window, text="x", command=lambda: add_to_calculation('*'), width=5, font=("Helvetica", 14), background="#FFA700", foreground="white")
btn_mul.grid(row=2, column=3)

# buttons 4 - 6
btn_4 = tk.Button(window, text="4", command=lambda: add_to_calculation(4), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_4.grid(row=3, column=0, padx=5, pady=10)

btn_5 = tk.Button(window, text="5", command=lambda: add_to_calculation(5), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_5.grid(row=3, column=1)

btn_6 = tk.Button(window, text="6", command=lambda: add_to_calculation(6), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_6.grid(row=3, column=2)

# subtraction
btn_sub = tk.Button(window, text="-", command=lambda: add_to_calculation('-'), width=5, font=("Helvetica", 14), background="#FFA700", foreground="white")
btn_sub.grid(row=3, column=3)

# buttons 1 to 3
btn_1 = tk.Button(window, text="1", command=lambda: add_to_calculation(1), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_1.grid(row=4, column=0, padx=5, pady=10)

btn_2 = tk.Button(window, text="2", command=lambda: add_to_calculation(2), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_2.grid(row=4, column=1)

btn_3 = tk.Button(window, text="3", command=lambda: add_to_calculation(3), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_3.grid(row=4, column=2)

btn_add = tk.Button(window, text="+", command=lambda: add_to_calculation('+'), width=5, font=("Helvetica", 14), background="#FFA700", foreground="white")
btn_add.grid(row=4, column=3)

# zero button
btn_0 = tk.Button(window, text="0", command=lambda: add_to_calculation(0), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_0.grid(row=5, column=0, padx=5, pady=5)

# mod button
btn_mod = tk.Button(window, text="%", command=lambda: add_to_calculation('%'), width=5, font=("Helvetica", 14), background="#A9A9A9", foreground="white")
btn_mod.grid(row=5, column=1)

# equal button
btn_equal = tk.Button(window, text="=", command=lambda: evaluate(), width=13, font=("Helvetica", 14), background="#FFA700", foreground="white")
btn_equal.grid(row=5, column=2, columnspan=2)

window.mainloop()
