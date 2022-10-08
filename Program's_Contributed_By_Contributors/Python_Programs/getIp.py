import requests

get = requests.get('https://ip.seeip.org/jsonip').json()
print('your ip :',get['ip'])
