#the input format of the below code looks like
# line1: n, m specifying number of rows and number of clumns
# next n lines contains m elements each

n, m = map(int, input().split())
matrix = []
for i in range(n):
    matrix.append(list(map(int, input().split())))
tot = n * m                                                           #the total elements in the matrix will  be n * m
i = 0                                                                 # we are taking two pointers and initializing them with 0
j = 0
for _ in range(tot):                                                  #we are iterating the for loop for n * m times, cause we need to print all the elements
    print(matrix[i][j], end = " ")                                    #if an element is visited, it is printed and it's values is changed  to "0", "0" has no specific importance, it can be any number of string beyond our range
    matrix[i][j] = "0"
    canGoUp = (i - 1 >= 0) and matrix[i - 1][j] != "0"                #in the below 4 lines, we are checking if we can go up or down or bottom or left. by checking the boundary conditions.
    canGoDown = (i + 1 <= n - 1) and matrix[i + 1][j] != "0"
    canGoLeft = (j - 1 >= 0) and matrix[i][j - 1] != "0"
    canGoRight = (j + 1 <= m - 1) and matrix[i][j + 1] != "0"
    if canGoRight and canGoDown:                                      #in the below conditions, we are going in a sequential order inorder to get the spiral traversal of the matrix.
        j += 1
    elif canGoDown and canGoLeft:
        i += 1
    elif canGoLeft and canGoUp:
        j -= 1
    elif canGoUp and canGoRight:
        i -= 1
    elif canGoRight:
        j += 1
    elif canGoDown:
        i += 1
    elif canGoLeft:
        j -= 1
    else:
        i -= 1
            
            