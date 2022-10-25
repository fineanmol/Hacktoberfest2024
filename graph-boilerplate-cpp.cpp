#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void __Main() {
#ifndef ONLINE_JUDGE
    freopen("Output.txt", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("LogE.txt", "w", stderr);
#endif
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
}

const int M = 1e9 + 7;
long long mod(long long x) {return ((x % M + M) % M);}
long long add(long long a, long long b) {return mod(mod(a) + mod(b));}
long long mul(long long a, long long b) {return mod(mod(a) * mod(b));}
template<typename o> void vec1d(vector<o> &v) {for (auto i : v) { cout << i << " ";} cout << "\n";}
template<typename o> void vec2d(vector<vector<o>> &v) {for (auto i : v) {for (auto j : i) {cout << j << " ";} cout << "\n";}}
template<typename o> void dbg(o x) {cerr << x << "\n";};
template<typename o> void ivec2d(vector<vector<o>> &v, int n, int m) {for (int i = 0; i < n; ++i) {vector<o> tmp(m, 0); v.push_back(tmp);}}
void m2p(multimap<int, int> &um) {for (auto i : um) {cout << i.first << " " << i.second << "\n";} cout << endl;}
void ump(unordered_map<int, int> &um) {for (auto i : um) {cout << i.first << " " << i.second << "\n";} cout << endl;}
void mp(map<long long int, long long int> &um) {for (auto i : um) {cout << i.first << " " << i.second << "\n";} cout << endl;}
void sds(stack<int> s) {cout << "\n--\n"; while (!s.empty()) {cout << s.top() << "\n"; s.pop();} cout << "--\n";}
/*------------------------------  Sublime  -----------------------------------*/



//Adjacency List (Interview)

/*

node -> (string,list)

graph

// map
[string,node *]

string to search name of the country
node * is the object which contains name and list
node -> [val,neighbours]
*/

class node {
public:
    int val;
    list<int> l;

    node(int n) {
        this->val = n;
    }
};

class graph {
public:
    unordered_map<int, node*> um;
    graph(vector<int> &s) {
        for (auto &i : s)
        {
            um.insert({i, new node(i)});
        }
    }
    void adEdge(int a, int b)
    {
        um[a]->l.push_back(b);
    }

    void print()
    {
        for (auto &i : um)
        {
            cout << i.first << "->";
            for (auto &j : i.second->l)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool cycle(int root, set<int> &visited, int parent)
    {
        if (visited.find(root) != visited.end())
        {
            return true;
        }

        auto i = um.find(root);
        visited.insert(root);
        for (auto &j : i->second->l)
        {
            visited.insert(j);
            bool z = cycle(j, visited, root);
            if (z == true) {
                return true;
            }


        }

        return false;
    }


};

int32_t main()
{
    __Main();
    vector<int> s{0, 2};
    graph g(s);
    g.adEdge(0, 2);
    g.adEdge(2, 0);
    g.adEdge(1, 0);
    g.adEdge(0, 1);
    g.adEdge(2, 1);
    g.adEdge(1, 2);
    g.print();

    set<int> visited;
    cout << g.cycle(0, visited, 0);
}