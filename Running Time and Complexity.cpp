#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n;
        cin >> n;
        if(n == 1){
            printf("Not prime\n");
            continue;
        }
        if(n <= 3){
            printf("Prime\n");
            continue;
        }
        if(n % 2 == 0 || n % 3 == 0){
            printf("Not prime\n");
            continue;
        }
        
        bool prime = true;
        int sqRoot = sqrt(n);
        for(int i = 3; i <= sqRoot; i+=2){
            if(n % i == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            printf("Prime\n");
        } else {
            printf("Not prime\n");
        }
        
    }
    return 0;
}
