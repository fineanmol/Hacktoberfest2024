import tkinter
import os
import subprocess
import tkinter.ttk as ttk
import psutil
from pathlib import Path
from tkinter import filedialog
THEME_WINDOW_BG, THEME_FOREGROUND = open("theme_config.txt").read().split("\n")
PROCESS_RUNNING = True
def refresh():
    global externalAppsList
    for i in externalAppsList.get_children():
        externalAppsList.delete(i)
    for dirpath, dirnames, filenames in os.walk(os.getcwd(), topdown=True):
        for file in Path(dirpath).glob("*SETUP.py"):
            externalAppsName.append(file)
    for file in range(len(externalAppsName)):
        externalAppsList.configure(style="Treeview")
        for i in externalAppsList.get_children():
            externalAppsList.delete(i)
        externalAppsList.insert(parent='', iid=file, text='', index=file, values=[externalAppsName[file]],)
def load(file: str = None, e=None):
    if file == None:
        indexSelect = externalAppsList.focus()
        fileToStart = externalAppsList.item(indexSelect, 'values')[0]
    else:
        fileToStart = file
    # The old code, this code actually failed because of the os call, and when the program is running
    #Yeah, as the program is running, the OS will freeze untill the program is closed somehow
    #So this idea was scrapped to a better solution, to use the subprocess.Popen method to do the thing without freezing the OS
    # So below is the old, failed code.
    # Note: If you want to access this code from function calls (ie not editing source code directly), 
    # Then, use the "use_legacy" parameter of the LoadExternalApps function to use the legacy code. 
    process = subprocess.Popen(["python3", f"{fileToStart}"])
def show(e=None):
    global externalAppsList
    global buttonText
    global showRefreshBtn
    buttonText = "Refresh"
    showRefreshBtn.configure(text=buttonText, command=refresh)
    externalAppsList = ttk.Treeview(externalApps, style="Treeview")
    externalAppsList.grid(row=1, column=0, sticky="w")
    externalAppsList['column'] = "Apps"
    externalAppsList.column("#0", anchor=tkinter.W, width=0, stretch=tkinter.NO)
    externalAppsList.column("Apps", anchor=tkinter.W, width=600)
    externalAppsList.heading("Apps", text="Apps", anchor=tkinter.CENTER)
    def a(e=None): load(None)
    externalAppsList.bind("<<TreeviewSelect>>", a)
    externalAppsList.configure(style="Treeview")
    refresh()
def loadCustomApp():
    fileToOpen = filedialog.askopenfilename(title="Select app to run!", filetypes=(("Windows 11 Apps", "*.py"), ("All Files", "*.*")))
    load(file=fileToOpen)
def main(*args):
    global externalAppsName
    global buttonText
    global externalApps
    global showRefreshBtn
    externalApps = tkinter.Toplevel(background=THEME_WINDOW_BG)
    externalAppsName = []
    buttonText = "Look for external apps!"
    showRefreshBtn = tkinter.Button(externalApps, text=buttonText, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=show)
    showRefreshBtn.grid(row=0, column=0)
    loadCusttomBtn = tkinter.Button(externalApps, text="Load Custom App!", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=loadCustomApp)
    loadCusttomBtn.grid(row=0, column=1)
    externalApps.mainloop()
    PROCESS_RUNNING = False