# Initialize the Tic-Tac-Toe board
board = [" " for _ in range(9)]

# Function to display the Tic-Tac-Toe board
def display_board(board):
    print(f"{board[0]} | {board[1]} | {board[2]}")
    print("---------")
    print(f"{board[3]} | {board[4]} | {board[5]}")
    print("---------")
    print(f"{board[6]} | {board[7]} | {board[8]}")

# Function to check if a player has won
def check_win(board, player):
    # Check rows, columns, and diagonals
    win_conditions = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
        [0, 4, 8], [2, 4, 6]              # Diagonals
    ]
    
    for condition in win_conditions:
        if all(board[i] == player for i in condition):
            return True
    return False

# Function to check if the board is full
def is_board_full(board):
    return " " not in board

# Main game loop
current_player = "X"

while True:
    display_board(board)
    move = int(input(f"Player {current_player}, enter your move (1-9): ")) - 1

    if board[move] == " ":
        board[move] = current_player
        if check_win(board, current_player):
            display_board(board)
            print(f"Player {current_player} wins!")
            break
        elif is_board_full(board):
            display_board(board)
            print("It's a tie!")
            break
        current_player = "O" if current_player == "X" else "X"
    else:
        print("Invalid move. Try again.")

