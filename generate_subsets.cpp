#include<bits/stdc++.h>
using namespace std;

void generateSubsets(string str,string cur="",int i=0){
    if(i==str.length()){
        cout<<cur<<endl;
        return;
    }
    generateSubsets(str,cur,i+1);
    generateSubsets(str,cur+str[i],i+1);
}
int main()
{
    string str;
    cin>>str;
    generateSubsets(str);
    return(0);
}
