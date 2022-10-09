import os, sys
from PIL import Image

print('Image Resizer w/ pillow module _(:3 _|)_')
try:
    # init root directory tree 
    root_dir = os.path.abspath(".")    

    # sys.argv module begin with index 0, 1, 2 ... n 
    # example: ~$ python resize_img.py name-image.png 200 300 
    # which mean index orders:
    # 0 = python
    # 1 = resize_img.py
    # 2 = name-image.png
    # 3 = 200 
    # 4 = 300
    arg1 = sys.argv[1]
    new_width = int(sys.argv[2])
    new_height = int(sys.argv[3])

    # populate image to canvas
    img = Image.open(arg1) # image with *.png,*.jpg
    # module will resize image in canvas 
    img = img.resize((new_width, new_height), Image.ANTIALIAS)
    name = input('Input a name for resized image file: ')
    # saving those canvas to file 
    img.save('resize_'+name+'.png')
    print('Finish..')
except:
    print('\nUsage :\n ~$ python3 resize_image.py <name of image file, using *.png or *.jpeg> <new_width> <new_height>\n\nPlease install pillow library first using pip..\n\n pip3 install pillow\n')

