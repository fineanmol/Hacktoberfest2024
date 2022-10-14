class Solution:
    def spiralOrder(self, matrix):
        size = len(matrix) * len(matrix[0])
        path = []
        cell = [0,0]
        step = [0,1]
        while len(path) < size:
            path.append(matrix[cell[0]][cell[1]])
            matrix[cell[0]][cell[1]] = 120
            # next cell
            nrow, ncol = cell[0]+step[0], cell[1]+step[1]
            if (0 <= nrow < len(matrix)) and (0 <= ncol < len(matrix[0])) and (matrix[nrow][ncol]) != 120:
                cell[0], cell[1] = nrow, ncol
            else:
                 # change direction (90 degrees clockwise)
                 step[0], step[1] = step[1], -step[0]
                 cell[0], cell[1] = cell[0]+step[0], cell[1]+step[1]
                
        return path
