#opening an image
import cv2
import numpy as np
from matplotlib import pyplot as plt

image_file="OCR/pictures/sample.jpg"
img = cv2.imread(image_file)

cv2.imshow("original image",img)
cv2.waitKey(0)

def display(im_path):
    dpi=80
    im_data=plt.imread(im_path)
    height,width,depth=im_data.shape
    figsize=width/float(dpi),height/float(dpi)
    fig=plt.figure(figsize=figsize)
    ax=fig.add_axes([0,0,1,1])
    ax.axis('off')
    ax.imshow(im_data,cmap='gray')
    plt.show()
    
    
#inverting an image
inverted_image=cv2.bitwise_not(img)
cv2.imwrite("OCR/temp/inverted.jpg",inverted_image)

#binarization
def grayscale(image):
    return cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)

gray_image=grayscale(img)
cv2.imwrite("OCR/temp/gray.jpg",gray_image)
thresh,im_bw = cv2.threshold(gray_image,127,255, cv2.THRESH_BINARY)
cv2.imwrite("OCR/temp/gray.jpg",im_bw)

#noise removal

def noise_removal(image):
    kernal = np.ones((1,1), np.unint8)
    image = cv2.dilate(image,kernal,iterations=1)
    kernel=np.ones((1,1),np.uint8)
    image = cv2.erode(image,kernel,iterations=1)
    image=cv2.morphologyEx(image,cv2.MORPH_CLOSE,kernel)
    image=cv2.medianBlur(image,3)
    return (image)

no_noise=noise_removal(im_bw)
cv2.imwrite("OCR/temp/no_noise.jpg",no_noise)


#dilation and erosion
def thick_font(image):
    image=cv2.bitwise_not(image)
    kernel=np.ones((2,2),np.uint8)
    image=cv2.erode(image,kernel,iterations=1)
    image=cv2.bitwise_not(image)
    return(image)

# eroded_image=thik_font(no_noise)
# cv2.imwrite("",eroded_image)

dilated_image=thick_font(no_noise)
cv2.imwrite("OCR/temp/eroded_image.jpg",dilated_image)


#rotating 

new = cv2.imread("")

def getSkewAngle(cvImage) -> float:
    # Prep image, copy, convert to gray scale, blur, and threshold
    newImage = cvImage.copy()
    gray = cv2.cvtColor(newImage, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (9, 9), 0)
    thresh = cv2.threshold(blur, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]

    # Apply dilate to merge text into meaningful lines/paragraphs.
    # Use larger kernel on X axis to merge characters into single line, cancelling out any spaces.
    # But use smaller kernel on Y axis to separate between different blocks of text
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (30, 5))
    dilate = cv2.dilate(thresh, kernel, iterations=5)

    # Find all contours
    contours, hierarchy = cv2.findContours(dilate, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    contours = sorted(contours, key = cv2.contourArea, reverse = True)

    # Find largest contour and surround in min area box
    largestContour = contours[0]
    minAreaRect = cv2.minAreaRect(largestContour)

    # Determine the angle. Convert it to the value that was originally used to obtain skewed image
    angle = minAreaRect[-1]
    if angle < -45:
        angle = 90 + angle
    return -1.0 * angle

# Rotate the image around its center
def rotateImage(cvImage, angle: float):
    newImage = cvImage.copy()
    (h, w) = newImage.shape[:2]
    center = (w // 2, h // 2)
    M = cv2.getRotationMatrix2D(center, angle, 1.0)
    newImage = cv2.warpAffine(newImage, M, (w, h), flags=cv2.INTER_CUBIC, borderMode=cv2.BORDER_REPLICATE)
    return newImage

# Deskew image
def deskew(cvImage):
    angle = getSkewAngle(cvImage)
    return rotateImage(cvImage, -1.0 * angle)

fixed = deskew(new)
cv2.imwrite("",fixed)

