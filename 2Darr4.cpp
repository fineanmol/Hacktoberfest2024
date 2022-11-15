#include<iostream>
using namespace std;

int main()
{
    int arr[3][3]={ {1,2,3} , {4,5,6} , {7,8,9}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            //swap
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    //print 
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}