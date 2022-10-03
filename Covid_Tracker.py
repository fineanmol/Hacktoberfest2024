# A GUI based COVID tracker to check the overall positivity and death rate.
# - GUI implemented using Tkinter.
# - Uses web scrapping to get the details of covid cases


import requests
import bs4

import tkinter as tk

def get_html_data(url):
    data = requests.get(url)
    return data

def get_covid_data():
    url = "https://www.worldometers.info/coronavirus/"
    html_data = get_html_data(url)
    bs = bs4.BeautifulSoup(html_data.text,'html.parser')
    # print(bs)
    info_div = bs.find("div",class_="content-inner").findAll("div",id="maincounter-wrap")
    # print(info_div)
    all_data=""
    for block in info_div:
        text = block.find("h1", class_=None).get_text()
        count = block.find("span",class_=None).get_text()
        all_data=all_data+text+" "+count+"\n"
    # print(all_data)
    return(all_data)


def get_country_data():
    name = textfield.get()
    url = "https://www.worldometers.info/coronavirus/country/"+name
    html_data = get_html_data(url)
    bs = bs4.BeautifulSoup(html_data.text, 'html.parser')
    # print(bs)
    info_div = bs.find("div", class_="content-inner").findAll("div", id="maincounter-wrap")
    # print(info_div)
    all_data = ""
    for block in info_div:
        text = block.find("h1", class_=None).get_text()
        count = block.find("span", class_=None).get_text()
        all_data = all_data + text + " " + count + "\n"

    print(all_data)
    mainlabel['text']=all_data


def reload():
    new_data = get_covid_data()
    mainlabel['text']=new_data

get_covid_data()
# GUI
# window create
root = tk.Tk()
root.geometry("900x700")
root.title("Covid Tracker")
f = ("popins",25, "bold")
# window ends

# banner/image to beautify
banner = tk.PhotoImage(file="covidimg.png")
bannerlabel = tk.Label(root,image=banner)
bannerlabel.pack()
# banner end

# search bar
textfield = tk.Entry(root,width=50)
# print(textfield)
textfield.pack()
#end

mainlabel = tk.Label(root,text=get_covid_data(),font=f)
mainlabel.pack()

# buttons
gbtn = tk.Button(root,text="Get Data",font = f,relief='solid',command = get_country_data)
gbtn.pack()
rbtn = tk.Button(root,text="Reload",font = f,relief='solid',command = reload)
rbtn.pack()
# end

root.mainloop()
