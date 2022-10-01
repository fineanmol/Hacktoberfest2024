//🧠Backtracking is a topic that will require concepts of dynamic programming and recursion😎
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **sol)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        sol[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, sol))
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, sol))
        {
            return true;
        }
        // Jis path me ja rahe the usme solution nahi mila so we're backtracking
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    // dynamic memory allocation😎
    int **arr = new int *[n];

    // Now har ek array element ke liye value allot karna
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // initializing and allocating the solution array
    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, sol))
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}