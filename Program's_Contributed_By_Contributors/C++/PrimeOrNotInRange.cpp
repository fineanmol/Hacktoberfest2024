#include <iostream>
using namespace std;

//Program to display prime numbers from a to b range.

int main()
{

    int a, b;
    cin >> a >> b;
    int i;
    for (int num = a; num < b; num++)

    { //int i=a is defining range from a number then we are running it till b.
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                cout << num << " Not Prime" << endl;
                break;
            }
        }
        if (i == num)
        {
            cout << num << " Prime" << endl;
        }
    }

    return 0;
}