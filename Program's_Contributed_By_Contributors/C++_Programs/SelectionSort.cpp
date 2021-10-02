
// Implementation of Selection sort using vectors

#include<iostream>
#include<vector>
using namespace std;

void swap(int *A, int i, int j) {    
          int temp = A[i];    
          A[i] = A[j];    
          A[j] = temp;    
}    


int findMinIndex(vector<int> &A, int start) {  
    int min_index = start;  
  
    ++start;  
  
    while(start < (int)A.size()) {  
        if(A[start] < A[min_index])  
            min_index = start;  
  
        ++start;  
    }  
  
    return min_index;  
}  
  
void selectionSort(vector<int> &A) {  
    for(int i = 0; i < (int)A.size(); ++i) {  
        int min_index = findMinIndex(A, i);  
  
        if(i != min_index)  
            swap(A[i], A[min_index]);  
    }  
}  

int main()
{
    vector<int> A = {5, 2, 6, 7, 2, 1, 0, 3};
    
    selectionSort(A);
    for(int num : A)  
        cout << num << ' ';  
  
    return 0;  
}
