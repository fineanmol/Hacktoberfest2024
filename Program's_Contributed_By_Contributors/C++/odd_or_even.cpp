#include<bits/stdc++.h>

using namespace std;

void checkOddOrEven(number)
{
    if(number % 2) {
        cout << "Even" << endl;
    }
    else {
        cout << "Odd" << endl;
    }
}

int main()
{
    int number;
    cin >> number;
    checkOddOrEven(number);

    return 0;
}