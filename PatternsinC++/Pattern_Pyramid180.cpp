#include<iostream>
using namespace std;
int main(){
    cout<<"NO OF ROWS:";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";

        }
        cout<<endl;

    }
    return 0;
}