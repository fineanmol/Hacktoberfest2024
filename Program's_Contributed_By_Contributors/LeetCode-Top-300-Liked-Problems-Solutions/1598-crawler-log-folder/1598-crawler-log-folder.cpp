class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(string s : logs){
            if(s == "../" && cnt > 0)
                cnt -= 1;
            else if(s == "../")
                continue;
            else if(s == "./")
                continue;
            else
                cnt += 1;
            cout << s << " : " << cnt << endl;
        }
        return cnt;
    }
};