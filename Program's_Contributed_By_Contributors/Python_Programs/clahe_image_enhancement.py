import cv2
import matplotlib.pyplot as plt

def apply_clahe_and_display(image_path, clip_limit=2.0, grid_size=(8, 8)):
    # Load the image
    image = cv2.imread(image_path, 0)  # Load as grayscale

    # Apply CLAHE
    clahe = cv2.createCLAHE(clipLimit=clip_limit, tileGridSize=grid_size)
    clahe_image = clahe.apply(image)

    # Display the original and CLAHE images
    plt.figure(figsize=(10, 5))
    plt.subplot(121)
    plt.imshow(image, cmap='gray')
    plt.title('Original Image')
    plt.axis('off')

    plt.subplot(122)
    plt.imshow(clahe_image, cmap='gray')
    plt.title('CLAHE Preprocessed Image')
    plt.axis('off')

    plt.show()

# Example usage:
input_image_path = 'input_image.jpg'
apply_clahe_and_display(input_image_path, clip_limit=2.0, grid_size=(8, 8))
