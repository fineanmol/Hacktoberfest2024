import os
from pytube import YouTube

def download_youtube_video(url, output_path, convert_to_mp3):
    domains = ['youtu.be', 'youtube', 'www.youtube.com', 'youtube.com']
    if url1.split("/")[2] in domains:
        try:
            if not os.path.isfile(output_path):
                yt = YouTube(url)
                if convert_to_mp3:
                    stream = yt.streams.filter(only_audio=True).first()
                    audio_output_path = os.path.splitext(output_path)[0]
                    output_file=stream.download(output_path=audio_output_path)
                    a=output_file.replace("downloads","personal/downloads/mp3")
                    new_file=a.replace(".mp4",".mp3")
                    os.rename(output_file,new_file)
                    print("MP3 Download complete.")
                else:
                    stream = yt.streams.get_highest_resolution()
                    output_file=stream.download(output_path)
                    a=output_file.replace("downloads","personal/downloads/mp4")
                    os.rename(output_file,a)
                    print("MP4 Download complete.")
            elif os.path.exists(output_path):
                print("File already exists. Skipping Download.")
        except FileExistsError: 
            print("File already exists. Skipping Download.")
    else:
        print("Invalid URL")
url1 = input("Enter URL: ")
format = input("Format: ")
if format == "mp4":
    cmp3= False
    output_file = "../downloads/"
elif format == "mp3":
    cmp3 = True
    output_file = "../downloads/"
else:
    print("Unsupported format!")
    exit()

download_youtube_video(url1, output_file, cmp3)
