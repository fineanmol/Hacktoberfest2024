// question:https://leetcode.com/problems/count-primes/submissions/812562322/
class Solution {
public:
    int countPrimes(int n) 
    {
      // sieve algorithm
        vector<bool> primes(n+1,true);
        primes[0]=primes[1]=false;
        for(int i=2;i<=n;++i){
            if(primes[i]==true){
                for(int j=2*i;j<=n;j+=i){
                    primes[j]=false;
                }
            }
        }
     // queries
        int ct=0;
        for(int i=0;i<n;++i)
        {
            if(primes[i]==true) ++ct;
        }
        return ct;
    }
};
