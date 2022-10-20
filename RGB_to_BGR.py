import cv2

img= cv2.imread("image.png",-1)
# -1 so it reads the image in BGR format
cv2.imshow("rgb",img)
img1=cv2.cvtColor(img,cv2.COLOR_RGB2BGR)
cv2.imshow("bgr",img1)

cv2.waitKey(10000)
cv2.destroyAllWindows()
