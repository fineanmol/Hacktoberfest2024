def solve_sudoku(grid):
    # Check if the grid is already solved
    if is_solved(grid):
        return grid

    # Find the next empty cell
    row, col = find_empty_cell(grid)

    # Try each possible value for the empty cell
    for value in range(1, 10):
        if is_valid(grid, row, col, value):
            grid[row][col] = value
            solve_sudoku(grid)
            if is_solved(grid):
                return grid
            grid[row][col] = 0

    # If no solution was found, return None
    return None

def is_solved(grid):
    # Check if all rows, columns, and boxes are filled
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                return False
    return True

def find_empty_cell(grid):
    # Find the first empty cell in the grid
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                return row, col
    return None

def is_valid(grid, row, col, value):
    # Check if the value is valid for the given cell
    for i in range(9):
        if grid[row][i] == value or grid[i][col] == value:
            return False
    return True