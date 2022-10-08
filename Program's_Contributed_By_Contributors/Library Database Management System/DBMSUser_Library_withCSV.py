1#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Aug 16 14:34:10 2020

@author: kandarpsolanki
"""

from DBMSlibrary_CSV import addrec,searchrec,delrec,delparrec,updaterec,allrecs
print()
print()
def use():
    print('                           +-------WELCOME TO LIBRARY MANAGEMENT SYSTEM-------+')
    print('                           |                                                  |')
    print('                           +--------------------------------------------------+')
    print('                           |             PRESS 0 TO VIEW ALL RECORDS          |',\
          '\n                           +--------------------------------------------------+',\
          '\n                           |             PRESS 1 TO ADD NEW RECORD            |',\
          '\n                           +--------------------------------------------------+',\
          '\n                           |             PRESS 2 TO SEARCH A RECORD           |',\
          '\n                           +--------------------------------------------------+',\
          '\n                           |             PRESS 3 TO UPDATE A RECORD           |',\
          '\n                           +--------------------------------------------------+',\
          '\n                           |        PRESS 4 TO DELETE PARTICULAR RECORD       |')
    print('                           +--------------------------------------------------+')
    print('                           |           PRESS 5 TO DELETE ALL RECORDS          |')
    print('                           +--------------------------------------------------+')
    print()

    user=input('                                          ENTER YOUR CHOICE: ')
    if user=='0':
        allrecs()
    elif user=='1':
        addrec()
    elif user=='2':
        searchrec()
    elif user=='3':
        updaterec()
    elif user=='4':
        delparrec()
    elif user=='5':
        delrec()
user_input='Y'
while user_input.upper()=='Y':
    use()
    user_input=input('Want to work more(Y/N)? ')
print('Thank you for using the software.')
                    
                         