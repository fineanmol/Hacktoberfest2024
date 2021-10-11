
#Hangman

import random
from word import word
import string

def valid(word):
  w = random.choice(word)
  while '-' in word or ' ' in word:
    w= random.choice(word)

  return w.upper()


def hangman():

  w = valid(word)
  word_letter =  set(w)
  alphabet = set(string.ascii_uppercase)
  used_letter = set() # empty for now

  lives = 6
  while len(word_letter)>0 and lives>0:

    print("you have", lives,"lives left used: "," " .join(used_letter) )

    #list for[w o _ d]
    currentCondition=[letter if letter in used_letter else "_" for letter in w]
    print("current Condition: ", " ".join(currentCondition))

    user_letter = input('guess a letter: ').upper()

    if user_letter in alphabet - used_letter:
      used_letter.add(user_letter)
      
      if user_letter in  word_letter:
        word_letter.remove(user_letter)
      else:
        lives=lives - 1
    elif user_letter in used_letter:
      print("already used, try smthing else")
      lives = lives - 1
    
    else:
      print("invalid character")

  if lives==0:
    print("u died the word was", w)
  else:
    print("yey u guessed",w)



user_input = input('type smthing to start')
print(user_input)

hangman()
