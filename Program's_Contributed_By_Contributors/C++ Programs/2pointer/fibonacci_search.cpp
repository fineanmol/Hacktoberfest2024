#include<iostream>
 
using namespace std;
 
void FibonacciSearch(int *a, int start, int end, int *fab, int index, int item)
{
	int i, mid;
 
	// Assigning middle of the array using Fibonacci element.
	mid = start+fab[index-2];
 
	// Return if item found at mid index.
	if(item == a[mid])
	{
		cout<<"\n item found at "<<mid<<" index.";
		return;
	}
	// Return if item found at start index.
	else if(item == a[start])
	{
		cout<<"\n item found at "<<start<<" index.";
		return;
	}
	// Return if item found at end index.
	else if(item == a[end])
	{
		cout<<"\n item found at "<<end<<" index.";
		return;
	}
	// If mid becomes start or end of the sub-array then element not found.
	else if(mid == start || mid == end)
	{
		cout<<"\nElement not found";
		return;
	}
	// According to the item value choose the partion to proceed further.
	else if(item > a[mid])
		FibonacciSearch(a, mid, end, fab, index-1, item);
	else
		FibonacciSearch(a, start, mid, fab, index-2, item);
}
 
int main()
{
	int n, i, biter, fab[20], a[20]={1, 9, 18, 24, 27, 35, 38, 41, 49, 53, 55, 66, 67, 72, 75, 77, 81, 89, 90, 97};
	char ch;
 
	fab[0] = 0;
	fab[1] = 1;
	i = 1;
	while(fab[i] < 20)
	{
		i++;
		fab[i] = fab[i-1]+fab[i-2];
	}
 
	up:
	cout<<"\nEnter the Element to be searched: ";
	cin>>n;
 
	// Implement Fibonacci search.
	FibonacciSearch(a, 0, 19, fab, i, n);
 
	// Ask user to enter choice for further searching.
	cout<<"\n\n	Do you want to search more...enter choice(y/n)?";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
		goto up;
 
	return 0;
}
