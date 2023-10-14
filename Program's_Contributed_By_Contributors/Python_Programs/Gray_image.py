##image read and showing using cv2
import cv2
path=r"Norway.jpg"##r(raw string) - to work backslash not as \n(escape sequence) or we can use double back slashes or forward slashes
src=cv2.imread(path)
image=cv2.cvtColor(src,cv2.COLOR_RGB2GRAY)
cv2.imshow("norway",image)
cv2.waitKey(0)##presenting time
cv2.destroyAllWindows()