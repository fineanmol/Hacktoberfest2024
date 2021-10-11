#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int arr[], int low, int high){
	int pivot = arr[high]; 
	int i = (low - 1); 
    for (int j = low; j <= high - 1; j++){
	    if (arr[j] < pivot){
	        i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high){
	if (low < high){
	    int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main(){
	int size;
    cout<<"Enter the size ";
    cin>>size;
	int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the element for index "<<i<<endl;
        cin>>arr[i];
    }
    int lb=0;
    int ub=size;
    cout<<"Lets start sorting..."<<endl;
    quickSort(arr,lb,ub);
    for(int j=0;j<size;j++){
        cout<<arr[j];
	}
	return 0;
}


