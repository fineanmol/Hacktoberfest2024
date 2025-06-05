#include<iostream>
#include<vector>
using namespace std;

void BinarySearch(vector <int> arr, int element)
{

int low=0, high=arr.size()-1;
int mid;
while(high > low)
{
mid=(low+high)/2;
if(arr[mid]==element)
{
cout<<"element found"<<endl;
return;
}
else if(element> arr[mid])
{
low=mid+1;
}
else
high=mid-1;
}
}

int main()
{

vector <int> A;
int size,n;
cout<<"enter size of array:";
cin>>size;
cout<<"enter elements of array:";
for(int i=0;i<size;i++)
{
cin>>n;
A.push_back(n);
}
int x;
cout<<"enter element to be searched:";
cin>>x;
BinarySearch(A,x);
return 0;
}