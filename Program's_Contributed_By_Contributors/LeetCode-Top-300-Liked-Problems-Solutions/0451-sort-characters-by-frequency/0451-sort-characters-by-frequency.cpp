class Solution {
public:
    string frequencySort(string s) {
        if (s.length() == 1)
            return s;

        map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < s.length(); i++)
            mp[s[i]]++;

        for (auto it : mp)
            pq.push({it.second, it.first});

        string st = "";
        while (!pq.empty()) {
            for (int i = 0; i < pq.top().first; i++)
                st += pq.top().second;

            pq.pop();
        }

        return st;
    }
};