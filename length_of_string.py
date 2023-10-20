#This program takes 2 inputs and whre first input will return the number of charcters in that string
#The second input returns a list of position of the input element of the first input
def length(s,k):
    c=0
    j=0
    l=[]
    for i in s:
        c=c+1
        if i == k:
            l.append(c)
            j=j+1
    if j == 0:
        return c,"The given character is not in the string"
    else:
        return c,l
