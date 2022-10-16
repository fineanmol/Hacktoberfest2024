from PIL import Image
import math

picture = Image.open('enter the location of the image that you want to compress')

x, y = picture.size
x2, y2 = math.floor(x-(x*87/100)), math.floor(y-(y*87/100))
picture_resize = picture.resize((x2,y2),Image.ANTIALIAS)
picture_resize.save("Location of image to be saved", "JPEG",optimize=True,quality=80)