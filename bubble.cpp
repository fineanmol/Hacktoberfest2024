#include <bits/stdc++.h>
using namespace std;

void display(vector<int> A, int n)
{
    cout << endl;
    for (auto i : A)
        cout << i << " ";
}

void bubbleSort (int arr[], int n){
    int i ,j ;
    bool swapped;
    for(i=0;i<n-1;i++){
        swapped = false;

    for (j=0;j<n-i-1;j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped =true;
        }
    }
    if (swapped == false)
    break;
    }
}
void printArray(int arr[],int size){
    int i;
    for(i=0;i < size;i++)
    cout << " "<< arr[i];
}

int main()
{
    int arr[] = {5,3,1,9,8,2,4,7};
    int N =sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,N);
    cout<< "Sorted array";
    printArray(arr,N);
    return 0; 
}