import pygame
from PIL import Image, ImageDraw

pygame.init()

# Set the dimensions of the Pygame window
window_width = 800
window_height = 600
screen = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("Grid with Brain")

# Load your background image (brain image)
brain_image = pygame.image.load('brain.jpg')  # Replace with your brain image file path

# Create a new image with the same dimensions as the window
grid_background = Image.new("RGB", (window_width, window_height), (255, 255, 255))  # White background

# Draw a grid on the new image
grid_color = (0, 255, 0)  # Black color for the grid lines
grid_spacing = 133  # Adjust the spacing between grid lines as needed
draw = ImageDraw.Draw(grid_background)

for x in range(0, window_width, grid_spacing):
    draw.line([(x, 0), (x, window_height)], fill=grid_color)

for y in range(0, window_height, grid_spacing):
    draw.line([(0, y), (window_width, y)], fill=grid_color)

# Convert the brain image to the same size as the window
brain_image = pygame.transform.scale(brain_image, (window_width, window_height))

running = True

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 0))  # Clear the screen
    
    screen.blit(brain_image, (0, 0))  # Draw your brain image as the background

    # Draw the grid on top of the brain image
    for x in range(0, window_width, grid_spacing):
        pygame.draw.line(screen, grid_color, (x, 0), (x, window_height))

    for y in range(0, window_height, grid_spacing):
        pygame.draw.line(screen, grid_color, (0, y), (window_width, y))

    pygame.display.flip()  # Update the display

pygame.quit()
