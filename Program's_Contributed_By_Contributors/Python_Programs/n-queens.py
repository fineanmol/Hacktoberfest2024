class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        if n == 1:
            return [["Q"]]
        def display(board, arr):
            temp = []
            for row in board:
                st = ""
                for j in row:
                    if j:
                        st += "Q"
                        # print('Q',end= " ") 
                    else:
                        st += "."
                        # print('*', end = " ")
                # temp.append(st)
                # print(st)
                temp.append(st)
            # print("tempis ",temp)
            arr.append(temp)
            # return temp

        def isSafe(board, row, col):
            for i in range(row):
                if board[i][col]:
                    return False

            leftMost = min(row, col)
            for i in range(1, leftMost+1):
                if board[row-i][col-i]:
                    return False

            rightMost = min(row, len(board)-col-1)
            for i in range(1, rightMost+1):
                if board[row-i][col+i]:
                    return False

            return True

        def Queens(board, row, arr):
            if row == len(board):
                x = display(board, arr)
                print("")
                return x
            for col in range(len(board)):
                if isSafe(board, row, col):
                    board[row][col] = True
                    Queens(board, row+1, arr)
                    board[row][col] = False




        # main block
        board = [[False]*n for i in range(n)]
        arr = [0]
        Queens(board, 0, arr)
        arr.pop(0)
        return arr