#include <iostream>
using namespace std;

int main(){
    int A[] = {10, 20, 40, 70, 90};
    int B[] = {100, 110, 170, 190};
    int C[11];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<5 && j<4){
        if(A[i]<B[j]){
            C[k++] = A[i++];

        }else{
            C[k++] = B[j++];
        }
    }
    // Remaining elements
    for(;i<5; i++){
        C[k++] = A[i];
    }
    for(;j<4; j++){
        C[k++] = B[j];
    }

    int len = sizeof(C)/sizeof(C[0]);

    for(int m = 0 ; m<len; m++){
        cout<<C[m]<<" ";

    }
  
   
    
}
