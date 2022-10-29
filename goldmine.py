def collectGold(gold, x, y, n, m):
 
    # Base condition.
    if ((x < 0) or (x == n) or (y == m)): 
        return 0
 
    # Right upper diagonal
    rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m)
 
     # right
    right = collectGold(gold, x, y + 1, n, m)
 
    # Lower right diagonal
    rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m)
 
    # Return the maximum and store the value
    return  gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right) 
 
 
def getMaxGold(gold,n,m):
 
    maxGold = 0
 
    for i in range(n):
 
        # Recursive function call for  ith row.
        goldCollected = collectGold(gold, i, 0, n, m)
        maxGold = max(maxGold, goldCollected)
 
    return maxGold
 
# Driver Code
gold = [[1, 3, 1, 5],
        [2, 2, 4, 1],
        [5, 0, 2, 3],
        [0, 6, 1, 2]
]
 
m,n = 4,4
print(getMaxGold(gold, n, m))
 