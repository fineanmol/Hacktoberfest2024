import cv2
import numpy as np

img = cv2.imread('Greyscale.jpg', cv2.IMREAD_UNCHANGED)
experiment = np.zeros((img.shape[0],img.shape[1]),dtype = 'uint8')

#Red Channel
red = img[:,:,2]
redChannel = np.zeros(img.shape)
redChannel[:,:,2] = red

#Green Channel
green = img[:,:,1]
greenchannel= np.zeros(img.shape)
greenchannel[:,:,1] = green

#Blue Channel
blue = img[:,:,0]
bluechannel = np.zeros(img.shape)
bluechannel[:,:,0] = blue

#Greyscale process to the average of pixels
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        for k in range(img.shape[2]):
            experiment[i,j] = (redChannel[i][j][k] + greenchannel[i][j][k]
                               + bluechannel[i][j][k])/3


cv2.imshow("Uji", experiment)
cv2.waitKey(0)