import pygame as pg
import os
"""This module keeps settings of Game."""
WIDTH=600  #Game screen Width
HEIGHT=700  #Game screen height
FPS=30  #Frame rate of game(frames per second)
TEXTSIZE=30  #size of text,player's score
TEXTCOLOR=(255,255,255)  #TextColor of player's score

PGIMLOAD=pg.image.load  #typedefines the pygame's image module's load method
OSPJ=os.path.join  #typedefine os module's path.join method
path='spaceArt'+os.sep+'png'+os.sep  #sets path of all sprites