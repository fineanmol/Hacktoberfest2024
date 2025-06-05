//Link: https://leetcode.com/problems/longest-common-prefix/

string longestCommonPrefix(vector<string>& strs) {
    string smallest= *min_element(strs.begin(),strs.end());
    int n=strs.size();
    string ans="";
    for(int i=0; i<smallest.length();i++){
        int count=0;
        for(int j=0; j < n;j++){
            if(smallest[i]==strs[j][i]){
                count++;
            }
        }
        if(count==n){
            ans+=smallest[i];
        }else{
            break;
        }
    }
    return ans;
}