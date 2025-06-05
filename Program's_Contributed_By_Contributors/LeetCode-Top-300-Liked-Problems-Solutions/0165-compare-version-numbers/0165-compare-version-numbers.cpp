class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i = 0, j = 0, n = s1.length(), m = s2.length();
        while(i < n || j < m){
            int v1 = 0, v2 = 0;
            while(i < n && s1[i] != '.'){
                v1 = v1 * 10 + (s1[i] - '0');
                i++;
            }
            while(j < m && s2[j] != '.'){
                v2 = v2 * 10 + (s2[j] - '0');
                j++;
            }
            if(v1 > v2)
                return 1;
            else if(v1 < v2)
                return -1;
            
            i++;
            j++;
        }
        return 0;
    }
};