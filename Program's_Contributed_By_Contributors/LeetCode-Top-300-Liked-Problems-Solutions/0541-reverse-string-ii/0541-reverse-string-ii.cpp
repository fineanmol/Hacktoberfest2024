class Solution {
public:
    // string reverseStr(string s, int k) {
    //     int n = s.length();
    //     int start = 0, ind = 0;
    //     for(int i = 0; i < n; i++){
    //         start += 1;
    //         if(start == 2 * k){
    //             reverse(s.begin() + ind, s.begin() + ind + k);
    //             ind = i + 1;
    //             start = 0;
    //         }
    //     }
    //     if(start < k)
    //         reverse(s.begin() + ind, s.end());
    //     else if(start < 2 * k && start >= k)
    //         reverse(s.begin() + ind, s.begin() + ind + k);
        
    //     return s;
    // }

    string reverseStr(string s, int k){
        int l = 0, h = k - 1, n = s.length();
        while(l < n){
            int start = l;
            if(h >= n)
                h = n - 1;
            
            while(l <= h){
                swap(s[l++], s[h--]);
            }

            l = start + 2 * k;
            h = l + k - 1;
        }
        return s;
    }
    
};