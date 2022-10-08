#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool matching(char a, char b){
    return((a=='('&&b==')')||(a=='{'&&b=='}')||(a=='[' && b==']'));
}
bool balancedparanthesis(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);

        else
            {
                if (s.empty() == true)
                {
                    return false;
                }
                else if (matching(s.top(), str[i]) == false)
                {
                    return false;
                }
                else
                    s.pop();
            }
    }
    return (s.empty() == true);
}
int main(){
   string avi;
   cout<<"Enter the paranthesis:";
   cin>>avi;
    if(balancedparanthesis(avi)){
    cout<<"balanced paranthesis";
    }
    else
    cout<<"Not a balanced paranthesis";
    return 0;
}


