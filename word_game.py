#it uses 

#virtual environment -> to use different versions of the same thing 

#dictionary
#random module
#lists
#if else
#loop
#various data types
#escape sequences


import random

#creating a dictionary
             # key : value -> giraffe : animal -> key can only be one
             #[] -> list
             #sports,basketball = 
word_list = {"sports" : ["cricket","badminton","basketball","footabll"],"fruits":["mango","apple","banana","peach","pear"],"vegetables":["radish","potato","carrot","capsicum"]}



#make a single list of all values 
values = []

for key in word_list:
    for value in word_list[key]: # word_list[sports]
        values.append(value)
      
# values= [cricket, badminton......, mango,radish]
    

chosen_word = random.choice(values)

#find the key for hint
Hint = {i for i in word_list.keys() if chosen_word in word_list[i]}     #list comprehnsion

#word_list[sports]
#[-----]
display = []
lives = 5

#displaying dashes mango -> len= 5 (index is one less)
for letter in range(len(chosen_word)): # start from 0    range(0, len(chosen_word))
    display += '-'
    

#game
Title = "\t\tGuess the word"     #           
print(Title)
print("Hint : {0}".format(Hint))
print(display)
game_over = False    #boolean -> True or False

while not game_over:                               # 0 1 2 3 4
    guessed_letter = input("Guess a letter : ")    # a p p l e
    for position in range(len(chosen_word)): 
        letter = chosen_word[position]
        if letter == guessed_letter:
            display[position] = guessed_letter    # - a - - -
            
    if guessed_letter not in chosen_word:
        lives -=1
        print("You lost one life. Lives remaining: {}".format(lives))
        if lives == 0:
            game_over = True
            print("You lost!!")
            print("Chosen word was : {}".format(chosen_word))
    else:
        print()
        print("\t\t", end= " ")             
        print("lives : {}".format(lives))
        print(display)
    if '-' not in display:
        game_over = True
        print("Wohooo! You guessed right!")
                
                
        

