#include<bits/stdc++.h>
using namespace std; 

int main(){

/*
Strings me input lene ke liye we use getline(cin,str), insted of cin, coz cin breaks after a space
or a next line but getline supports spaces.

Strings are always declared inside "" and characters are declared with ''

you can directly change the character at any index of a string by writing str[index]='a',note
you're changing character hence single qotes.

str.size(), gives you the size of the string
*/

int t;
cin>>t;
cin.ignore();
while (t--)
{
    string str; //A very peculiar error occurs here, insted of taking 3 inputs, it autonmatically takes a space as an input then takes remaing two strings.
    getline(cin,str); //Reason, cin, when taking inputs ignores /n, or " ", in between two inputs but getline takes input from the exact place the cursor is placed. ie after taking input of t, the cursor will be like 3\n , cin could have ignored this newline character but getline, takes this character as an input to the first string. To overcome this we use cin.ignore() ⚠️Actually this isnt the reason but an analogy
    string rev_str;
    //A simple code to reverse a string
    for (int i = str.size()-1; i >= 0; i--)
    {
        //insted of using rev_str = rev_str + str[i] O(size(str)), ie adding chars to a string we use push_back whose time complexity is O(n)
        rev_str.push_back(str[i]);
    }
    cout<<(rev_str==str)<<endl;
}

}