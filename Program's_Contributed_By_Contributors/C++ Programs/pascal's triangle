#include <iostream>
using namespace std;

int main() {

    int rows, coef = 1;

    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i = 0; i < rows; i++) {
        for(int space = 1; space <= rows-i; space++)
            cout <<"  ";

        for(int j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef*(i-j+1)/j;

            cout << coef << "   ";
        }
        cout << endl;
    }

    return 0;
}
