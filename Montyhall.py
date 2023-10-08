                                      """                   THE    MONTYHALL  PROBLEM
 The Monty Hall problem is a brain teaser, in the form of a probability puzzle, loosely based on the American television game show Let’s Make a Deal and named after its original host, Monty Hall.
    Suppose you’re on a game show, and you’re given the choice of three doors: Behind one door is a car; behind the other two are goats. You pick a door, say 1, and the host, who knows what’s behind the doors, opens another door, say №3, which has a goat. He then says to you, “Do you want to pick door 2?” Is it to your advantage to switch your choice?
Most people would say that once one door is revealed then you have only 2 choices left and therefore your chances of winning are 1/2 or 50%, and so it wouldn’t matter if you stay or switched doors.
"""



import random
door=[0]*3
goatdoor=[]
x=random.randint(0,2)
door[x]='BMW'
for i in range(3):
    if(i==x):
        continue
    else:
        door[i]='goat'
        goatdoor.append(i)
i=0        
while(i<10):
    choice=int(input('enter your choice 0,1,2'))
    dooropen=random.choice(goatdoor)
    while(choice==dooropen):
        dooropen=random.choice(goatdoor)
    print('goat is in position',dooropen)
    c=int(input('enter 1 to swap and 0 to not swap'))
    if(door[choice]=='goat' and c==1):
        print('player wins')
    elif(door[choice]=='goat' and c==0):
        print('player loose')
    elif(door[choice]=='BMW' and c==1):
        print('player loose')
    elif(door[choice]=='BMW' and c==0):
        print('player win') 
    else:
        print('invalid entry')
    i=i+1

