#include <bits/stdc++.h> // header file includes every Standard library
#include<cmath>
using namespace std;
int main() {
    int a,b;
    cin>>a;
    cin>>b;
    if(pow(a,b)> pow(b,a))
        cout<<"First"<<endl;
    else if(pow(a,b)< pow(b,a))
        cout<<"Second"<<endl;
    else    
        cout<<"Equal"<<endl;
	// Your code here
    return 0;
}
