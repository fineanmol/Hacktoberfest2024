class Solution:
    def solveNQueens(self, n):
        self.res = []
        board = self.fill_board(n)
        self.fill_boxes(board, 0, n)
        return self.res

    def fill_board(self, n):
        board = []
        for i in range(n):
            row = []
            for j in range(n):
                row.append(".")
            board.append(row)
        return board

    def fill_boxes(self, board, x, n):
        if x == n:
            res = []
            for row in board:
                res.append("".join(row))
            self.res.append(res)
            return True

        for j in range(n):
            if self.is_valid(board, x, j, n):
                board[x][j] = "Q"
                res = self.fill_boxes(board, x + 1, n)
                board[x][j] = "."

    def is_valid(self, board, x, y, n):
        # coloumn validation
        for i in range(n):
            if board[i][y] == "Q":
                return False

        # upper left diagonal
        i = x - 1
        j = y - 1
        while i >= 0 and j >= 0:
            if board[i][j] == "Q":
                return False
            i -= 1
            j -= 1

        # upper right diagonal
        i = x - 1
        j = y + 1
        while i >= 0 and j < n:
            if board[i][j] == "Q":
                return False
            i -= 1
            j += 1

        return True
sols = Solution().solveNQueens(8)
print("Number of Solutions {count}".format(count=len(sols)))
for sol in sols:
    print(sol)
