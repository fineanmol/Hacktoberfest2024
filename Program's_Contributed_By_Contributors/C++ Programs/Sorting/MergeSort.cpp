#include<iostream>
#include<vector>
#define MAX 100000
using namespace std;

//You are given two sorted arrays A and B. You want to merge these arrays and return a sorted vector will elements from both arrays.
void merge(vector<int> &a, vector<int> &b, vector<int> &toreturn)
{ 
    int apointer = 0, bpointer = 0; //point to the first element in the vectors
	
    //That hasn't been taken yet
    while(apointer<a.size() && bpointer<b.size())
	{
        if(a[apointer]<=b[bpointer]){
            toreturn.push_back(a[apointer++]);
        }
        else{ //b[bpointer] < a[apointer]
//            inv += (a.size() - apointer);
            toreturn.push_back(b[bpointer++]);
        }
    }
    while(apointer<a.size()) toreturn.push_back(a[apointer++]);
    while(bpointer<b.size()) toreturn.push_back(b[bpointer++]);
}

void ms(int arr[], int s, int e){
//	cout<<s<<" "<<e<<endl;
	if(s==e){// there is only one or no element
		return;
	}
	int mid = (s+e)/2;
	ms(arr, s, mid);
	ms(arr, mid+1, e);
	
	// Now arr[] has two sorted parts inside it. 
	// We have to take them out, merge the two parts and 
	// then resassign the values to arr[]
	vector<int> a,b;
	for(int i=s; i<=mid; i++) a.push_back(arr[i]);
	for(int i=mid+1; i<=e; i++) b.push_back(arr[i]);  
	
	vector<int> temp;
	merge(a,b, temp);
	for(int i=0; i<temp.size(); i++)
		arr[s+i] = temp[i];
	
}



int main()
{
	int n; 
	cin>>n; 
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	ms(arr, 0, n-1);
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	cout<<endl;
}