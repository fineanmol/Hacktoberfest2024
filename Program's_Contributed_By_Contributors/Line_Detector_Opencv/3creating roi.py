import numpy as np
from PIL import ImageGrab
import cv2
import time
import pyautogui



def roi(img,vertices):
    mask= np.zeros_like(img)
    cv2.fillPoly(mask,vertices,255)
    masked = cv2.bitwise_and(mask,img)
    return masked



def process_img(org_img):
    processed_img= cv2.cvtColor(org_img,cv2.COLOR_RGB2GRAY)
    processed_img=cv2.Canny(processed_img,threshold1=200,threshold2=300)
    
    # vertices = np.array([[0,600],[0,400],[200,200],[600,200],[800,400],[800,600]])
    vertices = np.array([[0,350],[0,500],[700,500],[700,350]])
    
    

    roi_img= roi(processed_img,[vertices])
    # return processed_img
    return roi_img



    



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
