#include <bits/stdc++.h>
using namespace std;

int main()
{
    // size of the pyramid
    int size = 5;
    for (int i = 0; i < size; i++)
    {
        // print spaces
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << " ";
        }
        // print stars
        for (int k = 0; k < 2 * i + 1; k++)
        {
            if (i == 0 || i == size - 1)
            {
                cout << "*";
            }
            else
            {
                if (k == 0 || k == 2 * i)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}

// OUTPUT
//
//     *
//    * *
//   *   *
//  *     *
// *********
//