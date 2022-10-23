
a = input('do you want to play game? := yes / no ')
b = [' _ ', ' _ ',' _ ',' _ ', ' _ ',' _ ',' _ ', ' _ ',' _ ']

def number():
    print(b[0] + b[1]+  b[2])
    print(b[3] + b[4] + b[5])
    print(b[6] + b[7] + b[8])


if a.lower()=='yes' :
    print("welcome to game")
    global game_runing 
    game_runing = True
    num=1
    while game_runing==True :
        number()
        p = int(input('write the position number between 1 to 9 '))
        if p < 10 and p>0 :
            if b[p-1] != (' O ' or ' X ') :
               if (num)%2!= 0 :
                    b[p-1] = ' O '
                    num+=1
               else :
                    b[p-1] = ' X '
                    num+=1
            else :
                print(" ==> it is already filled")
        else :
            print('==> please write number between 1 to 9  :)')
        if (b[0] == b[1] == b[2] == " O " or b[0] == b[3] == b[6] == " O " or b[6] == b[7] == b[8] == " O " or b[2] == b[5] == b[8] == " O " or b[0] == b[4] == b[8] == " O " or b[2] == b[4] == b[6] == " O ") :
           number()
           print("yeah ! mr. O is winner")
           game_runing = False

        elif (b[0] == b[1] == b[2] == " X " or b[0] == b[3] == b[6] == " X " or b[6] == b[7] == b[8] == " X " or b[2] == b[5] == b[8] == " X " or b[0] == b[4] == b[8] == " X " or b[2] == b[4] == b[6] == " X ") :
           number()
           print("yeah ! mr. X is winner")
           game_runing = False

        elif (b[0] == b[1] == b[2] == b[3] == b[4] == b[5] == b[6] == b[7] == b[8]  != ' _ '  ):
            number()
            print("Oh my god both of you are very tough oponent...  :) ")
            game_runing = False
    
else :
    print('okay next time we will play together')

