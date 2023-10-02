#displaying the matrix box
#The purpose of this function is to display the 3x3 matrix with or without symbols
#it is used after evey player's turn
def display(mat):
    print('\n')
    print(' ',mat[0][0],'|',mat[0][1],'|',mat[0][2])
    print('  ---------- ')
    print(' ',mat[1][0],'|',mat[1][1],'|',mat[1][2])
    print('  ---------- ')
    print(' ',mat[2][0],'|',mat[2][1],'|',mat[2][2])

#insertion of elements in the box
#this function check the postion and enters the symbol in its appropiate index value of matrix
#after insertion it checks if the symbols match horizontally, vertically or diagonally
#it has taken parameters: the matrix,n= position of the element to be inserted,k= symbol('x'/'o'), turn= which player's turn it is
def insert(mat,n,k,turn):
    n=int(n)
    if n==1:
        mat[0][0]=k
        check_horizontally(mat,k,0,turn)
        check_vertically(mat,k,0,turn)
        check_diagnol(mat,k,turn)
    elif n==2:
        mat[0][1]=k
        check_horizontally(mat,k,0,turn)
        check_vertically(mat,k,1,turn)
    elif n==3:
        mat[0][2]=k
        check_horizontally(mat,k,0,turn)
        check_vertically(mat,k,2,turn)
        check_diagnol(mat,k,turn)
    elif n==4:
        mat[1][0]=k
        check_horizontally(mat,k,1,turn)
        check_vertically(mat,k,0,turn)
    elif n==5:
        mat[1][1]=k
        check_horizontally(mat,k,1,turn)
        check_vertically(mat,k,1,turn)
        check_diagnol(mat,k,turn)
    elif n==6:
        mat[1][2]=k
        check_horizontally(mat,k,1,turn)
        check_vertically(mat,k,2,turn)
    elif n==7:
        mat[2][0]=k
        check_horizontally(mat,k,2,turn)
        check_vertically(mat,k,0,turn)
        check_diagnol(mat,k,turn)
    elif n==8:
        mat[2][1]=k
        check_horizontally(mat,k,2,turn)
        check_vertically(mat,k,1,turn)
    elif n==9:
        mat[2][2]=k
        check_horizontally(mat,k,2,turn)
        check_vertically(mat,k,2,turn)
        check_diagnol(mat,k,turn)


#check horizontally
#this function checks the row of the last inserted element to find matching symbols in that row
#parameters of function are: the matrix, mark= symbol, position and turn
def check_horizontally(mat,mark,position,turn):
    frequency=0
    frequency=int(frequency)
    for i in range(3):
        if mat[position][i]==mark:
            frequency=frequency+1

    if frequency==3:
    
        final_result(turn)


#check vertically
#this function checks the column of the last inserte element to find matching symbols in that columnm
#parameters of function are: matrix, mark= symbol, position and turn

def check_vertically(mat,mark,position,turn):
    frequency=0
    frequency=int(frequency)

    for i in range(3):
        if mat[i][position]==mark:
            frequency=frequency+1

    if frequency==3:
        
        final_result(turn)

#check diagonally
#this function checks the diagonal from both sides
# 
def check_diagnol(mat,mark,turn):
    frequency=0
    frequency=int(frequency)
    for i in range(3):
        if mat[i][i]==mark:
            frequency=frequency+1

    if frequency==3:
        final_result(turn)    

    frequency=0
    for i in range(3):
        if mat[i][2-i]==mark:
            frequency=frequency+1

    if frequency==3:
        final_result(turn)


#Displaying final result
#This function takes the argument of current player and displays the winner

def final_result(player):
    display(mat)
    if player%2==0:
        print('\nPLAYER 1 WON')
    else:
        print('\nPLAYER 2 WON')
    exit(0)



if __name__=='__main__':
    print('WELCOME TO Tick-Tack-Toe')
    #creating a blank matrix
    mat = []
    
    for i in range(0,3):
        mat.append([])
    for i in range(0,3):
        for j in range(0,3):
            mat[i].append(j)
            mat[i][j]=0

    for i in range(0,3):
        for j in range(0,3):
            mat[i][j]=" "


    display(mat)
    #Adding elements playerwise
    t=9
    flag=0
    flag=int(flag)
    turn=0
    turn=int(turn)
    empty=0
    empty=int(empty)
    while(t):
        if turn%2==0:                                       #when the turn is even, it will be player 1's chance
            
            p1=input("Player 1's turn:")
            o='O'
            insert(mat,p1,o,turn)
            display(mat)
        else:                                               #when the turn is odd, it will be player 2's chance    
            p2=input("Player 2's turn: ")
            x='X'
            insert(mat,p2,x,turn)
            display(mat)
        flag=flag+1
        turn=turn+1
        t=t-1

    if flag==9:
        print("IT'S A DRAW")
        exit(0)

    
    



    

    