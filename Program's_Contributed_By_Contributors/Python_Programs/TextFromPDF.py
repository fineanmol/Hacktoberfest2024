import pdf2image
import os
import sys
try:
    from PIL import Image
except ImportError:
    import Image
import pytesseract

PATH = input('Enter the path: ')
i = 1


def delete_ppms():
    for file in os.listdir(PATH):
        if '.ppm' in file or '.DS_Store' in file:
            try:
                os.remove(PATH + file)
            except FileNotFoundError:
                pass


pdf_files = []
docx_files = []

# append document names into the lists by their extension type
for f in os.listdir(PATH):
    full_name = os.path.join(PATH, f)
    if os.path.isfile(full_name):
        name = os.path.basename(f)
        filename, ext = os.path.splitext(name)
        if ext == '.pdf':
            pdf_files.append(name)
        elif ext == ('.docx'):
            docx_files.append(name)


def pdf_extract(file, i):
    print("extracting from file:", file)
    delete_ppms()
    images = pdf2image.convert_from_path(PATH + file, output_folder=PATH)
    j = 0
    for file in sorted(os.listdir(PATH)):
        if '.ppm' in file and 'image' not in file:
            os.rename(PATH + file, PATH + 'image' +
                      str(i) + '-' + str(j) + '.ppm')
            j += 1
    j = 0
    f = open(PATH + 'result{}.txt'.format(i), 'w')
    files = [f for f in os.listdir(PATH) if '.ppm' in f]

    for file in sorted(files, key=lambda x: int(x[x.index('-') + 1: x.index('.')])):
        temp = pytesseract.image_to_string(Image.open(PATH + file))
        f.write(temp)
    f.close()


for i in range(len(pdf_files)):
    pdf_file = pdf_files[i]
    pdf_extract(pdf_file, i)
