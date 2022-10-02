#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cout << "Enter the number of elements in the given array: ";
	//taking input
	cin >> n;
	int a[n];
	cout << "Enter the elements" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	//easy way to find the maximum difference between 2
	//elements in a given array is to find the difference
	//between maximum and minimum elements in the array
	
	int min = a[0], max = a[0];
	//applying linear search to find minimum and maximum of the given array
	for (int i = 1; i <n; i++){
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	
	//printing the difference
	cout << "The maximum difference between 2 elements in the given array is " << abs(max - min);
	return 0;
}
