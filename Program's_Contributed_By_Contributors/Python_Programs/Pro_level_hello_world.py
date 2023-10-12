# Install Pygame if not already installed
# You can install Pygame using pip by running this command in your terminal:
# pip install pygame

import pygame
import sys
import time
import math

pygame.init()

width, height = 800, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption('Blinking Hello, World!')

font = pygame.font.Font(None, 72)
text = font.render("Hello, World!", True, (255, 255, 255))  # White text

blink_interval = 0.5  # Blinking interval in seconds
last_blink_time = time.time()

running = True
show_text = True

rainbow_colors = [(255, 0, 0), (255, 165, 0), (255, 255, 0), (0, 128, 0), (0, 0, 255), (75, 0, 130), (143, 0, 255)]  # Rainbow colors

color_index = 0
color_change_interval = 1  # Color change interval in seconds
last_color_change_time = time.time()

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill((0, 0, 0))  # Black background

    current_time = time.time()

    if current_time - last_blink_time >= blink_interval:
        show_text = not show_text
        last_blink_time = current_time

    if current_time - last_color_change_time >= color_change_interval:
        color_index = (color_index + 1) % len(rainbow_colors)
        last_color_change_time = current_time
        text = font.render("Hello, World!", True, rainbow_colors[color_index])

    if show_text:
        screen.blit(text, (width // 2 - text.get_width() // 2, height // 2 - text.get_height() // 2))

    pygame.display.update()

pygame.quit()
sys.exit()
