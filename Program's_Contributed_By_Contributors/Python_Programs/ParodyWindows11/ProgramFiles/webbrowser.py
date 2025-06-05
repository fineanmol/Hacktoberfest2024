import tkinter
from tkinterweb import HtmlFrame
import shelve
from datetime import datetime
PROCESS_RUNNING = True
searchHistory = shelve.open("ProgramFiles/history")
searches = []
searchNo = -1
SHOWN_HISTORY = False
SHOWN_ABOUT = False
SHOWN_PERSONALIZATION = False
DARK_THEME = False 
THEME_WINDOW_BG, THEME_FOREGROUND = open("theme_config.txt").read().split("\n")
def browse():
    global frame
    searches.append(text.get())
    def a(title):
        searchHistory[str(datetime.now())] = title
        root.title(title)
    def addToList(url):
        global searches
        global searchNo
        global text
        searches.append(str(url))
        searchNo += 1
        frame.load_url(url)
        frame.enable_dark_theme(True, True)
        text.delete(0, tkinter.END)
        text.insert(0, url)
    frame = HtmlFrame(mainFrame)
    frame.load_website(text.get()) 
    frame.on_link_click(addToList)
    if DARK_THEME: frame.enable_dark_theme(True, True)
    frame.on_title_change(a)
    frame.grid(row=1, column=0)
def optionsWindow(e=None):
    global DARK_THEME
    def showHistory():
        global SHOWN_HISTORY
        global historyFrame
        SHOWN_HISTORY = True
        if SHOWN_ABOUT: aboutFrame.destroy()
        if SHOWN_PERSONALIZATION: perFrame.destroy()
        historyFrame = tkinter.Frame(optionsWn, background=THEME_WINDOW_BG, width=90, height=120)
        historyFrame.grid(row=0, column=1)
        for i, (time, search) in enumerate(searchHistory.items()):
            exec(f"a{i} = tkinter.Label(historyFrame, text='{search}', background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)")
            exec(f"a{i}.grid(row=i, column=0)")
            exec(f"n{i} = tkinter.Label(historyFrame, text=':{time}', background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)")
            exec(f"n{i}.grid(row=i, column=1)")
    def showAbout():
        global SHOWN_ABOUT
        global aboutFrame
        SHOWN_ABOUT = True
        if SHOWN_HISTORY: historyFrame.destroy()
        if SHOWN_PERSONALIZATION: perFrame.destroy()
        aboutFrame = tkinter.Frame(optionsWn, background=THEME_WINDOW_BG)
        aboutFrame.grid(row=0, column=1)
        about = tkinter.Label(aboutFrame, text=
        "Python Web browser v2.0\nThis doesn't use modern javascript, so JS has no support, period.",
        background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND)
        about.grid(row=0, column=0)
    def darkThemeMenu(e=None):
        global DARK_THEME
        global SHOWN_PERSONALIZATION
        global perFrame
        global DARK_THEME
        perFrame = tkinter.Frame(optionsWn, background=THEME_WINDOW_BG)
        perFrame.grid(row=0, column=1)
        def changeTheme(e=None): frame.enable_dark_theme(True, True); DARK_THEME = True
        def revChanges(e=None): frame.enable_dark_theme(False, False); DARK_THEME = False
        change = tkinter.Button(perFrame, text="Experimental dark theme! (on)", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=changeTheme)
        change.grid(row=0, column=0)
        revchange = tkinter.Button(perFrame, text="Experimental dark theme! (off)", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=revChanges)
        revchange.grid(row=1, column=0)
    optionsWn = tkinter.Toplevel(root, background=THEME_WINDOW_BG)
    btnFrame = tkinter.Frame(optionsWn, background=THEME_WINDOW_BG)
    btnFrame.grid(row=0, column=0)
    historyBtn = tkinter.Button(btnFrame, text="History", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=showHistory)
    historyBtn.grid(row=0, column=0)
    aboutBtn = tkinter.Button(btnFrame, text="About", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=showAbout)
    aboutBtn.grid(row=1, column=0)
    changeBtn = tkinter.Button(btnFrame, text="Personalization", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=darkThemeMenu)
    changeBtn.grid(row=2, column=0)
    optionsWn.mainloop()

def goBack(e=None):
    global frame
    if frame:
        frame.load_website(searches[searchNo-2])
        if DARK_THEME: frame.enable_dark_theme(True, True)
        global text
        text.delete(0, tkinter.END)
        text.insert(searches[searchNo-2])
def reloadWebsite(e=None):
    if frame:
        frame.load_website(searches[searchNo-1])
        if DARK_THEME: frame.enable_dark_theme(True, True)

def main(*args):
    global root
    global mainFrame
    global frame
    global text
    root = tkinter.Toplevel(background=THEME_WINDOW_BG)
    mainFrame = tkinter.Frame(root, background=THEME_WINDOW_BG)
    mainFrame.grid(row=1, column=0)
    btnFrame = tkinter.Frame(mainFrame, background=THEME_WINDOW_BG)
    btnFrame.grid(row=0, column=0)
    backButton = tkinter.Button(btnFrame, text="<-", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=goBack)
    backButton.grid(row=0, column=0)
    reloadButton = tkinter.Button(btnFrame, text="Reload", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=reloadWebsite)
    reloadButton.grid(row=0, column=1)
    text = tkinter.Entry(btnFrame, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, width=90)
    text.grid(row=0, column=2)
    text.configure(insertbackground=THEME_FOREGROUND, selectbackground=THEME_FOREGROUND, selectforeground=THEME_WINDOW_BG)
    btn = tkinter.Button(btnFrame, text="Go!", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=browse)
    btn.grid(row=0, column=3)
    exec(f"optionsICON = tkinter.PhotoImage(file=f'ProgramFiles/Icons/Settings.png').subsample(2, 2)")
    exec(f"optionsBTN = tkinter.Button(btnFrame, image=optionsICON, background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=optionsWindow)")
    exec(f"optionsBTN.IMGREF = optionsICON")
    exec(f"optionsBTN.grid(row=0, column=4)")
    root.mainloop()
    searchHistory.close()
    PROCESS_RUNNING = False
def focusIn(): root.state(newstate='normal'); 
def focusOut(): root.state(newstate='iconic'); 