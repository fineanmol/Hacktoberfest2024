#include <iostream>
using namespace std;

int countZeros(int n);

int main() {

    int n;
    cin>>n;

    cout<<countZeros(n);

    return 0;
}

int countZeros(int n){
    if(n<=9){
        if(n==0){
            return 1;
        }
        return 0;
    }

    int ans = n%10;
    int sum = 0;

    if(ans == 0){
        sum = 1;
    }

    return sum + countZeros(n/10);
}