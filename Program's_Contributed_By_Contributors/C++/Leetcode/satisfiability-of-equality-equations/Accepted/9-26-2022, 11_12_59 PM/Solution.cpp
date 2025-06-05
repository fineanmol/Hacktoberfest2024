// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
    
    int arr[26];
    
    int find(int ind){
        if (arr[ind] == ind){
            return ind;
        }
        
        return find(arr[ind]);
    }
    
public:
    
    Solution(){
        for (int i = 0;i<26;i++){
            arr[i] = i;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        for (auto s:equations){
            if (s[1] == '='){
                arr[find(s[0]-'a')] = find(s[3]-'a');
            }
        }
        
        for (auto s:equations){
            if (s[1] == '!' && find(s[0]-'a') == find(s[3]-'a'))
                return false;
        }
        

        
        return true;
    }
};