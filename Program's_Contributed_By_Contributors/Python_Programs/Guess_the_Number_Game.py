import random
Target=random.randint(1,100)
print("Let's Start The Game!! All The Best...")
while True:
    userchoice=int(input("Guess The Number Between 1-100 or Quit:"))
    if(userchoice== "Quit"):
        break
#Game made by Kunal Nagar
    if(userchoice == Target):
        print("Congratulations!! You Won The Game....")
        break
    elif(userchoice<Target):
        print("Guess Number Larger Than this..")
    else:
        print("Guess Number Smaller Than This..")
print("--------Game Over----------")





