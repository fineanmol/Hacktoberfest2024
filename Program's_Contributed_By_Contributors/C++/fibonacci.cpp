#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a = 1;
  int b = 1;
  cout << a << " " << b << " ";
  for (int i = 2; i < n; i++){
    int c = a+b;
    a=b;
    b=c;
    cout << c << " ";
  }
  cout << endl;
  return 0;
}