#include <bits/stdc++.h>
using namespace std;
//BIT with 1 based indexing
template <typename T>
struct BIT
{
    T N;
    vector<T> tree;
    void init(int n)
    {
        N = n;
        tree.assign(n + 1, 0);
    }
    //point update in O(log(n))
    void update(int idx, T val)
    {

        while (idx <= N)
        {
            tree[idx - 1] += val;
            idx += (idx & (-idx));
        }
    }
    //query in O(log(n))
    T query(int idx)
    {
        T sm = 0;
        while (idx > 0)
        {
            sm += tree[idx - 1];
            idx -= (idx & (-idx));
        }
        return sm;
    }
    //sum function to find sum of values [l,r]
    T sum(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    BIT<int> f;
    f.init(n + 1); //1 base indexing
    //Building of Fenwick Tree in O(n*(log(n)))
    for (int i = 0; i < n; i++)
    {
        f.update(i + 1, v[i]);
    }
    //queries
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        //two types of queries
        //1) t = 1 change element at index i to u
        //2) t = 2 print the sum of elements in range [l,r]
        cin >> t;
        if (t == 1)
        {
            int id, u;
            cin >> id >> u;
            id--; //changing to zero base
            int initial = v[id];
            f.update(id + 1, u - initial); //updating the delta
            v[id] = u;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << f.sum(l, r) << endl;
        }
    }
}

// Time Complexity:
// O(nlogn)
// Space Complexity:
// O(n)

// Test Cases:
// Input:
// 5
// 1 3 4 7 -15
// 3
// 2 2 5
// 1 3 -5
// 2 2 5
// Output:
// -1
// -10
