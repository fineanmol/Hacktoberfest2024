
def display_board(board):
    print("\n")
    print(f" {board[0]} | {board[1]} | {board[2]} ")
    print("---|---|---")
    print(f" {board[3]} | {board[4]} | {board[5]} ")
    print("---|---|---")
    print(f" {board[6]} | {board[7]} | {board[8]} ")
    print("\n")

# Check if there's a winner
def check_winner(board, mark):
    return ((board[0] == board[1] == board[2] == mark) or  # Row 1
            (board[3] == board[4] == board[5] == mark) or  # Row 2
            (board[6] == board[7] == board[8] == mark) or  # Row 3
            (board[0] == board[3] == board[6] == mark) or  # Column 1
            (board[1] == board[4] == board[7] == mark) or  # Column 2
            (board[2] == board[5] == board[8] == mark) or  # Column 3
            (board[0] == board[4] == board[8] == mark) or  # Diagonal 1
            (board[2] == board[4] == board[6] == mark))    # Diagonal 2

# Check if the board is full
def check_full(board):
    return ' ' not in board

# Main Tic-Tac-Toe Game
def play_tic_tac_toe():
    board = [' ' for _ in range(9)]  # Create an empty board
    current_player = "X"  # X goes first

    while True:
        display_board(board)
        try:
            move = int(input(f"Player {current_player}, choose your move (1-9): ")) - 1
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 9.")
            continue
        
        if move < 0 or move > 8 or board[move] != ' ':
            print("Invalid move. Try again.")
            continue

        board[move] = current_player

        if check_winner(board, current_player):
            display_board(board)
            print(f"Player {current_player} wins!")
            break
        elif check_full(board):
            display_board(board)
            print("It's a tie!")
            break

        # Switch players
        current_player = "O" if current_player == "X" else "X"

# Start the game
play_tic_tac_toe()
