#include <iostream>

int main(){
    int size;
    std::cin >> size;

    int * arr= new int[size];

    for(int i=0; i<size; i++){
        std::cout << "Array[" << i << "]" << std::endl;
        std::cin >> arr[i];

    }

     for(int i=0; i<size; i++){
       // std::cout << arr[i] << std::endl;      
        std::cout << *(arr + i)<< std::endl;
        
    }

    delete [] arr;
    arr= NULL;


    system("pause>0");
}