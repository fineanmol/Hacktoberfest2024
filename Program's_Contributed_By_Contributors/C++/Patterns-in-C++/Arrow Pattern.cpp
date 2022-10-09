#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i == (n + 1) / 2) {
      for (int j = n; j > 0; j--) {
       cout << "*\t";
      }
    }
    else {
      for (int j = 1; j <= n / 2; j++) {
        cout <<"\t";
      }
      if (i < (n + 1) / 2) {
        for (int j = 1; j <= i; j++) {
          cout <<"*\t";
        }
      }
      else {
        for (int j = n-i+1; j>0; j--) {
          cout << "*\t";
        }
      }
    }
    cout << endl;
  }
  return 0;

}
