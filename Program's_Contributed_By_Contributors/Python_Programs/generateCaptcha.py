# try to make captcha image from our text using python

from captcha.image import ImageCaptcha

image = ImageCaptcha(width=280, height=90)
captcha_text = input('Enter the text for CAPTCHA: ')
data = image.generate(captcha_text)
image.write(captcha_text, 'CAPTCHA.png')
