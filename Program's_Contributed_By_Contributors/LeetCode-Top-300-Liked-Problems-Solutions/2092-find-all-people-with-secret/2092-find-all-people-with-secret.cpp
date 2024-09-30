class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // For every person, we store the meeting time and label of the person met.
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        // Earliest time at which a person learned the secret
        // as per current state of knowledge. If due to some new information,
        // the earliest time of knowing the secret changes, we will update it
        // and again process all the people whom he/she meets after the time
        // at which he/she learned the secret.
        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        // Queue for BFS. It will store (person, time of knowing the secret)
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(firstPerson, 0);

        // Do BFS
        while (!q.empty()) {
            auto [person, time] = q.front();
            q.pop();
            for (auto [t, nextPerson] : graph[person]) {
                if (t >= time && earliest[nextPerson] > t) {
                    earliest[nextPerson] = t;
                    q.emplace(nextPerson, t);
                }
            }
        }

        // Since we visited only those people who know the secret,
        // we need to return indices of all visited people.
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (earliest[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};