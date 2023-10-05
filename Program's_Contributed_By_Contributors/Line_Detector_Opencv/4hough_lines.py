import numpy as np
from PIL import ImageGrab
import cv2
import time
import pyautogui



def draw_lines(img,lines):
    try:
        for line in lines:
            cords = line[0]
            cv2.line(img, (cords[0],cords[1]), (cords[2],cords[3]), [255,255,255], 3)
    except:
        pass
    



def roi(img,vertices):
    mask= np.zeros_like(img)
    cv2.fillPoly(mask,vertices,255)
    masked = cv2.bitwise_and(mask,img)
    return masked



def process_img(org_img):
    processed_img= cv2.cvtColor(org_img,cv2.COLOR_RGB2GRAY)
    processed_img=cv2.Canny(processed_img,threshold1=200,threshold2=300)
    
    # vertices = np.array([[0,600],[0,400],[200,200],[600,200],[800,400],[800,600]])
   
    

    vertices = np.array([[80,350],[80,400],[800,400],[800,350]])
    roi_img= roi(processed_img,[vertices])




    # bluring image although i dont think i need to do that
    roi_img = cv2.GaussianBlur(roi_img,(3,3),0)
    # gettinf lines from image 
    lines = cv2.HoughLinesP(roi_img,1,np.pi/180, 180,np.array([]), minLineLength=90,maxLineGap=5)
    draw_lines(roi_img,lines) #drawing line on image

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
