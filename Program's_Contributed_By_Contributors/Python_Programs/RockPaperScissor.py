resolved #6121
import random
print("welcome to rock,paper,scissors game:)")
user=input("what is user name :)  : ")
password=input("what is password: ")
if password=="shivz@2004":
    print("Entered to Game!")
else:
    while True :
        a=input("Tell me the correct password! ")
        if a=="shivz@2004":
            print("Entered to Game!")
            break
compscore=0
userscore=0
print("Hello %s you are in the hell now :( " %user)
r1=input("Round 1. what is your call(rock,paper,scissors) : ")
comp="scissors","papers","rock"
comp1=random.choice(comp)
print("Computers Call: %s " %comp1)
if r1=="rock" and comp1=="papers":
    print("you loose:( computer wins")
    compscore+=1
elif r1=="rock" and comp1=="scissors":
    print("yay! you win:) ")
    userscore+=1
elif r1=="rock" and comp1=="rock":
    print("Draw both will get 1 points ")
    compscore+=1
    userscore+=1
elif r1=="papers" and comp1=="papers":
    print("Draw Both will get 1 points")
    compscore+=1
    userscore+=1
elif r1=="papers" and comp1=="scissors":
    print("you loose:( computer wins")
    compscore+=1
elif r1=="papers" and comp1=="rock":
    print("yay! you win:) ")
    userscore+=1
elif r1=="scissors" and comp1=="scissors":
    print("Draw both will get 1 points ")
    compscore+=1
    userscore+=1
elif r1=="scissors" and comp1=="papers":
    print("yay! you win:) ")
    userscore+=1
elif r1=="scissors" and comp1=="rock":
    print("you loose:( computer wins")
    compscore+=1
r2=input("Round 2. what is your call(scissors,papers,rock) : ")
comp="scissors","papers","rock"
comp1=random.choice(comp)
print("Computers Call: %s " %comp1)
if r2=="rock" and comp1=="papers":
    print("you loose:( computer wins")
    compscore+=1
elif r2=="rock" and comp1=="scissors":
    print("yay! you win:) ")
    userscore+=1
elif r2=="rock" and comp1=="rock":
    print("Draw both will get 1 points ")
    compscore+=1
    userscore+=1
elif r2=="papers" and comp1=="papers":
    print("Draw Both will get 1 points")
    compscore+=1
    userscore+=1
elif r2=="papers" and comp1=="scissors":
    print("you loose:( computer wins")
    compscore+=1
elif r2=="papers" and comp1=="rock":
    print("yay! you win:) ")
    userscore+=1
elif r2=="scissors" and comp1=="scissors":
    print("Draw both will get 1 points ")
    compscore+=1
    userscore+=1
elif r2=="scissors" and comp1=="papers":
    print("yay! you win:) ")
    userscore+=1
elif r2=="scissors" and comp1=="rock":
    print("you loose:( computer wins")
    compscore+=1
r3=input("Round 3. what is your call(scissors,papers,rock) : ")
comp="scissors","papers","rock"
comp1=random.choice(comp)
print("Computers Call: %s " %comp1)
if r3=="rock" and comp1=="papers":
    print("you loose:( computer wins")
    compscore+=1
elif r3=="rock" and comp1=="scissors":
    print("yay! you win:) ")
    userscore+=1
elif r3=="rock" and comp1=="rock":
    print("Draw both will get 1 points ")
    compscore+=1
    userscore+=1
elif r3=="papers" and comp1=="papers":
    print("Draw Both will get 1 points")
    compscore+=1
    userscore+=1
elif r3=="papers" and comp1=="scissors":
    print("you loose:( computer wins")
    compscore+=1
elif r3=="papers" and comp1=="rock":
    print("yay! you win:) ")
    userscore+=1
elif r3=="scissors" and comp1=="scissors":
    print("Draw both will get 1 points ")
    compscore+=1
    userscore+=1
elif r3=="scissors" and comp1=="papers":
    print("yay! you win:) ")
    userscore+=1
elif r3=="scissors" and comp1=="rock":
    print("you loose:( computer wins")
    compscore+=1
print("computers total score is %s"%compscore)
print("user total score is %s" %userscore)
if userscore>compscore:
    print("yay you win the game champion")
elif compscore>userscore:
    print(" you loose! the game better luck next time")
elif compscore==userscore:
    print("Draw! play again")
