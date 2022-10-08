import cv2  
import numpy as np
import sys

def noise_attenuator(img1: np.ndarray, img2: np.ndarray, img3: np.ndarray, img4: np.ndarray, img5: np.ndarray, img6: np.ndarray, img7: np.ndarray, img8: np.ndarray, img9: np.ndarray):
    noiseless_img = np.ones(img1.shape, dtype=np.float32)
    noiseless_img = np.add(noiseless_img, img1)
    noiseless_img = np.add(noiseless_img, img2)
    noiseless_img = np.add(noiseless_img, img3)
    noiseless_img = np.add(noiseless_img, img4)
    noiseless_img = np.add(noiseless_img, img5)
    noiseless_img = np.add(noiseless_img, img6)
    noiseless_img = np.add(noiseless_img, img7)
    noiseless_img = np.add(noiseless_img, img8)
    noiseless_img = np.add(noiseless_img, img9)
    noiseless_img = np.divide(noiseless_img, 9)
    cv2.imshow("image", noiseless_img.astype(np.uint8)) 
    cv2.waitKey(0) 
    return 0

def main():
    try:
        pth_img1 = sys.argv[1]
        pth_img2 = sys.argv[2]
        pth_img3 = sys.argv[3]
        pth_img4 = sys.argv[4]
        pth_img5 = sys.argv[5]
        pth_img6 = sys.argv[6]
        pth_img7 = sys.argv[7]
        pth_img8 = sys.argv[8]
        pth_img9 = sys.argv[9]
        img1 = cv2.imread(pth_img1)
        img2 = cv2.imread(pth_img2)
        img3 = cv2.imread(pth_img3)
        img4 = cv2.imread(pth_img4)
        img5 = cv2.imread(pth_img5)
        img6 = cv2.imread(pth_img6)
        img7 = cv2.imread(pth_img7)
        img8 = cv2.imread(pth_img8)
        img9 = cv2.imread(pth_img9)
    except:
        print("Insira um caminho válido para as 9 imagens")
        return -1
    noise_attenuator(img1, img2, img3, img4, img5, img6, img7, img8, img9)

if __name__ == '__main__':
    main()