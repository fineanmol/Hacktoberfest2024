#include <iostream>
using namespace std;

int Josephus(int N, int k)
{
    int i = 1, ans = 0;
    while (i <= N)
    {
        ans = (ans + k) % i;
        i++;
    }
    return ans + 1;
}

int main()
{
    int N = 14, k = 2;
    cout << Josephus(N, k) << endl;
    return 0;
}
