import numpy as np
import cv2


def slice_intensity(img_path, lower_range, upper_range):
    '''
    INPUT : 
        image_path : path where your image is located
        lower_range : lower range pixel value (0 - 255) for slicing
        upper_range : upper range pixel value (0 - 255) for slicing

    RETURNS : Sliced grayscale image    
    '''
    img = cv2.imread(img_path, 0)
    row, col = img.shape

    for i in range(row):
        for j in range(col):
            if img[i,j] < lower_range or img[i,j] > upper_range:
                img[i,j] = 0
    return img       


if __name__=="__main__":

    '''
    Provide the path here, where your image is located
    '''
    image_path = r'......./input_image.jpg'

    sliced_image = slice_intensity(image_path, 10, 170)
    cv2.imshow("sliced_image", sliced_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()