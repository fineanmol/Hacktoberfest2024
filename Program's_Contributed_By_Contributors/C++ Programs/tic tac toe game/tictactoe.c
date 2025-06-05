#include <stdio.h>

// Function to initialize the Tic-Tac-Toe board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// Function to check if the game is over
int isGameOver(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    
    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    
    return -1; // Game is a draw
}

// Function to make a move
void makeMove(char board[3][3], int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
    }
}

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    int row, col;
    int gameOver = 0;
    
    initializeBoard(board);
    
    printf("Welcome to Tic-Tac-Toe!\n");
    
    while (!gameOver) {
        printf("Current board:\n");
        printBoard(board);
        
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            if (board[row][col] == ' ') {
                makeMove(board, row, col, currentPlayer);
                gameOver = isGameOver(board);
                if (gameOver == -1) {
                    printf("It's a draw!\n");
                } else if (gameOver) {
                    printf("Player %c wins!\n", currentPlayer);
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                printf("Invalid move. That cell is already occupied.\n");
            }
        } else {
            printf("Invalid move. Please enter row and column values between 0 and 2.\n");
        }
    }
    
    printf("Final board:\n");
    printBoard(board);
    
    return 0;
}