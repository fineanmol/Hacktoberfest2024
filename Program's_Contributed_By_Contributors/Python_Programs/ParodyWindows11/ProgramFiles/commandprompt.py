import tkinter
import os
import shelve

class cmdCommands(object):
    def __init__(self, stdout: tkinter.Text, stdin: tkinter.Entry, root: tkinter.Tk,) -> None:
        self.ROOT = root
        self.ADMINISTRATOR = False
        self.UP_ARROW_COUNT = 0
        self.ACCEPT_COMMANDS = True
        self.stdout = stdout
        self.stdin = stdin
        self.LINE_COUNT = 0.0
        self.COMMAND_LIST = ["clear", "shutdown", "restart", "exit", "sfcRepair", "cd", "dir", "mkd", "rmd", "user", "administrator", "startFile", "mk", "rm", "cmd"]
        self.INPUTTED_COMMANDS_LIST = []
        self.COMMAND_NOT_FOUND = "\nThe following command doesn't exist!"
        self.showMsg(f"Welcome to ParodyWindows11 Command Interpreter (OS Version 2.2)\nCurrent Working Directory: {os.getcwd()}\n>")
        try: self.ROOT.bind("<Up>", self.upArrowBind); self.ROOT.bind("<Down>", self.downArrowBind)
        except Exception as exp: print(f' {exp}')
    def cmd(self):
        self.INPUTTED_COMMANDS_LIST.append(self.stdin.get())
        if self.stdin.get().split(' ')[1].lstrip("-") == "restart":
            self.ROOT.destroy()
            def sendCommand(e=None):
                self.showMsg(f"\n>{yourCommand.get()}")
                if " " not in yourCommand.get():
                    yourCommand.insert(tkinter.END, "  ")
                if yourCommand.get().split(" ")[0] in self.COMMAND_LIST and self.ACCEPT_COMMANDS:
                    self.launchCmd()
                elif not self.ACCEPT_COMMANDS: self.showMsg("\nThe command prompt is busy"); self.clearStdIn()
                else: self.showMsg(self.COMMAND_NOT_FOUND); print("COMMAND_NOT_FOUND!")
            ROOT = tkinter.Tk()
            ROOT.configure(background=THEME_WINDOW_BG)
            ROOT.title("Command Interpreter")
            text = tkinter.Text(ROOT, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, width=120)
            text.grid(row=0, column=0)
            text.insert(tkinter.END, f"Welcome to ParodyWindows 11 Command Interpreter (OS Version 2.2)\nCurrent Working Directory: {os.getcwd()}")
            yourCommand = tkinter.Entry(ROOT, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
            yourCommand.configure(insertbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG, selectbackground=THEME_FOREGROUND, width=110)
            yourCommand.grid(row=1, column=0)
            yourCommand.focus()
            yourCommand.bind("<Return>", sendCommand)
            ROOT.mainloop()
        else:
            self.clear()
            self.clearStdIn()
            self.showMsg(f"\nWelcome to ParodyWindows11 Command Interpreter (OS Version 2.2)\nCurrent Working Directory: {os.getcwd()}")
    def user(self):
        if self.ADMINISTRATOR:
            from pathlib import Path
            import base64
            if self.getParams(1, " ").lstrip('-') != "list":
                try:
                    os.mkdir(os.path.join("ProgramFiles", self.stdin.get().split(' ')[2].lstrip('-')))
                except Exception: pass
                finally:
                    with open(f"ProgramFiles/accConfiguration{self.getParams(1, ' ').lstrip('-')}.conf", "w") as writeConfig:
                        writeConfig.write(f"{self.getParams(2, ' ').lstrip('-')}\n{self.getParams(3, ' ').lstrip('-')}")
                    self.clearStdIn()
                    self.showMsg("\nUser created successfully!")
            else:
                self.showMsg("\nCurrent User List: ")
                for dirpath, dirnames, filenames in os.walk("ProgramFiles"):
                    for file in Path(dirpath).glob("accConfiguration*.conf"):
                        with open(file,) as showUsers:
                            self.showMsg(f"\n {showUsers.readlines()[0]} ")
        else:
            self.showMsg("\nPlease enable administrator before editing or creating a new user!")
    def administrator(self):
        self.INPUTTED_COMMANDS_LIST.append(self.stdin.get()) 
        with open(f"ProgramFiles/accConfiguration{self.getParams(1, ' ').lstrip('-')}.conf", "r") as checkUser:
            usrname, pswd = checkUser.readlines()
            usrname = usrname.rstrip("\n")
            pswd = pswd.rstrip("\n")
            if self.getParams(2, " ").lstrip('-').rstrip("\n") == usrname and self.getParams(3, " ").lstrip('-').rstrip("\n") == pswd:
                self.ADMINISTRATOR = True
                self.showMsg("\nSuccesfully turned on administrator mode!")
                self.ROOT.title("Administrator - Command Interpreter")
            else:
                self.showMsg("\nEither the username or the password is incorrect. So authentication failed!")
        self.clearStdIn()
    def downArrowBind(self, e=None): self.clearStdIn(); self.stdin.insert(tkinter.END, self.INPUTTED_COMMANDS_LIST[-self.UP_ARROW_COUNT+1])
    def upArrowBind(self, e=None):
        self.UP_ARROW_COUNT += 1
        self.clearStdIn()
        self.stdin.insert(tkinter.END, self.INPUTTED_COMMANDS_LIST[-self.UP_ARROW_COUNT])
    def showMsg(self, msg: str):
        self.stdout.configure(state="normal")
        self.LINE_COUNT += 1.0
        self.stdout.insert(f"{self.LINE_COUNT+1}", msg)
        if "\n" in msg: self.LINE_COUNT += 1.0
        self.stdout.configure(state="disabled")
    def launchCmd(self, e=None):
        if " " not in self.stdin.get(): self.stdin.insert(tkinter.END, "  ")
        if self.getParams(0, " ") in self.COMMAND_LIST and self.ACCEPT_COMMANDS: self.showMsg(f"\n>{self.stdin.get()}"); exec(f"self.{self.stdin.get().split(' ')[0]}()")
    def clearStdIn(self):
        self.stdin.destroy()
        self.stdin = tkinter.Entry(self.ROOT, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, width=110)
        self.stdin.configure(insertbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG, selectbackground=THEME_FOREGROUND, )
        self.stdin.grid(row=1, column=0)
        self.stdin.bind("<Return>", self.launchCmd)
        self.stdin.focus()
    def clear(self):
        self.clearStdIn()
        self.stdout.configure(state="normal")
        try: self.stdout.delete(1.0, tkinter.END)
        except Exception as exp: self.showMsg(f"\nERROR OCCURED while clearing terminal: {exp}")
        finally: self.INPUTTED_COMMANDS_LIST.append("clear"); self.stdout.configure(state="disabled")
    def shutdown(self):
        self.clearStdIn()
        self.showMsg("\nShutting down...")
        self.ROOT.after(5000, lambda: os._exit(0))
    def restart(self):
        self.ROOT.destroy()
        if self.getParams(1, "-") == "useparams": useparams = True; params = self.getParams(2, "-")
        self.clearStdIn()
        if useparams: os.system(f"""python3 "Windows 11.py" -{params}""")
        else: os.system(""" python3 "Windows 11.py" """)
        exit()
    def sfcRepair(self):
        try: import requests
        except Exception: pass
        if self.ADMINISTRATOR:
            def resetConfigurations():
                try:
                    userToreset =  self.getParams(2, "-")
                    if userToreset.lower() != "defaultuser0":
                        try: 
                            with shelve.open(f"ProgramFiles/{userToreset}/USER_CONFIG") as deleteIt: deleteIt.clear()
                        except Exception as exp: self.showMsg(f"ERROR OCCURED While resetting...!Error: {exp}")
                    shelveFilesToDelete = ["ProgramFiles/history", "ProgramFiles/IPChat/_serverConfig", "ProgramFiles/IPChat/serversList"]
                    for shelveToDelete in shelveFilesToDelete:
                        try:
                            with shelve.open(shelveToDelete) as deleteIt: deleteIt.clear()
                        except Exception: pass
                except Exception as exp:
                    self.showMsg(f"\nERROR OCCURED While resetting...!Error: {exp}")
            if self.getParams(1, " ") == "-online":
                self.showMsg("Repairing system...")
                import zipfile
                from io import BytesIO
                try:
                    Windows11MainDownload = requests.get("https://raw.githubusercontent.com/Viswas-Programs/ParodyWindows11/main/Windows 11.py", timeout=10)
                    ProgramFilesMainDownload = requests.get("https://raw.githubusercontent.com/Viswas-Programs/ParodyWindows11/main/ProgramFiles.zip", timeout=40)
                    with open("Windows 11.py", "w") as writeTo:
                        try:
                            writeTo.write(Windows11MainDownload.content.decode(encoding="UTF-8"))
                        except UnicodeEncodeError as UER:
                            self.showMsg(f"\nUnicodeDecodeError occured while repairing 'Windows 11.py'\n--MSG:{UER}")
                    if os.access("ProgramFiles", os.F_OK) and os.path.isdir("ProgramFiles"):
                        import pathlib3x
                        Location = pathlib3x.Path("ProgramFiles")
                        Location.rmtree(ignore_errors=True)
                    PrograFile = zipfile.ZipFile(BytesIO(ProgramFilesMainDownload.content))
                    PrograFile.extractall("ProgramFiles")
                    self.showMsg("\nRepair success!")
                except Exception as PROBLEM:
                    self.showMsg(f"\nRepairing Failed!\nREASON: {PROBLEM}")
            elif self.getParams(1, " ") == "-offline":
                self.showMsg("\nResetting your system...")
                resetConfigurations()
                self.showMsg("\nReset Success!")
            else:
                self.showMsg("\nParameter not found.\nHELP: '-online' param for Online repair and '-offline' for a reset ")
            self.INPUTTED_COMMANDS_LIST.append(self.stdin.get())
        else:
            self.showMsg("\nPlease enable administrator mode before accessing sfcRepair")
        self.clearStdIn()
    def exit(self): self.ROOT.destroy();  
    def cd(self):
        import platform
        if self.getParams(1, " ") not in  ["..", "/", " ", "  ", ""]:
            os.chdir(self.getParams(1, " "))
            self.showMsg(f"\nCurrent Working Directory: {os.getcwd()}")
        elif self.getParams(1, " ") == "/":
            os.chdir("/")
            self.showMsg(f"\nCurrent Working Directory: {os.getcwd()}")
        elif self.getParams(1, " ") == "..":
            if platform.system() == "Windows": character = "\\"
            else: character = "/"
            fullDirList = os.getcwd().split(character)
            modifiedPath = "".join(f"{item}/" for item in fullDirList[:-1])
            os.chdir(modifiedPath)
            self.showMsg(f"\nCurrent Working Directory: {os.getcwd()}")
        elif self.getParams(1, " ") == "/":
            os.chdir("/")
            self.showMsg(f"\nCurrent Working Directory: {os.getcwd()}")
        else:
            self.showMsg("\nInvalid parameter... ")
        self.INPUTTED_COMMANDS_LIST.append(self.stdin.get())
        self.clearStdIn()
    def dir(self):
        for (filepath, dirname, filename) in os.walk(os.getcwd()):
            print(filepath, dirname)
            for file in dirname:
                self.showMsg(f"\n{dirname}/{file}")
        self.INPUTTED_COMMANDS_LIST.append(self.stdin.get())
        self.clearStdIn()
    def mkd(self):
        os.mkdir(self.stdin.get().split(" ")[1])
        self.clearStdIn()
        self.showMsg("\nFolder created succesfully!")
    def rmd(self):
        import pathlib3x
        Location = pathlib3x.Path(self.stdin.get().split(" ")[1])
        Location.rmtree(ignore_errors=True)
        self.clearStdIn()
        self.showMsg("\nFolder removed succesfully!")
    def startFile(self):
        import subprocess
        self.INPUTTED_COMMANDS_LIST.append(self.stdin.get())
        try:
            self.showMsg("\nSuccesfully started file!")
            subprocess.Popen(["python3", self.stdin.get().split(" ")[1]])
        except Exception: self.showMsg(f"\nCannot start the specified file, due to a technical error. \nError at {str(self.startFile)}")
    def mk(self):
        self.INPUTTED_COMMANDS_LIST.append(self.stdin.get())
        with open(self.stdin.get().split(" ")[2], "w") as CREATE_FILE: CREATE_FILE.writelines(self.stdin.get().split(" ")[1].replace("\\n", "\n"))
        self.clearStdIn()
        self.showMsg("\nCreated the file successfully!")
    def rm(self):
        if self.ADMINISTRATOR:
            self.INPUTTED_COMMANDS_LIST.append(self.stdin.get())
            os.remove(self.stdin.get().split(" ")[1])
            self.showMsg("\nRemoved the file successfully!")
        else: self.showMsg("\nPlease enable administrator mode before removing a file")
        self.clearStdIn()
    def getParams(self, paramToGet: int, includeParamSeparator: str) -> str:
        return self.stdin.get().split(' ')[paramToGet].lstrip(includeParamSeparator)
THEME_WINDOW_BG, THEME_FOREGROUND = shelve.open("ProgramFiles/SYS_CONFIG")["THEME"]
def main(*args): 
    global ROOT
    def sendCommand(e=None):
        cmdInstance.showMsg(f"\n>{yourCommand.get()}")
        if " " not in yourCommand.get():
            yourCommand.insert(tkinter.END, "  ")
        if yourCommand.get().split(" ")[0] in cmdInstance.COMMAND_LIST and cmdInstance.ACCEPT_COMMANDS:
            exec(f"cmdInstance.{yourCommand.get().split(' ')[0]}()")
        elif not cmdInstance.ACCEPT_COMMANDS: cmdInstance.clear()
        else: cmdInstance.showMsg(cmdInstance.COMMAND_NOT_FOUND); print("COMMAND_NOT_FOUND!")
    ROOT = tkinter.Tk()
    ROOT.configure(background=THEME_WINDOW_BG)
    ROOT.title("Command Interpreter")
    text = tkinter.Text(ROOT, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, width=100)
    text.grid(row=0, column=0)
    yourCommand = tkinter.Entry(ROOT, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
    yourCommand.configure(insertbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG, selectbackground=THEME_FOREGROUND, width=110)
    yourCommand.grid(row=1, column=0)
    cmdInstance = cmdCommands(text, yourCommand, root=ROOT)
    yourCommand.focus()
    yourCommand.bind("<Return>", sendCommand)
    ROOT.mainloop()


def focusIn(): ROOT.state(newstate='normal'); 
def focusOut(): ROOT.state(newstate='iconic'); 
if __name__ == "__main__":
    main()