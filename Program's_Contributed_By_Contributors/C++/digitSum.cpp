#include <iostream>
using namespace std;

int digitSum(int n){
    if(n<=9){
        return n;
    }

    int add = n%10;

    return add+digitSum(n/10);
}

int main() {

    int n;
    cin>>n;

    cout<<digitSum(n);

    return 0;
}