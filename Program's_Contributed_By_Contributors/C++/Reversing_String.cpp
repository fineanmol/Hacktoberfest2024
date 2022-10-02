// Reversing a String using iterators

#include <iostream>
using namespace std;


string reverseString(string s,int k){
    int i=0,j,temp;
    j=k-1;

    while(i<j){                     //Iterate through the string and swap them until i<j becomes false//
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    return s;
    
    
}

int main(){
    string s="Good Morning";
    int n=s.length();
    string c=reverseString(s,n);

    cout<<c;
}

