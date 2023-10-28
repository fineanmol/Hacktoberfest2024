import time
import pyautogui
import win32gui
from PIL import ImageGrab

# 0 -> tree, 1 -> bank
player_pos = 0

def findGameWindow():
	try:
		return win32gui.FindWindow(None, 'Old School RuneScape')
	except:
		print("the game isn't open.")
		exit(0)

def getWindowRect(hwnd):
	return win32gui.GetWindowRect(hwnd)

def hideWindow(hwnd):
	win32gui.ShowWindow(hwnd, 0)

def showWindow(hwnd):
	win32gui.ShowWindow(hwnd, 1)

def setActiveWindow(hwnd):
	win32gui.SetForegroundWindow(hwnd)

def captureScreen():
	return ImageGrab.grab()

def isTreeAvailable():
	tree_colour = (72, 87, 12)
	tree_pos = (651, 319)
	screen = captureScreen()
	screen_pixel = screen.getpixel(tree_pos)
	if abs(screen_pixel[1] - tree_colour[1]) <= 10 :
		return True
	else:
		return False

def isInventoryFull():
	last_oak_wood_colour = (104, 70, 26)
	last_oak_wood_pos = (1535, 800)
	screen = captureScreen()
	screen_pixel = screen.getpixel(last_oak_wood_pos)
	if abs(screen_pixel[0] - last_oak_wood_colour[0]) <= 10:
		return True
	else:
		return False

def chopTree():
	pyautogui.moveTo(641, 325)
	pyautogui.click()
	time.sleep(1)

def goToBank():
	global player_pos
	map_bank_pos = (1545, 155)
	pyautogui.moveTo(map_bank_pos)
	pyautogui.click()
	player_pos = 1
	time.sleep(10)

def clickBankBooth():
	bank_booth_pos = (790, 425)
	pyautogui.moveTo(bank_booth_pos)
	pyautogui.click()
	time.sleep(1)

def depositWood():
	first_wood_pos = (1415, 585)
	pyautogui.moveTo(first_wood_pos)
	pyautogui.click()
	time.sleep(1)

def returnTree():
	global player_pos
	tree_pos = (417, 119)
	oak_word_pos = (86, 34)
	oak_word_colour = (0, 220, 220)
	pyautogui.moveTo(tree_pos)
	screen = captureScreen()
	screen_pixel = screen.getpixel(oak_word_pos)
	if abs(screen_pixel[0] - oak_word_colour[0]) <= 10:
		pyautogui.moveTo(tree_pos)
		pyautogui.click()
		player_pos = 0
		time.sleep(10)


def main():
	setActiveWindow(findGameWindow())
	while True:
		if isInventoryFull() and player_pos == 0:
			print('Going to bank')
			goToBank()
		elif isTreeAvailable() and player_pos == 0:
			print('Chopping tree')
			chopTree()
		elif isInventoryFull() and player_pos == 1:
			print('Clicking on bank booth')
			clickBankBooth()
			print('Depositing wood')
			depositWood()
			print('Returning to tree')
			returnTree()
		elif not isInventoryFull() and player_pos == 1:
			print('Returning to tree')
			returnTree()

		time.sleep(2)
	exit(0)

	
screen_size = captureScreen().size
game_screen_size = getWindowRect(findGameWindow())

main()

