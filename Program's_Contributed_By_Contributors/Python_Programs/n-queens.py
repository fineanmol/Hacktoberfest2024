def print_solution(board):
    for row in board:
        line = ""
        for field in row:
            line += "Q" if field else "."
        print(line)
    print("\n")

def is_safe(board, row, col):
    for i in range(col):
        if board[row][i]:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False

    for i, j in zip(range(row, len(board), 1), range(col, -1, -1)):
        if board[i][j]:
            return False

    return True

def solve_n_queens_util(board, col):
    if col >= len(board):
        print_solution(board)
        return True

    res = False
    for i in range(len(board)):
        if is_safe(board, i, col):
            board[i][col] = True
            res = solve_n_queens_util(board, col + 1) or res
            board[i][col] = False  # backtrack

    return res

def solve_n_queens(n):
    board = [[False for j in range(n)] for i in range(n)]
    if not solve_n_queens_util(board, 0):
        print("No solution exists")
        return
    else:
        print("Solutions found")

# Usage:
n = 8  # for an 8x8 chessboard
solve_n_queens(n)
