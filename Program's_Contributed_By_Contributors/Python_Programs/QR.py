import qrcode as qr
from PIL import Image
img = qr.make("Hello I am Souvik Banerjee")
img.save("INFO.png")