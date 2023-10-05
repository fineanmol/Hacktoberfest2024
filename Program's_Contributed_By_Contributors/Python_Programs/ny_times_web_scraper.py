from bs4 import BeautifulSoup
from lxml import html
import requests
from pprint import pprint


res = requests.get('https://www.nytimes.com/')
soup = BeautifulSoup(res.content, 'html.parser')

tree = soup.find_all("h3", class_ = "indicate-hover css-66vf3i")
summary = soup.find_all("p", class_ = "summary-class") 
image = soup.find_all("img", class_="css-122y91a")

for i in range (len(tree)):
    print(tree[i].text + "\n")
    print(summary[i].text + "\n")
    print(image[i].attrs['src'])
    print("\n \n")

