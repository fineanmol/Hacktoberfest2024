import time
from pytube import  *
from tkinter.filedialog import *
from tkinter.messagebox import *
from tkinter import ttk
from threading import *
file_size=0
# https://www.youtube.com/watch?v=WnB6vfDpix8
def abc(stream=None, chunk =None,file_handler=None,remaining=None):
    percent=(100*(file_size-remaining))/file_size
    # a="{:00.0f} % downloaded".format(percent)
    btn.config(text="{:00.0f} % downloaded".format(percent))
def unit(size):
    return size/(1024*1024)
def convert(seconds):
    hour = seconds // 3600
    seconds %= 3600
    seconds = seconds % (24 * 3600)
    seconds %= 3600
    minutes = seconds // 60
    seconds %= 60
    return "%02d:%02d:%02d" % ( hour, minutes, seconds)
def download():
    global file_size
    c = choice1.get()
    choice1.config(state=DISABLED)
    url=urlfield.get()
    urlfield.config(state=DISABLED)
    if len(url) == 0:
        showinfo("Url not found","Please Paste Url Link in given field!!!")
        urlfield.config(state=NORMAL)
        urlfield.delete(0, END)
        choice1.config(state=NORMAL)
        choice1.delete(0, END)
    elif len(c) == 0:
        showinfo("Quality Error", "Please Select Video Quality!!!")
        urlfield.config(state=NORMAL)
        choice1.config(state=NORMAL)
        choice1.delete(0, END)
    else:
        try:
            if "youtube" not in url:
                showinfo("Url Error", "This is not a valid url Field!!!")
                urlfield.config(state=NORMAL)
                urlfield.delete(0, END)
                choice1.config(state=NORMAL)
                choice1.delete(0, END)
            else:
                save_video = askdirectory()
                btn.config(text="Fetching Video ...")
                btn.config(state=DISABLED)
                ob= YouTube(url)#,on_progress_callback=abc)
                if (c==choice[0]):
                    strm=ob.streams.get_highest_resolution()
                elif(c == choice[1]):
                    strm = ob.streams.get_lowest_resolution()
                elif(c == choice[2]):
                    strm = ob.streams.get_audio_only()
                file_size = strm.filesize
                ab=unit(file_size)
                Video_size = Label(text=f"File Size : {'%.2f' % ab} MB", font=("jost", 12))
                Video_size.pack(side=TOP, fill=X, pady=15)
                length=ob.length
                mins = convert(length)
                Video_length = Label(text=f"Video Length : {mins} ", font=("jost", 12))
                Video_length.pack(side=TOP, fill=X, pady=15)
                btn.config(text="downloading....Please wait")
                strm.download(save_video)
                btn.config(text="Download")
                btn.config(state=NORMAL)
                choice1.config(state=NORMAL)
                urlfield.config(state=NORMAL)
                showinfo("Video Status ","Video Downloaded Successfully!!!")
                time.sleep(1)
                urlfield.delete(0,END)
                choice1.delete(0,END)
                Video_size.destroy()
                Video_length.destroy()
        except Exception as e:
            print(e)
            showinfo("Download error ", "sorry, This Video cannot be downloaded")
            btn.config(text="Download")
            btn.config(state=NORMAL)
            urlfield.config(state=NORMAL)
            urlfield.delete(0, END)
            choice1.config(state=NORMAL)
            choice1.delete(0, END)

def downloadThread():
    thread=Thread(target=download)
    thread.start()
#Gui for Project
if __name__ == '__main__':

    root=Tk()
    # set Title
    root.title("Youtube Downloader")

    #set Icon
    root.iconbitmap('images/icon.ico')

    root.geometry('500x500')
    root.minsize(500, 500)
    root.maxsize(500, 500)
    #photo icon
    file=PhotoImage(file='images/youtube.png')
    headingIcon=Label(root,image=file)
    headingIcon.pack(side=TOP,pady=20)
    #Label
    aditya = Label(text="Paste Video URL Here",font=("verdena",12))
    aditya.pack(side=TOP,fill=X,padx=0)
    #Url field
    urlfield=Entry(root,font=("verdana",13),justify=CENTER)
    urlfield.pack(side=TOP,fill=X,padx=10,pady=20)


    aditya1 = Label(text="Select Quality", font=("jost", 12))
    aditya1.pack(side=TOP, fill=X, pady=15)

    #Combo box
    choice=["720p","144p","only Audio"]
    choice1=ttk.Combobox(root, values=choice)
    choice1.pack(side=TOP)

    # BUtton
    btn = Button(root, text="Download", font=("verdena", 12), relief='ridge', command=downloadThread)
    btn.pack(side=TOP,pady=20)
    root.mainloop()
