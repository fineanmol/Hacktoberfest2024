// Header Files and namespaces
#include<bits/stdc++.h>
using namespace std;

bool isbalancedparanthesis(char *a){

    stack <char> s;

    for (int i = 0 ; a[i]!=0 ; i++){

        char ch = a[i];

        switch (ch){

            case '(':
            case '{':
            case '[':

                s.push(ch);
                break;

            case ')':
                if (s.empty() or s.top() != '(' ){

                    return false;
                } 
                s.pop();
                break;

            case '}':
                if (s.empty() or s.top() != '{' ){

                    return false;
                }
                s.pop();
                break;

            case ']':
                if (s.empty() or s.top() != '[' ){

                    return false;
                } 
                s.pop(); 
        }
    }

    if (s.empty()) return true;
    else return false;
                
    
}
// Code
int main()
{
    char *a = new char;
    cout<<"enter an equation to check is its balanced or not: ";
    cin>>a;

    if (isbalancedparanthesis(a)){

        cout<<"Balanced";
    }

    else{

        cout<<"Not balanced";
    }
    return 0;
}
