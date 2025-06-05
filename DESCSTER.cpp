#include <bits/stdc++.h>
using namespace std;
  
int main()
  {
    //write your code here
  
  int t ;
  cin >> t ;
  while(t--)
  {
  string s ;
  cin >> s ;
  sort(s.begin(),s.end(),greater<char>()) ;
  cout<<s ;
  }
  
    return 0;
}