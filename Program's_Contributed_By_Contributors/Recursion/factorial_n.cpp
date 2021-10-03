// Find the factorial of n
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    int ans = factorial(n - 1);
    return n * ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}
