#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int count = i+1;
        for(int j=0;j<n+i;j++){
            if(i+j >= n-1){
                if(j<n){
                    cout<<count;
                    count++;
                    if(j==n-1){
                        count--;
                    }
                }
                else{
                    count--;
                    cout<<count;
                }
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}