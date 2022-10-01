#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
// unordered_map<lli, lli> mp;
// lli dp[100005] = {0};
#define MAX 1000000007
//lli g[6][6];
// map<lli, vector<int>> mp;
// lli arr[1000000];

struct Matrix
{
    lli a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix &other)
    {
        Matrix product;
        fo1(i, 2) fo1(j, 2) fo1(k, 2)
        {
            product.a[i][k] = (product.a[i][k] + a[i][j] * other.a[j][k]) % MAX;
        }
        return product;
    }
};
Matrix expo_power(Matrix b, lli k)
{
    Matrix product;
    fo1(i, 2) product.a[i][i] = 1;
    while (k > 0)
    {
        if (k % 2)
        {
            product = product * b;
        }
        b = b * b;
        k /= 2;
    }
    return product;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // w(t)
    // {
    //     doit();
    // }

    lli n;
    //double p;
    cin >> n;
    Matrix single;
    single.a[0][0] = 19;
    single.a[0][1] = 7;
    single.a[1][0] = 6;
    single.a[1][1] = 20;

    Matrix total = expo_power(single, n);
    cout << total.a[0][0] << endl;
}