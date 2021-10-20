#include<iostream>

using namespace std;

int main()
{
    int i,j,a[50],size;
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

    cout<<"\n\nDuplicate Values in Given Array are :: \n\n";
    for(i=0; i<size; i++)
    {
      for(j=i+1;j<size;j++)
      {
         if(a[i]==a[j])
         {
             cout<<" "<<a[i]<<" ";
         }
      }
    }

     cout<<"\n";

    return 0;
 }
