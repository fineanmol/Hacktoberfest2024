from sys import pycache_prefix
import pygame
import tkinter as tk
from tkinter.filedialog import askdirectory
import os

music_player = tk.Tk()
music_player.title("My Music Player")
music_player.geometry("450x350")
directory = askdirectory()
os.chdir(directory)
song_list = os.listdir()

play_list = tk.Listbox(music_player, font="Helvetica 12 bold",
                       bg='yellow', selectmode=tk.SINGLE)
for item in song_list:
    pos = 0
    play_list.insert(pos, item)
    pos += 1

pygame.init()
pygame.mixer.init()


def play():
    pygame.mixer.music.load(play_list.get(tk.ACTIVE))
    var.set(play_list.get(tk.ACTIVE))
    pygame.mixer.music.play()


def stop():
    pygame.mixer.music.stop()


def pause():
    pygame.mixer.music.pause()


def unpause():
    pygame.mixer.music.unpause()


Button1 = tk.Button(music_player, width=5, height=3, font="Helvetica 12 bold",
                    text="PLAY", command=play, bg='blue', fg='white')
Button2 = tk.Button(music_player, width=5, height=3, font="Helvetica 12 bold",
                    text="STOP", command=stop, bg='red', fg='white')
Button3 = tk.Button(music_player, width=5, height=3, font="Helvetica 12 bold",
                    text="PAUSE", command=pause, bg='purple', fg='white')
Button4 = tk.Button(music_player, width=5, height=3, font="Helvetica 12 bold",
                    text="UNPAUSE", command=unpause, bg='orange', fg='white')

var = tk.StringVar()
song_title = tk.Label(music_player, font="Helvetica 12 bold", textvariable=var)

song_title.pack()
Button1.pack(fill='x')
Button2.pack(fill='x')
Button3.pack(fill='x')
Button4.pack(fill='x')
play_list.pack(fill='both', expand='yes')
music_player.mainloop()
