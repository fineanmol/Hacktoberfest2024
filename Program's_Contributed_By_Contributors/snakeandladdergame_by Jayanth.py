import random
import sys

def Move(Player, value):
    snake_squares = {16: 4, 22:10, 33: 20, 48: 24, 62: 56, 78: 69, 74: 60, 91: 42, 97: 6}
    ladder_squares = {3: 12, 7: 23, 11:25, 21: 56, 47: 53, 60: 72, 80: 96}
    Throw = random.randint(1, 6)
    num = value + Throw
    if num>100:
        print("BAD LUCK, YOU CANT MOVE, YOU NEED A {} TO WIN".format(100 - value))
        return value
    if num == 100:
        return num
    print(Player, "Rolled a", Throw, "And is now on", num)
    if num in snake_squares:
        print(Player, " got bitten by a snake and is now on square", snake_squares[num])
        num = snake_squares[num]
    elif num in ladder_squares:
        print(Player, " climbed a ladder and is now on square", ladder_squares[num])
        num = ladder_squares[num]

    return num

def playerscount():
    numofplayers = int(input("How many players are in the game?"))
    print()
    if numofplayers > 4 or numofplayers < 2:
        print("Must be less than 5 and greater than 1")
    else:
        return numofplayers


def nameofplayers(N):
    Names = ['','','','']
    for i in range(N):
        Names[i] = input("What is the name of Player "+str(i+1)+" ?")
    return Names

def turn(player,pos):
    COMMANDSTATE = "Press Enter to continue or press 'stop' to stop"
    WINSTATEMENT = "WINS THE GAME! CONGRATULATIONS"
    COMMANDSTATE1 = str("Hey "+player+"! It's your turn now "+COMMANDSTATE)
    Command = input(COMMANDSTATE1)
    if Command.lower() == 'stop':
        return True, pos
    pos = Move(player, pos)
    if pos == 100:
        print(player, WINSTATEMENT)
        print("AT WINNING {} was at {}".format(player, pos))                 
        return True, pos
    return False, pos
def main():
    numofplayers = playerscount()
    playernames = nameofplayers(numofplayers)
    print(playernames[0], playernames[1], playernames[2], playernames[3], "- Welcome To Snakes And Ladders")
    COMMANDSTATE = "Press Enter to continue or press 'stop' to stop: "
    WINSTATEMENT = "WINS THE GAME! CONGRATULATIONS"
    Command = ''
    TURNS = 0
    PosArr=[1,1,1,1]
    GameOver = False
    while not GameOver:      
        while TURNS < numofplayers:
            TURNS += 1
            GameOver, PosArr[TURNS - 1] = turn(playernames[TURNS - 1], PosArr[TURNS - 1])
            if GameOver:
                return
        TURNS = 0
    return
if __name__=='__main__':
    main()
