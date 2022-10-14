#include <iostream>
using namespace std;

void printfBoard(char** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 'Q') board[i][j] = '-';
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// checking if its not in the same row, column or diagonal
bool valid(char** M, int row, int col, int N) {
    int i, j;
    for (i = 0; i < row; i++) { 
        if (M[i][col] == 'Q') return false;
    }
    for (i = row, j = col; j < N, i>=0; i--, j++) { 
        if (M[i][j] == 'Q') return false;
    }
    for (i = row, j = col;  i >= 0 && j >= 0; i--, j--) { 
        if (M[i][j] == 'Q') return false;
    }
    return true; 
}

void qns (char** M, int N, int row) {
    if (row == N) {
        printfBoard(M, N); // print every solution
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (valid(M, row, i, N)) {
            M[row][i] = 'Q'; // placing queen
            qns(M, N, row+1);
            M[row][i] = '-'; // remove queen
        }
    }
}

void solveNQ(int numQ) {
    if (numQ == 2 || numQ == 3 ) printf("Not Possible\n\n"); // out of 8 possible inputs
    else {
        char** board = new char*[numQ];
        for (int i = 0; i < numQ; i++) board[i] = new char[numQ];
        
        qns(board, numQ, 0);
    }
}

int main() {
    int numQ;
    scanf("%d", &numQ);
    solveNQ(numQ);
    return 0;
}