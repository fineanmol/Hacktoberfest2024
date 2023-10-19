#include <iostream>

using namespace std;

int main() {
    int limit, a = 0, b = 1, c;

    cout << "Enter the limit of the Fibonacci series: ";
    cin >> limit;

    if (limit == 0) {
        cout << "No terms in the Fibonacci series.";
    } else if (limit == 1) {
        cout << a;
    }else if(limit<0){
        cout<<"its a negetive number"<<endl;
    }
     else {
        cout << a << " " << b << " ";
        for (int i = 2; i < limit; i++) {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }

    return 0;
}
