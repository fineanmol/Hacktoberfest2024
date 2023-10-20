#include <iostream>
using namespace std; 
int arr[50];

void bubble(){
    int size;
    int num; 

    cout << "enter the size: " <<endl; 
    cin >> size;

    cout << "enter the elements: " <<endl; 

    for(int i = 0; i<size; i++){
        cin >> arr[i]; 
    }

    cout << "your normal array: " <<endl; 

    for(int i = 0; i<size; i++){
        cout << arr[i] << " "; 
    }

    for(int i = 0; i<size; i++){
        for(int j = 1; j<size-i; j++){
            if(arr[j] < arr[j-1]){
                int temp = arr[j]; 
                arr[j] = arr[j-1]; 
                arr[j-1] = temp; 
            }
        }
    }

    cout << endl; 

    cout << "your sorted array is: " <<endl; 
    for(int i = 0; i<size; i++){
        cout << arr[i] <<" "; 
    }

    
}

int main(){
    bubble();
    return 0; 
}
