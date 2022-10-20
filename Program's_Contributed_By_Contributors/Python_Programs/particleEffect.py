# Author : John Smith 
# Library/ Framework Used : Pygame
# Simple rain particle effect using pygame
import pygame
import random
import sys
import time

pygame.init()

blue = (135,206,250)
black = (0,0,0)
white = (255,255,255)

gravity = 10
FPS = 120
width = 1200
height = 980
rainSize = 7
rainNum = 200

varHeight = height
rainColor = white
bgColor = black

gameOver = False

display = pygame.display.set_mode((width,height))
pygame.display.set_caption('Rain')

rainDrops = []

for q in range(rainNum):
    x = random.randrange(0,width)
    y = random.randrange(0,varHeight)
    rainDrops.append([x,y])
clock = pygame.time.Clock()
while not gameOver:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameOver = True
    
    display.fill(bgColor)
    
    for i in rainDrops:
        i[1] += gravity
    
        pygame.draw.circle(display,rainColor,i,rainSize)
        
        if i[1] > varHeight:
            i[1] = random.randrange(-50,5)
            i[0] = random.randrange(width)
    
    pygame.display.flip()
    clock.tick(FPS)

