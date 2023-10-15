import random

# Function to generate a random maze
def generate_maze(size):
    maze = [['#' for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            if random.random() > 0.6:
                maze[i][j] = ' '
    maze[0][0] = 'S'  # Start
    maze[size - 1][size - 1] = 'E'  # End
    return maze

# Function to display the maze
def print_maze(maze):
    for row in maze:
        print(' '.join(row))

# Function to navigate through the maze
def solve_maze(maze, x, y):
    if x < 0 or x >= len(maze) or y < 0 or y >= len(maze):
        return False  # Out of bounds
    if maze[x][y] == 'E':
        return True  # Reached the exit
    if maze[x][y] in ('#', 'X'):
        return False  # Hit a wall or visited cell

    # Mark the current cell as visited
    maze[x][y] = 'X'

    # Try moving in all four directions (up, down, left, right)
    if solve_maze(maze, x - 1, y) or solve_maze(maze, x + 1, y) or solve_maze(maze, x, y - 1) or solve_maze(maze, x, y + 1):
        return True  # Found a path

    return False  # No path found

# Main function
def main():
    print("Welcome to the Maze Solver Game!")
    maze_size = 10  # You can adjust the size of the maze
    maze = generate_maze(maze_size)

    print("Here's your maze:")
    print_maze(maze)

    if solve_maze(maze, 0, 0):
        print("Congratulations! You've found the exit.")
    else:
        print("Sorry, there is no way to reach the exit.")

if __name__ == "__main__":
    main()
