import tkinter
from ProgramFiles.errorHandler import messagebox
def main(username, notifications):
    try:
        global root
        import ProgramFiles.Notepad_v3.notepadGUI as notepad
        PROCESS_RUNNING = True
        root = tkinter.Tk()
        root.title("Notepad GUI v3.0 STABLE")
        text = tkinter.Text(root, height=20, width=100,
                            font=("Arial Rounded MT Bold",
                                18), )
        text.grid(row=0, column=0, pady=10)
        saveTo = tkinter.Text(root, height=2, width=50,
                            font=("Arial Rounded MT Bold",
                                    12))
        saveTo.grid(row=1, column=0)
        notepad.NotepadRun(text_box=text, gui=root, saveTo=saveTo)
        PROCESS_RUNNING = False
    except Exception as exp:
        messagebox.showerror("Can't load app!", f"App not found! please re-install the app!\nPROB:{exp}", root=None)