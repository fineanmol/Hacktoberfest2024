#include <iostream>

using namespace std;

bool isSorted(int a[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(a[0] > a[1]){
        return false;
    }
    return isSorted(a+1, n-1);
}

int main() {

    int a[10] = {1,2,3,4,5,6,7,8,9,10};

    cout<<isSorted(a,10);



    return 0;
}