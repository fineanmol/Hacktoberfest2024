import tkinter
import requests
from tkinter import *
from tkinter import messagebox

window = Tk()
window.title('My Currency converter')
tops = Frame(window, bg='#e6e5e5', pady=10, padx=10, width=1950, height=100, relief="ridge")
tops.grid(row=0, column=0)
headlabel = Label(tops, font=('lato black', 19, 'bold'), text='Benji\'s: Currency Converter', bg='#e6e5e5', fg='black')
headlabel.grid(row=1, column=0)

variable1 = tkinter.StringVar(tops)
variable2 = tkinter.StringVar(tops)
variable1.set("currency")
variable2.set("currency")


def currency_converter():
    global variable1
    global variable2
    from_country = variable1.get()
    to_country = variable2.get()
    amount = int(amount_entry.get())

    if amount_entry.get() == '':
        messagebox.showerror(title='Error!', message='Amount not entered\nPlease enter amount')
    elif from_country == 'currency' or to_country == 'currency':
        messagebox.showerror(title='Error!', message='Currency Not Selected\nPlease select currency from the menu')
    else:
        class Currency_converter:
            rates = {}

            def __init__(self, result):
                data = result
                # Extract only the rates from the json
                self.rates = data['info']['rate']

            # Simple multiplication btw the amount and the rates
            def convert(self, from_currency, to_currency, amount):
                initial_amount = amount
                amount = round(amount * self.rates, 2)
                converted_amount_display.insert(0, str(amount))
                # print('{} {} = {} {}'.format(initial_amount, from_currency, amount, to_currency))

        parameters = {
            'to': to_country,
            'from': from_country,
            'amount': amount

        }
        url = "https://api.apilayer.com/fixer/convert"
        headers = {
            "apikey": "4WHDlrjPgAxHDAY5MlOapFEehZBJDqto"
        }
        response = requests.get(url, headers=headers, params=parameters)
        response.raise_for_status()
        result = response.json()
        cr = Currency_converter(result)
        cr.convert(from_currency=from_country, to_currency=to_country, amount=amount)


def clear_all():
    amount_entry.delete(0, END)
    converted_amount_display.delete(0, END)


# currency converter gui
currency_code_list = ["INR", "NGN", "USD", "CAD", "CNY", "DKK", "EUR", 'JPY', 'AUD', 'CHF', "NZD", "GBP"]
window.config(background='#e6e5e5')
window.geometry('700x400')

# Labels
amount = Label(tops, font=('lato black', 15, 'bold'), padx=10, pady=10, text="\t    Amount  :  ", bg="#e6e5e5",
               fg="black")
amount.grid(row=2, column=0, sticky=W)

from_currency = Label(tops, font=('lato black', 15, 'bold'), padx=10, pady=10, text="\t    From Currency  :  ",
                      bg="#e6e5e5", fg="black")
from_currency.grid(row=3, column=0, sticky=W)

to_currency = Label(tops, font=('lato black', 15, 'bold'), padx=10, pady=10, text="\t    To Currency  :  ",
                    bg="#e6e5e5", fg="black")
to_currency.grid(row=4, column=0, sticky=W)

converted_amount = Label(tops, font=('lato black', 15, 'bold'), padx=10, pady=10, text="\t    Converted amount  :  ",
                         bg="#e6e5e5",
                         fg="black")
converted_amount.grid(row=8, column=0, sticky=W)

# options & entries & buttons

from_currency_list_options = tkinter.OptionMenu(tops, variable1, *currency_code_list)
to_currency_list_options = tkinter.OptionMenu(tops, variable2, *currency_code_list)

from_currency_list_options.grid(row=3, column=1, ipadx=45, sticky=E)
to_currency_list_options.grid(row=4, column=1, ipadx=45, sticky=E)

amount_entry = Entry(tops)
amount_entry.grid(row=2, column=1, ipadx=28, sticky=E)

converted_amount_display = Entry(tops)
converted_amount_display.grid(row=8, column=1, ipadx=28, sticky=E)

convert_btn = Button(tops, font=('arial', 15, 'bold'), text="   Convert  ", padx=2, pady=2, bg="light blue", fg="white",
                     command=currency_converter)
convert_btn.grid(row=6, column=0, columnspan=2)

clear_all_btn = Button(tops, font=('arial', 15, 'bold'), text="   Clear All  ", padx=2, pady=2, bg="light blue",
                       fg="white",
                       command=clear_all)
clear_all_btn.grid(row=10, column=0, columnspan=2)

window.mainloop()
