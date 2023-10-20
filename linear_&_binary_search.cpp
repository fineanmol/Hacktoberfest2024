#include <iostream>
using namespace std;

int arr[50]; 

void linear_search(){
    int size; 
    int num; 
    
    cout << "size: " <<endl; 
    cin >> size; 

    cout << "elements: " <<endl; 
    for(int i = 0; i<size; i++){
        cin >> arr[i];
    }
     
    cout << "your arrat: " <<endl; 
    for(int i = 0; i<size; i++){
        cout << arr[i] << " "; 
    }

    cout << "enter targeht element: " <<endl;
    int target; 
    cin >> target; 

     

     //main

     if(size == 0){//array not found
            cout << "array not found" << endl; 
        }

        for(int i = 0; i<size; i++){ // element found and returned the index (i == index)
            int element = arr[i];
            if(element == target){
                cout << i << endl;
            }
            
        }
    }




    void binary_search(){
    int size; 
    int num; 
    
    cout << "size for binary search: " <<endl; 
    cin >> size; 

    cout << "elements: " <<endl; 
    for(int i = 0; i<size; i++){
        cin >> arr[i];
    }
     
    cout << "your array: " <<endl; 
    for(int i = 0; i<size; i++){
        cout << arr[i] << " "; 
    }

    cout << "enter target element: " <<endl;
    int target; 
    cin >> target; 

    //main

    int start = 0;
    int end = size-1;
        while(start <= end){ 
            int mid = start + (end-start)/2;
            if(target<arr[mid]){
                end = mid-1;
            
            } 
            else if (target>arr[mid]){
                start = mid + 1; 
            }
            else {
               cout << "ans found: " <<endl; 
               cout << mid <<endl; 
            }

        }

        cout << "not found" <<endl; 
    
    }


int main(){
    linear_search();
    binary_search(); 
    return 0; 
}
