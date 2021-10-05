from PIL import Image
import pytesseract
import glob


def ocr(file_to_ocr):
    image = Image.open(file_to_ocr)
    txt = pytesseract.image_to_string(image, lang="ben+eng")
    return txt


for file in glob.glob("*.jpg"):
    txt = ocr(file)
    with open(f"{file[:-4]}.txt", "w", encoding="utf-8") as f:
        f.write(str(txt))
