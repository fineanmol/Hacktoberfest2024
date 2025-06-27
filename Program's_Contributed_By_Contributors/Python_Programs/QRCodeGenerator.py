import pyqrcode
import png
from pyqrcode import QRCode

#string of url
url=input("Enter URL")

#generate qr
url_qr= pyqrcode.create(url)

print("Input 1 to save as PNG and 2 to save as SVG)")
if (int(input())==1):
	#create and save png file, here input is file name.
	name=input("Enter name for file")
	url_qr.png(name+".png", scale= 6)

else:
	#create and save svg file, here input is file name.
	name=input("Enter name for file")
	#url_qr.svg=(name+".svg", scale=8)
