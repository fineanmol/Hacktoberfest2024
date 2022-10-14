from tkinter import *
from tkinter import messagebox
from tkinter import ttk
from tkinter import filedialog
from tkinter.font import BOLD
import webbrowser
import os
import re
from os import startfile

DB_TEXT_FILE = 'dbfile.txt'
# Film Name, Director, Genre, Year, Main Actor, IMDB, Duraion, Trailer Link, File Location, Watched status
GENRES = [
    "",
    "Action",
    "Horror",
    "Thriller",
    "sci-fi",
    "Adventure",
    "War",
    "Drama",
    "Comedy",
    "Animated",
    "Romance",
    "Fantasy"
]


class Application():
    def __init__(self, master=None):
        try:
            file = open(DB_TEXT_FILE, 'a')
        finally:
            file.close()
        pass


# region MessageBoxes methods to show common messages
def error_msg(msg):
    messagebox.showerror('Error', msg)


def info_msg(msg):
    messagebox.showinfo('Information', msg)


# endregion


# File open dialog method
def select_file():
    filetypes = (
        ('All files', '*.*'),
        ('Video files', '*.mp4')
    )

    # after selecting this will get the file path
    filepath = filedialog.askopenfilename(
        title='Open a file',
        initialdir='/',
        filetypes=filetypes)

    entry_fileLocation.delete(0, END)  # first delete existing entry value
    entry_fileLocation.insert(0, filepath)


# -------------------------------------- Save Film Details Methods -----------------------------
filmSaveEntryList = []


# Validate name,year,imdb before save film details
def validate_filmDetails():
    validity = False

    name = entry_filmName.get()
    if name != "":
        validity = True
    else:
        validity = False
        error_msg('Film Name should not be empty, Please enter film name')  # if film name is empty display msg
        return validity

    try:
        year = int(entry_year.get())
        if year > 1900 and year < 3000:
            validity = True
        else:
            validity = False
            error_msg('Please enter valid year between 1900 - 3000')
            return validity
    except ValueError:
        validity = False
        error_msg('Please enter valid year')
        return validity

    try:
        imdb = float(entry_imdbVal.get())
        if imdb > 0 and imdb < 10:
            validity = True
        else:
            validity = False
            error_msg('Please enter valid imdb rating value between 0.0 - 9.9')
            return validity
    except ValueError:
        validity = False
        error_msg('Please enter valid imdb rating value')
        return validity

    try:
        duration = int(entry_duration.get())
        validity = True
    except ValueError:
        validity = False
        error_msg('Please enter valid film duration value')
        return validity

    return validity


# Save Film details
def click_saveFilmDetails():
    # Inside This method we need to save all the details to text file
    if validate_filmDetails():
        data_str = ''
        try:
            file = open(DB_TEXT_FILE, 'a')

            # Create comma seperated string using all entry fields
            for item in filmSaveEntryList:
                data_str += item.get() + ','

            # data_str = data_str.rstrip(',') # remove last ',' (we not need that)
            file.write(data_str + '\n')
            info_msg("Details Saved!")
        except:
            error_msg("Something went wrong !")
        finally:
            file.close()  # finally close the opened file
            clear_FilmDetailsEntry()  # clear entry after save


# Clear all entry in film detail screen
def clear_FilmDetailsEntry():
    entry_filmName.delete(0, END)
    entry_director.delete(0, END)
    genre_variable.set(GENRES[0])
    entry_year.delete(0, END)
    entry_mainCharacter.delete(0, END)
    entry_imdbVal.delete(0, END)
    entry_duration.delete(0, END)
    entry_trailerUrl.delete(0, END)
    entry_fileLocation.delete(0, END)


# ----------------------------------------------------------------------------------------------


# Check film year is betweeen search box entry
def isBetweenYears(startYear, endYear, filmYear):
    if startYear == '' and endYear == '':
        return False
    elif startYear != '' and endYear == '':
        if int(filmYear) >= int(startYear):
            return True
    elif startYear == '' and endYear != '':
        if int(filmYear) <= int(endYear):
            return True
    elif startYear != '' and endYear != '':
        if int(filmYear) >= int(startYear) and int(filmYear) <= int(endYear):
            return True

    return False


# Load search result to listbox when search button clicked
results = []
selectedFilm_Name = ''
selectedFilm_TrailerUrl = ''
selectedFilm_location = ''


def click_searchFilmDetails():
    results.clear()
    name = entry_searchFilmName.get()
    director = entry_searchDirector.get()
    genre = entry_searchGenre.get()
    imdb = entry_searchImdb.get()
    duration = entry_searchDuration.get()
    yearStart = entry_searchYearStart.get()
    yearEnd = entry_searchYearEnd.get()
    mainCharacter = entry_searchMainCh.get()

    # Notice, that we didn’t have to write “file.close()”. That will automatically be called.
    with open(DB_TEXT_FILE, "r") as filestream:
        for line in filestream:
            currentline = line.split(",")

            # line = A,B,C,D,4,f,
            # currentline = [A, B, C, D, 4, f]
            # currentline[2] -> C

            if intVar_searchFilmName.get() and currentline[0] == name:
                results.append(currentline)
                continue
            elif intVar_searchDirector.get() and currentline[1] == director:
                results.append(currentline)
                continue
            elif intVar_searchGenre.get() and currentline[2] == genre:
                results.append(currentline)
                continue
            elif intVar_searchYear.get() and isBetweenYears(yearStart, yearEnd, currentline[3]):
                results.append(currentline)
                continue
            elif intVar_searchMainCh.get() and currentline[4] == mainCharacter:
                results.append(currentline)
                continue
            elif intVar_searchImdb.get() and float(currentline[5]) > float(imdb):
                results.append(currentline)
                continue
            elif intVar_searchDuration.get() and float(currentline[6]) < float(duration):
                results.append(currentline)
                continue

    lstbx_searchResult.delete(0, END)  # clear list box
    for values in results:
        lstbx_searchResult.insert(END, values[0] + ' - (' + str(values[3]) + ')')


# Load more details when click in list box item
def search_ListBoxSelect(event):
    selection = event.widget.curselection()
    global selectedFilm_TrailerUrl
    global selectedFilm_location
    global selectedFilm_Name

    if selection:
        index = selection[0]
        data = event.widget.get(index)

        for i in range(len(results)):
            if results[i][0] + ' - (' + str(results[i][3]) + ')' == data:
                selectedFilm_Name = results[i][0]
                lbl_moreName['text'] = 'Name : ' + results[i][0]
                lbl_moreDirector['text'] = 'Director : ' + results[i][1]
                lbl_moreGenre['text'] = 'Genre : ' + results[i][2]
                lbl_moreActor['text'] = 'Main Actor : ' + results[i][4]
                lbl_moreImdbVal['text'] = 'IMDB Rating : ' + results[i][5]
                lbl_moreDuration['text'] = 'Duration (min) : ' + results[i][6]

                selectedFilm_TrailerUrl = str(results[i][7])
                if selectedFilm_TrailerUrl == '':
                    lbl_moreTrailerLink['text'] = 'Trailer not available'
                else:
                    lbl_moreTrailerLink['text'] = 'Click Here to watch Trailer'

                selectedFilm_location = str(results[i][8])
                if selectedFilm_location == '':
                    btn_moreWatchTheFilm['state'] = 'disabled'
                else:
                    btn_moreWatchTheFilm['state'] = 'normal'

                # populate watched check box
                chk_moreWatched.deselect()
                if len(results[i]) > 10 and int(results[i][9]):
                    chk_moreWatched.select()


# Open url when click the link
def open_Url():
    if selectedFilm_TrailerUrl != '':
        webbrowser.open_new(selectedFilm_TrailerUrl)


# reguler expresstion for check path is url
regex = re.compile(
    r'^(?:http|ftp)s?://'  # http:// or https://
    r'(?:(?:[A-Z0-9](?:[A-Z0-9-]{0,61}[A-Z0-9])?\.)+(?:[A-Z]{2,6}\.?|[A-Z0-9-]{2,}\.?)|'  # domain...
    r'localhost|'  # localhost...
    r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})'  # ...or ip
    r'(?::\d+)?'  # optional port
    r'(?:/?|[/?]\S+)$', re.IGNORECASE)


# open video
def open_Video():
    if selectedFilm_location != '':

        if os.path.isfile(selectedFilm_location.strip()):
            path = selectedFilm_location.replace('\\', '\\\\')  # make \ as /
            startfile(path.strip())  # remove newwline charactr of end

        elif re.match(regex, selectedFilm_location):
            webbrowser.open_new(selectedFilm_location)


# _________________ Edit Film data ______________________
def filmWatched_editdetails(filmName, val):
    with open(DB_TEXT_FILE, "r") as rfilestream:
        lines_list = rfilestream.readlines()
        for i in range(len(lines_list)):
            currentline = lines_list[i].split(",")
            if currentline[0] == filmName and len(currentline) == 10:
                lines_list[i] = lines_list[i].strip() + str(val) + ',\n'
            elif currentline[0] == filmName and len(currentline) == 11:
                lines_list[i] = lines_list[i].strip()[:-2] + str(val) + ',\n'

        new_file_contents = "".join(lines_list)

    with open(DB_TEXT_FILE, "w") as wfilestream:
        wfilestream.write(new_file_contents)


def filmWatched_Change():
    if selectedFilm_Name != '':
        if intVar_searchWatched.get():
            filmWatched_editdetails(selectedFilm_Name, 1)
        else:
            filmWatched_editdetails(selectedFilm_Name, 0)


# ___________________ Save Editede film details __________

# File open dialog method
def select_fileEditFrame():
    filetypes = (
        ('All files', '*.*'),
        ('Video files', '*.mp4')
    )

    # after selecting this will get the file path
    filepath = filedialog.askopenfilename(
        title='Open a file',
        initialdir='/',
        filetypes=filetypes)

    entry_EditfileLocation.delete(0, END)  # first delete existing entry value
    entry_EditfileLocation.insert(0, filepath)


def click_filmEditSearchBtn():
    entry_Editdirector.delete(0, END)
    genre_EditVariable.set(GENRES[0])
    entry_Edityear.delete(0, END)
    entry_EditmainCharacter.delete(0, END)
    entry_EditimdbVal.delete(0, END)
    entry_Editduration.delete(0, END)
    entry_EdittrailerUrl.delete(0, END)
    entry_EditfileLocation.delete(0, END)

    # load existing film data to UI entry widgits
    searchName = entry_EditfilmName.get()

    if searchName != '':
        with open(DB_TEXT_FILE, "r") as filestream:
            for line in filestream:
                currentline = line.split(",")

                if currentline[0] == searchName:
                    entry_Editdirector.delete(0, END)
                    entry_Editdirector.insert(0, currentline[1])

                    # Getting index of a eliment in list   ["foo", "bar", "baz"].index("bar")  == 1
                    genre_EditVariable.set(GENRES[GENRES.index(currentline[2])])

                    entry_Edityear.delete(0, END)
                    entry_Edityear.insert(0, currentline[3])

                    entry_EditmainCharacter.delete(0, END)
                    entry_EditmainCharacter.insert(0, currentline[4])

                    entry_EditimdbVal.delete(0, END)
                    entry_EditimdbVal.insert(0, currentline[5])

                    entry_Editduration.delete(0, END)
                    entry_Editduration.insert(0, currentline[6])

                    entry_EdittrailerUrl.delete(0, END)
                    entry_EdittrailerUrl.insert(0, currentline[7])

                    entry_EditfileLocation.delete(0, END)
                    entry_EditfileLocation.insert(0, currentline[8])

                    break


# Validate name,year,imdb before save edit film details
def validate_EditFilmDetails():
    validity = False

    name = entry_EditfilmName.get()
    if name != "":
        validity = True
    else:
        validity = False
        error_msg('Film Name should not be empty, Please enter film name')
        return validity

    try:
        year = int(entry_Edityear.get())
        if year > 1900 and year < 3000:
            validity = True
        else:
            validity = False
            error_msg('Please enter valid year between 1900 - 3000')
            return validity
    except ValueError:
        validity = False
        error_msg('Please enter valid year')
        return validity

    try:
        imdb = float(entry_EditimdbVal.get())
        if imdb > 0 and imdb < 10:
            validity = True
        else:
            validity = False
            error_msg('Please enter valid imdb rating value between 0.0 - 9.9')
            return validity
    except ValueError:
        validity = False
        error_msg('Please enter valid imdb rating value')
        return validity

    try:
        duration = int(entry_Editduration.get())
        validity = True
    except ValueError:
        validity = False
        error_msg('Please enter valid film duration value')
        return validity

    return validity


def save_EditedFilm():
    if validate_EditFilmDetails():
        filmName = entry_EditfilmName.get()

        edited_line = filmName + ',' + entry_Editdirector.get() + ',' + genre_EditVariable.get() + ',' + entry_Edityear.get() + ','
        edited_line += entry_EditmainCharacter.get() + ',' + entry_EditimdbVal.get() + ',' + entry_Editduration.get() + ','
        edited_line += entry_EdittrailerUrl.get() + ',' + entry_EditfileLocation.get()

        with open(DB_TEXT_FILE, "r") as rfilestream:
            lines_list = rfilestream.readlines()
            for i in range(len(lines_list)):
                currentline = lines_list[i].split(",")
                if currentline[0] == filmName:
                    lines_list[i] = edited_line + ',\n'

            new_file_contents = "".join(lines_list)

        with open(DB_TEXT_FILE, "w") as wfilestream:
            wfilestream.write(new_file_contents)
            info_msg("Film details updated !")

        entry_EditfilmName.delete(0, END)
        entry_Editdirector.delete(0, END)
        genre_EditVariable.set(GENRES[0])
        entry_Edityear.delete(0, END)
        entry_EditmainCharacter.delete(0, END)
        entry_EditimdbVal.delete(0, END)
        entry_Editduration.delete(0, END)
        entry_EdittrailerUrl.delete(0, END)
        entry_EditfileLocation.delete(0, END)


# -------------------------------------------- UI widgits ----------------------------------------
# -------------------------------------------------------------------------------------------------

root = Tk()
app = Application(master=root)
root.title('Customized Movie Recommendation System')
root.geometry('700x500')
root.resizable(width=False, height=False)  # make as can't resizable

# region Add Film Details Frame
frm_addFilms = Frame(master=root, width=700, height=500)
msg_addFilms = Label(frm_addFilms, text='Add Film Details', font=('Arial', 12))
msg_addFilms.grid(row=0, column=0, pady=10)

# ----------- create widgits ----------------

genre_variable = StringVar(frm_addFilms)
genre_variable.set(GENRES[0])  # default value
entry_genre = ttk.Combobox(frm_addFilms, textvariable=genre_variable, values=GENRES, state='readonly')
entry_genre.config(width=37)

lbl_filmName = Label(frm_addFilms, text='Film Name :')
lbl_director = Label(frm_addFilms, text='Director :')
lbl_genre = Label(frm_addFilms, text='Genre :')
lbl_year = Label(frm_addFilms, text='Year :')
lbl_mainCharacter = Label(frm_addFilms, text='Main Actor :')
lbl_imdbVal = Label(frm_addFilms, text='IMDB Rating:')
lbl_duration = Label(frm_addFilms, text='Duration (min) :')
lbl_trailerUrl = Label(frm_addFilms, text='Trailer Link:')
lbl_fileLocation = Label(frm_addFilms, text='File Location / Url :')

entry_filmName = Entry(frm_addFilms, width=40)
entry_director = Entry(frm_addFilms, width=40)
entry_year = Entry(frm_addFilms, width=40)
entry_mainCharacter = Entry(frm_addFilms, width=40)
entry_imdbVal = Entry(frm_addFilms, width=40)
entry_duration = Entry(frm_addFilms, width=40)
entry_trailerUrl = Entry(frm_addFilms, width=40)
entry_fileLocation = Entry(frm_addFilms, width=40)

btn_selectFileLocation = Button(frm_addFilms, text="Select file", width=7, command=select_file)
btn_saveFilmDetails = Button(frm_addFilms, text="SAVE", width=20, bg='pale green', command=click_saveFilmDetails)

# --------- Add entry widgits to a list ---------
filmSaveEntryList.append(entry_filmName)
filmSaveEntryList.append(entry_director)
filmSaveEntryList.append(genre_variable)
filmSaveEntryList.append(entry_year)
filmSaveEntryList.append(entry_mainCharacter)
filmSaveEntryList.append(entry_imdbVal)
filmSaveEntryList.append(entry_duration)
filmSaveEntryList.append(entry_trailerUrl)
filmSaveEntryList.append(entry_fileLocation)

# ----------- Put created widgits in UI locations using grid() ----------
# think this is as table column and row and we can place our created labels
# textbox entry, buttons to those columns and rows
lbl_filmName.grid(row=1, column=0, sticky=W, pady=5)
entry_filmName.grid(row=1, column=1)

lbl_director.grid(row=2, column=0, sticky=W, pady=5)
entry_director.grid(row=2, column=1)

lbl_genre.grid(row=3, column=0, sticky=W, pady=5)
entry_genre.grid(row=3, column=1)

lbl_year.grid(row=4, column=0, sticky=W, pady=5)
entry_year.grid(row=4, column=1)

lbl_mainCharacter.grid(row=5, column=0, sticky=W, pady=5)
entry_mainCharacter.grid(row=5, column=1)

lbl_imdbVal.grid(row=6, column=0, sticky=W, pady=5)
entry_imdbVal.grid(row=6, column=1)

lbl_duration.grid(row=7, column=0, sticky=W, pady=5)
entry_duration.grid(row=7, column=1)

lbl_trailerUrl.grid(row=8, column=0, sticky=W, pady=5)
entry_trailerUrl.grid(row=8, column=1)

lbl_fileLocation.grid(row=9, column=0, sticky=W, pady=2)
entry_fileLocation.grid(row=9, column=1, sticky=W)
btn_selectFileLocation.grid(row=9, column=2, sticky=E)

btn_saveFilmDetails.grid(row=10, column=1, pady=20)
# btn_saveFilmDetails.bind("<Button-1>", click_saveFilmDetails)

# endregion


# region Search Film Details Frame
frm_details = Frame(master=root, width=700, height=500)
frm_details.pack()
msg_filmDetails = Label(frm_details, text='Film Details', font=('Arial', 12))
msg_filmDetails.grid(row=0, column=0, pady=10)

# ----------- create widgits ----------------
lbl_searchFilmName = Label(frm_details, text='Film Name :')
lbl_searchDirector = Label(frm_details, text='Director :')
lbl_searchGenre = Label(frm_details, text='Genre :')
lbl_searchImdbVal = Label(frm_details, text='IMDB   > ')
lbl_searchDuration = Label(frm_details, text='Duration <')
lbl_searchYear = Label(frm_details, text='Year Between')
lbl_searchMainCh = Label(frm_details, text='Main Actor :')
lbl_searchResult = Label(frm_details, text='Results')

lbl_searchAND1 = Label(frm_details, text='')
lbl_searchAND2 = Label(frm_details, text='')
lbl_searchAND3 = Label(frm_details, text=' ')
lbl_searchTo = Label(frm_details, text='to')

intVar_searchFilmName = IntVar()
chk_searchFilmName = Checkbutton(frm_details, variable=intVar_searchFilmName)
intVar_searchDirector = IntVar()
chk_searchDirector = Checkbutton(frm_details, variable=intVar_searchDirector)
intVar_searchGenre = IntVar()
chk_searchGenre = Checkbutton(frm_details, variable=intVar_searchGenre)
intVar_searchImdb = IntVar()
chk_searchImdb = Checkbutton(frm_details, variable=intVar_searchImdb)
intVar_searchDuration = IntVar()
chk_searchDuration = Checkbutton(frm_details, variable=intVar_searchDuration)
intVar_searchYear = IntVar()
chk_searchYear = Checkbutton(frm_details, variable=intVar_searchYear)
intVar_searchMainCh = IntVar()
chk_searchMainCh = Checkbutton(frm_details, variable=intVar_searchMainCh)

entry_searchFilmName = Entry(frm_details, width=25)
entry_searchDirector = Entry(frm_details, width=25)
entry_searchImdb = Entry(frm_details, width=25)
entry_searchDuration = Entry(frm_details, width=25)
entry_searchYearStart = Entry(frm_details, width=10)
entry_searchYearEnd = Entry(frm_details, width=10)
entry_searchMainCh = Entry(frm_details, width=25)

genre_searchVariable = StringVar(frm_details)
genre_searchVariable.set(GENRES[0])  # default value
entry_searchGenre = ttk.Combobox(frm_details, textvariable=genre_searchVariable, values=GENRES, state='readonly')
entry_searchGenre.config(width=22)

btn_searchFilmDetails = Button(frm_details, text="SEARCH", width=35, bg='pale green', command=click_searchFilmDetails)

lstbx_searchResult = Listbox(frm_details, relief=SUNKEN, border=2, width=30, height=14)
lstbx_searchResult.bind("<<ListboxSelect>>", search_ListBoxSelect)
scrollbar_searchResult = Scrollbar(frm_details)  # Creating a Scrollbar

# ++++++++++++++++++++++++++ More Detail Frame +++++++++++++++++++++++
labelfrm_moreDetails = LabelFrame(frm_details, text="More Details", font=('Arial', 10, UNDERLINE))

lbl_moreName = Label(labelfrm_moreDetails, text="Name : ", anchor=W)
lbl_moreDirector = Label(labelfrm_moreDetails, text="Director : ", anchor=W)
lbl_moreGenre = Label(labelfrm_moreDetails, text="Genre : ", anchor=W)
lbl_moreActor = Label(labelfrm_moreDetails, text="Main Actor : ", anchor=W)
lbl_moreImdbVal = Label(labelfrm_moreDetails, text="IMDB Rating : ", anchor=W)
lbl_moreDuration = Label(labelfrm_moreDetails, text="Duration (min) : ", anchor=W)
lbl_moreTrailerLink = Label(labelfrm_moreDetails, text="Click Here to watch Trailer", fg="blue", cursor="hand2",
                            anchor=W)
lbl_moreTrailerLink.bind("<Button-1>", lambda e: open_Url())

intVar_searchWatched = IntVar()
chk_moreWatched = Checkbutton(labelfrm_moreDetails, anchor=W, text="This Film Watched", pady=10,
                              variable=intVar_searchWatched, command=filmWatched_Change)
btn_moreWatchTheFilm = Button(labelfrm_moreDetails, text="WATCH THIS NOW", width=20, bg='pale green',
                              command=open_Video)

lbl_moreName.pack(fill='both')
lbl_moreDirector.pack(fill='both')
lbl_moreGenre.pack(fill='both')
lbl_moreActor.pack(fill='both')
lbl_moreImdbVal.pack(fill='both')
lbl_moreDuration.pack(fill='both')
lbl_moreTrailerLink.pack(fill='both')

chk_moreWatched.pack()
btn_moreWatchTheFilm.pack()

# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


# row 1
lbl_searchFilmName.grid(row=1, column=0, sticky=W, pady=5)
entry_searchFilmName.grid(row=1, column=1)
chk_searchFilmName.grid(row=1, column=2, padx=5)
lbl_searchAND1.grid(row=1, column=3, padx=5)

lbl_searchDirector.grid(row=1, column=4, sticky=W, padx=20)
entry_searchDirector.grid(row=1, column=5)
chk_searchDirector.grid(row=1, column=6, padx=5)

# row 2
lbl_searchGenre.grid(row=2, column=0, sticky=W, pady=5)
entry_searchGenre.grid(row=2, column=1)
chk_searchGenre.grid(row=2, column=2, padx=5)
lbl_searchAND2.grid(row=2, column=3, padx=5)

lbl_searchImdbVal.grid(row=2, column=4, sticky=W, padx=20)
entry_searchImdb.grid(row=2, column=5)
chk_searchImdb.grid(row=2, column=6, padx=5)

# row 3
lbl_searchDuration.grid(row=3, column=0, sticky=W, pady=5)
entry_searchDuration.grid(row=3, column=1)
chk_searchDuration.grid(row=3, column=2, padx=5)
lbl_searchAND3.grid(row=3, column=3, padx=5)

lbl_searchYear.grid(row=3, column=4, sticky=W, padx=20)
entry_searchYearStart.grid(row=3, column=5, sticky=W)
lbl_searchTo.grid(row=3, column=5)
entry_searchYearEnd.grid(row=3, column=5, sticky=E)
chk_searchYear.grid(row=3, column=6, padx=5)

# row 4
lbl_searchMainCh.grid(row=4, column=0, sticky=W, pady=5)
entry_searchMainCh.grid(row=4, column=1)
chk_searchMainCh.grid(row=4, column=2, padx=5)
btn_searchFilmDetails.grid(row=4, column=3, sticky=W + E, columnspan=4)

# search result
lbl_searchResult.grid(row=6, column=0, sticky=NW, pady=50)
lstbx_searchResult.grid(row=6, column=1, sticky=W, pady=50)
scrollbar_searchResult.grid(row=6, column=2, sticky=NS, pady=50)
# Attaching Listbox to Scrollbar
# Since we need to have a vertical
# scroll we use yscrollcommand

lstbx_searchResult.config(yscrollcommand=scrollbar_searchResult.set)
scrollbar_searchResult.config(command=lstbx_searchResult.yview)

labelfrm_moreDetails.grid(row=6, column=3, columnspan=4, sticky=W + E + N, pady=50)

# endregion


# region Edit Film Details Frame
frm_edit = Frame(master=root, width=700, height=500)
msg_filmEdit = Label(frm_edit, text='Edit Film Details', font=('Arial', 12))
msg_filmEdit.grid(row=0, column=0, pady=10)

# ----------- create widgits ----------------

genre_EditVariable = StringVar(frm_addFilms)
genre_EditVariable.set(GENRES[0])  # default value
entry_EditGenre = ttk.Combobox(frm_edit, textvariable=genre_EditVariable, values=GENRES, state='readonly')
entry_EditGenre.config(width=37)

lbl_EditfilmName = Label(frm_edit, text='Search Film Name :')
lbl_Editdirector = Label(frm_edit, text='Director :')
lbl_Editgenre = Label(frm_edit, text='Genre :')
lbl_Edityear = Label(frm_edit, text='Year :')
lbl_EditmainCharacter = Label(frm_edit, text='Main Actor :')
lbl_EditimdbVal = Label(frm_edit, text='IMDB Rating:')
lbl_Editduration = Label(frm_edit, text='Duration (min) :')
lbl_EdittrailerUrl = Label(frm_edit, text='Trailer Link:')
lbl_EditfileLocation = Label(frm_edit, text='File Location / Url :')

entry_EditfilmName = Entry(frm_edit, width=40)
entry_Editdirector = Entry(frm_edit, width=40)
entry_Edityear = Entry(frm_edit, width=40)
entry_EditmainCharacter = Entry(frm_edit, width=40)
entry_EditimdbVal = Entry(frm_edit, width=40)
entry_Editduration = Entry(frm_edit, width=40)
entry_EdittrailerUrl = Entry(frm_edit, width=40)
entry_EditfileLocation = Entry(frm_edit, width=40)

btn_EditSearchFilmDetails = Button(frm_edit, text="Search", width=7, command=click_filmEditSearchBtn)
btn_EditselectFileLocation = Button(frm_edit, text="Select file", width=7, command=select_fileEditFrame)
btn_EditsaveFilmDetails = Button(frm_edit, text="SAVE", width=20, bg='pale green', command=save_EditedFilm)

lbl_EditfilmName.grid(row=1, column=0, sticky=W, pady=30)
entry_EditfilmName.grid(row=1, column=1)
btn_EditSearchFilmDetails.grid(row=1, column=2)

lbl_Editdirector.grid(row=2, column=0, sticky=W, pady=5)
entry_Editdirector.grid(row=2, column=1)

lbl_Editgenre.grid(row=3, column=0, sticky=W, pady=5)
entry_EditGenre.grid(row=3, column=1)

lbl_Edityear.grid(row=4, column=0, sticky=W, pady=5)
entry_Edityear.grid(row=4, column=1)

lbl_EditmainCharacter.grid(row=5, column=0, sticky=W, pady=5)
entry_EditmainCharacter.grid(row=5, column=1)

lbl_EditimdbVal.grid(row=6, column=0, sticky=W, pady=5)
entry_EditimdbVal.grid(row=6, column=1)

lbl_Editduration.grid(row=7, column=0, sticky=W, pady=5)
entry_Editduration.grid(row=7, column=1)

lbl_EdittrailerUrl.grid(row=8, column=0, sticky=W, pady=5)
entry_EdittrailerUrl.grid(row=8, column=1)

lbl_EditfileLocation.grid(row=9, column=0, sticky=W, pady=2)
entry_EditfileLocation.grid(row=9, column=1, sticky=W)
btn_EditselectFileLocation.grid(row=9, column=2, sticky=E)

btn_EditsaveFilmDetails.grid(row=10, column=1, pady=20)

# endregion


# region About Frame
frm_about = Frame(master=root, width=700, height=500)
msg_about = Label(frm_about, text='Customized Movie Recommendation App V 1.0.0')
msg_about.grid(row=0, column=0, pady=10)


# endregion


def show_about_frame():
    frm_addFilms.pack_forget()
    frm_details.pack_forget()
    frm_edit.pack_forget()
    frm_about.pack()


def show_addFilm_frame():
    frm_about.pack_forget()
    frm_details.pack_forget()
    frm_edit.pack_forget()
    frm_addFilms.pack()


def show_editFilm_frame():
    frm_about.pack_forget()
    frm_addFilms.pack_forget()
    frm_details.pack_forget()
    frm_edit.pack()


def show_detail_frame():
    frm_about.pack_forget()
    frm_addFilms.pack_forget()
    frm_edit.pack_forget()
    frm_details.pack()


# ----------------- Menu (This is for creating top menu items) --------------
main_menu = Menu(root)
root.config(menu=main_menu)

films_menu = Menu(main_menu, tearoff=0)
main_menu.add_cascade(label='Films', menu=films_menu)
films_menu.add_command(label='Details', command=show_detail_frame)

add_menu = Menu(main_menu, tearoff=0)
main_menu.add_cascade(label='Add', menu=add_menu)
add_menu.add_command(label='Add Films', command=show_addFilm_frame)

edit_menu = Menu(main_menu, tearoff=0)
main_menu.add_cascade(label='Edit', menu=edit_menu)
edit_menu.add_command(label='Edit Films', command=show_editFilm_frame)

help_menu = Menu(main_menu, tearoff=0)
main_menu.add_cascade(label='Help', menu=help_menu)
help_menu.add_command(label='About', command=show_about_frame)
help_menu.add_command(label='Exit', command=root.quit)

# ------------------------------------------------------------------------------------------------
# -------------------------------------------------------------------------------------------------


# this GUI should run in main loop.. To do that
root.mainloop()
