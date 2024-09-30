class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size() - 1, n2 = s.size() - 1; 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        while(n1 >= 0 && n2 >= 0){
            if(g[n1] <= s[n2]){
                cnt += 1;
                n1--;
                n2--;
            }else{
                n1--;
            }
        }
        return cnt;
    }
};