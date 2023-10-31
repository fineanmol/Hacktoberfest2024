#print("\u26d4 \u0000 \u26ab ")
rows, cols = (6,7)
arr = [[" O" for i in range(cols)] for j in range(rows)]
print("Type 0 to stop the program \n")
print([' 1', ' 2',' 3',' 4',' 5',' 6',' 7'])
for row in arr:
    print(row)
class move:
    def __init__(self, lane, color):
        self.lane=lane
        self.color=color
'''class player:
    def __init__(self, number, color):
        self.number= number
        self.color=color'''
class col:
    def __init__(self, number, height):
        self.number=number
        self.currow=height
class placer:
    def __init__(self, color):
        self.color=color

def inboard(i,j):
    if i in range(0,6) and j in range(0,7): 
        return True
    else: 
        return False

A = [(0,0),(0,1),(0,2),(0,3),(0,4),(0,5),(0,6),(1,0),(1,1),(1,2),(1,3),(1,4),(1,5),(1,6),(2,0),(2,1),(2,2),(2,3),(2,4),(2,5),(2,6),(3,0),(3,1),(3,2),(3,3),(3,4),(3,5),(3,6),(4,0),(4,1),(4,2),(4,3),(4,4),(4,5),(4,6),(5,0),(5,1),(5,2),(5,3),(5,4),(5,5),(5,6)]
#player1 = player(1, "black")
#player2 = player(2, "white")
print("Black steps first")
col1=col(1,0)
col2=col(2,0)
col3=col(3,0)
col4=col(4,0)
col5=col(5,0)
col6=col(6,0)
col7=col(7,0)
C=[0, col1, col2, col3, col4, col5, col6, col7]
count=0
curcolor="Black"
#'''
for count in range(0,41,1):
    inp=int(input("-->"))
    while inp>7 or inp<0:
        print("Please enter a number from 1 to 7")
        inp=int(input("-->"))
        pass
    if inp==0: break
    current = move(inp, curcolor)
    curcol= C[current.lane]
    arr[5-curcol.currow][current.lane-1]= "\u26d4" #Minus
        
    if curcolor=="Black":
        arr[5-curcol.currow][current.lane-1]= "\u26ab" #Black
    elif curcolor=="White":
        arr[5-curcol.currow][current.lane-1]= "\u26aa" #White
    else: print("SOMETHING IS WRONG")
    i=0
    j=0
    x=0
    var=0
    result=""
    while x < len(A):
        var=A[x]
        i= var[0]
        j= var[1]
        if inboard(i,j) == True and inboard(i+3,j) == True and arr[i][j] == arr[i+1][j] == arr[i+2][j] == arr[i+3][j] and arr[i][j] != " O":
                result=str(curcolor)+" is the winner \n"
                print(result)
                break
        #else:print(i,j,"did not pass the vertical test")
        if inboard(i,j) == True and inboard(i,j+3) == True and arr[i][j] == arr[i][j+1] == arr[i][j+2] == arr[i][j+3] and arr[i][j] != " O":
                result=str(curcolor)+" is the winner \n"
                print(result)
                break
        #else: print(i,j,"did not pass the horizontal test")
        if inboard(i,j) == True and inboard(i+3,j+3) == True and arr[i][j] == arr[i+1][j+1] == arr[i+2][j+2] == arr[i+3][j+3] and arr[i][j] != " O":
                result=str(curcolor)+" is the winner \n"
                print(result)
                break
        #else: print(i,j,"did not pass the slash test")
        if inboard(i,j) == True and inboard(i+3,j-3) == True and arr[i][j] == arr[i+1][j-1] == arr[i+2][j-2] == arr[i+3][j-3] and arr[i][j] != " O":
                result=str(curcolor)+" is the winner \n"
                print(result)
                break
        #else: print(i,j,"did not pass the back-slash test")
        x=x+1
    if curcolor=="Black":
        curcolor="White"
    elif curcolor=="White":
        curcolor="Black"
    else: print("SOMETHING IS WRONG")
    curcol.currow= curcol.currow + 1
    if curcol.currow>=6:
        print("You cannot add more coins into this column \n")
        print("If you place any more coins, it will not be accepted.")        
    print([' 1', ' 2',' 3',' 4',' 5',' 6',' 7'])
    for row in arr: print(row)
    print("")
    print("It is ", curcolor,"'s turn now.")
    if "is the winner" in result: break
if count==42: 
     print("The game was a probably a draw")
     print("If you think that the game ended prematurely, then maybe it is because you entered some wrong moves during the game.")

