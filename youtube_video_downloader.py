# import os
# from urllib.parse import urlparse
from tkinter import *
from pytube import YouTube

# filename_s = input("Please Enter Your File Name To Save:-")
root = Tk()
root.geometry('500x300')
root.resizable(0,0)
root.title("@MuL's video downloader")

Label(root,text = 'Youtube Video Downloader', font ='arial 20 bold',bg = 'yellow').pack()
link = StringVar()
Label(root, text = 'Paste Link Here:', font = 'arial 15 bold',bg = 'Red').place(x= 160 , y = 60)
Label(root, text = '@Mul Video Downloader', font = 'arial 12 bold',bg = 'blue').place(x= 140 , y = 40)
link_enter = Entry(root, width = 70,textvariable = link).place(x = 32, y = 90)
def Downloader():     
    url =YouTube(str(link.get()))
    video = url.streams.first().download(output_path = "D:\\Video's")

    video.download()
    Label(root, text = 'DOWNLOADED', font = 'arial 15',bg = 'purple').place(x= 180 , y = 210)  
Button(root,text = 'DOWNLOAD', font = 'arial 15 bold' ,bg = 'green', padx = 2, command = Downloader).place(x=180 ,y = 150)
root.mainloop()
    # link = input("Paste Your Link:-")

# yt = YouTube(link)
# # a = urlparse(link)


# try:
#     yt.streams.filter(progressive = True, 
# file_extension = input("Enter Extension(mp4/webm):-")).first().download(output_path = "D:\\Video's", filename = filename_s)

# except:
#     print("This File Dont Have webm Support Please Try With mp4 extension\nThank You!")
# print('Task Completed!')
