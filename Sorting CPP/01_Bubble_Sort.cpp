#include<iostream>
using namespace std;
 
/*
Best Time Complexity : O(n)
Average Time Complexity : O(n^2)
Worst Time Complexity : O(n^2)
Worst Space Complexity : O(1)
*/

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<", ";
    }
    cout<<endl;
}

void bubbleSort(int A[], int n){
    int temp;
    for (int i = 0; i < n-1; i++) 
    { 
        for (int j = 0; j <n-1-i ; j++) 
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}
 

 
int main(){
 
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    
    int n = 11;
    printArray(A, n);
    bubbleSort(A, n); 
    printArray(A, n); 
    return 0;
}
