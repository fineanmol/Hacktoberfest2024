/**
 Excersice -> https://codeforces.com/contest/52/problem/C
 tags: data structures
**/
#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(ll i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<string,int> psi;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(15) <<x<<endl;
 
//int n;
struct segtree
{
    vector<ll> st, lazy;
    int n;
    ll neutro = 1e9,aux = 0 ; // "infinito"
    segtree(const vector<int> &v)
    {
        n = v.size();
        st.assign(n*4, 0);
        lazy.assign(n*4,aux);
        build(1, 0, n-1, v);
    }
    void build(int p, int L, int R, const vector<int> &v)
    {
        if (L == R) st[p] = v[L];
        else
        {
            ll m = (L+R)/2, l = p*2, r = l+1;
            build(l, L, m, v);
            build(r, m+1, R, v);
            st[p] = min(st[l], st[r]);
        }
    }
    void propagate(ll p, ll L, ll R, int val)
    {
        if (val == aux) return;
        st[p] += val;
        lazy[p] = aux;
        if (L == R) return;
        ll l = p*2, r = l+1;
        lazy[l] += val;
        lazy[r] += val;
    }
    ll query(int i, int j)
    {
        return query(1, 0, n-1, i, j);
    }
    void upd(int i, int j, int val)
    {
        upd(1, 0, n-1, i, j, val);
    }
 
    ll query(ll p, ll L, ll R, ll i, ll j)
    {
        propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return neutro;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = p*2, r = l+1;
        int lf = query(l, L, m, i, j);
        int rg = query(r, m+1, R, i, j);
        return min(lf, rg);
    }
 
    void upd(ll p, ll L, ll R, ll i, ll j, int val)
    {
        propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return;
        if (i <= L && j >= R) propagate(p, L, R, val);//st[p] = val;
        else
        {
            int m = (L+R)/2, l = p*2, r = l+1;
            upd(l, L, m, i, j, val);
            upd(r, m+1, R, i, j, val);
            st[p] = min(st[l], st[r]);
        }
    }
};
 
vector<string> split(const string &s/*, char c*/)
{
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (ss >> sub) v.pb(sub);
    //while (getline(ss, sub, c)) v.pb(sub);
    return v;
}
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
 
    int q,n;
    string s;
    cin >> n;
    vector<int> v(n,0);
    forn(i,0,n)  cin >> v[i];
    cin >> q;
    segtree st(v);
    cin.ignore();
    while(q--)
    {
        getline(cin, s);
        vector<string> aux = split(s);
        if(aux.sz == 2)
        {
            ll a = stoi(aux[0]), b = stoi(aux[1]),  ans = 0;
            if(a > b)
            {
                ans = min(st.query(0, b), st.query(a, n-1));
            }
            else
            {
                ans = st.query(a, b);
            }
            cout << ans << endl;
        }
        else
        {
            ll a = stoi(aux[0]), b = stoi(aux[1]), v = stoi(aux[2]), ans = 0;
            if(a > b)
            {
                st.upd(a, n, v);
                st.upd(0, b, v);
            }
            else
            {
                st.upd(a, b, v);
            }
        }
    }
}
