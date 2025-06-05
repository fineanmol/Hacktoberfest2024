class Solution {
public:
    
    bool checkBipartite(vector<vector<int>>&graph,vector<int>&sets,bool flag,int src){
        for(auto x:graph[src]){
            if(sets[x]!=-1){
                if(sets[src]==sets[x]) {
                    flag=false; 
                    return false;
                }
            }
            else{
                sets[x]=sets[src]==0?1:0;
                flag = checkBipartite(graph,sets,flag,x);
            }
        }
        return flag;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> sets(graph.size(),-1);
        for(int i=0;i<sets.size();i++){
                if(sets[i]==-1){
                    bool flag = true;
                    sets[i]=0;
                    if(!checkBipartite(graph,sets,flag,i))return false; 
                }
            }
        return true;
        }
};
