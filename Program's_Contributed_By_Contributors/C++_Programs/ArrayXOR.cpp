#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    vector<int> v;
    
    while (t--)
    {
        int type, num;
        scanf("%d %d", &type, &num);

        if (type == 1)
        {
            v.push_back(num);
        }
        else if (type == 2)
        {
            for (int i = 0; i < v.size(); ++i)
            {
                v[i] = num ^ v[i];
            }
        }
    }

    sort(v.begin(), v.end());

    for (auto x : v)
    {
        printf("%d ", x);
    }

    return 0;
}
