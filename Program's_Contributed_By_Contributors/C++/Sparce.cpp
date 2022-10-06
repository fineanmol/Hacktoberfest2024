#include <iostream>
using namespace std;

int n;
int len=0;
int p=0;
int arr[100][100];
int sparce[100][3];

int main()
{
    
    cout<<"Enter the dimensions of the matrix: ";
    cin>>n;
    

    cout<<"Enter the Sparce Matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"Sparce Matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                sparce[p][0]=i;
                sparce[p][1]=j;
                sparce[p][2]=arr[i][j];
                p++;
            }
        }
    }
    len=p;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    cout<<"The Sparce List: "<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<sparce[i][0]<<" "<<sparce[i][1]<<" "<<sparce[i][2]<<endl;
    }

    cout<<"Transpose Sparce List: "<<endl;
    for(int i=0;i<p;i++)
    {
        int temp=sparce[i][1];
        sparce[i][1]=sparce[i][0];
        sparce[i][0]=temp;
    }
    for(int i=0;i<p;i++)
    {
        cout<<sparce[i][0]<<" "<<sparce[i][1]<<" "<<sparce[i][2]<<endl;
    }

    
    cout<<"Sorted :"<<endl;
    for(int i=0;i<p;i++)
    {
        for(int j=i+1;j<p;j++)
        {
            if(sparce[i][0]> sparce[j][0])
            {
                int temp=sparce[i][0];
                sparce[i][0]=sparce[j][0];
                sparce[j][0]=temp;

                temp=sparce[i][1];
                sparce[i][1]=sparce[j][1];
                sparce[j][1]=temp;

                temp=sparce[i][2];
                sparce[i][2]=sparce[j][2];
                sparce[j][2]=temp;
            }
            else if(sparce[i][0]==sparce[j][0])
            {
                for(int j=i;j<len;j++)
                {
                    if((sparce[j][1]>sparce[j+1][1])&&(sparce[j][0]==sparce[i][0]))
                    {
                        int temp=sparce[j][0];
                        sparce[j][0]=sparce[j+1][0];
                        sparce[j][0]=temp;

                        temp=sparce[j][1];
                        sparce[j][1]=sparce[j+1][1];
                        sparce[j+1][1]=temp;

                        temp=sparce[j][2];
                        sparce[j][2]=sparce[j+1][2];
                        sparce[j+1][2]=temp;
                    }
                    else
                    break;
                }
            }
        }        

        
    }
    for(int i=0;i<len;i++)
    {
        cout<<sparce[i][0]<<" "<<sparce[i][1]<<" "<<sparce[i][2]<<endl;
    }
}
