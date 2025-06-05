#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map> 

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n,1);

        for(int i=2; i*i<n;i++){
            if (primes[i]){
                for (int j=i;j*i<n;j++){
                    primes[i*j]=0;
                }
            }
        }
        int count=0;
        for (int i=2;i<n;i++){
            if (primes[i])
                count+=1;
        }
    return count;
    }
};