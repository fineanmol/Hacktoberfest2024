import os
from selenium import webdriver
from tkinter import *
import time
import fnmatch
import pyttsx3
import shutil
import os.path
import glob
import pyautogui
from selenium.webdriver.common.keys import Keys
from PIL import Image, ImageTk
import win32gui, win32con

hide = win32gui.GetForegroundWindow()
win32gui.ShowWindow(hide, win32con.SW_HIDE)

engine = pyttsx3.init('sapi5')
voice = engine.getProperty('voices')
engine.setProperty('rate',178)
engine.setProperty('voice',voice[2].id)

def speak(comm):
    engine.say(comm)
    engine.runAndWait()

def travel():
    folder_add = r'F:\New music playlists\travel'
    f_path = r'C:\Users\amanj\Downloads'
    file_type = '\*mp3'
    files = glob.glob(f_path+file_type)
    max_f = max(files, key = os.path.getctime)
    shutil.copy(max_f,folder_add)

def b_h():
    folder_add = r'F:\New music playlists\Broken heart'
    f_path = r'C:\Users\amanj\Downloads'
    file_type = '\*mp3'
    files = glob.glob(f_path+file_type)
    max_f = max(files, key = os.path.getctime)
    shutil.copy(max_f,folder_add)

def punjabi():
    folder_add = r'F:\New music playlists\punjabi'
    f_path = r'C:\Users\amanj\Downloads'
    file_type = '\*mp3'
    files = glob.glob(f_path+file_type)
    max_f = max(files, key = os.path.getctime)
    shutil.copy(max_f,folder_add)
def en():
    folder_add = r'F:\New music playlists\English songs'
    f_path = r'C:\Users\amanj\Downloads'
    file_type = '\*mp3'
    files = glob.glob(f_path+file_type)
    max_f = max(files, key = os.path.getctime)
    shutil.copy(max_f,folder_add)
def all():
    folder_add = r'F:\New music playlists\all'
    f_path = r'C:\Users\amanj\Downloads'
    file_type = '\*mp3'
    files = glob.glob(f_path+file_type)
    max_f = max(files, key = os.path.getctime)
    shutil.copy(max_f,folder_add)
def appy():
    folder_add = r'F:\New music playlists\appy'
    f_path = r'C:\Users\amanj\Downloads'
    file_type = '\*mp3'
    files = glob.glob(f_path+file_type)
    max_f = max(files, key = os.path.getctime)
    shutil.copy(max_f,folder_add)
def party():
    folder_add = r'F:\New music playlists\party'
    f_path = r'C:\Users\amanj\Downloads'
    file_type = '\*mp3'
    files = glob.glob(f_path+file_type)
    max_f = max(files, key = os.path.getctime)
    shutil.copy(max_f,folder_add)

def click():
    dirpath = r'C:\Users\amanj\Downloads'
    a = len(fnmatch.filter(os.listdir(dirpath), '*.mp3'))
    list = (song_n.get()).split("-")
    for item in list:
        driver = webdriver.Chrome(executable_path='F:\\chromedriver.exe')
        driver.maximize_window()

        url = "https://mp3quack.lol/"

        driver.get(url)

        inputElems = driver.find_elements_by_css_selector('[id="searchInput"]')

        for inputElem in inputElems:

	        inputElem.send_keys(item)

	
	        inputElem.send_keys(Keys.ENTER)

        down_click  = driver.find_element_by_xpath("/html/body/div[2]/div[3]/div/div[2]/div[2]/ul[1]/li[3]/span[2]").click()
        pyautogui.moveTo(8,0,duration=0.0)
        pyautogui.click()

        down_click  = driver.find_element_by_xpath("/html/body/div[2]/div[3]/div/div[2]/div[2]/ul[1]/li[3]/span[2]").click()
        down_click  = driver.find_element_by_xpath("/html/body/div[2]/div[3]/div/div[2]/div[2]/ul[1]/li[3]/span[2]").click()
        time.sleep(5)
        pyautogui.moveTo(720,475,duration =0.0)
        pyautogui.click()
        speak(f'Downloading {item} sir')
        driver.minimize_window()
        


root = Tk()

root.geometry("700x700")
root.title("MuSiC DoWNlodER")
root.wm_iconbitmap(r"a:\PYTHON\python projexts\music_downloader\img1.ico")
img1 = PhotoImage(file =r"a:\PYTHON\python projexts\music_downloader\bg4.png")

Label(root, image= img1).place(x = 0, y = 0)


Label(root, text= "MUSIC == LOVE ", font = "lucida 30 bold", fg="salmon",bg ="black").place(x =190, y = 10 )

song_n= StringVar()
Label(root, text= "If you want to download multiple songs then put - between every song", font ="lucida 15 bold").place(x = 15, y = 660)

Entry(root, textvariable= song_n,width=25,font ="lucida 10 bold",bg="salmon" ).place(x = 470, y= 260)

Button(root, text="Let Me download SIR!",width= 20, height=1,command = click,bg= "salmon",fg = "gray1").place(x = 500,y = 320)

Button(root, text="broken heart",width= 15, height=1,command = b_h,bg= "salmon",fg = "gray1").place(x = 170,y = 600)
Button(root, text="punjabi",width= 15, height=1,command = punjabi,bg= "salmon",fg = "gray1").place(x = 340,y = 600)
Button(root, text="english songs",width= 15, height=1,command = en,bg= "salmon",fg = "gray1").place(x = 500,y = 600)
Button(root, text="Travel",width= 15, height=1,command = travel,bg= "salmon",fg = "gray1").place(x = 15,y = 600)
Button(root, text="@LL",width= 3, height=1,command = all,bg= "salmon",fg = "grey").place(x = 650,y = 600)
Button(root, text="@ppy",width= 15, height=1,command = appy,bg= "salmon",fg = "black").place(x = 550,y = 500)
Button(root, text="P@rt-y",width= 15, height=1,command = party,bg= "salmon",fg = "black").place(x = 550,y = 550)

root.mainloop()