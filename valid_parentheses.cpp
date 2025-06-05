#include<bits/stdc++.h>
using namespace std;


bool isValid(string s) {
        stack <char> st;
        for (auto i:s){
            if (i=='(' || i=='[' || i=='{'){
                st.push(i);
            }
            else{
                if (!st.empty()){
                    if (st.top()=='(' && i==')') st.pop();
                    else if (st.top()=='[' && i==']') st.pop();
                    else if (st.top()=='{' && i=='}') st.pop();
                    else return false;
                }
                else return false;
                
            }
        }
        if (st.empty()) return true;
        else return false;
}

int main(){
    cout<<isValid("({})");
    return 0;
}