import pyautogui
import os
import time
emotion=input("enter emotion")
print(emotion)
os.system("Spotify")
time.sleep(5)
if(emotion.lower()=="neutral"):
    pyautogui.hotkey('ctrl','l')
    pyautogui.write('\t\tfrustration remover', interval=0.2)

    for key in ['enter', 'pagedown', 'tab', 'tab', 'enter']:
        time.sleep(2)
        pyautogui.press(key)
elif(emotion.lower()=="surprise")or(emotion.lower()=="happy"):
    pyautogui.hotkey('ctrl','l')
    pyautogui.write('\t\thappy english songs', interval=0.2)

    for key in ['enter', 'pagedown', 'tab', 'tab', 'enter']:
        time.sleep(2)
        pyautogui.press(key)
elif(emotion.lower()=="sad"):
    pyautogui.hotkey('ctrl','l')
    pyautogui.write('\t\tsad english songs', interval=0.2)

    for key in ['enter', 'pagedown', 'tab', 'tab', 'enter']:
        time.sleep(2)
        pyautogui.press(key)
elif(emotion.lower()=="angry"):
    pyautogui.hotkey('ctrl','l')
    pyautogui.write('\t\tangry english', interval=0.2)

    for key in ['enter', 'pagedown', 'tab', 'tab', 'enter']:
        time.sleep(2)
        pyautogui.press(key)
