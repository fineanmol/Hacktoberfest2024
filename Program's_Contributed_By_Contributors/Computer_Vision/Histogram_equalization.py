import numpy as np
import cv2
import matplotlib.pyplot as plt

def hist_equalizer(img):
    '''
    INPUTS : An image array
    RETURNS : Histogram equalized grayscale image
    '''
    arr = np.zeros((256))
    row, col = img.shape
    new_img = np.zeros([row,col], dtype = np.uint8)

    '''
    Creating Frequency array named "arr" 
    '''
    for i in range(row):
        for j in range(col):
            arr[img[i,j]] += 1
        
    sorted_pixel = list(set(sorted(img.flatten())))
    
    '''
    Creating Cumulative density function (cdf) Array
    '''
    cdf = []
    for i in range(len(sorted_pixel)):
        if len(cdf) != 0:
            cdf.append(cdf[-1] + arr[sorted_pixel[i]])
        else:
            cdf.append(arr[sorted_pixel[i]])

    ''' 
    Creating hv Values for corresponding pixels
    '''        
    hv = []
    min_cdf= min(cdf)
    for i in cdf:
        hv.append(round(((i - min_cdf)/ (row*col - min_cdf)) * 255 ))

    ''' 
    This dictionary holds the current pixel value (key) and its hv Value (value)
    '''
    pixel_hv_dict = dict(zip(sorted_pixel, hv))

    for i in range(row):
        for j in range(col):
            new_img[i,j] = int(pixel_hv_dict[img[i,j]])
    return new_img


def plot_histogram(equalized_image):
    fig, ax = plt.subplots(figsize =(10, 5))
    ax.hist(img.flatten(), bins=300, color='red')
    ax.hist(equalized_image.flatten(), bins=300, color='black')
    plt.title('Before(Red color) and After(black color) applying Histogram Equalizer')
    plt.xlabel('Pixel_intensity')
    plt.ylabel('Frequency')
    plt.show()



if __name__=="__main__":

    '''Provide the path of the image here'''
    path = '.../input_image_name.jpg'

    '''Displaying original image'''
    img = cv2.imread(path, 0)
    cv2.imshow("Original_image", img)

    '''Displaying histogram equalized image'''
    equalized__image = hist_equalizer(img)
    cv2.imshow("equalized_image",equalized__image)

    '''Histogram plots comparison before and after equalization'''
    plot_histogram(equalized__image)

    cv2.waitKey(0)
    cv2.destroyAllWindows()

