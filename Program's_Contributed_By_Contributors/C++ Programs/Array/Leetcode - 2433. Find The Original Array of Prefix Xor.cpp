// Problem Link : https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

// Vector : Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators
class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        vector<int> result;
        // Remember the property : if a ^ b = c then b ^ c = a and a ^ c = b
        for (int i = 0; i < pref.size(); i++)
        {
            if (i == 0)
                result.push_back(pref[i]);
            else
                // Xor of previous value with the current value
                result.push_back(pref[i - 1] ^ pref[i]);
        }
        return result;
    }
};