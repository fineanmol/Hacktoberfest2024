#include<bits/stdc++.h>
using namespace std;
//  Bfs using hashmap and node class
class Node{
public:
    int data;
    vector<int> nbrs;   // neighbour integers
    Node(int no){
        this->data = no;
    }
};

class Graph{

    unordered_map<int,Node*> m; // 1 -> 1 Node
  public:
    vector<bool> visited;  // 1-> visited   0-> not visited
    
    Graph(vector<int> v){
        for(auto i: v){
            m[i] = new Node(i);
        }
        int sz = v.size();
        visited.resize(sz);
    }

    void AddEdge(int a, int b, bool undir){
        m[a]->nbrs.push_back(b);
        if (undir)
        {
            m[b]->nbrs.push_back(a);
        }
    }

    void PrintGraph(){
        for(auto i: m){
            auto a = i.first;
            Node* node = i.second;
            cout<<a<<"->";

            for(auto j: node->nbrs){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    void Bfs(int a){
        Node* temp = m[a];
        queue<Node*> q;
        q.push(m[a]);
        visited[a] = true;

        while (!q.empty())
        {
            for(auto i: temp->nbrs){
                if(visited[i] ==false)
                {
                    q.push(m[i]);
                    visited[i] = true;
                }
            }
            cout<<q.front()->data<<" ";
            q.pop();
            temp = m[q.front()->data];
        }
    }
};

int main(){
    vector<int> v = {0,1,2,3,4,5,6};
    Graph g(v);

    g.AddEdge(1 ,0 ,1);
    g.AddEdge(1 ,2 ,1);
    g.AddEdge(0 ,4 ,1);
    g.AddEdge(2 ,3 ,1);
    g.AddEdge(3 ,4 ,1);
    g.AddEdge(4 ,5 ,1);
    g.AddEdge(3 ,5 ,1);
    g.AddEdge(5 ,6 ,1);

    g.Bfs(1);
    return 0;
}
