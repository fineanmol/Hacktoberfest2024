#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=0;j<n;j++){
            if(i+j >= n-1){
                cout<<count;
                count++;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}