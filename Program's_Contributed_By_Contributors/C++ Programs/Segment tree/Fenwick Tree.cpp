#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

class FenwickTree {
public:
	vector<long long> bit;
	long long n;
	FenwickTree(long long n) {
		this->n = n;
		bit.assign(n, 0);
	}

	long long sum(long long r) {
		long long ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	long long sum(long long l, long long r) {
		if (l > r)
			return 0;
		return sum(r) - sum(l - 1);
	}

	void add(long long idx, long long delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};