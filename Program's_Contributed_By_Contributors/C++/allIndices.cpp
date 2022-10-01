#include <iostream>
using namespace std;

int allIndices(int a[], int size, int x, int output[]);

int main() {

    int a[6] = {5,6,6,5,6,5};
    int b[6];

    int n = allIndices(a,6,6,b);
    cout<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }

    return 0;
}


int allIndices(int a[], int size, int x, int *output){
    if(size==0){
        return 0;
    }

    int ans = allIndices(a, size-1, x, output);

    

    if(a[size-1] == x){
        output[ans] = size-1;
        return ans+1;
    }
    return ans;
}