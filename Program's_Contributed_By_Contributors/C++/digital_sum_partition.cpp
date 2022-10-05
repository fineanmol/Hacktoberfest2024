/*
    Dhananjay Patel(Dhanu 😊)
    Codechef: dhanu0510
    Codeforces: Dhanu
    Github: dhanu0510
*/

#include <bits/stdc++.h>
using namespace std;
#pragma warning(push)
#define int long long int
#define loop(i, end) for (int i = 0; i < end; i++)
#define loopi(i, start, end) for (int i = start; i < end; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define mod 1000000007
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define endl "\n"

#define deb(x) cout << #x << " : " << x << endl;

template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void write(T... args)
{
    ((cout << args << " "), ...);
}

int sum_of_digit(int num){
    int sum = 0;
    while(num>0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// ASCII : a-z=97-122  ,A-Z=65-90, 0-9:48-57
void solve()
{
    int n;
    read(n);
    int main = sum_of_digit(n);
    bool even = false;
    if(main%2==0)
        even = true;
    for (int i = n + 1;;i++){
        int sum = sum_of_digit(i);
        if(even){
            if(sum%2!=0){
                cout << i << endl;
                break;
            }
        }
        else{
            if(sum%2==0){
                cout << i << endl;
                break;
            }
        }
    }
}

int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clock_t z = clock();
    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
