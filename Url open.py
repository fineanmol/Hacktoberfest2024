import urllib.request 
url="file:///C:/Users/NFate/Desktop/demo.html" 
site=urllib.request.urlopen(url)
data=site.read().decode('utf-8')
print(data)
