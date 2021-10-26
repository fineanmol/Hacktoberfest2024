# this program uses tinyurl api to shorten given url
# Contributor Name: Nimish Ph
import requests
from urllib.parse import urlencode

from urllib3 import response

def shorten(url: str) -> str:
  requestUrl = 'http://tinyurl.com/api-create.php?url=' + url  
  
  with requests.get(requestUrl) as response:
    if response.status_code == 200:
      shortUrl = response.content.decode('UTF-8')
      return shortUrl
    else:
      print('Error! Status Code:', response.status_code) 
  return None
url = input('For example: https://www.wikipedia.org\nPlease enter url to shorten: ') 

shortUrl = shorten(url)
if shortUrl is not None:
  print("Here's your shortened url:", shortUrl)
else:
  print("Sorry! Couldn't shorten given url :(")