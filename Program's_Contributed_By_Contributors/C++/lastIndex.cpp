#include <iostream>

using namespace std;

int lastIndex(int input[], int size, int x);

int main() {

    int a[10] = {2,4,1,2,8,5,2,1,9,8};
    
    cout<< lastIndex(a,10,1);

    return 0;
}

int lastIndex(int input[], int size, int x) {
	if(size == 0){
        return -1;
    }
    
    int ans = lastIndex(input+1, size-1, x);
    
    
    
    if(ans == -1){
        if(input[0] == x){
        	return 0;
    	}
        return -1;
    }
    
    return ans+1;
}