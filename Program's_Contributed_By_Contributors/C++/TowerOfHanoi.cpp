#include <iostream>
using namespace std;

int count = 0;

void towerOfHanoi(char s, char d, char e, int n){
    if(n<=0){
        return;
    }

    towerOfHanoi(s,e,d,n-1);
    
    cout<<"Move Disk "<< n <<" from "<< s <<" to "<<d<<endl;
    count++;
    towerOfHanoi(e,d,s,n-1);
}

int main() {

    towerOfHanoi('s','d','e', 6);
    cout<<endl;
    cout<<count<<endl;

    return 0;
}