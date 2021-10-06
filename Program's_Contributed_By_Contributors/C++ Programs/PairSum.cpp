#include <iostream>
using namespace std;

int main(){
	// Given a Sorted Array, Find Pair of Elements that sum to K(given)
	// 1 3, 5, 7, 10, 11, 12, 13
/*
	int n;
	cout<<"Enter length of array : ";
	cin>>n;
	int a[1000] ;
	
	cout<<"Enter the array :\n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
*/

	int a[] = {1,3,5,7,10,11,12,13};
	int s = 16;

	int i = 0;
	int j = sizeof(a)/sizeof(int) - 1;

	while(i<j){
		int current_sum = a[i] + a[j];
		if(current_sum > s){
			j--;
		}
		else if(current_sum < s){
			i++;
		}
		else if(current_sum == s){
			cout<<a[i] << " and " << a[j]<<endl;
			i++;
			j--;
		}
	}
	return 0;
}