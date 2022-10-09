#include <iostream>
using namespace std;

int main()
{

    int i, j, row, col;
    cout << "Enter Rows ";
    cin >> row;
    cout << "Enter Columns ";
    cin >> col;

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            if (i == 0 || i == col-1 || j == 0 || j == row-1)
            {
                cout << "* ";
            }
            else
                cout << "  ";
        }
        cout << endl;
    }
    return 0;
}
