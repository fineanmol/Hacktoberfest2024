#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows. \n";
    cin>>n;

    int m;
    cout<<"Enter the number of columns. \n";
    cin>>m;

    int arr[n][m];
    cout<<"Enter elements. \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Matrix is:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<"_";
        }
        cout<<endl;
    }

    return 0;
}