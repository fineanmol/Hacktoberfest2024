import bs4
import requests

country_name = input("Enter Country Name ")
print("Note : Please Enter the exact country name or it won't work")

url = "https://www.worldometers.info/coronavirus/country/" + country_name + "/"
res = requests.get(url)

soup = bs4.BeautifulSoup(res.text, "lxml")

data = soup.find_all("div", {"class" : "maincounter-number"})
print(data)

coronaCases = data[0].find("span").text
deaths = data[1].find("span").text
recoverd = data[2].find("span").text
print("Corona Virus Cases :", coronaCases)
print("Corona VIrus Deaths", deaths)
print('RECOVERED', recovered)