# Tic-Tac-Toe game in Python

# Function to print the Tic-Tac-Toe board
def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

# Function to check if a player has won
def check_winner(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True

    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True

    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True

    return False

# Function to check if the board is full
def is_board_full(board):
    for row in board:
        if " " in row:
            return False
    return True

# Main game loop
def tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    while True:
        print_board(board)
        print(f"Player {current_player}'s turn.")

        row = int(input("Enter the row (0, 1, or 2): "))
        col = int(input("Enter the column (0, 1, or 2): "))

        if 0 <= row < 3 and 0 <= col < 3 and board[row][col] == " ":
            board[row][col] = current_player

            if check_winner(board, current_player):
                print_board(board)
                print(f"Player {current_player} wins!")
                break

            if is_board_full(board):
                print_board(board)
                print("It's a draw!")
                break

            current_player = "O" if current_player == "X" else "X"
        else:
            print("Invalid move. Try again.")

if __name__ == "__main__":
    tic_tac_toe()
