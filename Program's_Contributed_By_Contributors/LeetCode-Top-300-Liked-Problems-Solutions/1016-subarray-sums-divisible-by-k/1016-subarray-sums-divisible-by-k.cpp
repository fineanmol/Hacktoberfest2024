class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        vector <int> occurance(k,0); // to store the occurances of the remainder of prev sum modulo k 
        int sum = 0; 

        for(int i : nums)
        {
            if(i < 0)
                sum += (i % k + k) % k; // keep track of running sum and making it to be positive by i % k
            else
                sum += i;
                
            occurance[sum % k]++; // inrementing the occurances of the remainders
        }

        int count = occurance[0]; // special case for 0 ( nC2 + n )

        for(int i : occurance)
        {
            count += (i*(i-1))/2; // general case for all others ( nC2 )
        }

        return count;
    }
};