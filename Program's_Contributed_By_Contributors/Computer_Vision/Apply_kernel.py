import numpy as np
import cv2

def compute_value(sub_img, kernel):
    '''
        This function takes a k*k sub image and kernel(k X k) as input
        and Returns the computed value for that particular pixel
        after applying the Kernel
    '''
    sum = 0
    k = kernel.shape[0]
    for i in range(k):
        for j in range(k):
            sum += (sub_img[i,j] * kernel[i,j])
    return sum


def apply_kernel(img, kernel):
    '''
        This function takes the entire image and kernel as input
        and compute the value of each pixel by applying the kernel
        and Returns the resultant matrix
    '''
    row, col = img.shape
    k= kernel.shape[0]
    img = img.astype(int)
    new_img = np.zeros((row, col))
    for i in range(k//2, row-(k//2)):
        for j in range(k//2, col-(k//2)):
            new_img[i,j] = compute_value(img[i-(k//2):i+(k//2 +1), j-(k//2): j+(k//2+1)], kernel)
    return new_img


def set_pixel_val_withinRange(img):
    '''
        This function takes the resultant image (after applying the kernel) as input
        and replace all the negetive value with 0
        and replace all the value greater than 255 (> 255) with the value 255
        keeping all the value as it is which are in between 0-255 already
    '''
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            if img[i,j] > 255:
                img[i,j] = 255
            elif img[i,j] < 0:
                img[i,j] = 0    
    return img



if __name__=="__main__":

    '''Provide image path here'''
    path = '.../input_image_name.jpg'
    img = cv2.imread(path, 0)

    """Provide kernel values here (kernel size = k*k) where k must be a odd number"""
    kernel = np.array([[-1, -1, -1],
                       [-1, 8, -1],
                       [-1, -1, -1]])

    k = kernel.shape[0]

    cv2.imshow("Original img",img)
    new_img = apply_kernel(img, kernel) 

    '''Triming top, bottom and two sides of the resultant image'''
    new_img = new_img[k//2:-(k//2) , k//2:-(k//2)]

    new_img = set_pixel_val_withinRange(new_img)
    cv2.imshow("Image after applying kernel", new_img)

    cv2.waitKey(0)
    cv2.destroyAllWindows()