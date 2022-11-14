#include<iostream>
using namespace std;
void knapSack(int W, int weight[], int value[], int n)
{   
    int a[n + 1][W + 1];
    for (int i = 0; i <= W; i++)
    {
        a[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        a[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(weight[i-1] > j)
                a[i][j] = a[i-1][j];
            else 
                a[i][j] = max(value[i-1] + a[i-1][j - weight[i-1]], a[i-1][j]);    
        }
    }
    cout<<" Matrix :"<<endl;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j< W+1; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" Max : "<<a[n][W];   
}
int main()
{
    int n ;
    cout<<"numbers of items"<<endl;
    cin>>n;

    int W ;
    cout<<" Capacity "<<endl;
    cin>>W;
    int value[n];
    cout<<"Enter the values"<<endl;
    for (int i=0;i<n;i++){
        cin>>value[i];
    }
    int weight[n];
    cout<<"Enter the weights"<<endl;
    for (int i=0;i<n;i++){
        cin>>weight[i];
    }
    knapSack(W, weight, value, n);

    return 0;
}
