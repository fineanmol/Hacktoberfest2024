
// find the rsb of a number...

#include<bits/stdc++.h>
using namespace std;

int main(){
  // input a number...
    int n;
    cin>>n;
    int onesComp = ~n;
    int twosComp = onesComp+1;
    int x = n & twosComp;
    // int x =  (n&-n);
    cout<<x<<":"<<bitset<8>(x).to_string()<<endl;
    return 0;
}

// 58  => 10
