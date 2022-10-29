#python script to download yt playlists
from pytube import Playlist
p = Playlist('Your playlist link')

print(f'Downloading: {p.title}')

for video in p.videos:
    print(video.title)
    st = video.streams.get_highest_resolution()
    st.download()
    #video.streams.first().download()
