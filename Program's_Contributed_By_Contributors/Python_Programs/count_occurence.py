# Write a function which takes a string as input and prints total occurrences of each character.

def charOccur(s):
  occurence = {}
   
  for i in s:
    if i in occurence:
      occurence[i]=occurence[i]+1
    else:
      occurence[i]=1
       
  return occurence
   
string1 = input('Enter a string:- ')
print(charOccur(string1))
