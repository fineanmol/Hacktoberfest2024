#include <iostream>
#define N 9
using namespace std;
int arr[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}};

// Check whether num exists in Column
bool isPresentInCol(int col, int num)
{
    for (int row = 0; row < N; row++)
        if (arr[row][col] == num)
            return true;
    return false;
}

// Check whether num exists in Row
bool isPresentInRow(int row, int num)
{
    for (int col = 0; col < N; col++)
        if (arr[row][col] == num)
            return true;
    return false;
}

// check num is present in 3x3 box or not
bool isPresentInBox(int InitialRow, int InitialCol, int num)
{

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (arr[row + InitialRow][col + InitialCol] == num)
                return true;
    return false;
}

// Prints Sudoku
void sudokuGrid()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << arr[row][col] << " ";
        }
        if (row == 2 || row == 5)
        {
            cout << endl;
            for (int i = 0; i < N; i++)
                cout << "---";
        }
        cout << endl;
    }
}

// Empty location and update row and column
bool EmptyGrid(int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (arr[row][col] == 0)
                return true;
    return false;
}
// Item Not in Box
bool isValidPlace(int row, int col, int num)
{
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);
}
bool solveSudoku()
{
    int row, col;
    if (!EmptyGrid(row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isValidPlace(row, col, num))
        {
            arr[row][col] = num;
            if (solveSudoku()) // recursively go for other rooms in the grid
                return true;
            arr[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    if (solveSudoku() == true)
        sudokuGrid();
    else
        cout << "No solution exists";
}