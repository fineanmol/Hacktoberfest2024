import moviepy.editor 


# Video path
video = moviepy.editor.VideoFileClip('file.mp4')


#audio conversion
audio = video.audio

audio.write_audiofile('file.mp3')
