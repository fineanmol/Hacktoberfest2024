""" notepad v3"""
import shutil
import ctypes as ct
import datetime
import inspect
import os
import platform
import shelve
import tkinter
from tkinter import filedialog, ttk, font, colorchooser
from tkinter import messagebox
import ProgramFiles.Notepad_v3.syntax_checker as syntax_checker
import typing
import socket
try:
    import requests
    from cryptography.fernet import Fernet
except Exception as EXP: messagebox.showerror("Can't import update modules!!", f"PROBLEM OCCURED. \n {EXP}")
import zipfile
from io import BytesIO

MSG_SHOWN = False
if platform.system() == "Windows":
    initialPath = os.getenv("USERPROFILE")
else:
    initialPath = os.getenv("HOME")
if not os.access(f"{initialPath}/Documents/update", os.F_OK):
    os.mkdir(f"{initialPath}/Documents/update")
with shelve.open(f"{initialPath}/Documents/update/updater") as updatePath:
    updatePath["filepath"] = inspect.getfile(lambda: None).lstrip(
        inspect.getfile(lambda: None).rstrip("notepadGUI.py"))
    filePath = updatePath["filepath"]
    updatePath["fullpath"] = f"{updatePath['filepath']}/notepadGUI.py"
    fullpath = updatePath["fullpath"]
def versionFind():
    try:
        with open("VERSION.txt", "r") as version:
            ver, branch = version.read().split("\n")
    except Exception: ver, branch = "3.3", "Stable"
    return ver, branch


filetype = (
    ("Text documents (.txt)", "*.txt"),
    ("All types (*)", "*.*"),
)

class NotepadRun(object):
    """ notepad run, so that people can use objects without GUI"""

    def __init__(self, text_box: tkinter.Text, gui: tkinter.Tk, saveTo:
    tkinter.Text, file_to_open: str=None):
        print(f"Program started at {datetime.datetime.now()}")
        self.CURRENT_VERSION, self.UPDATE_BRANCH = versionFind()
        self.fileopen = file_to_open
        self.PROGRAM_MODE_CONFIG = False
        self.font = "Arial Rounded MT Bold"
        self.size = 12
        self.PROGRAMMER_MODE = False
        self.SELECT_PROGRAMMING_LANG = False
        self.FILE_EXIST = False
        self.saved = False
        self.root = gui
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        self.text = text_box
        self.text.configure(font=(self.font, self.size))
        self.buttonFrame = tkinter.Frame(self.root, background="Black", pady=10)
        self.buttonFrame.grid(row=2, column=0)
        self.saveTo = saveTo
        self.THEME_FOREGROUND = "white"
        self.THEME_TYPING_WIDGETS_BG = "black"
        self.THEME_WINDOW_BG = "black"
        self.ZOOM_SIZE = 5
        self.saveTo.insert(1.0, f"{initialPath}/Documents/")
        print(f"Set initial path to {initialPath}/Documents/")
        print("Initialized button frame")
        print(os.getcwd())
        self.saveButton = tkinter.Button(self.buttonFrame, text="Save file",
                                         command=self.save,
                                         background=self.THEME_WINDOW_BG,
                                         foreground=self.THEME_FOREGROUND,
                                         borderwidth=2
                                         )
        self.saveButton.grid(row=0, column=0)
        self.readButton = tkinter.Button(self.buttonFrame, text="Read file",
                                         command=self.readFile,
                                         background=self.THEME_WINDOW_BG,
                                         foreground=self.THEME_FOREGROUND,
                                         borderwidth=2
                                         )
        self.readButton.grid(row=0, column=1, padx=20)
        self.deleteButton = tkinter.Button(self.buttonFrame, text="Delete file",
                                           command=self.deleter,
                                           background=self.THEME_WINDOW_BG,
                                           foreground=self.THEME_FOREGROUND,
                                           borderwidth=2
                                           )
        self.deleteButton.grid(row=0, column=2)
        self.clearText = tkinter.Button(self.buttonFrame, text="Clear text",
                                        command=self.clear,
                                        background=self.THEME_WINDOW_BG,
                                        foreground=self.THEME_FOREGROUND,
                                        borderwidth=2
                                        )
        self.clearText.grid(row=0, column=3, padx=20)
        self.contextMenu = tkinter.Menu(self.root, tearoff=False)
        self.controls = tkinter.Button(self.buttonFrame, text="Control Panel",
                                       command=self.control_panel,
                                       background=self.THEME_WINDOW_BG,
                                       foreground=self.THEME_FOREGROUND,
                                       borderwidth=2
                                       )
        self.controls.grid(row=0, column=4)
        self.contextMenu.add_command(label="Add to spell check",
                                     command=self.addToSpell)
        self.command_string = "Enable"
        self.command = self.programmerMode
        self.DARK_COLOURS = ['black', 'brown', 'blue', 'green', 'red', 'violet',
                             'purple', 'dark blue', 'dark green', 'dark red',
                             'dark brown', ]
        if self.THEME_TYPING_WIDGETS_BG in self.DARK_COLOURS:
            self.text.configure(insertbackground="white",
                                selectbackground='white',
                                selectforeground='black')
            self.saveTo.configure(insertbackground="white",
                                  selectbackground='white',
                                  selectforeground='black')
            self._title_bar(window=self.root, mode_val=20)
        print("Initialized the buttons to get into buttonFrame")
        self.root.bind("<Control-r>", self.readFile)
        self.root.bind("<Control-s>", self.save)
        self.root.bind("<Control-d>", self.deleter)
        self.root.bind("<Control-l>", self.clear)
        self.root.bind("<Button-3>", self.popup)
        self.root.bind("<Key>", self.Spell)
        self.root.bind("<Control-plus>", self.zoom_in)
        self.root.bind("<Control-minus>", self.zoom_out)
        self.root.bind("<Control-p>", self.programmerMode)
        self.root.bind("<Control-P>", self.disableProgrammerMode)
        self.root.configure(background=self.THEME_WINDOW_BG)
        self.text.configure(background=self.THEME_TYPING_WIDGETS_BG)
        self.saveTo.configure(background=self.THEME_TYPING_WIDGETS_BG)
        self.text.configure(foreground=self.THEME_FOREGROUND, borderwidth=5)
        self.saveTo.configure(foreground=self.THEME_FOREGROUND, borderwidth=5)
        try:
            self.UPDATER_FILE = requests.get("https://raw.githubusercontent.com/Viswas-Programs/Notepad/main/VERSION.txt", timeout=5)
            version, branch, a = str(self.UPDATER_FILE.content.decode(encoding='utf-8')).split("\n")
        except Exception: version = 3.3; branch = "STABLE"; 
        if float(version) > float(self.CURRENT_VERSION):
            messagebox.showinfo("Update available!", f"Version {version} of Notepad is available to download! kindly download this update.\n", None)
            self.update = tkinter.Label(self.root,
                                        text="An update is available!",
                                        background=self.THEME_WINDOW_BG,
                                        foreground=self.THEME_FOREGROUND)
            self.update.grid(row=3, column=0)
            self.wannaUpdate = tkinter.Button(self.buttonFrame, text="Update",
                                              command=self.updater,
                                              background=self.THEME_WINDOW_BG,
                                              foreground=self.THEME_FOREGROUND,
                                              borderwidth=2
                                              )
            self.wannaUpdate.grid(row=0, column=5, padx=20)
            self.root.bind("<Alt-d>", self.updater)
        self.root.mainloop()
        print(
            f"Exited the program at {datetime.datetime.now()}!\nadding an input"
            " so that from py console the console will show logs!")
        input()
    def showChangelogs(self):
        """ changelog """
        CHANGELOGS = tkinter.Toplevel()
        CHANGELOG = str(requests.get("https://raw.githubusercontent.com/Viswas-Programs/Notepad/main/CHANGELOG.txt").content.decode)

        showChangelog = tkinter.Label(CHANGELOGS, background=self.THEME_WINDOW_BG, foreground=self.THEME_FOREGROUND, text=CHANGELOG)
        showChangelog.grid(row=0, column=1)
        CHANGELOGS.mainloop()


    def updater(self, event=None):
        """ update program"""
        self.showChangelogs()
        SOURCE_FOLDER = inspect.getfile(lambda: None).removesuffix("notepadGUI.py")
        DESTINATION_FOLDER = f"{self.CURRENT_VERSION}-{self.UPDATE_BRANCH}"
        os.mkdir(DESTINATION_FOLDER)
        # from this point, till '=====', it's code copied from pynative.com. so don't blame me for the code!
        for file_name in os.listdir(SOURCE_FOLDER):
            # construct full file path
            source = SOURCE_FOLDER + file_name
            destination = DESTINATION_FOLDER + file_name
            # copy only files
            if os.path.isfile(source):
                shutil.copy(source, destination)
                os.remove(source)
        # =====
        # My code again
        updateZip = requests.get("https://github.com/Viswas-Programs/Notepad/raw/update/updatedProgram.zip")
        ExtractFiles = zipfile.ZipFile(BytesIO(updateZip.content))
        ExtractFiles.extractall(os.getcwd())

        def restart():
            import subprocess
            """ restart the program!"""
            subprocess.Popen(["python3", str(fullpath)])
            exit()

        check = messagebox.askyesno('Reboot required!', 'Do you want to restart the program now, or '
                                                        'later manually?')
        if check == 1:
            restart()

    def addBrace(self, event=None):
        """ add left curly brace automatically"""
        print("called addBrace() function")
        indexer = self.text.index(tkinter.INSERT)
        self.text.insert(indexer, "}")
        self.text.mark_set(tkinter.INSERT, "insert-1c")

    def addSquareBracket(self, event=None):
        """ add left square bracket (used for list) automatically"""
        print("called addSquareBracket() function")
        indexer = self.text.index(tkinter.INSERT)
        self.text.insert(indexer, "]")
        self.text.mark_set(tkinter.INSERT, "insert-1c")

    def addBracket(self, event=None):
        """ add left parenthesis automatically"""
        print("called addBracket() function")
        indexer = self.text.index(tkinter.INSERT)
        self.text.insert(indexer, ")")
        self.text.mark_set(tkinter.INSERT, "insert-1c")

    def save(self, event=None):
        """save files"""
        print("called save() function")
        self.FILE_EXIST = True
        self.saved = True
        try:
            if "rrr" in self.text.get(1.0, tkinter.END).rstrip("\n"):
                self.text.delete(1.0, tkinter.END)
                self.text.insert(1.0,
                                 """ We're no strangers to love
You know the rules and so do I
A full commitment's what I'm thinking of
You wouldn't get this from any other guy
I just want to tell you how I'm feeling
Gotta make you understand
Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you
We've known each other for so long
Your heart's been aching but you're too shy to say it
Inside we both know what's been going on
We know the game and we're gonna play it
And if you ask me how I'm feeling
Don't tell me you're too blind to see
Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you
Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you
Ooh, give you up
Ooh, give you up
(Ooh) Never gonna give, never gonna give (Give you up)
(Ooh) Never gonna give, never gonna give (Give you up)
We've known each other for so long
Your heart's been aching but you're too shy to say it
Inside we both know what's been going on
We know the game and we're gonna play it
I just want to tell you how I'm feeling
Gotta make you understand
Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you
Never gonna give you up, never gonna let you down
Never gonna run around and desert you
Never gonna make you cry, never gonna say goodbye
Never gonna tell a lie and hurt you
Never gonna give you up, never gonna let you down
Never gonna run around and desert you""")
            if ".pdf" in self.saveTo.get(1.0, tkinter.END).rstrip("\n").split("/")[-1]:
                from fpdf import FPDF
                PDF = FPDF('P', 'mm', 'A4')
                # check = self.text.get(1.0, tkinter.END)
                # index_no_width = check.find("width=")
                # semicolon1 = check.find(";1")
                # index_no_height = check.find("height=")
                # semicolon2 = check.find(";2")
                # height_PDF = str(check[index_no_width + 6:
                #                     semicolon1]).rstrip(";1")
                # width_PDF = str(check[index_no_height + 7:
                #                     semicolon2]).rstrip(";2")
                # print(height_PDF, width_PDF)
                PDF.add_page()
                PDF.set_font(str(self.font[0]), '', int(self.size))
                PDF.cell(40, 10, self.text.get(1.0, tkinter.END))
                PDF.output(self.saveTo.get(1.0, tkinter.END).rstrip("\n").rstrip("\r"))
            else:
                with open(self.saveTo.get(1.0, tkinter.END).rstrip("\n"), "w") as \
                        writer:
                    writer.write(self.text.get(1.0, tkinter.END))
            self.saveButton.config(text="Saved file")
            self.root.title(f"{self.saveTo.get(1.0, tkinter.END)} - Notepad")
        except FileNotFoundError:
            def folderCreate():
                """ create folder if it doesn't exist!"""
                os.mkdir(createFolderText.get(1.0, tkinter.END).rstrip("\n"))

            createFolder = tkinter.Tk()
            createFolder.configure(background=self.THEME_WINDOW_BG)
            self._title_bar(window=createFolder, mode_val=20)
            msg = tkinter.Label(createFolder, text="Create the folder before "
                                                   "saving file in the "
                                                   "folder!",
                                background=self.THEME_WINDOW_BG,
                                foreground=self.THEME_FOREGROUND)
            msg.grid(row=0, column=0, columnspan=2)
            createFolderText = tkinter.Text(createFolder, width=40, height=2)
            createFolderText.grid(row=1, column=0, padx=30, pady=30)
            createFolderButton = tkinter.Button(createFolder,
                                                text="Create folder!",
                                                command=folderCreate,
                                                background=self.THEME_WINDOW_BG,
                                                foreground=self.THEME_FOREGROUND,
                                                borderwidth=2)
            createFolderButton.grid(row=2, column=0)
            createFolder.mainloop()

    def programmerMode(self, event=None):
        """ enables programmer mode, automatic parenthesis completion and syntax
        highlighting"""
        self.command_string = "Disable"
        self.command = self.disableProgrammerMode
        TEMP = self.text.get(1.0, tkinter.END)
        self.text.destroy()
        self.text = tkinter.Text(self.root, height=20, width=100,
                                 font=(self.font, self.size),
                                 background=self.THEME_TYPING_WIDGETS_BG,
                                 foreground=self.THEME_FOREGROUND)
        if self.THEME_TYPING_WIDGETS_BG in self.DARK_COLOURS:
            self.text.configure(insertbackground="white",
                                selectbackground='white',
                                selectforeground='black')
            self.saveTo.configure(insertbackground="white",
                                  selectbackground='white',
                                  selectforeground='black')
        self.text.grid(row=0, column=0, pady=10)
        self.text.insert(1.0, TEMP)
        self.PROGRAMMER_MODE = True
        self.root.unbind("<Key>")
        syntax = syntax_checker.SyntaxChecker(text=self.text,
                                              root=self.root,
                                              )

        def syntax_Python():
            """ syntax check function, this is a redirect to the
            syntax_checker.py file. so the program doesn't need extensive
            changing. this is JUST A REDIRECT!"""
            syntax_checker.SyntaxChecker.syntax_python(syntax)
            self.root.unbind("<Button-3>")

        def syntax_JS():
            """ JS Version-> but same explanation
                syntax check function, this is a redirect to the
                syntax_checker.py file. so the program doesn't need extensive
                changing. this is JUST A REDIRECT!"""
            syntax_checker.SyntaxChecker.syntax_JS(syntax)
            self.root.unbind("<Button-3>")

        def syntax_C():
            """ C Version-> but same explanation
                syntax check function, this is a redirect to the
                syntax_checker.py file. so the program doesn't need extensive
                changing. this is JUST A REDIRECT!"""
            syntax_checker.SyntaxChecker.syntax_C(syntax)
            self.root.unbind("<Button-3>")

        global filetype
        print("called programmerMode() function")
        filetype = (
            ("Text documents (.txt)", "*.txt"),
            ("HTML Files (.html and .htm)", "*.html" and "*.htm"),
            ("Python files (.py)", ".py"),
            ("C++ files (.cpp)", "*.cpp"),
            ("C files (.c)", "*.c"),
            ("Java files (.java)", "*.java"),
            ("JS Files (.js)", "*.js"),
            ("All types (*)", "*.*"),
        )
        self.root.bind("(", self.addBracket)
        self.root.bind("{", self.addBrace)
        self.root.bind("[", self.addSquareBracket)
        self.root.bind('"', self.addDoubleQuotes)
        self.root.bind("'", self.addSingleQuote)
        self.PROGRAM_MODE_CONFIG = True
        lang = ["Python", "JS", "C"]
        if not self.SELECT_PROGRAMMING_LANG:
            newWindow = tkinter.Tk()
            newWindow.title("Select a programming language")
            self._title_bar(window=newWindow, mode_val=20)
            newWindow.configure(background=self.THEME_WINDOW_BG)
            chooser = tkinter.Listbox(newWindow, height=len(lang), width=30)
            chooser.grid(row=0, column=0)
            for i, v in enumerate(lang):
                chooser.insert(i, v)

            def command():
                """ command execute"""
                nonlocal syntax_Python
                nonlocal syntax_JS
                nonlocal syntax_C
                choose = chooser.curselection()
                selection = chooser.get(choose)
                commandToExecute = f"syntax_{selection}()"
                exec(commandToExecute)

            choose_it = tkinter.Button(newWindow, text="Choose language!",
                                       command=command,
                                       background=self.THEME_WINDOW_BG,
                                       foreground=self.THEME_FOREGROUND,
                                       borderwidth=2,)
            choose_it.grid(row=1, column=0)
            newWindow.mainloop()

    def disableProgrammerMode(self, event=None):
        """ disable programmer mode"""
        global filetype
        self.root.unbind("(")
        self.root.unbind("{")
        self.root.unbind("[")
        self.root.unbind('"')
        self.root.unbind("'")
        self.root.unbind("`")
        self.root.unbind_all("<Key>")
        TEMP = self.text.get(1.0, tkinter.END)
        self.text.destroy()
        self.text = tkinter.Text(self.root, height=20, width=100,
                                 font=(self.font, self.size),
                                 background=self.THEME_TYPING_WIDGETS_BG,
                                 foreground=self.THEME_FOREGROUND)
        if self.THEME_TYPING_WIDGETS_BG in self.DARK_COLOURS:
            self.text.configure(insertbackground="white",
                                selectbackground='white',
                                selectforeground='black')
            self.saveTo.configure(insertbackground="white",
                                  selectbackground='white',
                                  selectforeground='black')
        self.text.grid(row=0, column=0, pady=10)
        self.text.insert(1.0, TEMP)
        self.PROGRAMMER_MODE = False
        self.PROGRAM_MODE_CONFIG = False
        self.root.bind("<Key>", self.Spell)
        self.command_string = "Enable"
        self.command = self.programmerMode
        filetype = (
            ("Text documents (.txt)", "*.txt"),
            ("All types (*)", "*.*"),
        )
        print("called disableProgrammerMode() function")
        self.root.bind('<Button-3>', self.popup)

    def readFile(self, event=None, file=None):
        """ read files"""
        def checkIfPdfOrNot():
            if ".pdf" in filePath.split("/")[-1] or ".pdf" in filePath.split("/")[-1]:
                import PyPDF2
                PDFFile = PyPDF2.PdfReader(filePath)
                PageCount = len(PDFFile.pages)
                _OUTPUT = []
                for i in range(PageCount):
                    _OUTPUT.append(PDFFile.pages[i].extract_text())
                returnReader = "\n".join(ueif for ueif in _OUTPUT)
                check = returnReader.rstrip()
            else:
                with open(filePath, "r") as reader:
                    returnReader = reader.read()
                    check = returnReader.rstrip()
            return returnReader, check
        print("called readFile() function")
        self.root.title("Notepad GUI v3.3")
        self.saved = True
        if file is None:
            filePath = filedialog.askopenfilename(title="Open file to read",
                                                filetypes=filetype)
        else:
            filePath = file
        try:
            returnReader, check = checkIfPdfOrNot()
            if "VIEW MODE" in check:
                self.text.delete(1.0, tkinter.END)
                self.text.insert(1.0, returnReader)
                self.text.configure(state="disabled")
                self.saveTo.configure(state="disabled")
                self.saveTo.delete(1.0, tkinter.END)
                self.saveTo.insert(1.0, filePath)
            elif "PROTECTED MODE" in check:
                def proceed():
                    """ proceed to unlock file for the session!"""
                    if usrname_check.get() == username:
                        if password_check.get() == password:
                            self.saveTo.delete(1.0, tkinter.END)
                            self.text.delete(1.0, tkinter.END)
                            self.text.insert(1.0, returnReader)
                            elideTextLastIndex = self.text.index('1.5 lineend')
                            self.text.tag_add('hide', 1.0, elideTextLastIndex)
                            self.text.tag_configure('hide', elide=True)
                            self.saveTo.insert(1.0, filePath)
                        else:
                            messagebox.showerror("Access denied", "The password is incorrect!", None)
                    else:
                        messagebox.showerror("Access denied", "The username is incorrect!", None)

                check.split()
                index_no_usrname = check.find("usrname=")
                semicolon1 = check.find(";1")
                index_no_passwrd = check.find("password=")
                semicolon2 = check.find(";2")
                username = str(check[index_no_usrname + 8:
                                     semicolon1]).rstrip(";1")
                password = str(check[index_no_passwrd + 9:
                                     semicolon2]).rstrip(";2")
                gui = tkinter.Toplevel(self.root, background=self.THEME_WINDOW_BG)
                tkinter.Label(gui, text="This is a protected file, please enter"
                                        " the credentials",
                              background=self.THEME_WINDOW_BG,
                              foreground=self.THEME_FOREGROUND).grid(row=0,
                                                                     column=0)
                tkinter.Label(gui, text="Enter username -> ",
                              background=self.THEME_WINDOW_BG,
                              foreground=self.THEME_FOREGROUND).grid(row=1,
                                                                     column=0)
                usrname_check = tkinter.Entry(gui, background=self.THEME_TYPING_WIDGETS_BG, foreground=self.THEME_FOREGROUND)
                usrname_check.configure(insertbackground=self.THEME_FOREGROUND, selectbackground=self.THEME_FOREGROUND, selectforeground=self.THEME_WINDOW_BG)
                usrname_check.grid(row=1, column=1)
                tkinter.Label(gui, text='Enter password -> ',
                              background=self.THEME_WINDOW_BG,
                              foreground=self.THEME_FOREGROUND).grid(row=2,
                                                                     column=0)
                password_check = tkinter.Entry(gui, background=self.THEME_TYPING_WIDGETS_BG, foreground=self.THEME_FOREGROUND)
                password_check.configure(insertbackground=self.THEME_FOREGROUND, selectbackground=self.THEME_FOREGROUND, selectforeground=self.THEME_WINDOW_BG)
                password_check.grid(row=2, column=1)
                submit = tkinter.Button(gui, text="Check!", command=proceed,
                                        background=self.THEME_WINDOW_BG,
                                        foreground=self.THEME_FOREGROUND,
                                        borderwidth=2
                                        )
                submit.grid(row=3, column=1)
                gui.mainloop()

            else:
                self.saveTo.delete(1.0, tkinter.END)
                self.text.delete(1.0, tkinter.END)
                self.text.insert(1.0, returnReader)
                self.saveTo.insert(1.0, filePath)
                self.root.title(f"{filePath} - Notepad")
            if self.PROGRAMMER_MODE:
                self.programmerMode()
        except FileNotFoundError or TypeError:
            if filePath == '' or isinstance(filePath, tuple):
                print("No file selected")
            else:
                messagebox.showerror("File not found!", "The selected file doesn't exist! so, we "
                                                        "can't open it. reverted changes", None)
        except UnicodeDecodeError:
            messagebox.showerror("Cannot Open File",
                                 "This editor doesn't support this format! file"
                                 "cannot be opened! No changes made!", None)

    def addDoubleQuotes(self, event=None):
        """ add double quotes"""
        print("called addDoubleQuotes() function")
        self.text.insert(tkinter.INSERT, '"')
        self.text.mark_set(tkinter.INSERT, "insert-1c")

    def addSingleQuote(self, event=None):
        """ add single quotes"""
        print("called addSingleQuote() function")
        self.text.insert(tkinter.INSERT, "'")
        self.text.mark_set(tkinter.INSERT, "insert-1c")

    def deleter(self, event=None):
        """ delete files"""
        print("called deleter() function")
        if os.access(self.saveTo.get(1.0, tkinter.END).rstrip("\n"), os.F_OK):
            os.remove(self.saveTo.get(1.0, tkinter.END).rstrip("\n"))
            self.text.delete(1.0, tkinter.END)
            self.saveTo.delete(1.0, tkinter.END)
            self.root.title("Notepad GUI v3.3")
        else:
            messagebox.showerror("File doesn't exist",
                                 "The file you are trying to delete doesn't exist!", None)

    def clear(self, event=None):
        """ clear text """
        print("called clear() function")
        self.text.delete(1.0, tkinter.END)

    def Spell(self, event=None):
        """ spell checker"""
        print("called Spell() function")
        spellchecker = syntax_checker.SpellCheck(text=self.text, root=self.root)
        syntax_checker.SpellCheck.SpellChecker(spellchecker)

    def addToSpell(self, event=None):
        """ add to spell check"""
        print("called addToSpell() function")
        spellchecker = syntax_checker.SpellCheck(text=self.text, root=self.root)
        if self.text.tag_ranges(tkinter.SEL):
            syntax_checker.SpellCheck.addToSpellCheck(spellchecker,
                                                      self.text.get(
                                                          tkinter.SEL_FIRST,
                                                          tkinter.SEL_LAST))

    def popup(self, event=None):
        """ the context menu popup"""
        print("called popup() function")
        problem = None
        try:
            self.contextMenu.tk_popup(event.x_root, event.y_root, 0)
        except Exception as PROBLEM:
            problem = PROBLEM
        finally:
            self.contextMenu.grab_release()
            if problem:
                messagebox.showerror("Error", str(problem), None)

    def zoom_in(self, event=None):
        """ zoom in to the text!"""
        print("called zoom_in() function")
        self.size += self.ZOOM_SIZE
        self.text.configure(font=(self.font, self.size))

    def zoom_out(self, event=None):
        """ zoom out of the text"""
        print("called zoom_out() function")
        self.size -= self.ZOOM_SIZE
        self.text.configure(font=(self.font, self.size))

    def control_panel(self):
        """ control panel!"""
        print("called control_panel() function")
        control_window = tkinter.Tk()
        control_window.title("Control Panel")
        if self.THEME_WINDOW_BG in self.DARK_COLOURS:
            self._title_bar(window=control_window, mode_val=20)
        else:
            self._title_bar(window=control_window, mode_val=0)
        control_window.configure(background=self.THEME_WINDOW_BG)
        colour = self.THEME_WINDOW_BG
        if self.PROGRAM_MODE_CONFIG:
            self.command_string = "Disable"
            self.command = self.disableProgrammerMode
        else:
            self.command_string = "Enable"
            self.command = self.programmerMode

        programMode = tkinter.Button(control_window,
                                     text=f"{self.command_string} Programmer "
                                          f"mode",
                                     command=self.command,
                                     background=self.THEME_WINDOW_BG,
                                     foreground=self.THEME_FOREGROUND,
                                     borderwidth=2
                                     )
        programMode.grid(row=0, column=0)
        zoom_plus = tkinter.Button(control_window,
                                   text=f"Zoom in ({self.ZOOM_SIZE})",
                                   command=self.zoom_in,
                                   background=self.THEME_WINDOW_BG,
                                   foreground=self.THEME_FOREGROUND,
                                   borderwidth=2
                                   )
        zoom_plus.grid(row=1, column=3, padx=10)
        zoom_minus = tkinter.Button(control_window,
                                    text=f"Zoom out (-{self.ZOOM_SIZE})",
                                    command=self.zoom_out,
                                    background=self.THEME_WINDOW_BG,
                                    foreground=self.THEME_FOREGROUND,
                                    borderwidth=2
                                    )

        def change_colour(event=None):
            """ changes colour of `zoom_size` tkinter.Entry widget"""
            nonlocal colour
            if colour == self.THEME_WINDOW_BG:
                colour = "White"
                zoom_size.configure(bg="white")
            else:
                colour = self.THEME_WINDOW_BG
                zoom_size.configure(bg=self.THEME_WINDOW_BG)

        def change_colour_zoom(event=None):
            """ changes colour of `zoom` tkinter.Entry widget"""
            nonlocal colour
            if colour == self.THEME_WINDOW_BG:
                colour = "White"
                zoom.configure(bg="white")
            else:
                colour = self.THEME_WINDOW_BG
                zoom.configure(bg=self.THEME_WINDOW_BG)

        def apply_zoom_modif_size():
            """ apply zooming size, i.e. whether to zoom in +5 ot 2 or any
            other you enter to `zoom_size` tkinter.Entry widget!"""
            self.ZOOM_SIZE = int(zoom_size.get())
            zoom_plus.configure(text=f"Zoom in ({self.ZOOM_SIZE})")
            zoom_minus.configure(text=f"Zoom out ({self.ZOOM_SIZE})")

        def apply_zoom_size():
            """ apply zoom size, i.e. 18, 12, like that"""
            self.size = int(zoom.get())
            changed_size = tkinter.font.Font(family=self.font,
                                     size=self.size)
            self.text.configure(font=changed_size)

        def change_theme():
            """ changes the theme of whatever widget is selected from the
            `widget_selector_themes` combobox. """
            if widget_selector_themes.get() == "Text and SaveTo widget":
                colour = colorchooser.askcolor(title="Choose colours for the "
                                                     "typing widgets!")
                if str(colour[1]) in self.DARK_COLOURS:
                    self.text.configure(background=str(colour[1]),
                                        insertbackground="white",
                                        selectbackground='white',
                                        selectforeground='black')
                    self.saveTo.configure(background=str(colour[1]),
                                          insertbackground="white",
                                          selectbackground='white',
                                          selectforeground='black')
                else:
                    self.text.configure(background=str(colour[1]))
                self.saveTo.configure(background=str(colour[1]))
                self.THEME_TYPING_WIDGETS_BG = str(colour[1])
            elif widget_selector_themes.get() == "windows":
                colour = colorchooser.askcolor(title="Choose colours for the "
                                                     "window backgrounds!")
                self.root.configure(background=str(colour[1]))
                control_window.configure(background=str(colour[1]))
                self.THEME_WINDOW_BG = str(colour[1])
                if str(colour[1]) in self.DARK_COLOURS:
                    self._title_bar(window=self.root, mode_val=20)
                    self._title_bar(window=control_window, mode_val=20)
                else:
                    self._title_bar(self.root, 0)
                widgets = ("self.controls", 'self.saveButton',
                           'self.readButton', 'self.deleteButton',
                           'self.clearText')
                for widget in widgets:
                    exec(f"{widget}.configure("
                         "background=self.THEME_WINDOW_BG,)")
                self.buttonFrame.configure(background=self.THEME_WINDOW_BG,)
            else:
                colour = colorchooser.askcolor(title="Choose colours for the "
                                                     "foreground!")
                self.text.configure(foreground=str(colour[1]))
                self.saveTo.configure(foreground=str(colour[1]))
                self.THEME_TYPING_WIDGETS_BG = str(colour[1])
                widgets = ("self.controls", 'self.saveButton',
                           'self.readButton', 'self.deleteButton',
                           'self.clearText')
                for widget in widgets:
                    exec(f"{widget}.configure("
                         "foreground=self.THEME_FOREGROUND,)")

        zoom_minus.grid(row=1, column=4)
        tkinter.Label(control_window, text="Zooming-> ",
                      background=self.THEME_WINDOW_BG,
                      foreground=self.THEME_FOREGROUND).grid(row=1, column=0)
        zoom_size = tkinter.Entry(control_window, bg=self.THEME_WINDOW_BG)
        zoom_size.grid(row=1, column=1)
        zoom_size.insert(0, str(self.ZOOM_SIZE))
        zoom_size.bind("<Enter>", change_colour)
        zoom_size.bind("<Leave>", change_colour)
        tkinter.Label(control_window, text="Zoom Size-> ",
                      background=self.THEME_WINDOW_BG,
                      foreground=self.THEME_FOREGROUND).grid(row=2,
                                                             column=0)
        zoom = tkinter.Entry(control_window, bg=self.THEME_WINDOW_BG)
        zoom.grid(row=2, column=1)
        zoom.insert(0, str(self.size))
        zoom.bind("<Enter>", change_colour_zoom)
        zoom.bind("<Leave>", change_colour_zoom)
        apply = tkinter.Button(control_window,
                               text="Apply Zooming Size",
                               command=apply_zoom_modif_size,
                               background=self.THEME_WINDOW_BG,
                               foreground=self.THEME_FOREGROUND,
                               borderwidth=2
                               )
        apply.grid(row=1, column=2)
        apply_zoom = tkinter.Button(control_window,
                                    text="Apply Zoom Size",
                                    command=apply_zoom_size,
                                    background=self.THEME_WINDOW_BG,
                                    foreground=self.THEME_FOREGROUND,
                                    borderwidth=2
                                    )
        apply_zoom.grid(row=2, column=2, sticky=tkinter.N)
        tkinter.Label(control_window, text='Select your font!',
                      background=self.THEME_WINDOW_BG,
                      foreground=self.THEME_FOREGROUND).grid(row=3,
                                                             column=0)
        widget_selector_themes = ttk.Combobox(control_window)
        widget_selector_themes['values'] = ["Text and SaveTo widget",
                                            "windows", "foreground", ]
        widget_selector_themes.grid(row=4, column=0)
        change_colour_btn = tkinter.Button(control_window,
                                           text="Change colour of text widget",
                                           command=change_theme,
                                           background=self.THEME_WINDOW_BG,
                                           foreground=self.THEME_FOREGROUND,
                                           borderwidth=2
                                           )
        change_colour_btn.grid(row=4, column=1)
        font_selector = ttk.Combobox(control_window)
        fonts = list(font.families())
        font_selector['values'] = fonts
        font_selector['state'] = 'readonly'

        def confirm_selection(e=None):
            """ confirm font selection!"""
            self.font = (font_selector.get(),)
            self.text.configure(font=self.font)

        font_selector.bind("<<ComboboxSelected>>", confirm_selection)
        font_selector.grid(row=3, column=1)


        def send_file():
            global encryption
            """ send files GUI, if done neatly, will call the self._sendFiles()
            method"""
            def submit_form():
                """ submits the form to self._sendFiles()"""
                self._sendFiles(ip_address.get(), port.get(), fileSelect)
            key = b'KEYKEYKEY123456123456'
            messagebox.showinfo("Key", f"Key is {key}", None)
            encryption = Fernet(key)
            send_file_gui = tkinter.Tk()
            send_file_gui.configure(background=self.THEME_WINDOW_BG,)
            send_file_gui.title("File transfer form")
            self._title_bar(window=send_file_gui, mode_val=20)
            a = tkinter.Label(send_file_gui,
                              text="Enter the IP address of the receiver:->",
                              background=self.THEME_WINDOW_BG,
                              foreground=self.THEME_FOREGROUND)
            a.grid(row=0, column=0)
            ip_address = tkinter.Entry(send_file_gui)
            ip_address.grid(row=0, column=1)
            b = tkinter.Label(send_file_gui,
                              text="Enter the file needed to be sent:->",
                              background=self.THEME_WINDOW_BG,
                              foreground=self.THEME_FOREGROUND)
            b.grid(row=1, column=0)

            def fileselector():
                """ file select"""
                global fileSelect
                fileSelect = filedialog.askopenfilename(title="Select files to "
                                                              "send over")
                return fileSelect

            select_files = tkinter.Button(send_file_gui,
                                          text="Select file",
                                          background=self.THEME_WINDOW_BG,
                                          foreground=self.THEME_FOREGROUND,
                                          command=fileselector)
            select_files.grid(row=1, column=1)
            port_label = tkinter.Label(send_file_gui,
                                       text="Enter the port to send files",
                                       background=self.THEME_WINDOW_BG,
                                       foreground=self.THEME_FOREGROUND,)
            port_label.grid(row=2, column=0)
            port = tkinter.Entry(send_file_gui,)
            port.insert(tkinter.END, 5001)
            port.grid(row=2, column=1)
            submit = tkinter.Button(send_file_gui,
                                    text="Submit the form",
                                    background=self.THEME_WINDOW_BG,
                                    foreground=self.THEME_FOREGROUND,
                                    command=submit_form)
            submit.grid(row=3, column=0)
            send_file_gui.mainloop()


        def recieveFiles():
            """ recieve files that had been sent (using thepythoncode.com's
            code)"""
            def submit_form():
                """ submits the form to self._sendFiles()"""
                self._receiveFiles(ip_address.get(), port=int(port.get()))
            recieve_files = tkinter.Tk()
            recieve_files.configure(background=self.THEME_WINDOW_BG,)
            recieve_files.title("File transfer form")
            self._title_bar(window=recieve_files, mode_val=20)
            a = tkinter.Label(recieve_files,
                              text="Enter the IP address of the receiver:->",
                              background=self.THEME_WINDOW_BG,
                              foreground=self.THEME_FOREGROUND)
            a.grid(row=0, column=0)
            ip_address = tkinter.Entry(recieve_files)
            ip_address.grid(row=0, column=1)
            b = tkinter.Label(recieve_files,
                              text="Enter the port:->",
                              background=self.THEME_WINDOW_BG,
                              foreground=self.THEME_FOREGROUND)
            b.grid(row=1, column=0)
            port = tkinter.Entry(recieve_files)
            port.grid(row=1, column=1)
            submit = tkinter.Button(recieve_files,
                                    text="Submit the form",
                                    background=self.THEME_WINDOW_BG,
                                    foreground=self.THEME_FOREGROUND,
                                    command=submit_form)
            submit.grid(row=2, column=0)
            recieve_files.mainloop()
        a = tkinter.Label(master=control_window,
                          text="Transfer Files",
                          background=self.THEME_WINDOW_BG,
                          foreground=self.THEME_FOREGROUND)
        a.grid(row=5, column=0)
        send_files_btn = tkinter.Button(control_window,
                                    text="Send files over local network",
                                    background=self.THEME_WINDOW_BG,
                                    foreground=self.THEME_FOREGROUND,
                                    command=send_file)
        send_files_btn.grid(row=5, column=1)
        recieve_files_btn = tkinter.Button(control_window,
                                           text="Read the sent files in the "
                                                "network",
                                           background=self.THEME_WINDOW_BG,
                                           foreground=self.THEME_FOREGROUND,
                                           command=recieveFiles)
        recieve_files_btn.grid(row=5, column=2)

        control_window.mainloop()

    def on_close(self):
        """ closing message!"""
        print("called on_close() function")
        if not self.saved:
            alert = messagebox.askyesnocancel(
                "Save the file?",
                "This is an unsaved document. so do you wanna save em and, "
                "close this?", )
            print("CAME FROM ALERT")
            print(type(alert))
            if alert == True:
                self.save()
                self.root.destroy()
            elif alert == False:
                self.root.destroy()
            else:
                pass
        elif self.saved:
            self.root.destroy()

    def _title_bar(self, window: tkinter.Tk or tkinter.Toplevel, mode_val:
    typing.Literal[20, 0]):
        """
        MORE INFO:
        https://docs.microsoft.com/en-us/windows/win32/api/dwmapi/ne-dwmapi-dwmwindowattribute
        """
        global MSG_SHOWN
        if platform.system() == "Windows":
            window.update()
            DWMWA_USE_IMMERSIVE_DARK_MODE = mode_val
            set_window_attribute = ct.windll.dwmapi.DwmSetWindowAttribute
            get_parent = ct.windll.user32.GetParent
            hwnd = get_parent(window.winfo_id())
            rendering_policy = DWMWA_USE_IMMERSIVE_DARK_MODE
            value = 0
            value = ct.c_int(value)
            set_window_attribute(hwnd, rendering_policy, ct.byref(value),
                                 ct.sizeof(value))
        else:
            if not MSG_SHOWN:
                messagebox.showinfo(f"Function not supported for "
                                     f"{platform.system()}!", "The Title-Bar changer function is not "
                                     f"supported for {platform.system()}, the program will continue", None)
                MSG_SHOWN = True

    def _sendFiles(self, sender_ip, port, file_path):
        global encryption
        """ send files over the same network
        thepythoncode.com's CODE"""
        #ALERT: thepythoncode.com's CODE! MAY CONTAIN FLAWS WITH MY CODE
        SEPARATOR = "<SEPARATOR>"
        BUFFER_SIZE = 4096
        host = sender_ip
        port = port
        # the name of file we want to send, make sure it exists
        filename = file_path
        # get the file size
        filesize = os.path.getsize(filename)
        s = socket.socket()
        print(f"[+] Connecting to {host}:{port}")
        s.connect((host, port))
        print("[+] Connected.")
        s.send(f"{filename}{SEPARATOR}{filesize}".encode())
        with open(filename, "rb+") as f:
            while True:
                # read the bytes from the file
                bytes_read =  f.read(BUFFER_SIZE)
                if not bytes_read:
                    # file transmitting is done
                    break
                # we use sendall to assure transimission in busy networks
                file_to_send = encryption.encrypt(bytes_read)
                s.sendall(file_to_send)
        messagebox.showinfo("Success", f"Connected and sent to {sender_ip}", None)

        # close the socket
        s.close()

    def _receiveFiles(self, key, receiver_ip, port=5001):
        """ receive files in the same network (thepythoncode.com's code)"""
        SERVER_HOST = receiver_ip
        SERVER_PORT = port
        # receive 4096 bytes each time
        BUFFER_SIZE = 4096
        SEPARATOR = "<SEPARATOR>"
        s = socket.socket()
        # bind the socket to our local address
        s.bind((SERVER_HOST, SERVER_PORT))
        s.listen(10)
        print(f"[*] Listening as {SERVER_HOST}:{SERVER_PORT}")
        client_socket, address = s.accept()
        # if below code is executed, that means the sender is connected
        print(f"[+] {address} is connected.")
        messagebox.showinfo("Connection successful", f"{address} is connected to your computer")
        received = client_socket.recv(BUFFER_SIZE).decode()
        filename, filesize = received.split(SEPARATOR)
        # remove absolute path if there is
        filename = os.path.basename(filename)
        # convert to integer
        filesize = int(filesize)
        with open(filename, "wb+") as f:
            while True:
                # read 1024 bytes from the socket (receive)
                bytes_read = client_socket.recv(BUFFER_SIZE)
                if not bytes_read:
                    # nothing is received
                    # file transmitting is done
                    break
                # write to the file the bytes we just received
                decryptor = Fernet(key=key)
                file_to_receive = decryptor.decrypt(bytes_read).decode(encoding='utf-8')
                f.write(file_to_receive)
        # close the client socket
        client_socket.close()
        # close the server socket
        s.close()

    def open_file_default(self):
        if self.fileopen != None:
            self.readFile(file=self.fileopen)

def main():
    """ main """
    root = tkinter.Tk()
    root.title("Notepad GUI v3.3 STABLE")
    text = tkinter.Text(root, height=20, width=100,
                        font=("Arial Rounded MT Bold",
                              18), )
    text.grid(row=0, column=0, pady=10)
    saveTo = tkinter.Text(root, height=2, width=50,
                          font=("Arial Rounded MT Bold",
                                12))
    saveTo.grid(row=1, column=0)
    NotepadRun(text_box=text, gui=root, saveTo=saveTo)


if __name__ == "__main__":
    main()
