class Solution {
public:
    vector<int> topoSort(int sz, vector<vector<int>> &adj){
        vector<int> in(sz);
        vector<int> ans;
        for(int i = 0 ; i< sz; i++){
             for(auto node : adj[i]){
                 in[node]++;
             }
        }

        queue<int> q;
        for(int i = 0; i < sz; i ++){    
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto child : adj[curr]){
                in[child]--;
                if(in[child]==0){
                    q.push(child);
                }
            }
        }
        return (ans.size()==sz) ? ans : vector<int>{} ;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Reassign Group names if it is -1
        for(int i = 0 ; i< n ; i++){
            if(group[i]==-1){
                group[i] = m;
                m++;
            }
        }

        // Build 2 graphs, items and groups
        vector<vector<int>> adjItems(n);
        vector<vector<int>> adjGroups(m);

        for(int i=0;i<n;i++){
            vector<int> node = beforeItems[i];  
            for(auto child : node){
                adjItems[child].push_back(i);
                if(group[child]!=group[i]){ //If they are not same group, make an edge
                        adjGroups[group[child]].push_back(group[i]);
                }
            }
        }

        // Topo Sort both Graphs
        vector<int> sortedItems = topoSort(n, adjItems);
        vector<int> sortedGroups = topoSort(m, adjGroups);

        // Arrange Group items in toposorted Item order
        vector<vector<int>> sortedItemsGroup(m);
        for(auto item : sortedItems){
            sortedItemsGroup[group[item]].push_back(item);
        }

        // Use Group Sorted order to fill in final ans 

        vector<int> ans;
        for(auto grp : sortedGroups){
            for(auto node : sortedItemsGroup[grp]){
                ans.push_back(node);
            }
        }

        return ans;
    }
};