import numpy as np
from PIL import ImageGrab
import cv2
import time
import pyautogui




def process_img(org_img):
    processed_img= cv2.cvtColor(org_img,cv2.COLOR_RGB2GRAY)
    processed_img=cv2.Canny(processed_img,threshold1=50,threshold2=200) # t1=200, t2=300
    return processed_img



    



while (1):
    last_time= time.time()
    screen = cv2.cvtColor(np.array( ImageGrab.grab(bbox=(0,20,800, 600))),cv2.COLOR_BGR2RGB)
    print(f"loop tool {time.time()-last_time} second")
    processed_img = process_img(screen)
    cv2.imshow("processde_img",processed_img)
    # cv2.imshow("win",screen)
    if cv2.waitKey(25) & 0xFF == ord('q'):
        cv2.destroyAllWindows()
        break
