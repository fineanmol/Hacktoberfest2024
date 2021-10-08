#include<iostream>
using namespace std;
int main(){
    cout<<"NO OF ROWS:";
    int n;
    cin>>n;
    int count=1;
    for(int i=1;i<=n;i++){

        for (int j=1;j<=i;j++){


            if(count>=10){
                cout<<count<<" ";
                count++;
            }
            else {
                cout<<count<<"  ";
                count++;
            }   
            

        }
    
        cout<<endl;

    }
    return 0;
}