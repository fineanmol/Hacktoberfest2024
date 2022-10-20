import random 

going=1
you,system=0,0
greets=["You guessed it correct smartass!","Bingo, you got that right!","That was a superb guess!","Bullseye!"]
while going:
    a=random.randint(1,20)
    chances=4
    print("The system has choosen a number in between 1 and 20")
    print("Guess the number choosen by the system. You have a total of 4 chances for it. Good luck!")
    # print("\n")

    while chances:
        b=int(input())
        if b==a:
            print(greets[random.randit(0,len(greets))])
            you+=1
            break 
        else:
            if chances==1:
                print("Oops, you ran out of attempts!")
                print("The number guessed by the system was:", a)
                system+=1
                # print("\n")
                break
            elif b>a:
                print("Incorrect")
                print("HINT: Your last guess was too high")
            elif b<a:
                print("Incorrect")
                print("HINT: Your last guess was too low")
        chances-=1
    print("You:",you,"System:",system)
    c=input("Do you wish to continue? (Y/N):")
    if c=="Y" or c=="y":
        going=1
    elif c=="N" or c=="n":
        going=0
    # print("\n")
print("-*-"*30)



