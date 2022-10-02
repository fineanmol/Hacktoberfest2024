#include<iostream>

using namespace std;
/*
Enter the rows : 4
*
**
***
****
 */
int main(){
    int n;
    cout<<"Enter the rows : ";
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<"*"<<" ";
            j++;
        }
        i++;
        cout<<endl;
    }
}