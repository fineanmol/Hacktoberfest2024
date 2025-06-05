import time

import pyautogui
from PIL import ImageGrab

# TODO 1. Stop the script if the player dies

x_position = 360

def capture_screen():
	screen = ImageGrab.grab()
	return screen
	
def detect_enemy(screen):
	f_colour = screen.getpixel((int(x_position), 405))
	for x in range(int(x_position), int(x_position + 15)):
		for y in range(405, 465):
			colour = screen.getpixel((x, y))
			if colour != f_colour:
				return True
			else:
				f_colour = colour

def jump():
	global x_position
	pyautogui.press('up')
	print(time.process_time())
	if time.process_time() < 30:
		x_position += (time.process_time()/10)
	else:
		x_position += (time.process_time()/5)

print('Starting in 3 seconds...')
time.sleep(3)

while True:
	screen = capture_screen()
	if detect_enemy(screen):
		jump()
	