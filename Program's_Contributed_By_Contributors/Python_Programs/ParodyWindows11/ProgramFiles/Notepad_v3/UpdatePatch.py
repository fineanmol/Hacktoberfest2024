""" This patch is for program versions below 3.3, so the old updater. 
this patch essentially does the update for you! so if you're in v2, or 2.1/v3.2,
then, this file will be downloading your new version into your computer.
NOTE: It can be used for any version though, like even above 3.3 as it is a update manager. so you don't need
to delete this application once upraded. """
import tkinter
import requests
import tkinter.messagebox as msgbox
import os
import shutil
import zipfile
from io import BytesIO
def versionFind():
    with open("VERSION.txt", "r") as version:
        ver, branch = version.read().splitlines()
    return ver, branch
updateWindow = tkinter.Tk()
updateWindow.configure(background="Black")
updateWindow.title("Update Manager for versions older than v3.3")
changelogText = str(requests.get("https://raw.githubusercontent.com/Viswas-Programs/Notepad/main/CHANGELOG.txt").content.decode(encoding="utf-8"))
changelogs = tkinter.Label(updateWindow,text=changelogText ,background="Black", foreground='White')
changelogs.grid(row=0, column=0)
CURRENT_VERSION, CURRENT_BRANCH = versionFind()
UPDATER_FILE = requests.get("https://raw.githubusercontent.com/Viswas-Programs/Notepad/main/VERSION.txt")
version, branch, a = str(UPDATER_FILE.content.decode(encoding='utf-8')).split("\n")
def updateToNew():
    SOURCE_FOLDER = os.getcwd()
    DESTINATION_FOLDER = f"{CURRENT_VERSION}-{CURRENT_BRANCH}"
    os.mkdir(DESTINATION_FOLDER)
    # from this point, till '=====', it's code copied from pynative.com. so don't blame me for the code!
    for file_name in os.listdir(SOURCE_FOLDER):
        # construct full file path
        source = os.path.join(SOURCE_FOLDER, file_name)
        destination = os.path.join(DESTINATION_FOLDER, file_name)
        # copy only files
        if os.path.isfile(source):
            shutil.copy(source, destination)
            os.remove(source)
    # =====
    # My code again
    updateZip = requests.get("https://github.com/Viswas-Programs/Notepad/raw/update/updatedProgram.zip")
    ExtractFiles = zipfile.ZipFile(BytesIO(updateZip.content))
    ExtractFiles.extractall(os.getcwd())
def checkForUpdates():
    if version > CURRENT_VERSION:
        msgbox.showinfo("Update available", f"Notepad v{version} is ready to be installed!"
                        f"\n({CURRENT_VERSION} -> {version})")
        updateButton = tkinter.Button(updateWindow, text="Update to latest version!", command=updateToNew,
                                        background="Black", foreground="White")
        updateButton.grid(row=3, column=0)
    else:
        msgbox.showinfo("All caught up!", "You're all set, no updates (yet)")
tkinter.Label(updateWindow, text=f"Check for updates down below! your current version = {CURRENT_VERSION}",
            background="Black", foreground="White").grid(row=1, column=0)
checkForUpdatesBtn = tkinter.Button(updateWindow, text="Check For Updates!", command=checkForUpdates,
                                    background="Black", foreground="White")
checkForUpdatesBtn.grid(row=2, column=0)
updateWindow.mainloop()
