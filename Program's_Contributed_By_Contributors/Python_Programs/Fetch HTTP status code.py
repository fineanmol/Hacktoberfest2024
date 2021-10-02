from urllib.request import urlopen
from urllib.error import URLError, HTTPError
import emoji

URL = input("Enter the URL: ")

try:
    response = urlopen(URL)
    print('Status code : ' + str(response.code) + ' ' + emoji.emojize(':thumbs_up:'))
    print('Message : ' + 'Request succeeded. Request returned message - ' + response.reason)
except HTTPError as e:
    print('Status : ' + str(e.code) + ' ' + emoji.emojize(':thumbs_down:'))
    print('Message : Request failed. Request returned reason - ' + e.reason)
except URLError as e:
    print('Status :',  str(e.reason).split(']')[0].replace('[','') +  ' ' + emoji.emojize(':thumbs_down:'))
    print('Message : '+ str(e.reason).split(']')[1])