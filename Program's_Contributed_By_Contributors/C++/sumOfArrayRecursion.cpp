#include <iostream>
using namespace std;

int sum(int a[], int n){
    if(n==-1 || n==0){
        return 0;
    }
    if(n==1){
        return a[0];
    }
    int result = a[0] + a[1];
    return result + sum(a+2, n-2);
}

int main() {
    int n = 5;
    int a[n] = {1,1,1,3,2};
    int output = sum(a, n);
    cout<<output<<endl;
}


