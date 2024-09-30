class Solution {
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        string ans = "";
        
        pair<int,char> prev={0,'#'};

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            if(prev.first > 0) pq.push(prev);
            
            if(top.first < prev.first)
            {
                ans += top.second;
                top.first -= 1;
            }
            else
            {
                ans += top.second;
                if(top.first > 1) ans += top.second;
                top.first -= 2;
            }
            prev = top;
        }
        
        return ans;
    }
};