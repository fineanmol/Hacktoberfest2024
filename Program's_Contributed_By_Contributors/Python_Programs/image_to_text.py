from PIL import Image, ImageOps
from pytesseract import pytesseract
import requests
from io import BytesIO

url = r"Some-url-with-text-image"
response = requests.get(url)
img = Image.open(BytesIO(response.content))
# img.show()

# Loading the image
# img = Image.open(r"report2.jpg")
img = ImageOps.invert(img)
print(img.size)

# Setting the points for cropped image
left1 = 925
top1 = 317
right1 = 990
bottom1 = 330

left2 = 1060
top2 = 315
right2 = 1125
bottom2 = 350

# Cropping the image
img_crop_name = img.crop((left1, top1, right1, bottom1))
img_crop_value = img.crop((left2, top2, right2, bottom2))
# img_crop_name.show()
# img_crop_value.show()

# Converting the image to text
pytesseract.tesseract_cmd = r".\Tesseract-OCR\tesseract.exe"
name = pytesseract.image_to_string(img_crop_name)
value = pytesseract.image_to_string(img_crop_value)

print(f"{name[:-1]} : {value}")
