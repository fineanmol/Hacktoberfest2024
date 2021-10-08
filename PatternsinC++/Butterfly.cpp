#include<iostream>
using namespace std;

int main(){

    cout<<"      BUTTERFLY PATTERN IN C++    "<<endl;

    cout<<"NO OF ROWS:";             

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){             //loop for left wing of butterfly
        for( int j=1;j<=i;j++){      
            cout<<"* ";
        }
        int space=2*n-2*i;

        for(int j=1;j<=space;j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }

        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        for( int j=1;j<=i;j++){     //loop for right wing of butterfly
            cout<<"* ";
        }
        int space=2*n-2*i;

        for(int j=1;j<=space;j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }

        cout<<endl;
    }
    return 0;
}
