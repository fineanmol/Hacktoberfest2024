#include <iostream>
using namespace std;

int prime(int n){
    int i;
    for (i=2;i<n;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    string text,pattern,check;
    cout<<"Enter the text : ";
    cin>>text;
    cout<<"Enter the pattern : ";
    cin>>pattern;
    int q=0;
    int i,j;
    i = text.length();
    while (q==0){
        if (prime(i)==0){
            i = i+1;
        }
        else{
            q = i;
        }
    }
    int patt_code=0,check_code=0,mult=1,found=0;
    for (i=0;i<pattern.length();i++){
        patt_code = patt_code+int(pattern[i])*mult;
        mult = mult*10;
    }
    patt_code = patt_code%q;
    for (i=0;i<text.length()-pattern.length()+1;i++){
        check="";
        for (j=i;j<i+pattern.length();j++){
            check = check+text[j];
        }
        cout<<check<<" ";
        check_code = 0;
        mult = 1;
        for (j=0;j<pattern.length();j++){
            check_code = check_code+int(check[j])*mult;
            mult = mult*10;
        }
        check_code = check_code%q;
        cout<<check_code<<endl;
        if (patt_code==check_code){
            cout<<"Pattern found after "<<i<<" shifts!"<<endl;
            found = 1;
        }
    }
    if (found==0){
        cout<<"Pattern not found!"<<endl;
    }
    return 0;
}