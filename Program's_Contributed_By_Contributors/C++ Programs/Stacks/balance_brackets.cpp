#include <bits/stdc++.h>
using namespace std;

void solve(string s){
  stack <char> st;
  int n = s.length();
  for(int i=0; i<n; i++){
    if(st.empty()){
      st.push(s[i]);
    }
    else if((st.top()=='(' && s[i]==')')
          ||(st.top()=='['&&s[i]==']')
          ||(st.top()=='{'&&s[i]=='}'))
          {
            st.pop();
          }
    else {
      st.push(s[i]);
    }
  }
  if(st.empty()){
    cout << "yes" << endl;
  }
  else cout << "no" << endl;
}

int main(){
  string s;
  cin >> s;
  solve(s);
}
