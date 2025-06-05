#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
int arr[50], size, insert, i, pos;
cout<<"Enter Array Size : ";
cin>>size;
cout<<"Enter array elements : \n";
for(i=0; i<size; i++)
{
cin>>arr[i];
}
for(i=0; i<size; i++)
{
for(int j=0; j<size; j++)
{
if(arr[j]>arr[j+1])
{
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
cout<<"Data After Sorting :\n";
for(int j=0;j<size;j++)
{
cout<<"\n"<<arr[j];
}
getch();
}
