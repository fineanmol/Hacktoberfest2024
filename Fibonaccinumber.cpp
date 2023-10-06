#include <iostream>

using namespace std;
long int fibonacci(int n) {

     long int a = 0;
    long int b = 1;
    long int sum=1;

    if (n <=1) {
        return n;
    }
    for (int i = 2; i <= n; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    long int sum = fibonacci(n);

    cout << "The " << n << "th Fibonacci number is: " << sum << endl;

    return 0;
}
