import pandas as pd

punctuation_chars = ["'", '"', ",", ".", "!", ":", ";", '#', '@']
# lists of words to use
positive_words = []
with open("positive_words.txt.txt") as pos_f:
    for lin in pos_f:
        if lin[0] != ';' and lin[0] != '\n':
            positive_words.append(lin.strip())


negative_words = []
with open("negative_words.txt.txt") as pos_f:
    for lin in pos_f:
        if lin[0] != ';' and lin[0] != '\n':
            negative_words.append(lin.strip())


string = ""
def strip_punctuation(string):
    for y in punctuation_chars:
            if y in string:
                string=string.replace(y,"")
    return(string)            

def get_pos(str1):
    l1=[]
    l2=[]
    cnt = 0
    s = str1.lower()
    l1 = s.split(" ")
    for x in l1:
        l2.append(strip_punctuation(x))
    for y in positive_words:
        if y in l2:
            print(y)
            cnt = cnt + 1
    print(cnt)
    return cnt

def get_neg(str1):
    l1=[]
    l2=[]
    cnt = 0
    s = str1.lower()
    l1 = s.split(" ")
    for x in l1:
        l2.append(strip_punctuation(x))
    for y in negative_words:
        if y in l2:
            print(y)
            cnt = cnt + 1
    print(cnt)
    return cnt         

#def get_count(strng):    
 #   neg = get_neg(strng)
  #  pos = get_pos(strng)

   # return (neg,pos);


def get_data(strng):    
    print(strng)
    l3=[]
    l4=[]
    l5=[]
    str1 = strng[0]
    str2 = str1.split(",")
    
    str3 = str2[0]
    ps = get_pos(str3)
    ng = get_neg(str3)
    l4.append(ps)
    l5.append(ng)
    #print(l4)
    #print(l5)
    return list(zip(l4,l5))


l3=[]
l4=[]
l5=[]
lnlist=[]
rtcount=[]
repcount=[]

import csv     

with open("project_twitter_data.csv", mode ='r')as file:
    
  csvFile = csv.reader(file)
  for lines in csvFile:
      lnlist.append(lines)
      #str2 = lines[0]
      #l3 = str2.split(",")
      #str3 = l3[0]
      #ps = get_pos(str3)
      #ng = get_neg(str3)
      #l4.append(ps)
      #l5.append(ng)
      #data = list(zip(l4,l5))

for x in lnlist[1:]:
    #print(x)    
    str2 = x[0]
    l3 = str2.split(",")
    strn1 = l3[1]
    strn2 = l3[2]
    rtcount.append(strn1)
    repcount.append(strn2)
    str3 = l3[0]
    ps = get_pos(str3)
    ng = get_neg(str3)
    l4.append(ps)
    l5.append(ng)
    data = list(zip(l4,l5))

    


fields = ['Number of Retweets', 'Number of Replies', 'Positive Score', 'Negative Score', 'Net Score']

rows=[]

#def rowfn(x,y,z,u):
 #   return None
    
    
#for x,y,z,u in map(rowfn, rtcount,repcount,l4,l5):
 #   list1 = [x,y,z,u,z-u]
  #  rows.append(list1)

from itertools import zip_longest

for i, j, k, l in zip_longest(rtcount,repcount,l4,l5):
    list1 = [i,j,k,l,k-l]
    rows.append(list1)




    

filename = "result_data.csv"
    
with open(filename, 'w') as csvfile:
    
    csvwriter = csv.writer(csvfile) 
        
    csvwriter.writerow(fields) 
        
    csvwriter.writerows(rows)


with open('result_data.csv') as f:
    for line in f:
        print(line.strip())


print(data)

print(rows)
