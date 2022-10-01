#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define fo(a,n) for(int i=a;i<n;i++)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int mpow(int base, int exp) {
	base %= mod;
	int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((int)result * base) % mod;
		base = ((int)base * base) % mod;
		exp >>= 1;
	}
	return result;
}

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int profit_top(int prices[], int n, int dp1[]) {
	if (n <= 0) return 0;
	int maxi = INT_MIN;
	if (dp1[n] != 0) return dp1[n];
	fo(0, n) {
		int cut = i + 1;
		maxi = max(maxi, profit_top(prices, n - cut, dp1) + prices[i]);
	}
	dp1[n] = maxi;
	return dp1[n];
}

int profit_b(int prices[], int n, int dp[]) {

	fo(1, n + 1) {
		int maxi = INT_MIN;
		for (int j = 1; j <= i; j++) {
			maxi = max(maxi, dp[i - j] + prices[j - 1]);
		}
		dp[i] = maxi;
	}
	return dp[n];
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	c_p_c();
	int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(prices) / sizeof(int);
	int dp1[n + 1] = {0};
	int dp2[n + 1] = {0};
	cout << profit_top(prices, n, dp1) << " Top Down\n";
	cout << profit_b(prices, n, dp2) << " Bottom up\n";
	return 0;
}