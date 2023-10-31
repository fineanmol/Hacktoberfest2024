def display(board):
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j]:
                print("🦄 ", end = "")
            else:
                print("❌ ", end = "")
        print()
        
def isValid(board, row, col):
    if row >= 0 and row < len(board) and col >= 0 and col < len(board) :
        return True
    return False

def isSafe(board, row, col):
    if isValid(board, row-2, col-1):
        if board[row-2][col-1]:
            return False

    if isValid(board, row-2, col+1):
        if board[row-2][col+1]:
            return False

    if isValid(board, row-1, col+2):
        if board[row-1][col+2]:
            return False

    if isValid(board, row+1, col+2):
        if board[row+1][col-2]:
            return False

    return True 

def Nknights(board, row, col, knight):
    if knight == 0:
        display(board)
        print("")
        return
    if row == len(board) - 1 and col == len(board) :
        return       
    if col == len(board): 
        Nknights(board, row + 1, 0, knight)
        return
    if isSafe(board, row, col):
        board[row][col] = True
        Nknights(board, row, col+1, knight-1)
        board[row][col] = False    
    Nknights(board, row, col+1, knight)

# main 
board = [[False]*4 for i in range(4)]
Nknights(board, 0, 0, 4)
# by default i have made it for 4
# you can do it for n*n board and k number of Knight
#board = [[False]*n for i in range(n)]
#Nknight(board, 0 ,0 ,4)

#git rm --cached hacktober/Hacktoberfest2022