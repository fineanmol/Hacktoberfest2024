// problem statement: http://codeforces.com/contest/165/problem/B
// author : St. James Peter
// Date: 09.10.2022

#include <iostream>
#include <climits>
#include <cmath>
#define ull unsigned long long

using namespace std;

int main()
{
		ull i, j, k;
		ull n, m, x;
		ull high, low, mid, ans, cnt;
		cin>>n>>k;
		high = n, low = 1, ans = 100000000000;
		while (low <= high)
		{
				mid = (high + low) / 2;
				cnt = mid;
				m = k;
				while (1)
				{
						x = mid / m;
						m *= k;
						cnt += x;
						if (!x)
								break;
				}
				if (cnt == n)
				{
						ans = mid;
						break;
				}
				if (cnt > n)
						ans = min(ans, mid), high = mid - 1;
				else
						low = mid + 1;
		}
		cout << ans;
		return 0;
}
