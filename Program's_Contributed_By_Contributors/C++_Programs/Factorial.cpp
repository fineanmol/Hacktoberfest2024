#include <iostream>
using namespace std;

int main() {
    int n;
    int factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0)
        cout << "\nError! Factorial of a negative number doesn't exist....\n";
    else 
    {
        for(int i = 1; i <= n; i++) 
        {
            factorial *= i;
        }
        cout << "\nFactorial of " << n << " = " << factorial;    
    }

    return 0;
}
