from kivymd.app import MDApp
from kivymd.uix.label import MDLabel
from kivymd.uix.behaviors import SpecificBackgroundColorBehavior
from tkinter import *
from tkinter import filedialog
from pytube import YouTube
from moviepy import *
from moviepy.editor import VideoFileClip

#functions
def select_path():
    #allows user to select a path from the explore
    path=filedialog.askdirectory()
    path_label.config(text=path)

def download_file():
    # get user path
    get_link=link_field.get()
    #get selected path
    user_path=path_label.cget("text")
    #Download video
    mp4_Video = YouTube(get_link).streams.get_highest_resolution().download()
    vid_clip = VideoFileClip(mp4_Video)
    vid_clip.close()



screen =Tk()
title = screen.title('Youtube Downloader')
canvas = Canvas(screen, width=500, height=500)
canvas.pack()

#image_logo
logo_img = PhotoImage(file="yt.png")

#resize
logo_img = logo_img.subsample(2,2)
canvas.create_image(250, 80, image=logo_img)


link_field = Entry(screen, width=50)
link_label = Label(screen, text='Enter Download Link:', font=('Arial', 15))

#select for saving the file
path_label = Label(screen, text="Select path for Download", font=('Arial', 15))
select_btn = Button(screen, text='Select', command=select_path)

#Add to window
canvas.create_window(250, 280, window=path_label)
canvas.create_window(250, 330, window=select_btn)



#Add widgets to windows
canvas.create_window(250, 170, window=link_label)
canvas.create_window(250, 220, window=link_field)

#Download btns

download_btn = Button(screen, text="Download File", command=download_file)

#add to canvas
canvas.create_window(250, 390, window=download_btn)



screen.mainloop()


