#include <iostream>
using namespace std;
   
int main(){
    int Arr[100], size, i, num;
       
    cout << "Enter Number of Elements in Array\n";
    cin >> size;
     
    cout<<"enter elements of array:"<<endl;

    for(i = 0; i < size; i++){
        cin >> Arr[i];
    }
      
    cout << "Enter a number to serach in Array\n";
    cin >> num;
      
    // search num in inputArray from index 0 to elementCount-1 
    for(i = 0; i < size; i++){
        if(Arr[i] == num){
            cout << "Element found at index " << i;
            break;
        }
    }
      
    if(i == size){
        cout  << "Element Not Present in Input Array\n";
    }
 
    return 0;
}