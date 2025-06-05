import tkinter, shelve
THEME_WINDOW_BG, THEME_FOREGROUND = shelve.open("ProgramFiles/SYS_CONFIG")["THEME"]
returner_ASKYESNOCANCEL = "Job pend"
returner_SHOWERROR = "Job pend"

class messagebox:
    def showerror(header=None, msg=None, root=None, use_preset=False, type_preset=None):
        def returnOk(): MsgBox.destroy(); return 1
        if root == None:
            root = tkinter.Toplevel(background=THEME_WINDOW_BG)
            root.title("DEBUG WINDOW")
        
        MsgBox = tkinter.Toplevel(root, background=THEME_WINDOW_BG)
        MsgBox.title(header)
        try:
            if use_preset: import ProgramFiles.errorHandles as errorHandles; msg = errorHandles.find_item(type_preset); header = "Error!"
        except Exception: msg = " "; header = " "
        exec(f"errorICON = tkinter.PhotoImage(file='ProgramFiles/Icons/error.png')")
        exec(f"Msg = tkinter.Label(MsgBox, text=str(msg), background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, image=errorICON, compound=tkinter.LEFT)")
        exec(f"MsgBox.IMGREF = errorICON")
        exec(f"Msg.pack(side='left')")
        exec(f'Btn = tkinter.Button(MsgBox, text="Ok", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnOk)')
        exec(f"Btn.pack(side='right', anchor='s')")
        MsgBox.mainloop()
    def showinfo(header, msg, root, use_preset=False, type_preset=None):
        def returnOk(): MsgBox.destroy(); return 1
        if root == None:
            root = tkinter.Toplevel(background=THEME_WINDOW_BG)
            root.title("DEBUG WINDOW")
        MsgBox = tkinter.Toplevel(root, background=THEME_WINDOW_BG)
        MsgBox.configure(background=THEME_WINDOW_BG)
        MsgBox.title(header)
        if use_preset: 
            try:
                import ProgramFiles.errorHandles as errorHandles; msg = errorHandles.find_item(type_preset)
            except ModuleNotFoundError: msg = ""; header=' '
        exec(f"errorICON = tkinter.PhotoImage(file=f'ProgramFiles/Icons/info.png')")
        exec(f"Msg = tkinter.Label(MsgBox, text=str(msg), background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, image=errorICON, compound=tkinter.LEFT)")
        exec(f"MsgBox.IMGREF = errorICON")
        exec(f"Msg.pack(side='left')")
        exec(f'Btn = tkinter.Button(MsgBox, text="Ok", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnOk)')
        exec(f"Btn.pack(side='right', anchor='s')")
        MsgBox.mainloop()
    def showwarning(header, msg, root, use_preset=False, type_preset=None):
        def returnOk(): MsgBox.destroy(); return 1
        if root == None:
            root = tkinter.Toplevel(background=THEME_WINDOW_BG)
            root.title("DEBUG WINDOW")
        MsgBox = tkinter.Toplevel(root, background=THEME_WINDOW_BG)
        MsgBox.configure(background=THEME_WINDOW_BG)
        MsgBox.title(header)
        if use_preset: 
            try:
                import ProgramFiles.errorHandles as errorHandles; msg = errorHandles.find_item(type_preset)
            except ModuleNotFoundError: msg = ""; header=' '
        exec(f"errorICON = tkinter.PhotoImage(file=f'ProgramFiles/Icons/warning.png')")
        exec(f"Msg = tkinter.Label(MsgBox, text=str(msg), background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, image=errorICON, compound=tkinter.LEFT)")
        exec(f"MsgBox.IMGREF = errorICON")
        exec(f"Msg.pack(side='left')")
        exec(f'Btn = tkinter.Button(MsgBox, text="Ok", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnOk)')
        exec(f"Btn.pack(side='right', anchor='s')")
        MsgBox.mainloop()
    def askyesorno(header, msg, root,):
        def returnOk(): 
            MsgBox.destroy()
            return 1
        def returnFalse(): 
            MsgBox.destroy()
            return 0
        if root == None:
            root = tkinter.Toplevel(background=THEME_WINDOW_BG)
            root.title("DEBUG WINDOW")
        MsgBox = tkinter.Toplevel(root, background=THEME_WINDOW_BG)
        MsgBox.configure(background=THEME_WINDOW_BG)
        MsgBox.title(header)
        exec(f"errorICON = tkinter.PhotoImage(file=f'ProgramFiles/Icons/question.png')")
        exec(f"Msg = tkinter.Label(MsgBox, text=str(msg), background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, image=errorICON, compound=tkinter.LEFT)")
        exec(f"MsgBox.IMGREF = errorICON")
        exec(f"Msg.pack(side='left')")
        exec(f'Btn = tkinter.Button(MsgBox, text="Yes", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnOk)')
        exec(f"Btn.pack(side='right', anchor='s')")
        exec(f'Btn = tkinter.Button(MsgBox, text="No", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnFalse)')
        exec(f"Btn.pack(side='right', anchor='s')")
        MsgBox.mainloop()
    def askyesnocancel(header, msg, root=None,):
        def returnOk(): 
            global returner_ASKYESNOCANCEL
            MsgBox.destroy()
            if ROOT_WINDOW_NOT_PROVIDED: root.destroy(); returner_ASKYESNOCANCEL = True
        def returnFalse():
            global returner_ASKYESNOCANCEL 
            MsgBox.destroy()
            if ROOT_WINDOW_NOT_PROVIDED: root.destroy(); returner_ASKYESNOCANCEL =  False
        def returnNothing(): 
            global returner_ASKYESNOCANCEL
            MsgBox.destroy()
            if ROOT_WINDOW_NOT_PROVIDED: root.destroy(); returner_ASKYESNOCANCEL =  None
        ROOT_WINDOW_NOT_PROVIDED = False
        if root == None:
            ROOT_WINDOW_NOT_PROVIDED = True
            root = tkinter.Toplevel(background=THEME_WINDOW_BG)
            root.title("DEBUG WINDOW, Close this windnow")
        print("starting")
        MsgBox = tkinter.Toplevel(root, background=THEME_WINDOW_BG)
        print("made toplevel")
        MsgBox.configure(background=THEME_WINDOW_BG)
        MsgBox.title(header)
        print("configured window")
        exec(f"errorICON = tkinter.PhotoImage(file=f'ProgramFiles/Icons/question.png')")
        print("initialized icon")
        exec(f"Msg = tkinter.Label(MsgBox, text=str(msg), background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, image=errorICON, compound=tkinter.LEFT)")
        exec(f"MsgBox.IMGREF = errorICON")
        print('finished label')
        exec(f"Msg.pack(side='left')")
        exec(f'Btn = tkinter.Button(MsgBox, text="Yes", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnOk)')
        exec(f"Btn.pack(side='right', anchor='s')")
        exec(f'NOBtn = tkinter.Button(MsgBox, text="No", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnFalse)')
        exec(f"NOBtn.pack(side='right', anchor='s')")
        exec(f'CANCELBtn = tkinter.Button(MsgBox, text="Cancel", background=THEME_WINDOW_BG, foreground=THEME_FOREGROUND, command=returnNothing)')
        exec(f"CANCELBtn.pack(side='right', anchor='s')")
