#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr1 = {1,4,8,9,11};
	vector<int> arr2 = {2,3,6,7};

	int size = arr1.size() + arr2.size();
	int gap;
	gap = (size + 1)/2;
	//int flag = 0;
	while(gap>=1)
	{
		int low = 0;
		int high = gap;
		while(high<size)
		{
			if(low<arr1.size() and high<arr1.size())
			{
				if(arr1[low]>arr1[high])
					swap(arr1[low],arr1[high]);
			}
			else if(low<arr1.size() and high>=arr1.size())
			{
				if(arr1[low] > arr2[high-arr1.size()])
				{
					swap(arr1[low],arr2[high-arr1.size()]);
				}
			}
			else
			{
				if(arr2[low-arr1.size()]>arr2[high-arr1.size()])
				{
					swap(arr2[low-arr1.size()],arr2[high-arr1.size()]);
				}
			}
			low++;
			high++;
		}
		if(gap==1)
			break;
		gap = (gap+1)/2;
	}
	for(auto x: arr1)
	{
		cout<<x<<" ";
	}
	for(auto x: arr2)
	{
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}