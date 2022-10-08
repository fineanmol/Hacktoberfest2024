#include <bits/stdc++.h>
using namespace std;
//reverse function logic using iterative method
 string reverse( string s){
  int i=0;
  int j=s.length()-1;
  while(i<j){
   swap(s[i++],s[j--]);
  }
  return s;
 }
//main driver code
int main(){
string a="sahil";
string s=reverse(a);
cout<<s;
    return 0;
}
