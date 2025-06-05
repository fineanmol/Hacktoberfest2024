#include<bits/stdc++.h>
using namespace std;
//finding the next palindrome using brute force 

//to make string symmetric
string mirror(string s){
    int l=s.length();
    int j=0;
    for(int i=l-1;i>=l/2;i--){
        s[i] =s[j];
        j++;
    }
    return s;
}
//to check if middle digits are nine
int nine(string s){
    int l=s.length();
    if(s[l/2]=='9'){
        return 1;
    }
    else{
        return 0;
    }
}
//if middle digits not nine then increase middle digit by 1
string inc(string s){
    int l=s.length();
    char c=s[l/2];
    int n= c;
    n++;
    char c1=n;
    if(l%2==0){
        s[l/2]=c1;
        s[(l/2)-1]=c1;
    }
    else{
        s[l/2]=c1;
    }
    return s;
}
//to check if all digit is 9 or not
int allnine(string s){
    int l=s.length();
    int c=0;
    for(int i=0;i<l;i++){
        if(s[i]!='9') {
            c++;
        }
    }
    if(c==0){
        return 1;
    }
    else{
        return 0;
    }
}
//if all digit are nine then increase by 1
string ifallnine(string s){
    int l=s.length();
    string ns="1";
    for(int i=0;i<l;i++){
        ns+="0";
    }
    return ns;
}
//if middle digit is nine but all digits are not nine:
//then make middle digit 0 and increase side digits by 1;
string f(string s){
    int l=s.length();
    if(l%2==0){
        int j=1;
        for(int i=l/2;i<l;i++){
            if(s[i]=='9'){
                s[i]='0';
                s[l/2-j]='0';
            }
            else{
                int n=s[i];
                n++;
                int c=n;
                s[i]=c;
                s[l/2-j]=c;
                break;
            }
            j++;
        }
    }
    else{
        int j=0;
        for(int i=l/2;i<l;i++){
        if(s[i]=='9'){
            s[i]='0';
            s[l/2-j]='0';
        }
        else{
            int n=s[i];
            n++;
            int c=n;
            s[i]=c;
            s[l/2-j]=c;
            break;
        }
        j++;
    }
    }
    return s;
}
//main function
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ns=mirror(s);
        if(ns>s){
            cout<<ns<<'\n';
        }
        else{
            if(nine(ns)==0){
                cout<<inc(ns)<<'\n';
            }
            else{
                if(allnine(ns)==1){
                    cout<<mirror(ifallnine(ns))<<'\n';
                }
                else{
                    cout<<f(ns)<<'\n';
                }
            }
        }
    }
    return 0;
}