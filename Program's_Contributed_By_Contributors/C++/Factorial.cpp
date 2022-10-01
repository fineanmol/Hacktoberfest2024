#include<iostream>
using namespace std;

int fact(int n);

int main(){
    int n;
    cout<<"Enter the number to find factorial: ";
    cin>>n;
    cout<<fact(n);

    return 0;
}

int fact(int n){
    int ans=1;
    for(int i=n;i>0;i--){
        ans*=i;
    }
    return ans;
}

int fact(int n){
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}