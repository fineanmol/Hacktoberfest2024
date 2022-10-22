import pyautogui as pg
import time
time.sleep(10)

for i in range(10): #range defines no of times 
  pg.write('Enter your text')
  pg.press('Enter')
