import pyqrcode 
from pyqrcode import QRCode 
  
s = "https://www.youtube.com/channel/UCeO9hPCfRzqb2yTuAn713Mg"
  
url = pyqrcode.create(s) 
  
url.svg("myyoutube.svg", scale = 8)
