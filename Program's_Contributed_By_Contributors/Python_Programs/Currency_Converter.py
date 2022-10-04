from tkinter import *
import requests
from tkinter import ttk
import tkinter as tk
class real_time_CC():
    def __init__(self,url):
        self.data=requests.get(url).json()
        self.currencies=self.data['rates']
    def convert(self,from_currency,to_currency,amount):
        initial_amount=amount
        if from_currency!='USD':
            amount=amount/self.currencies[from_currency]
        amount=round(amount*self.currencies[to_currency],4)
        return amount

converter = real_time_CC('https://api.exchangerate-api.com/v4/latest/USD')
print(converter.convert('INR','USD',100))