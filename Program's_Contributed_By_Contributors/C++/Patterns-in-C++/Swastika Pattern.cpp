#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
     for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            if(i==1){
                if(j==n || j<=(n+1)/2){
                    cout<<"*\t";
                }
                else{
                    cout<<"\t";
                } }
            else if(i<=n/2){
                if(j==n || j==(n+1)/2){
                    cout<<"*\t";
                }
                else{
                    cout<<"\t";
                }
            }
            
            else if(i==(n+1)/2){
                cout<<"*\t";
            }
            else if(i<n ){
                if(j==1 || j==(n+1)/2){
                    cout<<"*\t";
                }
                else{
                    cout<<"\t";
                }
            
            }
            else{
                if(j==1 || j>=(n+1)/2){
                    cout<<"*\t";
                }
                else{
                    cout<<"\t";
                }
            }
         }
         cout<<endl;
     }
    return 0;
}
