#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    vector<int> m(256,0);
    int i;
    for(int i=0; a[i] && b[i]; i++){
        m[a[i]]++;
        m[b[i]]--;
    }
    if (i<a.size() || i<b.size())
        cout<< "false";
 
    // See if there is any non-zero value in count array
    for (i = 0; i < 256; i++)
        if (m[i])
            cout<<"false";
    cout<<"true";
    return 0;
}
