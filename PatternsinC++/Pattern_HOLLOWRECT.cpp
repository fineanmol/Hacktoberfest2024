#include<iostream>
using namespace std;

int main(){
    cout<<"NO OF ROWS:";
    int row,col;
    cin>>row;
    cout<<"NO OF COLUMNS:";
    cin>>col;
    for (int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1 || i==row || j==1 || j==col){
            cout<<"* ";
            }
            else{
                cout<<"  ";
            }
            
        }
        cout<<endl;


    }

    return 0;

}