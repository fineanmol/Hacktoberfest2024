#include<iostream>
using namespace std;
int main(){
    cout<<"NO OF ROWS:";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n-i;j++){
                cout<<" ";

        }
        for( int j=1;j<=n;j++){
            cout<<"* ";

        }

    
        cout<<endl;

    }
    
    cout<<endl;
    return 0;
}