#include <iostream>
using namespace std;

const int MAX = 100;

int screen[MAX][MAX];
int M, N; // Dimensions of the screen

void floodFillUtil(int x, int y, int prevColor, int newColor) {
    if (x < 0 || x >= M || y < 0 || y >= N) return;
    if (screen[x][y] != prevColor) return;

    screen[x][y] = newColor;

    floodFillUtil(x+1, y, prevColor, newColor);
    floodFillUtil(x-1, y, prevColor, newColor);
    floodFillUtil(x, y+1, prevColor, newColor);
    floodFillUtil(x, y-1, prevColor, newColor);
}

void floodFill(int x, int y, int newColor) {
    int prevColor = screen[x][y];
    floodFillUtil(x, y, prevColor, newColor);
}

int main() {
    M = 8;
    N = 8;

    // Initialize the screen with colors (represented by numbers)
    int screen[MAX][MAX] = {{1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1, 1, 0, 0},
                            {1, 0, 0, 1, 1, 0, 1, 1},
                            {1, 2, 2, 2, 2, 0, 1, 0},
                            {1, 1, 1, 2, 2, 0, 1, 0},
                            {1, 1, 1, 2, 2, 2, 2, 0},
                            {1, 1, 1, 1, 1, 2, 1, 1},
                            {1, 1, 1, 1, 1, 2, 2, 1}};

    int x = 4, y = 4; // Starting point
    int newColor = 3; // New color

    floodFill(x, y, newColor);

    cout << "Updated screen after flood fill:" << endl;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
