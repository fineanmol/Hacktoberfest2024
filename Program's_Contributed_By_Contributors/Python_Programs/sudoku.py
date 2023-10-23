def print_grid(grid):
    for row in grid:
        print(" ".join(map(str, row))

def is_valid_move(grid, row, col, num):
    # Check if the number is not in the current row and column
    if num in grid[row] or num in [grid[i][col] for i in range(9)]:
        return False

 
    subgrid_row, subgrid_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if grid[subgrid_row + i][subgrid_col + j] == num:
                return False

    return True

def is_valid_sudoku(grid):
    # Check if the initial Sudoku grid is valid
    for row in range(9):
        for col in range(9):
            if grid[row][col] != 0:
                num = grid[row][col]
                grid[row][col] = 0
                if not is_valid_move(grid, row, col, num):
                    return False
                grid[row][col] = num
    return True

def solve_sudoku(grid):
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                for num in range(1, 10):
                    if is_valid_move(grid, row, col, num):
                        grid[row][col] = num
                        if solve_sudoku(grid):
                            return True
                        grid[row][col] = 0
                return False
    return True

def generate_sudoku():
    
    pass

if __name__ == "__main__":
    sudoku_grid = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]

    if not is_valid_sudoku(sudoku_grid):
        print("Invalid Sudoku puzzle.")
    else:
        if solve_sudoku(sudoku_grid):
            print("Sudoku solution:")
            print_grid(sudoku_grid)
        else:
            print("No solution exists.")
