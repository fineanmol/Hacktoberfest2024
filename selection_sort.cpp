#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n];

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]<ar[i])
            {
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }

    return 0;
}