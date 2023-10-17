def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

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

def is_board_full(board):
    return all(cell != " " for row in board for cell in row)

def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    print("Welcome to Tic-Tac-Toe!")
    print_board(board)

    while True:
        row = int(input(f"Player {current_player}, choose a row (0, 1, 2): "))
        col = int(input(f"Player {current_player}, choose a column (0, 1, 2): "))

        if board[row][col] == " ":
            board[row][col] = current_player
        else:
            print("That cell is already occupied. Try again.")
            continue

        print_board(board)

        if check_winner(board, current_player):
            print(f"Player {current_player} wins! Congratulations!")
            break
        elif is_board_full(board):
            print("It's a draw!")
            break

        current_player = "O" if current_player == "X" else "X"

if __name__ == "__main__":
    main()
