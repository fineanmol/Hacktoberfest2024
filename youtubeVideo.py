from pytube import YouTube
link = input("URL of video: ")
video = YouTube(link)
stream = video.streams.get_highest_resolution()
stream.download()
