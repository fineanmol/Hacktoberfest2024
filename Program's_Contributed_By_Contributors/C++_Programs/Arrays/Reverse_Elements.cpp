#include<iostream>
using namespace std;

int main()
{
   int a[20],b[20],i,j,size;

   cout<<"Enter array size( Max:50 ) :: ";
   cin>>size;
   
   cout<<"\nEnter array elements :: \n";
   for(i=0; i<size; i++)
     {
        cout<<"\nEnter arr["<<i<<"] Element :: ";
        cin>>a[i];
     }

   cout<<"\nThe Entered Array is :: \n\n";

   for(i=0;i<size;i++)
   {
     cout<<" "<<a[i]<<" ";
   }

   cout<<"\n\nReverse of Given Array is :: \n\n";

   for(i=size-1,j=0; i>=0;i--,j++)
   {
      b[i]=a[j];
   }

   for(i=0;i<size;i++)
   {
    cout<<" "<<b[i]<<" ";
   }

  cout<<"\n";

  return 0;
  }