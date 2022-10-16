#Our approach is just to find that element which we have to replace and add other element at it's place
def replace(str,char1,char2):
    newstr = ""                     #creating an empty string
    for char in str:                #iterate over given string
        if(char == char1):          #if we get "k" in given string we replace it with "p" by adding 'p' in new string at it's position
            newstr += char2         
        else:                       #else we just add that element in new string
            newstr += char
    return newstr

#main   
#we are replacing "k" with "p" in given string 
str = "ksbckssrleafaf"              
str = replace(str,'k','P')
print(str)