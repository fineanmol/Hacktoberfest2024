import tkinter
from datetime import datetime
import time
from tkinter import messagebox
THEME_WINDOW_BG, THEME_FOREGROUND = open("theme_config.txt").read().split("\n")
SHOWN_TIMER = False
SHOWN_ALARMS = False
def showTimer(e=None):
    def updateTime(e=None):
        timerTime = int(timerEntry.get())
        timerLabel = tkinter.Label(timerFrame, text=f"{timerTime}", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
        timerLabel.grid(row=0, column=0)
        for t in range(0, timerTime):
            if t == timerTime:
                timerLabel.configure(text='0')
            timerLabel.configure(text=f"{timerTime-t}")
            timerFrame.update()
            alarmWindow.update()
            time.sleep(1)
        # while timerTime > 0:
        #     timerFrame.after(1000, updateLabel)
        #     if timerTime == 0:
        #         timerLabel.configure(text="0")
        #         break
        else:
            messagebox.showerror("Timer finished", "Timer ran out!!!")

            
    global SHOWN_ALARMS
    global timerFrame
    global alarmFrame
    if SHOWN_ALARMS: alarmFrame.destroy()
    SHOWN_ALARMS = False
    timerFrame = tkinter.Frame(alarmWindow, background=THEME_WINDOW_BG)
    timerFrame.grid(row=0, column=1)
    timerEntry = tkinter.Entry(timerFrame, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    timerEntry.configure(insertbackground=THEME_FOREGROUND, selectbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG)
    timerEntry.grid(row=1, column=0)
    startTimerBtn = tkinter.Button(timerFrame, text="Start Timer!", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=updateTime)
    startTimerBtn.grid(row=1, column=1)
    
def showAlarms(e=None):
    global SHOWN_TIMER
    global timerFrame
    global alarmFrame
    if SHOWN_TIMER: timerFrame.destroy()
    SHOWN_TIMER = False
    alarmFrame = tkinter.Frame(alarmWindow, background=THEME_WINDOW_BG)
    alarmFrame.grid(row=0, column=1)
def main(*args):
    global alarmWindow
    global sidebar
    alarmWindow = tkinter.Toplevel(background=THEME_WINDOW_BG)
    sidebar = tkinter.Frame(alarmWindow, background=THEME_WINDOW_BG)
    sidebar.grid(row=0, column=0)
    timerBtn = tkinter.Button(sidebar, text="Timer", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=showTimer)
    timerBtn.grid(row=0, column=0)
    alarmBtn = tkinter.Button(sidebar, text="Alarm", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=showAlarms)
    alarmBtn.grid(row=1, column=0)
    alarmWindow.mainloop()
def focusIn(): alarmWindow.state(newstate='normal'); 
def focusOut(): alarmWindow.state(newstate='iconic'); 
if __name__ == "__main__":
    main()