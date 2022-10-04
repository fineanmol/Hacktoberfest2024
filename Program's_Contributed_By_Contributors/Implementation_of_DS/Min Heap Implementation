#include<queue>
vector<int> minHeap(int n, vector<vector<int>>& q) {
   priority_queue<int, vector<int>, greater<int> > p;
   vector<int> ans;
    
    for(int i = 0; i < q.size(); i++){
        if(q[i][0] == 0)
            p.push(q[i][1]);
        
        else{
            ans.push_back(p.top());
            p.pop();}
    }
    return ans;
}
