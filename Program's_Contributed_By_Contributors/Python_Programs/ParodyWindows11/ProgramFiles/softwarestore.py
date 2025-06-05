import requests
import tkinter
import tkinter.messagebox as messagebox
import os
import json
import tkinter.ttk as ttk
import shelve

global usrname
rootWn = tkinter.Tk()
def FTRConfigSettings(path, data: str=None, prepCodeBool=False, prepCode=None) -> tuple:
    if prepCodeBool: exec(prepCode)
    if os.access(path, os.F_OK):
        with open(path) as read_config:
            # print(bytes(read_config.read(), encoding='utf-8').decode(encoding='utf-8') == "")
            read_config_out = read_config.read()
            if bytes(read_config_out, encoding='utf-8').decode(encoding='utf-8') == "":
                print("in if")
                with open(path, "w") as writeData: writeData.write(data)
                updateRead =  open(path, "r")
                read_config = updateRead
                print("wrote data")
                updateRead.close()
            config = read_config_out.splitlines()
    else:
        with open(path, "w") as FTR_write_config: #FirstTimeRun_Write_config, full form.
            FTR_write_config.write(data)
            config = data.splitlines()
    return config
THEME_WINDOW_BG, THEME_FOREGROUND = shelve.open("ProgramFiles/SYS_CONFIG")["THEME"]
def showDescription(e=None):
    def uninstallProgram(e=None):
        try:
            with open(f"ProgramFiles/{usrname}/APPS_LIST.txt", "wr") as uninstallProgram:
                prevProgramList = str(uninstallProgram.read()).split("\n")
                prevProgramList.pop(prevProgramList.index(item))
                newProgramList = "".join(app for app in prevProgramList)
                uninstallProgram.write(newProgramList)
            with open(f"ProgramFiles/{usrname}/APPS_COMMAND_LIST.txt", "wr") as uninstallProgramC:
                prevProgramList = str(uninstallProgramC.read()).split("\n")
                prevProgramList.pop(prevProgramList.index(item))
                newProgramList = "".join(app for app in prevProgramList)
                uninstallProgramC.write(newProgramList)
            uninstaller = requests.get(appsList[item][2]).content.decode(encoding='utf-8')
            exec(uninstaller)
        except Exception as PRB:
            messagebox.showerror("Error", f"Error occured while uninstalling '{item}': {PRB}")
    def installProgram(e=None):
        try:
            installProgram = requests.get(appsList[item][1], timeout=10)
            exec(installProgram.content.decode(encoding='utf-8'))
        except Exception as PRB:
            messagebox.showerror("ERROR! While installing app....", f"Can't install app '{item}'! Retry Again.\n DEBUG:<< {PRB} >> ")
    global externalAppsList
    wn = tkinter.Toplevel(background=THEME_WINDOW_BG)
    item = str(externalAppsList.item(externalAppsList.focus(), 'values')[0])
    tkinter.Label(wn, text=appsList[item][0], background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND).pack()
    if item not in FTRConfigSettings(f"ProgramFiles/{usrname}/APPS_LIST.txt", ""):
        tkinter.Button(wn, text="Install", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=installProgram).pack()
    else:
        tkinter.Button(wn, text="Uninstall", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=uninstallProgram).pack()
    wn.mainloop()
def main(username, notification):
    global usrname
    usrname = username
    global externalAppsList
    global appsList
    try:
        appsList = requests.get("https://raw.githubusercontent.com/Viswas-Programs/ParodyWindows11/main/softwareStoreApps.json", timeout=10)
        appsList = appsList.json()
    except Exception as PROB:
        messagebox.showerror("ERROR!", f"Can't load apps list from internet! using locals\nERR: {PROB}")
        try:
            print(os.getcwd())
            with open("ProgramFiles/localAppsList.json", "r") as applistLocal:
                appsList = json.load(applistLocal)
        except Exception as PRB:
            messagebox.showerror("Can't load local apps list!", f"Error: {PRB}")
        rootWn.configure(background=THEME_WINDOW_BG)
    rootWn.title("Software Store")
    externalAppsList = ttk.Treeview(rootWn, style="Treeview")
    externalAppsList.grid(row=1, column=0, sticky="w")
    externalAppsList['column'] = "Apps"
    externalAppsList.column("#0", anchor=tkinter.W, width=0, stretch=tkinter.NO)
    externalAppsList.column("Apps", anchor=tkinter.W, width=600)
    externalAppsList.heading("Apps", text="Apps", anchor=tkinter.CENTER)
    externalAppsList.bind("<<TreeviewSelect>>", showDescription)
    externalAppsList.configure(style="Treeview")
    for i, app in enumerate(appsList):
        externalAppsList.insert(parent='', iid=i, text='', index=i, values=[app],)
    rootWn.mainloop()
ROOT = rootWn
def focusIn(): ROOT.state(newstate='normal'); 
def focusOut(): ROOT.state(newstate='iconic'); 
if __name__ == "__main__":
    main()