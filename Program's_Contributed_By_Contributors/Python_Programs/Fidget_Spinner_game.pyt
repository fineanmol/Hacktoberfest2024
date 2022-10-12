import pygame
import sys
from math import *
   

pygame.init()

width = 500
height = 500

display = pygame.display.set_mode((width, height))
clock = pygame.time.Clock()
pygame.display.set_caption("Fidget Spinner ")
# all needed colors
background = (51, 51, 51)
white = (240, 240, 240)
red = (176, 58, 46)
dark_red = (120, 40, 31)
dark_gray = (23, 32, 42)
blue = (40, 116, 166)
dark_blue = (26, 82, 118)
yellow = (183, 149, 11)
dark_yellow = (125, 102, 8)
green = (29, 131, 72)
dark_green = (20, 90, 50)
orange = (230, 126, 34)
dark_orange = (126, 81, 9)


# Closing the game
def close():
    pygame.quit()
    sys.exit()


# Fidget spinner model
def show_spinner(angle, color, dark_color):
    d = 80
    innerd = 50
    x = width/2 - d/2
    y = height/2
    l = 200
    r = l/(3**0.5)
    w = 10
    lw = 60
    
    centre = [x, y, d, d]
    centre_inner = [x + d/2 - innerd/2, y + d/2 - innerd/2, innerd, innerd]
    
    top = [x, y - l/(3)**0.5, d, d]
    top_inner = [x, y - l/(3)**0.5, innerd, innerd]

    top[0] = x + r*cos(radians(angle))
    top[1] = y + r*sin(radians(angle))
    top_inner[0] = x + d/2 - innerd/2 + r*cos(radians(angle))
    top_inner[1] = y + d/2 - innerd/2 + r*sin(radians(angle))
    
    left = [x - l/2, y + l/(2*(3)**0.5), d, d]
    left_inner = [x, y - l/(3)**0.5, innerd, innerd]

    left[0] = x + r*cos(radians(angle - 120))
    left[1] = y + r*sin(radians(angle - 120))
    left_inner[0] = x + d/2 - innerd/2 + r*cos(radians(angle - 120))
    left_inner[1] = y + d/2 - innerd/2 + r*sin(radians(angle - 120))
    
    
    right = [x + l/2, y + l/(2*(3)**0.5), d, d]
    right_inner = [x, y - l/(3)**0.5, innerd, innerd]

    right[0] = x + r*cos(radians(angle + 120))
    right[1] = y + r*sin(radians(angle + 120))
    right_inner[0] = x + d/2 - innerd/2 + r*cos(radians(angle + 120))
    right_inner[1] = y + d/2 - innerd/2 + r*sin(radians(angle + 120))
    
    pygame.draw.line(display, dark_color, (top[0] + d/2, top[1] + d/2), (centre[0] + d/2, centre[1] + d/2), lw)
    pygame.draw.line(display, dark_color, (left[0] + d/2, left[1] + d/2), (centre[0] + d/2, centre[1] + d/2), lw)
    pygame.draw.line(display, dark_color, (right[0] + d/2, right[1] + d/2), (centre[0] + d/2, centre[1] + d/2), lw)
    pygame.draw.ellipse(display, color, tuple(centre))
    pygame.draw.ellipse(display, dark_color, tuple(centre_inner))
    pygame.draw.ellipse(display, color, tuple(top))
    pygame.draw.ellipse(display, dark_gray, tuple(top_inner), 10)
    pygame.draw.ellipse(display, color, tuple(left))
    pygame.draw.ellipse(display, dark_gray, tuple(left_inner), 10)
    pygame.draw.ellipse(display, color, tuple(right))
    pygame.draw.ellipse(display, dark_gray, tuple(right_inner), 10)
    

# Users Instructions 
def show_info(friction, speed):
    font = pygame.font.SysFont("Times New Roman", 22)
    speedText = font.render("Click and hold <-Left or Right -> keys to Spin ", True, white)
    frictionText = font.render("Click Space to change Color", True, white)
    display.blit(speedText, (15, 15))
    display.blit(frictionText, (15, 45))


# The Main Function
def spinner():
    spin = True

    angle = 0

    speed = 0.0
    friction = 0.03
    rightPressed = False
    leftPressed = False

    direction = 1
    color = [[red, dark_red], [blue, dark_blue], [yellow, dark_yellow], [green, dark_green], [orange, dark_orange]]
    index = 0
    
    while spin:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                close()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    close()
                if event.key == pygame.K_RIGHT:
                    rightPressed = True
                    direction = 1
                if event.key == pygame.K_LEFT:
                    leftPressed = True
                    direction = -1
                if event.key == pygame.K_SPACE:
                    index += 1
                    if index >= len(color):
                        index = 0
            if event.type == pygame.KEYUP:
                leftPressed = False
                rightPressed = False

        #Changing rotation angle
        if direction == 1:
            if rightPressed:
                speed += 0.3
            else:
                speed -= friction
                if speed < 0:
                    speed = 0.0
        else:
            if leftPressed:
                speed -= 0.3
            else:
                speed += friction
                if speed > 0:
                    speed = 0.0
                    
        display.fill(background)
        
        angle += speed

        #Fidget spinner
        show_spinner(angle, color[index][0], color[index][1])
        show_info(friction, speed)
        
        pygame.display.update()
        clock.tick(90)

spinner()
