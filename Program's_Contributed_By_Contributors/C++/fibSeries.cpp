#include <iostream>

using namespace std;

int fibSeries(int n){
    if(n<=1){
        return n;
    }

    int ans = fibSeries(n-1) + fibSeries(n-2);

    cout<<ans<<" ";
    return fibSeries(n-1) + fibSeries(n-2);
}

int main() {

    int n;
    cin>>n;

    fibSeries(n);

    return 0;
}