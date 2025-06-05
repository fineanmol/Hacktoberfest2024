from tkinter import *
from tkinter import messagebox
from tkinter import simpledialog
import urllib.parse
import requests

def run():
    global show
    url = "https://codeforces.com/api/user.info?handles="
    h = e1.get()
    data = requests.get(url+h).json()
    if data['status'] == "OK":
        x = data['result'][0]
        a = [h, x['rating'], x['rank'], x['maxRating'], x['maxRank']]
        if show != None:
            for i in show.winfo_children():
                i.destroy()
        else:
            show = Frame(m)
        Label(show,text="").pack()
        Label(show,text="Handle: {}".format(a[0])).pack(anchor='center')
        Label(show,text="Current Rating: {}".format(a[1])).pack(anchor='center')
        Label(show,text="Current Rank: {}".format(a[2])).pack(anchor='center')
        Label(show,text="Max Rating: {}".format(a[3])).pack(anchor='center')
        Label(show,text="Max Rank: {}".format(a[4])).pack(anchor='center')
        show.pack()
    else:
        messagebox.showerror("Error", "User doesn't exist!")
        
m = Tk()
show = None
m.geometry("400x200")
Label(m, text='Handle: ').pack(anchor="center")
a = ""
h=""
e1 = Entry(m)
e1.pack(anchor='center')
sub = Button(m, text="Show Stats",command=run)
sub.pack()
m.mainloop()
