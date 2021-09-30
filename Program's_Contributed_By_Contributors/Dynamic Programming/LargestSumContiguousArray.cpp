#include<iostream>
using namespace std;


int kadanes(int *a,int n){

int current_sum = 0;
int max_sum =0;

for(int i=0;i<n;i++){

    if(current_sum + a[i] >0){
        current_sum += a[i];
        max_sum = max(max_sum,current_sum);
    }
    else{
        current_sum = 0;
    }
}
return max_sum;
}

int main(){

int a[] = {-2,-3,4,-1,-2,4,-3};
int n = sizeof(a)/sizeof(int);

cout<<kadanes(a,n);

return 0;
}
