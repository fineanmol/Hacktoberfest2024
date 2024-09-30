class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(char ch : tasks)
            freq[ch]++;
        
        priority_queue<int> pq;
        for(auto it : freq){
            pq.push(it.second);
        }

        int cnt = 0;

        while(!pq.empty()){
            int cycle = n + 1;
            int tasksCount = 0;
            vector<int> temp;

            while(cycle-- && !pq.empty()){
                if(pq.top() > 1)
                    temp.push_back(pq.top() - 1);
                pq.pop();
                tasksCount++;
            }

            for(int num : temp){
                pq.push(num);
            }

            cnt += (pq.empty() ? tasksCount : n + 1);
        }
        return cnt;
    }
};