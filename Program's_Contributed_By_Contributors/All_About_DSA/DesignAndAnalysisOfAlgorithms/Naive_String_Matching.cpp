#include <iostream>
#include <string>
using namespace std;

int main(){
    string text,pattern,check;
    cout<<"Enter the text : ";
    cin>>text;
    cout<<"Enter the pattern : ";
    cin>>pattern;
    int i,j,found;
    found = 0;
    for (i=0;i<text.length()-pattern.length()+1;i++){
        check = "";
        for (j=i;j<i+pattern.length();j++){
            check = check+text[j];
        }
        if (check==pattern){
            cout<<"Pattern found after : "<<i<<" shifts!"<<endl;
            found = 1;
            break;
        }
    }
    if (found==0){
        cout<<"Pattern not found!"<<endl;
    }
    return 0;
}