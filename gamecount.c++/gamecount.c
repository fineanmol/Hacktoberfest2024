#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
const ll mod = 98794607;
const ll Inf = 9000000000000000000ll;
const int Maxn = 10005;
const ll mod2 = 1012201;
 
ll O[Maxn];
ll A[Maxn];
ll F[Maxn];
ll qO[Maxn];
ll qF[Maxn];
ll inv[Maxn];
int t, n, k;
 
void gcd(int a, int &x, int b, int &y)
{
	if (a == 0) { x = 0; y = 1; }
	else {
		int xx, yy; gcd(b % a, xx, a, yy);
		x = yy - b / a * xx; y = xx;
	}
}
 
int Inv(int a, int mod)
{
	int x, y;
	gcd(a, x, mod, y);
	x %= mod;
	if (x < 0) x += mod;
	return x;
}
 
ll Mult(ll a, ll b, ll mod)
{
	if (a == 0 || b == 0) return 0;
	if (a <= Inf / b) return a * b % mod;
	if (a > b) swap(a, b);
	ll res = 0;
	while (a) {
		if (a & 1) res = (res + b) % mod;
		a >>= 1; b = (b + b) % mod;
	}
	return res;
}
 
int main()
{
	O[0] = 1;
	A[0] = F[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		O[i] = O[i - 1];
		F[i] = F[i - 1];
        A[i] = F[i - 1];
		for (int j = 2; j <= i; j++) {
			O[i] = (O[i] + O[j - 2] * O[i - j]) % mod;
			F[i] = (F[i] + F[j - 2] * A[i - j]) % mod;
            A[i] = (A[i] + A[j - 1] * F[i - j]) % mod;
		}
        A[i] = (A[i] + F[i]) % mod;
	}
	for (int i = 1; i < Maxn; i++)
		inv[i] = Inv(i, mod2);
	qO[0] = 1;
	for (int i = 1; i + 2 < Maxn; i++) {
		qO[i] = ll(2 * i + 1) * qO[i - 1];
		if (i >= 2) qO[i] = (qO[i] + ll(3 * i - 3) * qO[i - 2]);
		qO[i] %= mod2;
		qO[i] = Mult(qO[i], inv[i + 2], mod2);
	}
	qF[0] = 1;
	for (int i = 1; i + 1 < Maxn; i++) {
        qF[i] = 2 * ll(2 * i - 1) * qF[i - 1] % mod2;
		qF[i] = Mult(qF[i], inv[i + 1], mod2);
	}
	ll m1 = Inv(mod, mod2), m2 = Inv(mod2, mod);
	ll mod3 = mod * mod2;
	for (int i = 1; i + 2 < Maxn; i++) {
		ll a1 = O[i], a2 = qO[i];
		ll fir = Mult(Mult(a1, m2, mod3), mod2, mod3);
		ll sec = Mult(Mult(a2, m1, mod3), mod, mod3);
		O[i] = (fir + sec) % mod3;
 
		a1 = F[i], a2 = qF[i];
		fir = Mult(Mult(a1, m2, mod3), mod2, mod3);
		sec = Mult(Mult(a2, m1, mod3), mod, mod3);
		F[i] = (fir + sec) % mod3;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		ll res;
		if (k == 0) res = 0;
		else if (k == 1) res = (O[n] - 1 + mod3) % mod3;
		else res = (F[n] - 1 + mod3) % mod3;
		printf("%lld\n", res);
	}
	return 0;
}  
