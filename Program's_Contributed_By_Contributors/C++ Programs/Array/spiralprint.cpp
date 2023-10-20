#include <iostream>
using namespace std;

void spiralPrint(int arr[][3], int m, int n)
{
    int sRow = 0;
    int eRow = m-1;
    int sCol = 0;
    int eCol = n-1;
    int count = 0;
    int total = m * n;
    while(count < total){
        for (int i = sCol; count < total && i <= eCol; i++)
        {
            cout << arr[sRow][i] << " ";
            count++;
        }
        sRow++;
        for (int i = sRow; count < total && i <= eRow; i++)
        {
            cout << arr[i][eCol] << " ";
            count++;
        }
        eCol--;
        for (int i = eCol; count < total && i >= sCol; i--)
        {
            cout << arr[eRow][i] << " ";
            count++;
        }
        eRow--;
        for (int i = eRow; count < total && i >= sRow; i--)
        {
            cout << arr[i][sCol] << " ";
            count++;
        }
        sCol++;
    }
}

int main(int argc, char const *argv[])
{
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }

    spiralPrint(arr, 3, 3);
    return 0;
}
