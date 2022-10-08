def sum(a,b,c):
    return a+b+c



def printBoard(xState, zState):
    zero = 'X' if xState[0] else ('O' if zState[0] else 0)
    one = 'X' if xState[1] else ('O' if zState[1] else 1)
    two = 'X' if xState[2] else ('O' if zState[2] else 2)
    three = 'X' if xState[3] else ('O' if zState[3] else 3)
    four = 'X' if xState[4] else ('O' if zState[4] else 4)
    five = 'X' if xState[5] else ('O' if zState[5] else 5)
    six = 'X' if xState[6] else ('O' if zState[6] else 6)
    seven = 'X' if xState[7] else ('O' if zState[7] else 7)
    eight = 'X' if xState[8] else ('O' if zState[8] else 8)
    print(f" {zero} | {one} | {two} ")
    print(f"---|---|---")
    print(f" {three} | {four} | {five} ")
    print(f"---|---|---")
    print(f" {six} | {seven} | {eight} ")

def checkWin(xState, zState):
    xwins = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]]
    for win in xwins:
        if(sum(xState[win[0]], xState[win[1]], xState[win[2]]) == 3):
            print("X won the match!")
            return 1
        if(sum(xState[win[0]], xState[win[1]], xState[win[2]]) == 3):
            print("O won the match!")
            return 0

    return -1
            
def checkState(xState, zState):
    for i in range(len(xState)):
        if xState[i] or zState == 0:
            return True


if __name__ == "__main__":
    xState = [0,0,0,0,0,0,0,0,0]
    zState = [0,0,0,0,0,0,0,0,0]

    turn  = 1 #for x and 0 for z
    print("Welcome to TicTacToe!")
    while(True):
        printBoard(xState, zState)
        if(turn == 1):
            print("X's Turn")
            value = int(input("Please enter a value: "))
            xState[value] = 1

        else:
            print("Z's Turn")
            value = int(input("Please enter a value: "))
            zState[value] = 1
        
        cWin = checkWin(xState, zState)
        if (cWin != -1):
            printBoard(xState, zState)
            print("Match Finished")
            
            break
        if checkState(xState, zState) != True:
            printBoard(xState, zState)
            print("Game Over!")
            break
        turn = 1 - turn 