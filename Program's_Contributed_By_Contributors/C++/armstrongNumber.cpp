#include <iostream>
#include <math.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter n: ";
    cin >> n;

    int sum = 0;

    int originalN = n;
    while (n > 0)
    {
        int lastDigit = n % 10;
        sum += round(pow(lastDigit, 3)); // we have to roundoff because the pow returns float/decimal value. If we keep that it will show "no armstrong number forever"
        n = n / 10;
    }

    if (sum == originalN)
    {
        cout << "armostrong number!" << endl;
    }
    else
    {
        cout << "Not armstrong number";
    }

    return 0;
}