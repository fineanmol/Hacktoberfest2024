This is a notepad project created with code from-
stackoverflow,
thepythoncodes.com,
geeksforgeeks.org,
and official python tkinter documentation

[PLEASE READ IT TILL THE END, FOR THE DOCUMENTATION!]

this program mainly uses tkinter and it's modules, and no modules imported
in this program require an external installation.
inside the file, 'notepadGUI.py', you will find a class called 'NotepadRun',
it was originally a normal program with function, but for better editing of
methods, i converted it to a class.

this class is dependent on outside frames, for example, the mainframe
tkinter window when it starts, and the text widgets, are created outside
the class, and needed to be provided as a parameter to NotepadRun.__init__
method.

This program is totally open source, anyone can edit it, and use it for 
their purpose, just add that credit when doing so in the top of the program,
where I included a triple-quoted line for this.

There is another file, called 'syntax_checker.py' , which is important when
accessing the 'NotepadRun.programmerMode' method.
As the name of the object describes, it not essentially acts as a basic IDE,
providing help with the automatic quotation and bracket closing, and a basic,
keyword highlighter, which highlights the function and keywords so on and so
forth.
There is also another purpose for this, that is doing the highlighting for
the spellchecking, how it gets the dictionary to check with, is documented
below.

There is one text file, named as 'spellcheck.txt', which has over 450000+
words, which is used as a spell checker.
it is basically Microsoft Word's typo functionality.

You can edit the class by overriding methods, but be careful since these
methods are interlinked like crazy, and you might break stuff while doing so.
so beware when editing the class or overriding in your program.

DOCUMENTATION:
First, make sure you have setuptools upgraded (to check that, type the command- 
"pip install --upgrade setuptools")

Now, after that, install the wheel. NOTE: DON'T EDIT THE FILENAME OF THE WHL FILE!

After that, now use the library. you do this if you want to use it
to do the import, type in "import NotepadGUI.notepadGUI as notepad".
now paste in this code to generate the base for this class that will lateron use this.
of course, you can edit this to your liking, perhaps change the font and size? maybe bold? italics? name it.
"
def main():
    """ main """
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


if __name__ == "__main__":
    main()
"

Now this program should run. 
You can, as mentioned, email me for reporting bugs and features. 
And I also will update in the drive folder, so you always test the newest version!


That's basically it!
Have a great day :D
-A normal high school student
