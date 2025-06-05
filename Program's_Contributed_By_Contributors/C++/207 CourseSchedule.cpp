class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(auto i: prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        
        queue<int> q;
        //vector<int> res;
        
        for (int i=0; i< indegree.size(); i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            //res.push_back(v);
            for (auto i: adj[v]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        
        for (int i=0; i< indegree.size(); i++) {
            if (indegree[i] > 0) 
                return false;
        }
        return true;
    }
};
