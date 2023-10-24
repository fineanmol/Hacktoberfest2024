#include <bits/stdc++.h>
using namespace std;
int main(){
  int a = 0;
  int b;
  cout << "enter 5 numbers: ";
  for(int i = 0, i < 5, i++){
    cin >> b;
    a += b;
  }
  cout << a / 5;
}
