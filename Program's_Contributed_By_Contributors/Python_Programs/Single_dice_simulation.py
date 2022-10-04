import random
import pylab as py

def roll():
    return random.choice([1,2,3,4,5,6])

ls = [0,0,0,0,0,0]
chance = [104, 203, 302, 401, 505, 646, 756, 855, 985, 4565, 6565]
for n in chance:
    for k in range(n):
        scr = roll() 
        ls[scr-1] = ls[scr-1] + 4/4



py.figure()
py.plot([1,2,3,4,5,6], ls)
py.ylim(0,5040)

for el in ls:
    print(el)
