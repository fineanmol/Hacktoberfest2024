from pynput.keyboard import Key, Controller
import time

keyboard= Controller()

def auto(n):
    time.sleep(5)
    for i in n.split("\n"):
        keyboard.type(i)
        keyboard.press(Key.enter)
        time.sleep(0.01)

n='''



'''
auto(n) #this function is to call


