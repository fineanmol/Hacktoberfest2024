import requests

data = requests.get("https://ipinfo.io/json").json()


print(f'Your IP : ', data['ip'])
print(f'Your City : ', data['city'])
print(f'Your Region : ', data['region'])
print(f'Your Country : ', data['country'])
print(f'Your loc : ', data['loc'])
print(f'Your org : ', data['org'])
print(f'Your timezone : ', data['timezone'])