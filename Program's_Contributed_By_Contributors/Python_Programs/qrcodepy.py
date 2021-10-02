import qrcode
from qrcode.image.styledpil import StyledPilImage
from qrcode.image.styles.moduledrawers import RoundedModuleDrawer

qr = qrcode.QRCode(error_correction=qrcode.constants.ERROR_CORRECT_L)
qr.add_data("https://www.youtube.com/watch?v=dQw4w9WgXcQ")

img_1 = qr.make_image(image_factory=StyledPilImage, module_drawer=RoundedModuleDrawer())
'''img_3 = qr.make_image(image_factory=StyledPilImage, embeded_image_path="/path/to/image.png")'''

img_1.save("qr.png")

'''img = qrcode.make("www.google.com")
img.save("qr1.png")'''
