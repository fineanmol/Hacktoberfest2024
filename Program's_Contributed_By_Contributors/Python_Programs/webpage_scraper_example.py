#Python Web Scraping Example

import requests
from bs4 import BeautifulSoup

#This is the url to scrape
urlToScrape = "https://finance.yahoo.com/quote/BTC-USD"

#Get the HTML page
page = requests.get(urlToScrape)

soup = BeautifulSoup(page.content, "html.parser")

#Find search value by <tag> and after the attributes like class, id and similar
getData0 = soup.find("h1", attrs={"class": "D(ib) Fz(18px)"}).text 
getData1 = soup.find("span", attrs={"class": "Trsdu(0.3s) Fw(b) Fz(36px) Mb(-4px) D(ib)"}).text

#For the example here I'm printing the live value of one bitcoin from Yahoo Finance
print(getData0+ " " + getData1)
