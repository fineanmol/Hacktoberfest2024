#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"Enter the number of rows. \n";
    cin>>n;
    cout<<"Enter the number of columns. \n";
    cin>>m;
    int arr[n][m];
    cout<<"Enter elements. \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int x;
    cout<<"Enter the key to be searched. \n";
    cin>>x;
    bool flag=0;
    cout<<"Ans is:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j]==x)
            {
                cout<<i+1<<"_"<<j+1<<endl;
                flag=true;
            }
        }
    }
    
    if (flag){
        cout<<"Element is found. \n";
    }else{
         cout<<"Element is not found. \n";
    }    

    return 0;
}