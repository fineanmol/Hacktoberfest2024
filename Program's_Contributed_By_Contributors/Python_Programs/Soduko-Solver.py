#Backtracking algorithm, written in python, that can solve any solvable sudoku game.
#The grid is formated as a 2d array, where the zeros are the blank spaces. 
#Python Terminal Colour Codes were used to customize the desin of the grid.



grid = [
    [5,3,0,0,7,0,0,0,0],
    [6,0,0,1,9,5,0,0,0],
    [0,9,8,0,0,0,0,6,0],
    [8,0,0,0,6,0,0,0,3],
    [4,0,0,8,0,3,0,0,1],
    [7,0,0,0,2,0,0,0,6],
    [0,6,0,0,0,0,2,8,0],
    [0,0,0,4,1,9,0,0,5],
    [0,0,0,0,8,0,0,7,9]
]

bold = '\33[1m'
black = '\033[30m'
blue = '\033[34m'
border_horz = " ---------------------------"

#This portion of the code formates the grid. 
#It makes sure that after every 3 items a horizontal border is printed
#It makes sure that after every 3 numbers there is a line separating it from the other items 

def print_game(grd):
    for i in range(len(grd)):
        if i % 3 == 0:
            print(bold + border_horz)

        for n in range(len(grd[0])):
            if n % 3 == 0:
                print("\033[30m | ", end="")
            if n == 8:
                print(blue + str(grd[i][n]) + "\033[30m | ")
            else:
                print(blue + str(grd[i][n]) + " "  , end="")
    print(bold + border_horz)

#Finds Empty spots by returning the row and colume.
#NOTE: the return is a (y,x) not in (x,y) cordinate
#Zeros are the empty spots

def locate_blank(grd):
    for i in range(len(grd)):
        for n in range(len(grd[0])):
            if grd[i][n] == 0:
                return (i, n)

    return None

#To validate if a number can be assigned to a postion the row, the column and the box have to clear. 
def valid(grd, num, coordinate):

    # Checks the row
    for i in range(len(grd[0])):
        if grd[coordinate[0]][i] == num and coordinate[1] != i:
            return False

    # Checks the column
    for i in range(len(grd)):
        if grd[i][coordinate[1]] == num and coordinate[0] != i:
            return False

    # Checks the box
    box_X = coordinate[1] // 3
    box_Y = coordinate[0] // 3

    for i in range(box_Y*3, box_Y*3 + 3):
        for n in range(box_X * 3, box_X*3 + 3):
            if grd[i][n] == num and (i,n) != coordinate:
                return False

    return True


#If there are no zero's in the grid, locate_blank will return nothing. 
#If there are still zero's, continue with this
def find_Solution(grd):
    find = locate_blank(grd)
    if not find:
        return True
    else:
        row, col = find
    for i in range(1,10):
        if valid(grd, i, (row, col)):
            grd[row][col] = i

            if find_Solution(grd):
                return True
            grd[row][col] = 0
    return False
print("Unsolved")
print_game(grid)
find_Solution(grid)
print("Solved!")
print_game(grid)