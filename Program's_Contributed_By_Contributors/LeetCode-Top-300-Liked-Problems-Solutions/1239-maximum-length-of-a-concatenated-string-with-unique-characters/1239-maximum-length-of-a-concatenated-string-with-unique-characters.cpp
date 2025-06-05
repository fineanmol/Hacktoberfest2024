class Solution 
{
public:
    int maxLength(vector<string>& arr) 
    {
        int max_len = 0;
        
        // [1] we should first throw away all strings with any
        //    duplicate characters; strings with all unique 
        //    characters are the subsets of the alphabet, thus,
        //    can be encoded using binary form
        vector<bitset<26>> unique;
        for (auto s : arr)
        {
            bitset<26> bin;
            for (char ch : s) bin.set(ch - 'a');
            if (bin.count() == s.size())
                unique.push_back(bin);
        }
        
        // [2] now start with an empty concatenation and iteratively
        //    increase its length by trying to add more strings
        vector<bitset<26>> concat = {bitset<26>()};
        for (auto& u : unique)
            for (int i = concat.size() - 1; i >= 0; i--)
                if ((concat[i] & u).none())
                {
                    concat.push_back(concat[i] | u);
                    max_len = max(max_len, (int)(concat[i].count() + u.count()));
                }
        
        return max_len;
    }
};