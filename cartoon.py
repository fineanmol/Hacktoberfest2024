import os
import argparse
import cv2
from utils import read_img, edge_detection, color_quantisation

parser = argparse.ArgumentParser(description='Cartoonify Face Images')
parser.add_argument('--input_path', default='./temp/image.jpg', type=str, help='Directory of input images or path of single image')
parser.add_argument('--result_dir', default='./temp/', type=str, help='Directory for restored results')


args = parser.parse_args()
out_dir = args.result_dir
os.makedirs(out_dir, exist_ok=True)


img = read_img(args.input_path)

line_wdt = 9
blur_value=7
totalcolours=9

edgeImg = edge_detection(img, line_wdt,blur_value)
img = color_quantisation(img, totalcolours)
blurred = cv2.bilateralFilter(img, d=7,sigmaColor=200,sigmaSpace=200) 
cartoon = cv2.bitwise_and(blurred,blurred,mask=edgeImg)
out_path = os.path.join(out_dir, os.path.split(args.input_path)[-1])
cv2.imwrite(out_path,cv2.cvtColor(cartoon, cv2.COLOR_RGB2BGR))