#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> v)
{
    int i = 0, t = 0;

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                t++;
            }
        }
        if (t == 0)
        {
            cout << "Already sorted" << endl;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int size;
    cin >> size;

    vector<int> v1(size);

    for (auto &i : v1)
    {
        cin >> i;
    }

    bubbleSort(v1);

    return 0;
}