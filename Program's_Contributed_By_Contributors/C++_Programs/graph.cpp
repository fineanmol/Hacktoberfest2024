#include <iostream> 
#include<vector>
#include<unordered_set>
//#include <bits/stdc++.h>
#include<algorithm>
#include<queue>
using namespace std;


class Edge{
    public:
    int v=0;;
    int w=0;

    Edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};
int N=7;
vector<vector<Edge>> graph(N,vector<Edge>());

void AddEdge(vector<vector<Edge>> &gp,int u, int v, int w)
{
      Edge e1(u,w);
      Edge e2(v,w);
      gp[v].push_back(e1);
      gp[u].push_back(e2);
}

void display(vector<vector<Edge>> &gp)
{
for(int i=0;i<gp.size();i++)
{
   cout<<i<<"->";
    for(int j=0;j<gp[i].size();j++)
    {
        Edge e=gp[i][j];
        cout<<"("<<e.v<<","<<e.w<<")";
    }
     cout<<endl;
}
}

int findEdge(int v1,int v2)
{
    int vtx=-1;
    for(int i=0;i<graph[v1].size();i++)
    {   Edge e=graph[v1][i];
        if(e.v==v2)
        {
            vtx=i;
            break;
        }
    }
    return vtx;
}

void removeEdge(int u,int v)
{
    int idx1=findEdge(u,v);
    int idx2=findEdge(v,u);

    graph[u].erase(graph[u].begin()+idx1);
     graph[v].erase(graph[v].begin()+idx1);

}

void allpath(int src,int dest, vector<bool> vis,int w, string ans )
{
    if(src==dest)
    {
        cout<< ans+to_string(dest)<<endl;
        return;
    }
      vis[src]=true;
    for(Edge e:graph[src])
    {
        if(!vis[e.v])
        {
            
            allpath(e.v,dest,vis,w+ e.w,ans+to_string(src)+" ");
        }

        
    }
    vis[src]=false;
}
// void preorder(int src, vector<bool> vis, int w, string ans)
// {
//     vis[src]=true;

//     for(Edge e:graph[src])
//     {
//         if(!vis[e.v])
//         {
//             preorder(e.v,vis,w+e.w+ans+to_string())
//         }
//     }
// }

// class pair{
//     public:
//     int lightw=1e7;
//     string lights="";

//     int heawyw=0;
//     string heawys="";

//     int ceil=1e7;

//     int floor=0;

// };
// void allsol(int src,int dest, vector<bool> vis,int w, string ans, int data, pair &p )
// {
//     if(src==dest)
//     {
//        p.heawyw=max(p.heawyw,w);
       

//        p.lightw=max(p.lightw,w);

//        if(w>data)
//        {
//            p.ceil=min(w,p.ceil);
//        }

//        if(w<data)
//        {
//            p.floor=max(w,p.floor);
//        }
//        return;
//     }
//       vis[src]=true;
//     for(Edge e:graph[src])
//     {
//         if(!vis[e.v])
//         {
            
//             allsol(e.v,dest,vis,w+ e.w,ans+to_string(src)+" ",pair,p);
//         }

        
//     }
//     vis[src]=false;
// }

void HamiltonianPath(int src, int orsrc, vector<bool> visited,int cnt, string ans)
{
    if(cnt==visited.size()-1)
    {
        int idx=findEdge(src,orsrc);
        if(idx!=-1)
        {
            cout<<"cycle: "<<ans+to_string(src)<<endl;
        }
        else
        {
            cout<<"path: "<<ans+to_string(src)<<endl;
        }
    }
    visited[src]=true;
    for(Edge e:graph[src])
    {
        if(!visited[e.v])
        {
          HamiltonianPath(e.v,orsrc,visited,cnt+1,ans+to_string(src)+" ");
        }
    }
     visited[src]=false;
}

int dfs_gcc(int src,vector<bool> &vis)
{
    int count=0;
    vis[src]=true;

    for(Edge e: graph[src])
    {
        if(!vis[e.v])
        {
           count+= dfs_gcc(e.v,vis);
        }
    }
    return count + 1;
}



void BFS(int src, vector<bool> &vis)
{
  queue<pair<int,string>> q;
  int dest=6;
  q.push({src,to_string(src)});
  int cycle=0;

  while(q.size()!=0)
  {
      pair<int,string> rvtx=q.front();
      q.pop();
      
      if(vis[rvtx.first])    //cycle
      {
          cout<<"cycle: "<<rvtx.second<<endl;
          cycle++;
          continue;
      }

      vis[rvtx.first]=true;

      if(rvtx.first==dest)
      {
        cout<<rvtx.second<<endl;
        
      }

      for(Edge e: graph[rvtx.first])
      {
          if(!vis[e.v])
          {
              q.push({e.v,rvtx.second+ to_string(e.v)});
          }
      }

  }
cout<<cycle;

}

void BFS02(int src, vector<bool> vis)           //size 
{
    queue<pair<int,string>> q;
  int dest=6;
  q.push({src,to_string(src)});
  vis[src]=true;

  while(q.size()!=0)
  {
     

      int size=q.size();
       
      while(size-- >0)
      {
           pair<int,string> rvtx=q.front();
           q.pop();
       
         if(rvtx.first==dest)
         {
           cout<<rvtx.second<<endl;
        
         } 
          for( Edge e: graph[rvtx.first])
          {
              if(!vis[e.v])
          {
              q.push({e.v,rvtx.second+ to_string(e.v)});
              vis[e.v]=true;
          }

          }
      } 
  }

}

int GCC() //get connected components
{
    vector<bool> vis(N,false);
    int count=0;
    int maxsize=0;
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            count++;
            maxsize=max(maxsize,dfs_gcc(i,vis));
        }
    }
    cout<<maxsize<<endl;
    return count;
}

vector<int> par;
vector<int> setSize;

int findPar(int vtx)
{
    if(par[vtx]==vtx) return vtx;
    return par[vtx]=findPar(par[vtx]);
}

void mergeSet(int l1, int l2)
{
    if (setSize[l1] < setSize[l2])
    {
        par[l1] = l2;
        setSize[l2] += setSize[l1];
    }
    else
    {
        par[l2] = l1;
        setSize[l1] += setSize[l2];
    }
}

void kruskalalgo(vector<vector<int>> arr)
{
    vector<vector<Edge>> Kgraph(arr.size(),vector<Edge>());

    sort(arr.begin(),arr.end(),[](vector<int> &a, vector<int> &b){
        return a[2]<b[2]; 
    });
     for(vector<int> & ar: arr)
     {
         int u=ar[0];
         int v=ar[1];
         int p1=findPar(u);
         int p2=findPar(v);
         if(p1!=p2)
         {
             mergeSet(p1,p2);
             AddEdge(Kgraph,p1,p2,ar[2]);
         }
     }
}
class dpair{
    public:
    int src;
    int par;
    int w;
    int wsf;

    dpair(int src,int par, int w,int wsf)
    {
        this->src=src;
        this-> par=par;
        this->w=w;
        this->wsf=wsf;
    }
};

struct dcomp
{
    public:
    bool operator()(dpair &p1,dpair &p2)
    {
        return p1.wsf > p2.wsf;   //min pq
    }
};

void dijkstra(int src)
{
    priority_queue<dpair, vector<dpair>,dcomp> pq;
    vector<bool> vis(N,false);
    vector<vector<Edge>> Dgraph(N,vector<Edge>());

    pq.push(dpair(src,-1,0,0));

    while(pq.size()!=0)
    {
        int sz=pq.size();
        while(sz-->0){
        dpair rvtx=pq.top();
        pq.pop();
        if(vis[rvtx.src])
        {
            continue;
        }
        if(rvtx.par!=-1)
        AddEdge(Dgraph,rvtx.par,rvtx.src,rvtx.w);
        vis[rvtx.src]=true;
        for(Edge e:graph[rvtx.src])
        {
            if(!vis[e.v])
           pq.push( dpair(e.v,rvtx.src,e.w,rvtx.wsf+e.w));
        }
        
        }

    }
   display(Dgraph);

}
class primpair{
    public:
    int src;
    int par;
    int w;

    primpair(int src,int par, int w,int wsf)
    {
        this->src=src;
        this-> par=par;
        this->w=w;
        
    }
};
struct pcomp
{
    public:
    bool operator()(primpair &p1,primpair &p2)
    {
        return p1.w > p2.w;   //min pq
    }
};

void primsalgo(int src)
{
    priority_queue<primpair, vector<primpair>,pcomp> pq;
    vector<bool> vis(N,false);
    vector<vector<Edge>> Pgraph(N,vector<Edge>());

    pq.push(primpair(src,-1,0));

    while(pq.size()!=0)
    {
        int sz=pq.size();
        while(sz-->0){
        dpair rvtx=pq.top();
        pq.pop();
        if(vis[rvtx.src])
        {
            continue;
        }
        if(rvtx.par!=-1)
        AddEdge(Pgraph,rvtx.par,rvtx.src,rvtx.w);
        vis[rvtx]=true
        for(Edge e:graph[rvtx.src])
        {
            if(!vis[e.v])
           pq.push( primpair(e.v,rvtx.src,e.w));
        }
        
        }

    }
   display(Pgraph);

}

int main()
{
    AddEdge(graph,0,1,10);
    AddEdge(graph,1,2,10);
    AddEdge(graph,0,3,10);
    AddEdge(graph,2,3,40);
   AddEdge(graph,3,4,2);
    AddEdge(graph,4,5,2);
    AddEdge(graph,5,6,1);
    AddEdge(graph,4,6,3);
   // AddEdge(graph,2,5,8);
     //removeEdge(3,4);
   // display(graph);
    vector<bool> vis(N,false);
    //HamiltonianPath(2,2,vis,0,"");
   // cout<<GCC();
  // allpath(0,6,vis,0,"");
//   pair p;
//     allsol(0,6,vis,0,"",22,p);
//     cout<<p.heavyw<<endl;
//     cout<<p.lightw<<endl;
//BFS02(0,vis);
//dijkstra(0);
primsalgo(0);
    return 0;
    
}