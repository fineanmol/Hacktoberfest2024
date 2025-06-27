#include<iostream>
using namespace std;
int main(){
    cout<<"NO OF ROWS:";
    int n;
    cin>>n;
    int count=1;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(j<=n-i){
                cout<<"  ";
            }
            else{
                cout<<count;
                count++;
            }

        }
    
        cout<<endl;

    }
    return 0;
}