# Python program to convert
# date to timestamp


import time
import datetime


string = "20/01/2020"


element = datetime.datetime.strptime(string,"%d/%m/%Y")

timestamp = datetime.datetime.timestamp(element)
print(timestamp)
