#include <iostream>

using namespace std;

int firstIndex(int input[], int size, int x);

int main() {

    int a[10] = {2,4,1,2,8,5,2,1,9,8};
    
    cout<< firstIndex(a,10,1);

    return 0;
}


int firstIndex(int input[], int size, int x) {
    if(size == 0){
        return -1;
    }
    
    if(input[0] == x){
        return 0;
    }
    
    int ans = firstIndex(input+1, size-1, x);
    
    if(ans == -1){
        return -1;
    }
    
    return ans + 1;

}
