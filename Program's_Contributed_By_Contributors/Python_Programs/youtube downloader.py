# This program is to download youtube videos
from pytube import YouTube


link = input("Enter the Youtube url: ")
yt = YouTube(link)
videos = yt.streams.all()
#this will stream all the format available for video

video =list(enumerate(videos))
# this will be index all the format in list starting with zero

for i in video:
    print(i)
    #this will print all the available format of video with proper index

print("Enter the desired option to download the format: ")
dn_option = int(input("Enter the option: "))
#ask user to input desired format    
dn_video = videos[dn_option]
dn_video.download()#for downloading the video

print("Downloaded successfully ")
