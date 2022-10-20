""" properties displayer"""
import os
import time
import tkinter
import tkinter.filedialog as filedialog


def show(filepath):
    """ show the properties of the file"""

    acc_time = tkinter.Label(root,
                             text=f'Access time  : '
                                  f'{time.ctime(os.path.getatime(filepath))}')
    acc_time.grid(row=2, column=0)
    modif_time = tkinter.Label(root,
                               text=f'Modified time: '
                                    f'{time.ctime(os.path.getmtime(filepath))}')
    modif_time.grid(row=3, column=0)
    file_size = tkinter.Label(root,
                              text=f'Size\t\t: '
                                   f'{os.path.getsize(filepath)}b (bytes)')
    file_size.grid(row=4, column=0)
    if os.access("notepadGUI.py", os.F_OK):
        import notepadGUI

        def main():
            """ main """
            with open(filepath, "r") as insert_it:
                text_to_insert = insert_it.read()
            root1 = tkinter.Tk()
            root1.title("Notepad GUI v3.0 STABLE")
            text = tkinter.Text(root1, height=20, width=100,
                                font=("Arial Rounded MT Bold",
                                      18), )
            text.grid(row=0, column=0, pady=10)
            saveTo = tkinter.Text(root1, height=2, width=50,
                                  font=("Arial Rounded MT Bold",
                                        12))
            saveTo.grid(row=1, column=0)
            text.insert(text.index(1.0), text_to_insert)
            saveTo.insert(saveTo.index(1.0), filepath)
            notepadGUI.NotepadRun(text_box=text, gui=root1, saveTo=saveTo,
                                  file_to_open=filepath)

        edit_file = tkinter.Button(root,
                                   text="Edit the file with NotepadGUI!",
                                   command=main)
        edit_file.grid(row=1, column=1, padx=10)


def file_to_inspect():
    """ button command: to create an open-file dialog to show the properties."""
    filepath = filedialog.askopenfilename(
        title="Select the file needed to be inspected.")
    show(filepath=filepath)


root = tkinter.Tk()
tkinter.Label(root,
              text="Inspect files that you want, and edit them too.").grid(
    row=0, column=0)
select_file = tkinter.Button(root, text="Select file", command=file_to_inspect)
select_file.grid(row=1, column=0)
root.mainloop()
