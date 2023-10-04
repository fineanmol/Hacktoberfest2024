from pytube import YouTube
import pyperclip
from termcolor import colored
from tkinter.filedialog import askdirectory
from resources import logo
import os

end_program = False
while not end_program:
    print(logo)
        
    lines = colored("-", "green", attrs=["bold"])
    print(lines*80)

    options = {
        "1" : "Paste Link From Clipboard",
        "2" : "Copy New Link To Clipboard"
    }
    print(colored("Choose Your Options:", "cyan", attrs=["bold"]))
    for items in options:
        print(f"{items} : {options[items]}")
    user_option = input(colored(">> ", "yellow", attrs=["bold"]))
    if user_option == "1":
        vd_link = pyperclip.waitForPaste()
    else:
        vd_link = pyperclip.waitForNewPaste()
    print(lines*80)
    video = YouTube(vd_link)
    print(colored(f"{video.title}", "red", attrs=["bold", "reverse"]))
    print(lines*80)
    print(colored("Download video (Y / N):", "cyan", attrs=["bold"]))
    do_download = input(colored(">> ", "yellow", attrs=["bold"])).lower()
    if do_download == "y":
        video_save_path = askdirectory(title='Select Folder To Save')
        final_video = video.streams.get_highest_resolution()
        final_video.download(video_save_path)
        print(colored(f"Download Successful.\nSaved to {video_save_path}", "green", attrs=["bold", "reverse"]))
        print(lines*80)
        download_other = input(colored("Download Another(Y / N)\n>> ", "magenta", attrs=["bold"])).lower()
        if download_other == "n":
            end_program = True
            goodbye = colored("GOODBYE !!", "red", attrs=["bold", "reverse"])
            print(goodbye)
        else:
            os.system("clear")

    else:
        end_program = True
        print(goodbye)