#include<bits/stdc++.h>
using namespace std;
int bin_search(int arr[],int size,int key){
	int start=0;
	int end = size-1;
	int mid= start+(end-start)/2;
	while(start <=end){
		if(arr[mid]==key){
			return mid;
		}
if(key>arr[mid]){
	start = mid+1;
}
else{
	end=mid-1;
}
mid = start+(end-start)/2;
}
return -1;
}

int main()
{
 int t;
 cin>>t;
 while(t>0)
 {
 	int size,key; cin>>size>>key;
 	int a[size];
 	for(int i=0 ;i<size;i++)
 	{
 		cin>>a[i];
 	}
 	int index =bin_search(a,size,key);
 	cout<<"index of given array :"<<index<<endl; 
   t--;
 }
 return 0;
}
