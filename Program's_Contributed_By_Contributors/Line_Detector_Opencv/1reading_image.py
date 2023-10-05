



import numpy as np
from PIL import ImageGrab
import cv2


# too slow

# while (1):
#     screen = ImageGrab.grab(bbox=(0,20,800, 640))        # 1d array of the screenshot
#     screen_np = np.array(screen.getdata(),dtype='uint8')\
#         .reshape((screen.size[1],screen.size[0],3))      #screen.size return dimensionof image (width,height)
#     cv2.imshow("window",screen_np)
#     if cv2.waitKey(25) & 0xFF == ord('q'):w
#         cv2.destroyAllWindows()
#         break


# tryin another  faster as we are avoideing getting data from pil obejct and directly passing it to imshow
while (1):
    # screen = ImageGrab.grab(bbox=(0,20,800, 600))        # 1d array of the screenshot
    screen = cv2.cvtColor(np.array( ImageGrab.grab(bbox=(0,20,800, 600))),cv2.COLOR_BGR2RGB)
    # cv2.imshow("window",cv2.cvtColor( np.array(screen),cv2.COLOR_BGR2RGB))
    cv2.imshow("win",screen)
    if cv2.waitKey(25) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break


