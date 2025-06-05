#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    for(int j=1; j<=rows; j++)
    {
        for(int i=1; i<=cols; i++)
        {
            if((i==1 && (j==1 || j==rows)))
            {
                cout << "0" << " ";
            }
            else if((i==cols && (j==1 || j==rows)))
            {
                cout << "0";
            }
            else if(i==1 || j==rows || j==1)
            {
                cout << "1" << " ";
            }
            else if(i==cols || j==rows)
            {
                cout << "1";
            }
            else
            {
                cout << "0" << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
