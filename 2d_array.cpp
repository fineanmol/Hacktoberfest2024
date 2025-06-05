#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int c = 1;
    
    int i, j;
    int arr[i][j];

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j <= 5; j++)
        {
            arr[i][j] = c;
            c = c + 1;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j <= 5; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}