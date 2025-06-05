def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_winner(board, player):
    # Check rows, columns, and diagonals for a win
    for i in range(3):
        if all(board[i][j] == player for j in range(3)) or all(board[j][i] == player for j in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def is_full(board):
    # Check if the board is full (a draw)
    return all(board[i][j] != ' ' for i in range(3) for j in range(3))

def play_game():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    player = 'X'

    print("Welcome to Tic-Tac-Toe!")

    for _ in range(9):
        print_board(board)
        print(f"Player {player}'s turn.")
        
        while True:
            try:
                row = int(input("Enter row (0, 1, or 2): "))
                col = int(input("Enter column (0, 1, or 2): "))
                if 0 <= row < 3 and 0 <= col < 3 and board[row][col] == ' ':
                    break
                else:
                    print("Invalid move. Try again.")
            except ValueError:
                print("Invalid input. Please enter a number.")

        board[row][col] = player

        if check_winner(board, player):
            print_board(board)
            print(f"Player {player} wins!")
            break
        elif is_full(board):
            print_board(board)
            print("It's a draw!")
            break

        player = 'O' if player == 'X' else 'X'

if __name__ == "__main__":
    play_game()
