#python script to download youtube playlist
from pytube import Playlist
p = Playlist('playlist link')

print(f'Downloading: {p.title}')

for video in p.videos:
    print(video.title)
    st = video.streams.get_highest_resolution()
    st.download()
    #video.streams.first().download()
