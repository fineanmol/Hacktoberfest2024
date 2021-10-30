import numpy as np
from imageio import imread, imwrite
import cv2
img= imread('image1.jpeg')
arr=img * np.array( [0.1, 0.2, 0.5])
arr2 = (255*arr/arr.max()).astype(np. uint8)
imwrite('image1.jpeg',arr2)
img2= cv2.imread('srudhe.jpeg')
gamma= 2 #More the gamma more will be the darkness 
gamma_img= np.array(255*(img2/255) **gamma, dtype='uint8') 
cv2.imwrite('image2.jpeg',gamma_img)
print("Conversion Done!")
