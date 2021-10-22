
#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>>graph[100];




class CompareDist
{
public:
    bool operator()( pair<int,pair<string,int>>n1, pair<int,pair<string,int>>n2) {
        return n1.first>n2.first;
    }
};

void bfs(int src){
    int visited[100];
    memset(visited,0,sizeof(visited));
    priority_queue< pair<int,pair<string,int>>,vector< pair<int,pair<string,int>>>,CompareDist>q;
    
    q.push(make_pair(0,make_pair(to_string(src)+"",src)));
    
    while(!q.empty()){
        auto current=q.top();
        q.pop();
        
        if(visited[current.second.second]==1){
            continue;
        }
        visited[current.second.second]=1;
        
        cout<<current.second.second<< " via "<<current.second.first<<" @ "<<current.first<<endl;
        for(auto x : graph[current.second.second]){
            if(visited[x.first]==0){
            q.push(make_pair((x.second+current.first),make_pair(current.second.first+to_string(x.first),x.first)));
            }
        }
    
        
    }
}

int main(){
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back(make_pair(y,z)); 
        graph[y].push_back(make_pair(x,z));

        
    }

int src;
cin>>src;
bfs(src);
    

    
    return 0;
}



