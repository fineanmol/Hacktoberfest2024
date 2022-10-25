/*
Codeforces Problem 1703/A 

Problem statement: There is a string 𝑠 of length 3, consisting of uppercase and lowercase English letters.
 Check if it is equal to "YES" (without quotes), where each letter can be in any case. 
 For example, "yES", "Yes", "yes" are all allowable.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n ;//no of test cases
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(tolower(s[0])=='y' && tolower(s[1])=='e' && tolower(s[2])=='s'){
            cout<<"YES"<<endl;
        } 
        else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}