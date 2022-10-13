#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size = 5;
    // upside pyramid
    for (int i = 1; i <= size; i++)
    {
        // printing spaces
        for (int j = size; j > i; j--)
        {
            cout << " ";
        }
        // printing star
        for (int k = 0; k < i * 2 - 1; k++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    // downside pyramid
    for (int i = 1; i <= size - 1; i++)
    {
        // printing spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // printing star
        for (int k = (size - i) * 2 - 1; k > 0; k--)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}

// OUTPUT

//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *