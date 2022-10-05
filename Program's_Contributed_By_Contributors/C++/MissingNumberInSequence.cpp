//Contributed by: Divyansh Jha. Github: https://github.com/divyanshjha30 
//Program to find missing number in AP Sequence

#include <iostream>
using namespace std;
int main()
    {
        int arr[20],n;
        int d=0,i;
        int mis=0;
        cout<<"\nEnter Number of elements : ";
        cin>>n;
        cout<<"\nEnter elementes in array : ";
        for(i=0;i<n;i++)
            cin>>arr[i];
        cout<<"\nEntered elements are : ";
        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
        int cd=arr[1]-arr[0];
        for(i=0;i<n-1;i++)
            {
                d=arr[i+1]-arr[i];
                cout<<"\n"<<d<<"\n";
                if(cd!=d)
                    {
                        mis=arr[i]+cd;
                    }
                d=0;
            }
        cout<<"\nMissing number is : "<<mis;
    }