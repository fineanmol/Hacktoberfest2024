#include<iostream>

using namespace std;

int main()
{
    int i, a[50] ,size;
    cout<<"Enter array size( Max:50 ) :: ";
    cin>>size;
    cout<<"\nEnter array elements :: \n";
    for(i=0; i<size; i++)
     {
       cout<<"\nEnter arr["<<i<<"] Element :: ";
       cin>>a[i];
     }
    
    cout<<"\nStored Data in Array :: \n\n";
    
    for(i=0;i<size;i++)
     {
       cout<<" "<<a[i]<<" ";
     }

    int  largest=a[0];
    
    for (i=0;i<size;i++)
    {
      if(a[i]>largest)
       {
         largest=a[i];
       }
    }
    cout<<"\n\nLargest Element in an Array :: "<<largest<<endl;
    return 0;
}