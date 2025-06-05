#include<iostream>
using namespace std;

int main() {
    int n, sum = 0, temp;
    cout << "Enter a number: ";
    cin >> n;
    temp = n;

    while (n > 0) {
        int last_dig = n % 10;
        sum = sum + (last_dig * last_dig * last_dig);
        n = n / 10;
    }

    if (temp == sum) {
        cout << temp << " is an Armstrong number." << endl;
    } else {
        cout << temp << " is not an Armstrong number." << endl;
    }

    return 0;
}
