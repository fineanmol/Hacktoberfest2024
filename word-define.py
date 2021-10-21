#!/usr/bin/env python

# requests Module for interacting with API

import requests

# sys Module to accept arguments to python script run command
import sys

# pydantic's BaseModel to define a base model for the Word

from pydantic import BaseModel


# New Defined Word

class NewWord(BaseModel):
    word : str = ""
    ascii_art : str = ""
    definition : str = ""

# Procedure to Define a Word

class DefineAWord:

    #/- processing the input variables

    def __init__(self, word, get_ascii_art=False):
        self.word = word
        self.get_ascii_art = get_ascii_art

    #/- looking up the Dictionary API for the word meaning

    def _perform_request(self):
        response = requests.get("https://api.dictionaryapi.dev/api/v2/entries/en/{}".format(self.word)).json()
        return response

    #/- to parse the JSON response to get the word meaning

    def _parse_meaning(self, jsonresponse):

        #/- a blank string to be substituted by the definition

        thedef = ''

        #/- "try"ing to parse the JSON response, if we recieved a valid response

        try:

            #/- parsing every meaning for the word

            for i in (jsonresponse[0]['meanings']):
                for x in (i['definitions']):

                    #/- concatenating to blank string so as to
                    #/- add in customization than just defining
                    #/- the variable as the JSON response's meaning

                    thedef+=(x['definition'])
                    thedef+=('\n')
                thedef+=('\n')

            #/- replacing any multiple carriage returns//newlines to
            #/- make the response look neat when printed

            thedef = thedef.replace('\n\n','\n').replace('\n\n','\n')

            #/- skipping any leading newlines before the
            #/- actual word definition

            if thedef[-1]=='\n':
                thedef=thedef[0:-1]

        #/- "No meaning found" in case no meaning is
        #/- found in the JSON response

        except:
            thedef = 'No meaning found for {} :('.format(self.word)

        #/- setting the definition of the word

        self.definition = thedef

        #/- returning a NewWord object as it is
        #/- more organized and structured

        return NewWord(
                    word=self.word,

                    #/- setting the 'ascii_art' as
                    #/- the word itself in case the
                    #/- flag was not raised.

                    ascii_art=self.word,
                    definition=self.definition
                      )

    def _get_ascii(self, text):

        #/- to convert any text to ASCII art
        #/- in case the ASCII flag is set true

        return requests.get(f"https://artii.herokuapp.com/make?text={text}").text

    def run_scrap(self):

        #/- getting the NewWord object

        newword = self._parse_meaning(self._perform_request())

        if self.get_ascii_art == True:

            #/- adding the ASCII art to the NewWord object
            #/- in case the ASCII flag was set to "True"

            ascii_ver = self._get_ascii(self.word)
            newword = NewWord(
                            word = newword.word,
                            ascii_art = ascii_ver,
                            definition = newword.definition
                             )
        return newword

#/- ensuring the script is not imported

if __name__ == "__main__":

    #/- setting the 'get_ascii' flag to False in case
    #/- the optional flag was not input by the user

    get_ascii = False

    #/- getting the word to define

    argument = (str(list(enumerate(sys.argv))[1][-1]))

    #/- "try"ing to get the 'get_ascii' flag in case the user
    #/- has mentioned it in their inputs

    try:
        if (str(list(enumerate(sys.argv))[2][-1])).lower() == "true":
            get_ascii = True
    except:
        pass

    #/- defining the word

    word = DefineAWord(word=argument,get_ascii_art = get_ascii).run_scrap()

    #/- returning output by printing the word
    #/- to the user.

    #/- the 'word.ascii_art' is also printed without
    #/- paying heed to whether the flag was raised or not,
    #/- because, if the flag was not raised, we have set
    #/- 'word.ascii_art' to the word itself as plain text.

    print(word.ascii_art,f'"{word.word}"',word.definition,sep="\n")

#/- this script can also function as a module 


'''
DOCUMENTATION
Web Scraper to get word definitions from the Dictionary API
## Prerequisites
Modules required to be able to use the script successfully are :
requests==2.26.0
pydantic=1.8.2
## Usage
-> as a script
To get started run :
python main.py word
replacing "word" with the word you wish to define.
This will print out the word and the word meaning. As an additional feature, you can raise
the ASCII Art flag by adding the "true" (case insensitive) argument like so:
python main.py word true
This flag prints an ASCII Art version of the word to be defined.
If you have lolcat installed on your terminal, I suggest piping it through lolcat for aesthetic results.
-> as a module
- Import this file by renaming the file to something else (for example, define.py) so that you can import it using from define import * or rename the folder to something else (for example `define`) so you can import it using from define.main import *
- Use the command DefineAWord(word=your_word,get_ascii_art = get_ascii).run_scrap() where:
| Parameter  | Type    | Description                       |
| :--------  | :-------| :-------------                    |
| yourword   | string  | the word you wish to define       |
| get_ascii  | boolean | if you wish for ascii art as well |
this will return to you a "NewWord" object with methods/attributes :
| Parameter   | Type      | Description                        |
| :--------   | :-------  | :-------------                     |
| word        | string  | the word you wish to define          |
| ascii_art   | string  | a nice looking ASCII art of the word |
| definition  | string  | the definition of the word           |
'''
