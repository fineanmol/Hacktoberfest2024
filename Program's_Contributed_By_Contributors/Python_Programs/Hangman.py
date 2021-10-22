
# Classic Game of Hangman
# Created by Santosh Vasisht

import random

# Initialization
fruit_list = [
    'apple',
    'banana',
    'orange',
    'mango',
    'strawberry',
    'watermelon',
    'kiwi',
    'peach',
    'pear',
    'papaya',
    'grapes',
    'pineapple',
    'guava',
    'blueberry',
    'blackberry',
    'raspberry',
    'apricot']

choice = 'Y'

# Game Start
while choice == 'Y':
    #Setup
    fruit = random.choice(fruit_list)
    lives = 5
    temp = []
    word = []

    for i in fruit:
        word.append(i)
        temp.append('_')
    
    print("\n\tHANGMAN!")
    
    #Gameplay
    while '_' in temp and lives!=0:
        print() #newline
        for i in temp:
            print(i, end = ' ')
        print("\t Lives:", lives, '\n')
        l = input("Guess a letter: ").lower()

        if l in word:
            for i in range(0,len(word)):
                if word[i] == l:
                    temp[i] = l
        else:
            lives -= 1
    
    # Game End
    if lives == 0:
        print("\nGAME OVER!")
    else:
        print("\nYOU WIN!!!")
    print("The word was", fruit.upper())

    choice = input("\nPlay Again?(y/n) ").upper()