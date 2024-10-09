import pytesseract
from PIL import Image
img_file=""
no_noise=""
img = Image.open(no_noise)
ocr_result=pytesseract.image_to_string(img)
print(ocr_result)
