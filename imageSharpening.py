import cv2
import numpy as np

#FOR IMAGE SHARPENING
image=cv2.imread('E:/Codes/Internshala Assignment/test.jpg',flags=cv2.IMREAD_COLOR)


cv2.imshow('Sample Image',image)
cv2.waitKey()
cv2.destroyAllWindows()


kernel=np.array([[0,-1,0],
                 [-1,5,-1],
                 [0,-1,0]])
image_sharp=cv2.filter2D(src=image, ddepth=-1, kernel=kernel)
cv2.imshow('Sharpened Image', image_sharp)
cv2.waitKey()
cv2.destroyAllWindows()

