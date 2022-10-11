#Image Crop and Resize
import os
import sys
import glob
from PIL import Image

# Get the path of the folder containing the images from the user
path = input("Enter the path of the folder containing the images: ")
# Get the size to resize the images to from the user
Resolution = int(input("Enter the size to resize the images to: "))
# Change the current working directory to the given path
# os.chdir(path)
# Get the current working directory
cwd = os.getcwd()
# Get the list of all files in that directory
files = glob.glob(cwd + "/*.jpg")
# Iterate over the list of files
for file in files:
    # Open each file
    img = Image.open(file)
    # Get the width and height of the image
    width, height = img.size
    # Check if width is greater than height
    if width > height:
        # Calculate the ratio
        ratio = height/width
        # Resize the image
        img = img.resize((Resolution, int(Resolution*ratio)), Image.Resampling.LANCZOS)
        # Crop the image
        img = img.crop((0, 0, Resolution, Resolution))
    # If height is greater than width
    elif height > width:
        # Calculate the ratio
        ratio = width/height
        # Resize the image
        img = img.resize((int(Resolution*ratio), Resolution), Image.Resampling.LANCZOS)
        # Crop the image
        img = img.crop((0, 0, Resolution, Resolution))
    # If width and height are equal
    else:
        # Resize the image
        img = img.resize((Resolution, Resolution), Image.Resampling.LANCZOS)
    # Save the image
    img.save(file)