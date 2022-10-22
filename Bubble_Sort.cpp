#include<iostream>
using namespace std;

void BubbleSort(int arr[],int size){
	for(int i = 0 ;i<size ; i++){
		for(int j = 0; j<size -1 - i;j++){
			if(arr[j] >arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	
	
}
void printArray(int arr[], int size){
	for(int i = 0; i <size ; i++){
		cout<<arr[i]<<endl;
	}
}

int main(){
	
	int arr[6] = {23,10,65,55,34,5};
	cout<<"Array before Sorting :";
	printArray(arr,6);
	cout<<"\nArray After Sorting :";
	BubbleSort(arr,6);
	printArray(arr,6);
	
	
	
	
	
	return 0;
}
